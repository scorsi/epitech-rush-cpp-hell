cmake_minimum_required(VERSION 3.9)
project(test_fsa)

set(CMAKE_CXX_STANDARD 98)

add_executable(test_fsa main.cpp Machine.hpp Machine.cpp)