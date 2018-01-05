cmake_minimum_required(VERSION 3.9)
project(test_functor_type)

set(CMAKE_CXX_STANDARD 98)

if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/..)
else (CMAKE_SYSTEM_NAME STREQUAL "Linux")
endif (CMAKE_SYSTEM_NAME STREQUAL "Linux")


add_executable(test_functor_type main.cpp FunctionSignature.hpp)