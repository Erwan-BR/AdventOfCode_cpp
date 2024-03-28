#!/bin/bash

# Set the constants
BUILD_DIR="build"

FLAGS="-Wall -Wextra -g"
CPP_VERSION="23"
CXX_FLAGS="$FLAGS -std=c++$CPP_VERSION"
CXX="g++"

SOURCE_DIR="src"
SOURCES=$(find "$SOURCE_DIR" -name '*.cpp')
EXECUTABLE="AdventOfCode"

# 0. Create build folder or delete its contents if it exists
if [ -d "$BUILD_DIR" ]; then
    echo "Deleting contents of $BUILD_DIR..."
    rm -rf "$BUILD_DIR"/*
else
    echo "Creating $BUILD_DIR folder..."
    mkdir "$BUILD_DIR"
fi

# 1. Informing the user that the executable is compiling
echo "Compiling all files..."

# 2. Compiling main.cpp and every cpp file found by find into the build folder
$CXX $CXX_FLAGS $SOURCES -o "$BUILD_DIR/$EXECUTABLE"

# 3. Checking if compilation worked.
if [ $? -eq 0 ]; then
    # 4. Launching the object file if everything worked, with arguments passed to the bash.
    "./$BUILD_DIR/$EXECUTABLE" "$@"
else
    # 5. If the compilation failed, inform the user.
    read -p "Compilation failed. Type any key to exit."
fi
