cmake_minimum_required(VERSION 3.20)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set variables
set(PROJECT_NAME ds_ge_graphics)
set(PROJECT_VERSION 0.0.1)
set(LIBRARY_NAME ${PROJECT_NAME})

# Project name
project(${PROJECT_NAME} VERSION ${PROJECT_VERSION})

# Set the C++ files to complie
file(GLOB_RECURSE SOURCES "*.cpp")

# Create a test executable
add_library(${LIBRARY_NAME} ${SOURCES})