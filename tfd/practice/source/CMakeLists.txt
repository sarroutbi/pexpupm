# Specify the minimum version for CMake
cmake_minimum_required(VERSION 2.8)

# Project's name
project(eqresolver)
# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# C++ Standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# eqresolver particular directories
set(EQRESOLVER_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)
set(EQRESOLVER_UNIT_TESTS_DIR ${PROJECT_SOURCE_DIR}/test)
  
# The following folder will be included
include_directories("${EQRESOLVER_SOURCE_DIR}")

# The following subdirectories are included in the build path
add_subdirectory("${EQRESOLVER_SOURCE_DIR}")
add_subdirectory("${EQRESOLVER_UNIT_TESTS_DIR}")