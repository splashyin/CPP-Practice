cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(Practice_01 VERSION 1.0)

# specify the cxx standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# pass the version number to the source code
configure_file(Practice_01Config.h.in Practice_01Config.h)

# add executable
add_executable(Practice_01 pimpl.cpp main.cpp)

# Add to the paths to search for include files
target_include_directories(Practice_01 PUBLIC "${PROJECT_BINARY_DIR}")

