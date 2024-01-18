#!/usr/bin/env bash

# Build project on any system with a bash shell
rm -rf build
mkdir build
cd build
cmake ..
cmake --build .