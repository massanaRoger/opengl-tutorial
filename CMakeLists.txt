cmake_minimum_required(VERSION 3.10)
project(MyCppProject)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add glad library
add_library(glad vendor/glad/src/glad.c)
target_include_directories(glad PUBLIC vendor/glad/include)

# Find GLFW package
find_package(glfw3 3.3 REQUIRED)

# Add the executable
add_executable(MyCppProject src/main.cpp)

# Include directories for the main project
target_include_directories(MyCppProject PRIVATE vendor/glad/include)

# Link libraries
target_link_libraries(MyCppProject glad glfw)
