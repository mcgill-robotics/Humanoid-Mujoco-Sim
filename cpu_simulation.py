import jax
from jax import numpy as jp
import numpy as np
import mujoco
from mujoco import mjx
import cv2
import random
from simulation_parameters import *
from reward_functions import *
from jax.scipy.spatial.transform import Rotation
import gc
import os

inverseRotateVectors = lambda q, v : Rotation.from_quat(q).inv().apply(v)

class CPUSimulation:
  def __init__(self, xml_path, reward_fn, physics_steps_per_control_step=5, timestep=0.001, randomization_factor=0, verbose=False):
    self.xml_path = xml_path
    self.randomization_factor = randomization_factor
    self.timestep = timestep
    self.reward_fn = reward_fn
    self.physics_steps_per_control_step = physics_steps_per_control_step
    self.rng_key = jax.random.PRNGKey(42)
    self.verbose = verbose
    
    self.reset()
    
  def reset(self):
    try:
      del self.renderer
    except: pass
    
    if self.verbose: print("Creating new simulation...")
    
    #load model from XML
    self.model = mujoco.MjModel.from_xml_path(self.xml_path)
    if os.environ.get('RENDER_SIM', "True") == "True": self.renderer = mujoco.Renderer(self.model, 720, 1080)
    self.model.opt.timestep = self.timestep
    self.model.opt.solver = mujoco.mjtSolver.mjSOL_NEWTON
    self.model.opt.iterations = 3
    self.model.opt.ls_iterations = 5
    self.model.opt.jacobian = mujoco.mjtJacobian.mjJAC_DENSE
   
    # Visualization Options:
    self.scene_option = mujoco.MjvOption()
    mujoco.mjv_defaultOption(self.scene_option)
    self.scene_option.flags[mujoco.mjtVisFlag.mjVIS_CONTACTPOINT] = True
    self.scene_option.flags[mujoco.mjtVisFlag.mjVIS_CONTACTFORCE] = False
    self.scene_option.flags[mujoco.mjtVisFlag.mjVIS_TRANSPARENT] = True
    self.scene_option.flags[mujoco.mjtVisFlag.mjVIS_JOINT] = True
    self.model.vis.scale.contactwidth = 0.1
    self.model.vis.scale.contactheight = 0.03
    self.model.vis.scale.forcewidth = 0.05
    self.model.vis.map.force = 0.3
    
    #initialize instance parameters
    self.next_force_start_time = 0
    self.next_force_direction = jp.zeros((2))
    self.next_force_magnitude = 0
    self.next_force_duration = 0
    self.next_force_body = 0
    self.previous_torso_local_velocity = jp.zeros((3))
    # save gravity vector
    self.gravity_vector = self.model.opt.gravity
    # save torso body index
    self.torso_idx = self.model.body(TORSO_BODY_NAME).id
    # save joint addresses in data.qpos
    self.joint_qpos_idx = []
    for joint in JOINT_NAMES:
      self.joint_qpos_idx.append(self.model.jnt_qposadr[self.model.joint(joint).id])
    self.joint_qpos_idx = jp.array(self.joint_qpos_idx)
    # get pressure sensor geometries
    self.pressure_sensor_ids = [self.model.geom(pressure_sensor_geom).id for pressure_sensor_geom in PRESSURE_GEOM_NAMES]
    
    # RANDOMIZATION
    # floor friction (0.5 to 1.0)
    self.model.geom('floor').friction = [coef * (1.0*(1.0-self.randomization_factor) + random.uniform(FLOOR_FRICTION_MIN_MULTIPLIER, FLOOR_FRICTION_MAX_MULTIPLIER)*self.randomization_factor) for coef in self.model.geom('floor').friction]    
    #delays in actions and observations (10ms to 50ms)
    self.action_delay = random.uniform(MIN_DELAY*self.randomization_factor, MAX_DELAY*self.randomization_factor)
    self.observation_delay = random.uniform(MIN_DELAY*self.randomization_factor, MAX_DELAY*self.randomization_factor)
    #round delays to be multiples of the timestep
    actual_timestep = self.timestep * self.physics_steps_per_control_step
    self.observation_delay = round(self.observation_delay / actual_timestep) * actual_timestep
    self.action_delay = round(self.action_delay / actual_timestep) * actual_timestep
    #make buffers for observations and actions
    self.observation_buffer = [None] * (int)(self.observation_delay/actual_timestep)
    self.action_buffer = [None] * (int)(self.action_delay/actual_timestep)
    # vary the mass of all limbs randomly
    for i in range(self.model.nbody-1): self.model.body(i+1).mass[0] += random.uniform(-MAX_MASS_CHANGE_PER_LIMB*self.randomization_factor, MAX_MASS_CHANGE_PER_LIMB*self.randomization_factor)
    # attach a random external mass (up to 0.1 kg) to a randomly chosen limb
    self.model.body(random.randint(1, self.model.nbody - 1)).mass[0] += random.uniform(0, MAX_EXTERNAL_MASS_ADDED*self.randomization_factor)
    # randomize IMU Z
    self.imu_z_offset = jax.random.uniform(key=self.rng_key, minval=-IMU_Z_OFFSET_MAX, maxval=IMU_Z_OFFSET_MAX)
    # randomize joint properties  
    for joint in JOINT_NAMES:
      self.model.joint(joint).damping[0] += random.uniform(-JOINT_DAMPING_MAX_CHANGE, JOINT_DAMPING_MAX_CHANGE)*self.randomization_factor
      self.model.joint(joint).armature[0] += random.uniform(0, JOINT_ARMATURE_MAX_CHANGE)*self.randomization_factor
      self.model.joint(joint).stiffness[0] += random.uniform(0, JOINT_STIFFNESS_MAX_CHANGE)*self.randomization_factor
      self.model.joint(joint).margin[0] += random.uniform(0, JOINT_MARGIN_MAX_CHANGE)*self.randomization_factor
      self.model.joint(joint).range[0] += random.uniform(-JOINT_RANGE_MAX_CHANGE, JOINT_RANGE_MAX_CHANGE)*self.randomization_factor
      self.model.joint(joint).range[1] += random.uniform(-JOINT_RANGE_MAX_CHANGE, JOINT_RANGE_MAX_CHANGE)*self.randomization_factor
    for joint in JOINT_ACTUATOR_NAMES:
      self.model.actuator(joint).forcerange[0] += random.uniform(-JOINT_FORCE_LIMIT_MAX_CHANGE, JOINT_FORCE_LIMIT_MAX_CHANGE)*self.randomization_factor
      self.model.actuator(joint).forcerange[1] += random.uniform(-JOINT_FORCE_LIMIT_MAX_CHANGE, JOINT_FORCE_LIMIT_MAX_CHANGE)*self.randomization_factor
      kp = max(0, JOINT_PID_P_GAIN + random.uniform(-JOINT_PID_GAIN_MAX_CHANGE, JOINT_PID_GAIN_MAX_CHANGE)*self.randomization_factor)
      kv = max(0, JOINT_PID_V_GAIN + random.uniform(-JOINT_PID_GAIN_MAX_CHANGE, JOINT_PID_GAIN_MAX_CHANGE)*self.randomization_factor)
      self.model.actuator(joint).gainprm[0] = kp
      self.model.actuator(joint).biasprm[1] = -kp
      self.model.actuator(joint).biasprm[2] = -kv
      
    # create data from model
    self.cpu_model = None
    self.data = mujoco.MjData(self.model)
    mujoco.mj_kinematics(self.model, self.data)
    # randomize joint initial states (CPU)
    for i in range(len(self.data.qpos)):
      self.data.qpos[i] += random.uniform(-JOINT_INITIAL_STATE_OFFSET_MAX/180.0*jp.pi, JOINT_INITIAL_STATE_OFFSET_MAX/180.0*jp.pi)*self.randomization_factor

    self.step()      

    # clean up any unreferenced variables
    gc.collect()
    
    if self.verbose: print("Simulation initialized.")
      
  def getObs(self):
    if self.verbose: print("Collecting observations...")
    
    torso_quat = self.data.xquat[self.torso_idx]
    torso_global_vel = self.data.cvel[self.torso_idx]
    
    # joint positions     20          Joint positions in radians
    joint_angles = self.data.qpos[self.joint_qpos_idx] + ((JOINT_ANGLE_NOISE_STDDEV/180.0*jp.pi) * jax.random.normal(key=self.rng_key, shape=[len(self.joint_qpos_idx)]))
    
    # angular velocity    3           Angular velocity (roll, pitch, yaw) from IMU
    torso_global_ang_vel = torso_global_vel[0:3]
    local_ang_vel = inverseRotateVectors(torso_quat, torso_global_ang_vel) + (GYRO_NOISE_STDDEV * jax.random.normal(key=self.rng_key, shape=(3,)))
    # agent velocity      2           X and Y velocity of robot torso
    torso_global_velocity = torso_global_vel[3:] + (VELOCIMETER_NOISE_STDDEV * jax.random.normal(key=self.rng_key, shape=(3,)))
    # linear acceleration 3           Linear acceleration from IMU
    torso_local_velocity = inverseRotateVectors(torso_quat, torso_global_velocity)
    torso_local_accel = (torso_local_velocity - self.previous_torso_local_velocity) + (ACCELEROMETER_NOISE_STDDEV * jax.random.normal(key=self.rng_key, shape=(3,)))
    self.previous_torso_local_velocity = torso_local_velocity
    # gravity             3           Gravity direction, derived from angular velocity using Madgwick filter
    noisy_torso_quat = torso_quat + ((IMU_NOISE_STDDEV/180.0*jp.pi) * jax.random.normal(key=self.rng_key, shape=(4,)))
    local_gravity_vector = inverseRotateVectors(noisy_torso_quat, self.gravity_vector)
    # foot pressure       8           Pressure values from foot sensors
    pressure_values = np.zeros((8))
    for i in range(len(self.pressure_sensor_ids)):
      for ci in range(len(self.data.contact.geom1)):
        if self.data.contact.geom1[ci] == self.pressure_sensor_ids[i]: pressure_values[i] += abs(self.data.efc_force[self.data.contact.efc_address[ci]])
        if self.data.contact.geom2[ci] == self.pressure_sensor_ids[i]: pressure_values[i] += abs(self.data.efc_force[self.data.contact.efc_address[ci]])
    
    observations = jp.concatenate((joint_angles, local_ang_vel, torso_global_velocity[0:2], torso_local_accel, local_gravity_vector, pressure_values))
  
    # cycle observation through observation buffer
    self.observation_buffer.append(observations)
    delayed_observations = self.observation_buffer.pop(0)
    
    if self.verbose: print("Observations collected.")
    
    return delayed_observations
    
  def computeReward(self):
    if self.verbose: print("Computing reward...")
    
    torso_global_velocity = self.data.cvel[self.torso_idx][3:]
    torso_z_pos = self.data.xpos[self.torso_idx, 2]
    torso_z_pos += self.imu_z_offset
    torso_quat = self.data.xquat[self.torso_idx]
    joint_torques = self.data.qfrc_constraint + self.data.qfrc_smooth
    
    rewards = self.reward_fn(torso_global_velocity, torso_z_pos, torso_quat, joint_torques)
    
    if self.verbose: print("Reward computed.")

    return rewards
    
  def step(self, action=None):
    if self.verbose: print("Stepping simulation...")
    # cycle action through action buffer
    self.action_buffer.append(action)
    action_to_take = self.action_buffer.pop(0)
    if action_to_take is not None:
      self.data.ctrl = action_to_take
        
    # apply forces to the robot to destabilise it
    if self.data.time > self.next_force_start_time + self.next_force_duration:
      self.next_force_start_time = self.data.time + random.uniform(MIN_EXTERNAL_FORCE_INTERVAL, MAX_EXTERNAL_FORCE_INTERVAL)
      self.next_force_duration = random.uniform(MIN_EXTERNAL_FORCE_DURATION*self.randomization_factor, MAX_EXTERNAL_FORCE_DURATION*self.randomization_factor)
      self.next_force_magnitude = random.uniform(MIN_EXTERNAL_FORCE_MAGNITUDE*self.randomization_factor, MAX_EXTERNAL_FORCE_MAGNITUDE*self.randomization_factor)
      self.next_force_body = random.randint(1, len(self.data.xfrc_applied) - 1)
      self.next_force_direction = np.array([random.uniform(-1, 1), random.uniform(-1, 1)])
      self.data.xfrc_applied[self.next_force_body][0] = 0
      self.data.xfrc_applied[self.next_force_body][1] = 0
      
      while np.linalg.norm(self.next_force_direction) == 0: self.next_force_direction = np.array([random.uniform(-1, 1), random.uniform(-1, 1)])
      self.next_force_direction = self.next_force_direction / np.linalg.norm(self.next_force_direction)
    if self.data.time > self.next_force_start_time and self.data.time < self.next_force_start_time + self.next_force_duration:
      self.data.xfrc_applied[self.next_force_body][0] = self.next_force_direction[0] * self.next_force_magnitude
      self.data.xfrc_applied[self.next_force_body][1] = self.next_force_direction[1] * self.next_force_magnitude
    
    # step simulation
    for _ in range(self.physics_steps_per_control_step):
      mujoco.mj_step(self.model, self.data)
      
    if self.verbose: print("Simulation stepped.")
    
  def render(self, display=True):
    if not os.environ.get('RENDER_SIM', "True") == "True": return np.zeros((100,100))
    self.renderer.update_scene(self.data, camera="track", scene_option=self.scene_option)
    frame = self.renderer.render()
    if display:
      cv2.imshow("Sim View", frame)
      cv2.waitKey(1)
    return frame
    
if __name__ == "__main__":
    sim = CPUSimulation(xml_path="assets/world.xml", reward_fn=standingRewardFn, timestep=0.005, randomization_factor=1)
    
    while True:
      while sim.data.time < 2:
        observation = sim.getObs()
        action = [0]*4
        sim.step(action)
        reward = sim.computeReward()
        print(reward)
        sim.render()
      sim.reset()