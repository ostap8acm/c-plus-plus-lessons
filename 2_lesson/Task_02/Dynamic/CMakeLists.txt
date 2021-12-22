cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)

set(PROJECT_NAME dynamic_lib)
set(PROJECT_DIR C:/Cpp_lessons/2_lesson/Task_02/Dynamic)

project(${PROJECT_NAME})

add_library(${PROJECT_NAME}_lib SHARED lib_src/test.cpp)
target_include_directories(${PROJECT_NAME}_lib PUBLIC ${PROJECT_DIR}/lib_src)

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}_lib)