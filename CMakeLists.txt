cmake_minimum_required(VERSION 3.10)
project(OpenGLTutorial)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
message(STATUS "${CMAKE_SOURCE_DIR}")

set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake")

# Add glad library
add_library(glad vendor/glad/src/glad.c)
target_include_directories(glad PUBLIC vendor/glad/include)

# Add GLFW library
add_subdirectory(vendor/glfw)

# Find Assimp package
find_package(assimp CONFIG REQUIRED)

# Include glm and assimp directory
include_directories(includes)

# Add the executable
add_executable(OpenGLTutorial src/main.cpp src/Shader.cpp src/stb_image.cpp
        src/Mesh.cpp
        src/Model.cpp
        src/Model.h)

# Include directories for the main project
target_include_directories(OpenGLTutorial PRIVATE vendor/glad/include includes vendor/glfw/include)

# Link libraries
target_link_libraries(OpenGLTutorial glad glfw assimp::assimp)
