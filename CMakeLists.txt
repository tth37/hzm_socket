cmake_minimum_required(VERSION 3.2)
project(hzm_socket)

find_package(nlohmann_json 3.2.0 REQUIRED)

set(CMAKE_CXX_STANDARD 17)

set(SRC_FILE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(HEADER_FILE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/includes")

FILE(GLOB SRC_FILES ${SRC_FILE_DIR}/*.cpp)

add_library(hzm_socket ${SRC_FILES})

target_link_libraries(hzm_socket PRIVATE nlohmann_json::nlohmann_json)

target_include_directories(hzm_socket PUBLIC ${HEADER_FILE_DIR})

if (CMAKE_BUILD_TYPE STREQUAL Debug)
    add_subdirectory(develop)
endif ()
