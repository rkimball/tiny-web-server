cmake_minimum_required(VERSION 3.12)
project(tiny_web_server)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add subdirectories for your project components
add_subdirectory(src)
add_subdirectory(test)
