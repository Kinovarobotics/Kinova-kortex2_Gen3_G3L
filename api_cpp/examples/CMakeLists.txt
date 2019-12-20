# ----------------------------------------------------------------------------
#  CMakeLists.txt for C++ Kortex API Examples
#  Copyright © 2018 Kinova Robotics
#
#  Build instructions for the supported platforms (CMake only) : 
#
#  In Linux (x86-64 architecture):
#  From the api_cpp/examples directory, invoke:
#    $ mkdir build
#    $ cd build/
#    $ cmake .. 
#    $ make
#
#  In Windows (MinGW) :
#  From the api_cpp/examples directory, invoke:
#    $ mkdir build
#    $ cd build/
#    $ cmake .. -G "MinGW Makefiles"
#    $ mingw32-make
#
#  In Windows (MSVC command line) :
#  From the api_cpp/examples directory, invoke:
#    $ call "C:\Program Files (x86)\Microsoft Visual Studio\2017\BuildTools\VC\Auxiliary\Build\vcvars64.bat" [MODIFY THIS PATH FOR YOURS]
#    $ mkdir build
#    $ cd build/
#    $ cmake .. -G "NMake Makefiles"
#    $ nmake
#
# ----------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.5)

project(kortexApiCppExamples VERSION 2.1.0 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR   ON)
set(CMAKE_VERBOSE_MAKEFILE      ON)
set(CMAKE_COLOR_MAKEFILE        ON)
set(BUILD_SHARED_LIBS           OFF)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE release)
endif()

if(NOT KORTEX_SUB_DIR)
  set(KORTEX_SUB_DIR "")
else()
  set(KORTEX_SUB_DIR "${KORTEX_SUB_DIR}/")
endif()

# Activate C++ 11
set (CMAKE_CXX_STANDARD 11)

if(MSVC)
  add_compile_options(-W2)
else()
  add_compile_options(-Wall)
  add_compile_options(-Wno-reorder)

endif()

if(UNIX)
  add_definitions(-D_OS_UNIX)
  execute_process(COMMAND ./download_kortex_api.sh
                WORKING_DIRECTORY ../scripts
                RESULT_VARIABLE DOWNLOAD_API_RESULT
                OUTPUT_VARIABLE DOWNLOAD_API_OUTPUT)
  
  if(NOT DOWNLOAD_API_RESULT EQUAL 0)
    message("Kortex API was not downloaded prior to running CMake.")
    message(FATAL_ERROR ${DOWNLOAD_API_OUTPUT})
  endif()
elseif(WIN32)
  add_definitions(-D_OS_WINDOWS -DNOMINMAX)
  execute_process(COMMAND download_kortex_api.bat
                WORKING_DIRECTORY ../scripts
                RESULT_VARIABLE DOWNLOAD_API_RESULT
                OUTPUT_VARIABLE DOWNLOAD_API_OUTPUT)

  if(NOT DOWNLOAD_API_RESULT EQUAL 0)
    message("Kortex API was not downloaded prior to running CMake.")
    message(FATAL_ERROR ${DOWNLOAD_API_OUTPUT})
  endif()

  if(MSVC)
    # Compiling with /MT must also be done in executables using the library
    add_compile_options(/bigobj /MT)
  endif()
endif()

##################################################################################
set(KORTEX_DIR "${PROJECT_SOURCE_DIR}/kortex_api/${KORTEX_SUB_DIR}")
message("KORTEX_DIR " ${KORTEX_DIR})

##### Link to lib
if(MSVC)
  link_libraries(${KORTEX_DIR}lib/${CMAKE_BUILD_TYPE}/KortexApi.lib)
else()
  link_libraries(${KORTEX_DIR}lib/${CMAKE_BUILD_TYPE}/libKortexApi.a)
endif()

# link other libs
if(UNIX)
  link_libraries(pthread)
elseif(WIN32)
  # link_libraries(PRIVATE ws2_32 winMM Winusb Setupapi xinput)
  link_libraries(winMM ws2_32)
else()
  MESSAGE(FATAL_ERROR "Unknown os! Not supported yet")
endif()

# add include dir
include_directories(${KORTEX_DIR}include)
include_directories(${KORTEX_DIR}include/client)
include_directories(${KORTEX_DIR}include/common)
include_directories(${KORTEX_DIR}include/messages)
include_directories(${KORTEX_DIR}include/client_stubs)
##################################################################################

# Link to submodule based on OS
if(UNIX)
  link_libraries(pthread)
elseif(WIN32)
  link_libraries(ws2_32 winMM Winusb Setupapi xinput)
else()
  MESSAGE(FATAL_ERROR "Unknown OS! Not supported yet.")
endif()


# Create executable for each example

# Look for examples under folders
file(GLOB EXE_LIST RELATIVE ${PROJECT_SOURCE_DIR} "[0-9]*-*/[0-9]*.cpp")
foreach ( SRC_FILE ${EXE_LIST} )

  string(REPLACE ".cpp" "" TARGET_EXE_NAME ${SRC_FILE})
  string(REPLACE "/" "_" TARGET_EXE_NAME ${TARGET_EXE_NAME})

  MESSAGE("creating TARGET_EXE_NAME: '${TARGET_EXE_NAME}'")

  add_executable(${TARGET_EXE_NAME} ${SRC_FILE})

endforeach()
