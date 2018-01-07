cmake_minimum_required(VERSION 3.9)
project(devil)

set(CMAKE_CXX_STANDARD 98)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/..)

add_executable(devil main.cpp Inspector.hpp)