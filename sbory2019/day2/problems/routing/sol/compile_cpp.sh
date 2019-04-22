#!/bin/bash
name=routing

echo "This script compiles solutions in C++"
echo "Compiling $name.cpp..."

g++ -Wall -O2 -std=c++14 -DEVAL -static $name.cpp grader.cpp -o $name -lm

