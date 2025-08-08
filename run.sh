#!/bin/bash


# Building the project
cmake -S . -B build -DCMAKE_INSTALL_PREFIX=./ -DCMAKE_BUILD_TYPE=DEBUG -DCMAKE_COLOR_DIAGNOSTICS=ON
cmake --build ./build
cmake --install ./build



# Generating doccumentation
doxygen ./Doxyfile
