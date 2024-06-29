#!/bin/bash

# Remove existing build directory
rm -rf build

# Create and navigate to build directory
mkdir build
cd build || exit

# Run CMake to generate build system files
cmake ..

# Compile the project
make

cd $WORKDIR