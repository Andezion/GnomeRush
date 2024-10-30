cmake_minimum_required(VERSION 3.23)
project(help_task C)

set(CMAKE_C_STANDARD 23)

add_executable(help_task main.c)

target_link_libraries(help_task)