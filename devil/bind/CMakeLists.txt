cmake_minimum_required(VERSION 3.9)
project(bind)

set(CMAKE_CXX_STANDARD 98)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/..)

add_executable(bind main.cpp Bind.hpp Storage.hpp TypeTraits.hpp Generator.hpp)