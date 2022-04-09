#!/bin/sh
echo 'Echo'

CXX=g++

g++ -std=c++14 \
main.cpp \
-I ./  \
-g -o main.o \
-fno-elide-constructors #构造函数返回值优化