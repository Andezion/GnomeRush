cmake_minimum_required(VERSION 3.23)
project(Pong)

set(CMAKE_CXX_STANDARD 11)

add_library(Pong library.cpp windows.h pong.h main.cpp)
