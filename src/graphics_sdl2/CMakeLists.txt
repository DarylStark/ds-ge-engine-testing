cmake_minimum_required(VERSION 3.20)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set variables
set(PROJECT_NAME ds_ge_graphics_sdl2)
set(PROJECT_VERSION 0.0.1)
set(LIBRARY_NAME ${PROJECT_NAME})

# Project name
project(${PROJECT_NAME} VERSION ${PROJECT_VERSION})

# Add a CMake module
# include(ExternalProject)

# # Configure the installation for SDL2
# set(SDL2_VERSION 2.30.9)
# set(SDL2_INSTALL_DIR ${CMAKE_BINARY_DIR}/deps/sdl2)

# if(WIN32)
#     # Windows-specific commands
#     ExternalProject_Add(
#         SDL2
#         URL https://github.com/libsdl-org/SDL/archive/refs/tags/release-${SDL2_VERSION}.tar.gz
#         PREFIX ${SDL2_INSTALL_DIR}
#         CONFIGURE_COMMAND ${SDL2_INSTALL_DIR}/src/SDL2/configure.bat --prefix=${SDL2_INSTALL_DIR}
#         BUILD_COMMAND ${CMAKE_COMMAND} --build .
#         INSTALL_COMMAND ${CMAKE_COMMAND} --install .
#         EXCLUDE_FROM_ALL true
#     )
# else()
#     # Unix-like system commands
#     ExternalProject_Add(
#         SDL2
#         URL https://github.com/libsdl-org/SDL/archive/refs/tags/release-${SDL2_VERSION}.tar.gz
#         PREFIX ${SDL2_INSTALL_DIR}
#         CONFIGURE_COMMAND ${SDL2_INSTALL_DIR}/src/SDL2/configure --prefix=${SDL2_INSTALL_DIR}
#         BUILD_COMMAND make
#         INSTALL_COMMAND make install
#         EXCLUDE_FROM_ALL true
#     )
# endif()

# # Specify the include directory for SDL2
# include_directories(${SDL2_INSTALL_DIR}/include)

# Create a test executable
add_library(${LIBRARY_NAME} main.cpp)

# # Link SDL2 to the library
# add_dependencies(${LIBRARY_NAME} SDL2)
# if(WIN32)
#     target_link_libraries(${LIBRARY_NAME} ${SDL2_INSTALL_DIR}/lib/SDL2.lib)
# else()
#     target_link_libraries(${LIBRARY_NAME} ${SDL2_INSTALL_DIR}/lib/libSDL2.a)
# endif()

target_link_libraries(${LIBRARY_NAME} ds_ge_graphics)