cmake_minimum_required(VERSION 3.20)

# Set variables
set(PROJECT_NAME SDL2Testing)
set(PROJECT_VERSION 0.0.1)
set(EXECUTABLE_NAME ${PROJECT_NAME})

# Project name
project(${PROJECT_NAME} VERSION ${PROJECT_VERSION})

# Add include path
include_directories(src/graphics)
include_directories(src/graphics_sdl2)

# Add the subdirectories
add_subdirectory(src/graphics)
add_subdirectory(src/graphics_sdl2)
add_subdirectory(src/test-game)