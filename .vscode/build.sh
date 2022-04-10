#!/bin/sh
echo 'Compile Start'

CXX=g++

g++ -std=c++17 \
main.cpp \
-I ./  \
-g -o main.o \
# -fno-elide-constructors #构造函数返回值优化