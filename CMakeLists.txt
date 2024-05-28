cmake_minimum_required(VERSION 3.10)
project(OpenGLTutorial)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add glad library
add_library(glad vendor/glad/src/glad.c)
target_include_directories(glad PUBLIC vendor/glad/include)

# Find GLFW package
find_package(glfw3 3.3 REQUIRED)

# Include glm directory
include_directories(includes)

# Add the executable
add_executable(OpenGLTutorial src/main.cpp src/Shader.cpp src/stb_image.cpp)

# Include directories for the main project
target_include_directories(OpenGLTutorial PRIVATE vendor/glad/include includes)

# Link libraries
target_link_libraries(OpenGLTutorial glad glfw)
