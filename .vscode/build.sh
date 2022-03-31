#!/bin/sh
echo 'Compile Start'

CXX=g++

g++ -std=c++14 main.cpp -I ./ -g -o main.o