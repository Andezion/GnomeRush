cmake_minimum_required(VERSION 3.23)
project(Snake)

set(CMAKE_CXX_STANDARD 11)

add_executable(Snake main.cpp screen.cpp screen.h winsys.cpp winsys.h snake.cpp snake.h cmake-build-debug/cpoint.h cpoint.h)
