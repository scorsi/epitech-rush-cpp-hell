cmake_minimum_required(VERSION 3.9)
project(test_functor_type)

set(CMAKE_CXX_STANDARD 98)

add_executable(test_functor_type main.cpp FunctionSignature.hpp)