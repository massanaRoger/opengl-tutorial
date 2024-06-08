@echo off

REM Create a new build directory
mkdir build
cd build

REM Run CMake to configure the project with Ninja generator
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 .. -G Ninja

REM Build the project using Ninja
ninja

cd ..
