#!/bin/bash

rm scop
mkdir build
cd build
cmake ..
cmake --build
make
mv scop ..
cd ..
rm -r build
