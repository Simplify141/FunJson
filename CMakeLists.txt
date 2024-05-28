cmake_minimum_required(VERSION 3.10)

project(funjson)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)



include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/src)

# 添加src和include目录下的源文件
file(GLOB_RECURSE SOURCES "src/*" "include/*")

add_executable(funjson_test ${SOURCES})