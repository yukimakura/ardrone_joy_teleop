cmake_minimum_required(VERSION 2.8.3)
project(ardrone_joy_teleop)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  sensor_msgs
  std_msgs
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES ardrone_joy_teleop
  CATKIN_DEPENDS geometry_msgs roscpp sensor_msgs std_msgs
  DEPENDS system_lib
)
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)


add_executable(ardrone_joy_teleop_node src/ardrone_joy_teleop_node.cpp src/ardrone_joy_teleop.cpp)

target_link_libraries(ardrone_joy_teleop_node
  ${catkin_LIBRARIES}
)