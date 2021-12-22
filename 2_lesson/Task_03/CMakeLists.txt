cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)

set(PROJECT_NAME delayed_lib)


project(${PROJECT_NAME})

add_executable(${PROJECT_NAME} src/main.cpp)
