cmake_minimum_required(VERSION 3.9)
project(test_nsa_to_dfa)

set(CMAKE_CXX_STANDARD 98)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/..)

add_executable(test_dynamic_fsa main.cpp State.hpp Matcher.hpp FSA.hpp)