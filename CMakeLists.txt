cmake_minimum_required(VERSION 3.10)

project(calculator)

add_library(calculator STATIC calculator.cpp)
add_executable(out calculator.cpp)

target_link_libraries(out calculator)
