cmake_minimum_required(VERSION 3.10)
project(KinovaExample)

set(CMAKE_CXX_STANDARD 14)

# Set DURATION variable in seconds, default value of 0 runs until Ctrl+C
if(NOT DEFINED DURATION)
    set(DURATION 0)
endif()

# Include directory for the Kortex API headers
include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}/kortex_api/include
	${CMAKE_CURRENT_SOURCE_DIR}/kortex_api/include/client
	${CMAKE_CURRENT_SOURCE_DIR}/kortex_api/include/client_stubs
	${CMAKE_CURRENT_SOURCE_DIR}/kortex_api/include/common
	${CMAKE_CURRENT_SOURCE_DIR}/kortex_api/include/google
	${CMAKE_CURRENT_SOURCE_DIR}/kortex_api/include/messages
	${CMAKE_CURRENT_SOURCE_DIR}/kortex_api/include/participant
	${CMAKE_CURRENT_SOURCE_DIR}/kortex_api/include/server
	${CMAKE_CURRENT_SOURCE_DIR}/kortex_api/include/server_stubs
	${CMAKE_CURRENT_SOURCE_DIR}/kortex_api/include/util
)

#Including my directories
include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Link directory for the Kortex API libraries (adjust if needed)
link_directories(
	${CMAKE_CURRENT_SOURCE_DIR}/kortex_api/lib/release)


#add_executable(kinova_example api_setup.cpp leader.cpp arm_core_functions.cpp)
add_executable(kinova_example api_setup.cpp leader.cpp arm_core_functions.cpp)

target_compile_definitions(kinova_example PRIVATE _OS_UNIX DURATION=${DURATION})

# Link against the Kortex API libraries (adjust as needed)
target_link_libraries(kinova_example KortexApiCpp pthread)

# Original version: leader actuators in low-level current mode (no gravity compensation)
add_executable(kinova_example_current_mode api_setup.cpp leader_current_mode.cpp arm_core_functions.cpp)
target_compile_definitions(kinova_example_current_mode PRIVATE _OS_UNIX DURATION=${DURATION})
target_link_libraries(kinova_example_current_mode KortexApiCpp pthread)

# Xbox version: leader driven by an Xbox controller connected to the leader arm instead of hand guiding
add_executable(kinova_example_xbox api_setup.cpp leader_xbox.cpp arm_core_functions.cpp)
target_compile_definitions(kinova_example_xbox PRIVATE _OS_UNIX DURATION=${DURATION})
target_link_libraries(kinova_example_xbox KortexApiCpp pthread)
