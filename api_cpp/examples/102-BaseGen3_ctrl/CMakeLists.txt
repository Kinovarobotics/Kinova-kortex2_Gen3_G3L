cmake_minimum_required(VERSION 3.10)

project(Getting_started)
MESSAGE("---------------------------------------------------------------------------------")
MESSAGE("Project '${PROJECT_NAME}' args: ${CMAKE_ARGS}")
MESSAGE("Project building for: '${CMAKE_SYSTEM_NAME}' in '${CMAKE_BUILD_TYPE}' mode")

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE release)
endif()

if(NOT KORTEX_SUB_DIR)
  set(KORTEX_SUB_DIR "")
else()
  set(KORTEX_SUB_DIR "${KORTEX_SUB_DIR}/")
endif()

set(CMAKE_INCLUDE_CURRENT_DIR   ON)
set(CMAKE_AUTOMOC               ON)
set(CMAKE_VERBOSE_MAKEFILE      ON)
set(CMAKE_COLOR_MAKEFILE        ON)
set(BUILD_SHARED_LIBS           OFF)

file(GLOB EXE_LIST RELATIVE ${PROJECT_SOURCE_DIR} "*.cpp")

foreach ( SRC_FILE ${EXE_LIST} )
    string(REPLACE ".cpp" "" TARGET_EXE_NAME ${SRC_FILE})
    MESSAGE("create TARGET_EXE_NAME: '${TARGET_EXE_NAME}'")

    add_executable(${TARGET_EXE_NAME} ${SRC_FILE})
    if(MSVC)
        target_compile_options(${TARGET_EXE_NAME} PRIVATE -W2)
    else()
        target_compile_options(${TARGET_EXE_NAME} PRIVATE -Wall)
        target_compile_options(${TARGET_EXE_NAME} PRIVATE -Wno-reorder)
        target_compile_features(${TARGET_EXE_NAME} PRIVATE cxx_std_11)
    endif()

    if(UNIX)
        target_compile_definitions(${TARGET_EXE_NAME} PRIVATE -D_OS_UNIX)
    elseif(WIN32)
        target_compile_definitions(${TARGET_EXE_NAME} PRIVATE -D_OS_WINDOWS)
        
        if(MSVC)
            # Compilation with /MT option must also be done in executables using the library
            target_compile_options(${TARGET_EXE_NAME} PRIVATE /bigobj /MT)
        endif()
    endif()

    ##################################################################################
    set(KORTEX_DIR "${PROJECT_SOURCE_DIR}/../kortex_api/${KORTEX_SUB_DIR}")

    ##### Link to lib
    if(MSVC)
        target_link_libraries(${TARGET_EXE_NAME} PRIVATE ${KORTEX_DIR}lib/${CMAKE_BUILD_TYPE}/CppKinovaApi.lib)
    else()
        target_link_libraries(${TARGET_EXE_NAME} PRIVATE ${KORTEX_DIR}lib/${CMAKE_BUILD_TYPE}/libCppKinovaApi.a)
    endif()

    # link other libs
    if(UNIX)
        target_link_libraries(${TARGET_EXE_NAME} PRIVATE pthread)
    elseif(WIN32)
        # target_link_libraries(${TARGET_EXE_NAME} PRIVATE ws2_32 winMM Winusb Setupapi xinput)
        target_link_libraries(${TARGET_EXE_NAME} PRIVATE winMM ws2_32)
    else()
        MESSAGE(FATAL_ERROR "Unknown os! Not supported yet")
    endif()

    # add include dir
    target_include_directories(${TARGET_EXE_NAME} PRIVATE ${KORTEX_DIR}include)
    target_include_directories(${TARGET_EXE_NAME} PRIVATE ${KORTEX_DIR}include/client)
    target_include_directories(${TARGET_EXE_NAME} PRIVATE ${KORTEX_DIR}include/common)
    target_include_directories(${TARGET_EXE_NAME} PRIVATE ${KORTEX_DIR}include/messages)
    target_include_directories(${TARGET_EXE_NAME} PRIVATE ${KORTEX_DIR}include/client_stubs)
    ##################################################################################

endforeach()
