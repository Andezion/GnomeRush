cmake_minimum_required(VERSION 3.23)
project(Binary C)

set(CMAKE_C_STANDARD 11)

add_executable(Binary main.c binary.c binary.h)
