project(matrix_vector)
cmake_minimum_required(VERSION 2.8)

add_definitions(-std=c++14 -Wall -Wextra)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/")
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-D__STDC_CONSTANT_MACROS")

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

list(APPEND SOURCES
    main.cpp
)

add_executable(matrix_vector_ops ${SOURCES})


