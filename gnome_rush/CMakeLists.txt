cmake_minimum_required(VERSION 3.23)
project(gnome_rush)

set(CMAKE_CXX_STANDARD 23)

set(RAYLIB_INCLUDE_DIR C:\\Libs\\Raylib\\raylib-5.0_win64_mingw-w64\\include)
set(RAYLIB_LIB_DIR C:\\Libs\\Raylib\\raylib-5.0_win64_mingw-w64\\lib)

include_directories(${RAYLIB_INCLUDE_DIR})
link_directories(${RAYLIB_LIB_DIR})

add_executable(gnome_rush main.cpp)

target_link_libraries(gnome_rush raylib winmm)