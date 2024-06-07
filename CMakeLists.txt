cmake_minimum_required(VERSION 3.10)

project(funjson)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)


set(SRC_LIST)
file(GLOB SRC_LIST ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories("/usr/include/x86_64-linux-gnu/c++/11")

add_executable(funjson_test ${SRC_LIST})