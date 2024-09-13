# CMake generated Testfile for 
# Source directory: /Humanoid-MPC/mujoco_mpc/mjpc/test/spline
# Build directory: /Humanoid-MPC/mujoco_mpc/build/mjpc/test/spline
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(TimeSplineAllInterpolationsTest.Empty "/Humanoid-MPC/mujoco_mpc/build/bin/spline_test" "--gtest_filter=TimeSplineAllInterpolationsTest.Empty")
set_tests_properties(TimeSplineAllInterpolationsTest.Empty PROPERTIES  WORKING_DIRECTORY "/Humanoid-MPC/mujoco_mpc/mjpc/test" _BACKTRACE_TRIPLES "/usr/share/cmake-3.22/Modules/GoogleTest.cmake;400;add_test;/Humanoid-MPC/mujoco_mpc/mjpc/test/CMakeLists.txt;31;gtest_add_tests;/Humanoid-MPC/mujoco_mpc/mjpc/test/spline/CMakeLists.txt;15;test;/Humanoid-MPC/mujoco_mpc/mjpc/test/spline/CMakeLists.txt;0;")
add_test(*/TimeSplineAllInterpolationsTest.OneNode/* "/Humanoid-MPC/mujoco_mpc/build/bin/spline_test" "--gtest_filter=*/TimeSplineAllInterpolationsTest.OneNode/*")
set_tests_properties(*/TimeSplineAllInterpolationsTest.OneNode/* PROPERTIES  WORKING_DIRECTORY "/Humanoid-MPC/mujoco_mpc/mjpc/test" _BACKTRACE_TRIPLES "/usr/share/cmake-3.22/Modules/GoogleTest.cmake;400;add_test;/Humanoid-MPC/mujoco_mpc/mjpc/test/CMakeLists.txt;31;gtest_add_tests;/Humanoid-MPC/mujoco_mpc/mjpc/test/spline/CMakeLists.txt;15;test;/Humanoid-MPC/mujoco_mpc/mjpc/test/spline/CMakeLists.txt;0;")
add_test(*/TimeSplineAllInterpolationsTest.TwoNodes/* "/Humanoid-MPC/mujoco_mpc/build/bin/spline_test" "--gtest_filter=*/TimeSplineAllInterpolationsTest.TwoNodes/*")
set_tests_properties(*/TimeSplineAllInterpolationsTest.TwoNodes/* PROPERTIES  WORKING_DIRECTORY "/Humanoid-MPC/mujoco_mpc/mjpc/test" _BACKTRACE_TRIPLES "/usr/share/cmake-3.22/Modules/GoogleTest.cmake;400;add_test;/Humanoid-MPC/mujoco_mpc/mjpc/test/CMakeLists.txt;31;gtest_add_tests;/Humanoid-MPC/mujoco_mpc/mjpc/test/spline/CMakeLists.txt;15;test;/Humanoid-MPC/mujoco_mpc/mjpc/test/spline/CMakeLists.txt;0;")
add_test(*/TimeSplineReserveTest.AddNodeBeforeStart/* "/Humanoid-MPC/mujoco_mpc/build/bin/spline_test" "--gtest_filter=*/TimeSplineReserveTest.AddNodeBeforeStart/*")
set_tests_properties(*/TimeSplineReserveTest.AddNodeBeforeStart/* PROPERTIES  WORKING_DIRECTORY "/Humanoid-MPC/mujoco_mpc/mjpc/test" _BACKTRACE_TRIPLES "/usr/share/cmake-3.22/Modules/GoogleTest.cmake;400;add_test;/Humanoid-MPC/mujoco_mpc/mjpc/test/CMakeLists.txt;31;gtest_add_tests;/Humanoid-MPC/mujoco_mpc/mjpc/test/spline/CMakeLists.txt;15;test;/Humanoid-MPC/mujoco_mpc/mjpc/test/spline/CMakeLists.txt;0;")
add_test(TimeSplineTest.AddNodeResetsToZeroByDefault "/Humanoid-MPC/mujoco_mpc/build/bin/spline_test" "--gtest_filter=TimeSplineTest.AddNodeResetsToZeroByDefault")
set_tests_properties(TimeSplineTest.AddNodeResetsToZeroByDefault PROPERTIES  WORKING_DIRECTORY "/Humanoid-MPC/mujoco_mpc/mjpc/test" _BACKTRACE_TRIPLES "/usr/share/cmake-3.22/Modules/GoogleTest.cmake;400;add_test;/Humanoid-MPC/mujoco_mpc/mjpc/test/CMakeLists.txt;31;gtest_add_tests;/Humanoid-MPC/mujoco_mpc/mjpc/test/spline/CMakeLists.txt;15;test;/Humanoid-MPC/mujoco_mpc/mjpc/test/spline/CMakeLists.txt;0;")
add_test(TimeSplineTest.ZeroOrder "/Humanoid-MPC/mujoco_mpc/build/bin/spline_test" "--gtest_filter=TimeSplineTest.ZeroOrder")
set_tests_properties(TimeSplineTest.ZeroOrder PROPERTIES  WORKING_DIRECTORY "/Humanoid-MPC/mujoco_mpc/mjpc/test" _BACKTRACE_TRIPLES "/usr/share/cmake-3.22/Modules/GoogleTest.cmake;400;add_test;/Humanoid-MPC/mujoco_mpc/mjpc/test/CMakeLists.txt;31;gtest_add_tests;/Humanoid-MPC/mujoco_mpc/mjpc/test/spline/CMakeLists.txt;15;test;/Humanoid-MPC/mujoco_mpc/mjpc/test/spline/CMakeLists.txt;0;")
add_test(TimeSplineTest.Linear "/Humanoid-MPC/mujoco_mpc/build/bin/spline_test" "--gtest_filter=TimeSplineTest.Linear")
set_tests_properties(TimeSplineTest.Linear PROPERTIES  WORKING_DIRECTORY "/Humanoid-MPC/mujoco_mpc/mjpc/test" _BACKTRACE_TRIPLES "/usr/share/cmake-3.22/Modules/GoogleTest.cmake;400;add_test;/Humanoid-MPC/mujoco_mpc/mjpc/test/CMakeLists.txt;31;gtest_add_tests;/Humanoid-MPC/mujoco_mpc/mjpc/test/spline/CMakeLists.txt;15;test;/Humanoid-MPC/mujoco_mpc/mjpc/test/spline/CMakeLists.txt;0;")
add_test(TimeSplineTest.Cubic "/Humanoid-MPC/mujoco_mpc/build/bin/spline_test" "--gtest_filter=TimeSplineTest.Cubic")
set_tests_properties(TimeSplineTest.Cubic PROPERTIES  WORKING_DIRECTORY "/Humanoid-MPC/mujoco_mpc/mjpc/test" _BACKTRACE_TRIPLES "/usr/share/cmake-3.22/Modules/GoogleTest.cmake;400;add_test;/Humanoid-MPC/mujoco_mpc/mjpc/test/CMakeLists.txt;31;gtest_add_tests;/Humanoid-MPC/mujoco_mpc/mjpc/test/spline/CMakeLists.txt;15;test;/Humanoid-MPC/mujoco_mpc/mjpc/test/spline/CMakeLists.txt;0;")
add_test(*/TimeSplineAllInterpolationsTest.DiscardBefore/* "/Humanoid-MPC/mujoco_mpc/build/bin/spline_test" "--gtest_filter=*/TimeSplineAllInterpolationsTest.DiscardBefore/*")
set_tests_properties(*/TimeSplineAllInterpolationsTest.DiscardBefore/* PROPERTIES  WORKING_DIRECTORY "/Humanoid-MPC/mujoco_mpc/mjpc/test" _BACKTRACE_TRIPLES "/usr/share/cmake-3.22/Modules/GoogleTest.cmake;400;add_test;/Humanoid-MPC/mujoco_mpc/mjpc/test/CMakeLists.txt;31;gtest_add_tests;/Humanoid-MPC/mujoco_mpc/mjpc/test/spline/CMakeLists.txt;15;test;/Humanoid-MPC/mujoco_mpc/mjpc/test/spline/CMakeLists.txt;0;")
add_test(TimeSplineTest.DiscardBeforeRingLoop "/Humanoid-MPC/mujoco_mpc/build/bin/spline_test" "--gtest_filter=TimeSplineTest.DiscardBeforeRingLoop")
set_tests_properties(TimeSplineTest.DiscardBeforeRingLoop PROPERTIES  WORKING_DIRECTORY "/Humanoid-MPC/mujoco_mpc/mjpc/test" _BACKTRACE_TRIPLES "/usr/share/cmake-3.22/Modules/GoogleTest.cmake;400;add_test;/Humanoid-MPC/mujoco_mpc/mjpc/test/CMakeLists.txt;31;gtest_add_tests;/Humanoid-MPC/mujoco_mpc/mjpc/test/spline/CMakeLists.txt;15;test;/Humanoid-MPC/mujoco_mpc/mjpc/test/spline/CMakeLists.txt;0;")
add_test(TimeSplineTest.ReserveAfterAdd "/Humanoid-MPC/mujoco_mpc/build/bin/spline_test" "--gtest_filter=TimeSplineTest.ReserveAfterAdd")
set_tests_properties(TimeSplineTest.ReserveAfterAdd PROPERTIES  WORKING_DIRECTORY "/Humanoid-MPC/mujoco_mpc/mjpc/test" _BACKTRACE_TRIPLES "/usr/share/cmake-3.22/Modules/GoogleTest.cmake;400;add_test;/Humanoid-MPC/mujoco_mpc/mjpc/test/CMakeLists.txt;31;gtest_add_tests;/Humanoid-MPC/mujoco_mpc/mjpc/test/spline/CMakeLists.txt;15;test;/Humanoid-MPC/mujoco_mpc/mjpc/test/spline/CMakeLists.txt;0;")
add_test(*/TimeSplineReserveTest.MoveConstructor/* "/Humanoid-MPC/mujoco_mpc/build/bin/spline_test" "--gtest_filter=*/TimeSplineReserveTest.MoveConstructor/*")
set_tests_properties(*/TimeSplineReserveTest.MoveConstructor/* PROPERTIES  WORKING_DIRECTORY "/Humanoid-MPC/mujoco_mpc/mjpc/test" _BACKTRACE_TRIPLES "/usr/share/cmake-3.22/Modules/GoogleTest.cmake;400;add_test;/Humanoid-MPC/mujoco_mpc/mjpc/test/CMakeLists.txt;31;gtest_add_tests;/Humanoid-MPC/mujoco_mpc/mjpc/test/spline/CMakeLists.txt;15;test;/Humanoid-MPC/mujoco_mpc/mjpc/test/spline/CMakeLists.txt;0;")
add_test(*/TimeSplineReserveTest.MoveAssignment/* "/Humanoid-MPC/mujoco_mpc/build/bin/spline_test" "--gtest_filter=*/TimeSplineReserveTest.MoveAssignment/*")
set_tests_properties(*/TimeSplineReserveTest.MoveAssignment/* PROPERTIES  WORKING_DIRECTORY "/Humanoid-MPC/mujoco_mpc/mjpc/test" _BACKTRACE_TRIPLES "/usr/share/cmake-3.22/Modules/GoogleTest.cmake;400;add_test;/Humanoid-MPC/mujoco_mpc/mjpc/test/CMakeLists.txt;31;gtest_add_tests;/Humanoid-MPC/mujoco_mpc/mjpc/test/spline/CMakeLists.txt;15;test;/Humanoid-MPC/mujoco_mpc/mjpc/test/spline/CMakeLists.txt;0;")
add_test(*/TimeSplineReserveTest.CopyConstructor/* "/Humanoid-MPC/mujoco_mpc/build/bin/spline_test" "--gtest_filter=*/TimeSplineReserveTest.CopyConstructor/*")
set_tests_properties(*/TimeSplineReserveTest.CopyConstructor/* PROPERTIES  WORKING_DIRECTORY "/Humanoid-MPC/mujoco_mpc/mjpc/test" _BACKTRACE_TRIPLES "/usr/share/cmake-3.22/Modules/GoogleTest.cmake;400;add_test;/Humanoid-MPC/mujoco_mpc/mjpc/test/CMakeLists.txt;31;gtest_add_tests;/Humanoid-MPC/mujoco_mpc/mjpc/test/spline/CMakeLists.txt;15;test;/Humanoid-MPC/mujoco_mpc/mjpc/test/spline/CMakeLists.txt;0;")
add_test(*/TimeSplineReserveTest.CopyAssignment/* "/Humanoid-MPC/mujoco_mpc/build/bin/spline_test" "--gtest_filter=*/TimeSplineReserveTest.CopyAssignment/*")
set_tests_properties(*/TimeSplineReserveTest.CopyAssignment/* PROPERTIES  WORKING_DIRECTORY "/Humanoid-MPC/mujoco_mpc/mjpc/test" _BACKTRACE_TRIPLES "/usr/share/cmake-3.22/Modules/GoogleTest.cmake;400;add_test;/Humanoid-MPC/mujoco_mpc/mjpc/test/CMakeLists.txt;31;gtest_add_tests;/Humanoid-MPC/mujoco_mpc/mjpc/test/spline/CMakeLists.txt;15;test;/Humanoid-MPC/mujoco_mpc/mjpc/test/spline/CMakeLists.txt;0;")
add_test(*/TimeSplineReserveTest.Clear/* "/Humanoid-MPC/mujoco_mpc/build/bin/spline_test" "--gtest_filter=*/TimeSplineReserveTest.Clear/*")
set_tests_properties(*/TimeSplineReserveTest.Clear/* PROPERTIES  WORKING_DIRECTORY "/Humanoid-MPC/mujoco_mpc/mjpc/test" _BACKTRACE_TRIPLES "/usr/share/cmake-3.22/Modules/GoogleTest.cmake;400;add_test;/Humanoid-MPC/mujoco_mpc/mjpc/test/CMakeLists.txt;31;gtest_add_tests;/Humanoid-MPC/mujoco_mpc/mjpc/test/spline/CMakeLists.txt;15;test;/Humanoid-MPC/mujoco_mpc/mjpc/test/spline/CMakeLists.txt;0;")
add_test(TimeSplineTest.Dim0 "/Humanoid-MPC/mujoco_mpc/build/bin/spline_test" "--gtest_filter=TimeSplineTest.Dim0")
set_tests_properties(TimeSplineTest.Dim0 PROPERTIES  WORKING_DIRECTORY "/Humanoid-MPC/mujoco_mpc/mjpc/test" _BACKTRACE_TRIPLES "/usr/share/cmake-3.22/Modules/GoogleTest.cmake;400;add_test;/Humanoid-MPC/mujoco_mpc/mjpc/test/CMakeLists.txt;31;gtest_add_tests;/Humanoid-MPC/mujoco_mpc/mjpc/test/spline/CMakeLists.txt;15;test;/Humanoid-MPC/mujoco_mpc/mjpc/test/spline/CMakeLists.txt;0;")
add_test(TimeSplineTest.Iterator "/Humanoid-MPC/mujoco_mpc/build/bin/spline_test" "--gtest_filter=TimeSplineTest.Iterator")
set_tests_properties(TimeSplineTest.Iterator PROPERTIES  WORKING_DIRECTORY "/Humanoid-MPC/mujoco_mpc/mjpc/test" _BACKTRACE_TRIPLES "/usr/share/cmake-3.22/Modules/GoogleTest.cmake;400;add_test;/Humanoid-MPC/mujoco_mpc/mjpc/test/CMakeLists.txt;31;gtest_add_tests;/Humanoid-MPC/mujoco_mpc/mjpc/test/spline/CMakeLists.txt;15;test;/Humanoid-MPC/mujoco_mpc/mjpc/test/spline/CMakeLists.txt;0;")
add_test(TimeSplineTest.ConstIterator "/Humanoid-MPC/mujoco_mpc/build/bin/spline_test" "--gtest_filter=TimeSplineTest.ConstIterator")
set_tests_properties(TimeSplineTest.ConstIterator PROPERTIES  WORKING_DIRECTORY "/Humanoid-MPC/mujoco_mpc/mjpc/test" _BACKTRACE_TRIPLES "/usr/share/cmake-3.22/Modules/GoogleTest.cmake;400;add_test;/Humanoid-MPC/mujoco_mpc/mjpc/test/CMakeLists.txt;31;gtest_add_tests;/Humanoid-MPC/mujoco_mpc/mjpc/test/spline/CMakeLists.txt;15;test;/Humanoid-MPC/mujoco_mpc/mjpc/test/spline/CMakeLists.txt;0;")
