cmake_minimum_required(VERSION 3.23)
project(crossword C)

set(CMAKE_C_STANDARD 11)

add_executable(crossword main.c doubly_linked_list.c doubly_linked_list.h)
