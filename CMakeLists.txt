project(CPSL_D1_Arm)
cmake_minimum_required(VERSION 3.8)

SET(CMAKE_CXX_STANDARD 17)

find_package(ament_cmake REQUIRED)

include_directories(/usr/local/include/ddscxx /usr/local/include/iceoryx/v2.0.2)
link_libraries(unitree_sdk2 ddsc ddscxx rt pthread)

# 编译成共享库
# add_library(grasp SHARED src/grasp.cpp src/msg/ArmString_.cpp)
add_library(left_1 SHARED src/left_1.cpp src/msg/ArmString_.cpp)
add_library(left_2 SHARED src/left_2.cpp src/msg/ArmString_.cpp)
add_library(right_1 SHARED src/right_1.cpp src/msg/ArmString_.cpp)
add_library(right_2 SHARED src/right_2.cpp src/msg/ArmString_.cpp)
add_library(grasp_1_1 SHARED src/grasp_1_1.cpp src/msg/ArmString_.cpp)
add_library(grasp_1_2 SHARED src/grasp_1_2.cpp src/msg/ArmString_.cpp)
add_library(grasp_2_1 SHARED src/grasp_2_1.cpp src/msg/ArmString_.cpp)
add_library(grasp_2_2 SHARED src/grasp_2_2.cpp src/msg/ArmString_.cpp)
add_library(grasp_3_1 SHARED src/grasp_3_1.cpp src/msg/ArmString_.cpp)
add_library(grasp_3_2 SHARED src/grasp_3_2.cpp src/msg/ArmString_.cpp)
add_library(grasp_4_1 SHARED src/grasp_4_1.cpp src/msg/ArmString_.cpp)
add_library(grasp_4_2 SHARED src/grasp_4_2.cpp src/msg/ArmString_.cpp)
add_library(zero SHARED src/zero.cpp src/msg/ArmString_.cpp)

add_executable(joint_angle_control src/joint_angle_control.cpp src/msg/ArmString_.cpp)
add_executable(multiple_joint_angle_control src/multiple_joint_angle_control.cpp src/msg/ArmString_.cpp)
add_executable(joint_enable_control src/joint_enable_control.cpp src/msg/ArmString_.cpp)
add_executable(arm_zero_control src/arm_zero_control.cpp src/msg/ArmString_.cpp)
add_executable(get_arm_joint_angle src/get_arm_joint_angle.cpp src/msg/ArmString_.cpp src/msg/PubServoInfo_.cpp)

ament_export_libraries(left_1 left_2 right_1 right_2 grasp_1_1 grasp_1_2 grasp_2_1 grasp_2_2 grasp_3_1 grasp_3_2 grasp_4_1 grasp_4_2 zero)
ament_export_include_directories(include)

install(TARGETS left_1 left_2 right_1 right_2 grasp_1_1 grasp_1_2 grasp_2_1 grasp_2_2 grasp_3_1 grasp_3_2 grasp_4_1 grasp_4_2 zero
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
)

ament_package()