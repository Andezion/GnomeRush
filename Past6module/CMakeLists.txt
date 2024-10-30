cmake_minimum_required(VERSION 3.23)
project(Past6module C)

set(CMAKE_C_STANDARD 11)

add_executable(Past6module main.c int_operations.c int_operations.h circular_buffer.c circular_buffer.h for_loop.c for_loop.h char_operations.c char_operations.h comparators.c comparators.h)
