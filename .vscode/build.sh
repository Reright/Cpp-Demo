#!/bin/sh
echo 'Compile Start'

CXX=g++

g++ -std=c++14 main.cpp \
-I ./ -I ./include \
-g -o \
main.o

echo '====================='
echo 'Compile successfully!'