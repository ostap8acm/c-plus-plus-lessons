cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

set(PROJECT_NAME MultiThread)

project(${PROJECT_NAME})

add_executable(${PROJECT_NAME} src/main.cpp)
