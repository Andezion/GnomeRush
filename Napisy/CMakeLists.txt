cmake_minimum_required(VERSION 3.23)
project(Napisy C)

set(CMAKE_C_STANDARD 11)

add_executable(Napisy main.c helper.c format_type.h vector_utils.c vector_utils.h comparators.c comparators.h)
