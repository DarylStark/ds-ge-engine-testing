cmake_minimum_required(VERSION 3.20)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set variables
set(PROJECT_NAME ds_ge_testgame)
set(PROJECT_VERSION 1.0.0)
set(EXECUTABLE_NAME ${PROJECT_NAME})

# Project name
project(${PROJECT_NAME} VERSION ${PROJECT_VERSION})

# Create a test executable
add_executable(${EXECUTABLE_NAME} main.cpp)

# Add dependencies
target_link_libraries(${EXECUTABLE_NAME} ds_ge_graphics_sdl2)