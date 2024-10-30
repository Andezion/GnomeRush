cmake_minimum_required(VERSION 3.23)
project(Simulator)

set(CMAKE_CXX_STANDARD 11)
set(SFML_DIR "C:/Users/vdoro/Downloads/SFML-2.6.0-windows-vc17-64-bit/SFML-2.6.0")
find_package(SFML 2.6 COMPONENTS graphics window system REQUIRED)
add_executable(Simulator main.cpp)
target_link_libraries(Simulator sfml-graphics sfml-window sfml-system)

