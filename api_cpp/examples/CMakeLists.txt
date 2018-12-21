# ----------------------------------------------------------------------------
#  Sources CMake file for C++ api Library
#
#    From the api_cpp/examples directory, invoke:
#      $ mkdir build
#      $ cd build/
#      $ cmake ..
#      $ make
#
#  Copyright © 2018 Kinova Robotics
# ----------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.10)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE release)
endif()

if(NOT KORTEX_SUB_DIR)
  set(KORTEX_SUB_DIR "")
else()
  set(KORTEX_SUB_DIR "${KORTEX_SUB_DIR}/")
endif()

add_subdirectory(000-Getting_started)
#add_subdirectory(101-BaseGen3_config)
add_subdirectory(100-BaseGen3_overview)
add_subdirectory(102-BaseGen3_ctrl)
add_subdirectory(200-BaseGen3_low_level_cyclic)
add_subdirectory(300-BaseGen3_low_level_bypass)
#add_subdirectory(400-Actuator)
add_subdirectory(500-Vision)
