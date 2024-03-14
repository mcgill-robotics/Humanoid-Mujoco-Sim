import os
from reward_functions import *
from simulation.gpu_vec_env import GPUVecEnv
from simulation.cpu_env import CPUEnv
from simulation import SIM_XML_PATH
import torch
from torch import nn
from stable_baselines3 import PPO
from stable_baselines3.common.callbacks import EvalCallback, CheckpointCallback, StopTrainingOnRewardThreshold
from stable_baselines3.common.torch_layers import FlattenExtractor
from stable_baselines3.common.vec_env import VecMonitor, DummyVecEnv

###########################
##  TRAINING PARAMETERS  ##
###########################

# Set environment variable to disable rendering
os.environ["RENDER_SIM"] = "False"

log_dir = "data/training_results"

##########################
##    HYPERPARAMETERS   ##
##########################

NUM_ENVS = 256
N_EVAL_EPISODES = 3
POLICY_ITERATIONS = 1000
POLICY_UPDATE_TIMESTEPS = 24 #24 # paper did policy iteration every ~0.24 seconds
TOTAL_TIMESTEPS = 4096 * POLICY_ITERATIONS * POLICY_UPDATE_TIMESTEPS # paper had 4096 agents running
CHECKPOINT = None
EVAL_FREQ = POLICY_UPDATE_TIMESTEPS * 10
CHECKPOINT_FREQ = POLICY_UPDATE_TIMESTEPS * 50
RANDOMIZATION_INCREMENT = 0.1

env = VecMonitor(GPUVecEnv(
    num_envs=NUM_ENVS,
    xml_path=SIM_XML_PATH,
    reward_fn=standingRewardFn,
    randomization_factor=0
))

print("\nInitializing environment...      ", end='')
env.reset()
env.step(None)
print("Done")

# env = VecMonitor(DummyVecEnv([ lambda : CPUEnv(
#                                     xml_path=SIM_XML_PATH,
#                                     reward_fn=standingRewardFn,
#                                     randomization_factor=0
#                                 )] * NUM_ENVS))

eval_env = VecMonitor(DummyVecEnv([ lambda : CPUEnv(
                                    xml_path=SIM_XML_PATH,
                                    reward_fn=standingRewardFn,
                                    randomization_factor=0
                                )]))

print("\nBeginning training.\n")


if CHECKPOINT is None:
    policy_args = {
        "net_arch": [256,256,256],
        "activation_fn": nn.ELU,
        "ortho_init": True,
        "log_std_init": -2,
        "full_std": False,
        "use_expln": True,
        "squash_output": False,
        "features_extractor_class": FlattenExtractor,
        "features_extractor_kwargs": None,
        "share_features_extractor": True,
        "normalize_images": False,
        "optimizer_class": torch.optim.Adam,
        "optimizer_kwargs": None
    }

    model = PPO(
        policy = "MlpPolicy",
        env = env,
        learning_rate = 0.00001,
        n_steps = POLICY_UPDATE_TIMESTEPS,
        batch_size = 64,
        n_epochs = 10,
        gamma = 0.99,
        gae_lambda = 0.95,
        clip_range = 0.2,
        clip_range_vf = None,
        normalize_advantage = True,
        ent_coef = 0.1,
        vf_coef = 1.0,
        max_grad_norm = 0.5,
        use_sde = True,
        sde_sample_freq = -1,
        rollout_buffer_class = None,
        rollout_buffer_kwargs = None,
        target_kl = None,
        stats_window_size = 100,
        tensorboard_log = None,
        policy_kwargs = policy_args,
        verbose = 1,
        seed = None,
        device = "auto",
        _init_setup_model = True,
    )
else:
    model = PPO.load(
        path=CHECKPOINT,
        env=env,
    )

##########################
##    TRAINING  LOOP    ##
##########################

for randomization_factor in [x*RANDOMIZATION_INCREMENT for x in range(0, 11)]:
    print(" >> TRAINING WITH RANDOMIZATION FACTOR {}".format(randomization_factor))
    env.set_attr("randomization_factor", randomization_factor)
    env.reset()
    eval_env.set_attr("randomization_factor", randomization_factor)
    eval_env.reset()

    checkpoint_callback = CheckpointCallback(save_freq=CHECKPOINT_FREQ,
                                            save_path=log_dir + "_r{}".format(randomization_factor),
                                            name_prefix="checkpoint",
                                            verbose=1)
    
    stop_training_callback = StopTrainingOnRewardThreshold(reward_threshold=950, verbose=1)

    eval_callback = EvalCallback(eval_env, best_model_save_path=log_dir + "_r{}".format(randomization_factor),
                                log_path=log_dir + "_r{}".format(randomization_factor), eval_freq=EVAL_FREQ,
                                n_eval_episodes=N_EVAL_EPISODES, deterministic=True,
                                render=False, callback_on_new_best=stop_training_callback, verbose=0)

    model.learn(total_timesteps=TOTAL_TIMESTEPS,
                callback=[checkpoint_callback, eval_callback],
                log_interval = 1,
                tb_log_name = "Standing_r{}".format(randomization_factor),
                reset_num_timesteps = False,
                progress_bar = True)
    
    print(" >> COMPLETED TRAINING WITH RANDOMIZATION FACTOR {}".format(randomization_factor))