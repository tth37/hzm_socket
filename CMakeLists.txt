cmake_minimum_required(VERSION 3.21)
project(hzm_socket)

set(CMAKE_CXX_STANDARD 17)

set(SRC_FILE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(HEADER_FILE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/includes")

FILE(GLOB SRC_FILES ${SRC_FILE_DIR}/*.cpp)

add_library(hzm_socket ${SRC_FILES})

target_include_directories(hzm_socket PUBLIC ${HEADER_FILE_DIR})

if(CMAKE_BUILD_TYPE STREQUAL Debug)
    add_subdirectory(develop)
endif()
