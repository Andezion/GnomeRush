cmake_minimum_required(VERSION 3.23)
project(gamefiles)

set(CMAKE_CXX_STANDARD 14)

set(ALLEGRO_INCLUDE_DIR C:\\Libs\\Allegro\\allegro\\include)
set(ALLEGRO_LIB_DIR C:\\Libs\\Allegro\\allegro\\lib)

include_directories(${ALLEGRO_INCLUDE_DIR})
link_directories(${ALLEGRO_LIB_DIR})

add_executable(gamefiles main.cpp)

target_link_libraries(gamefiles allegro allegro_font allegro_primitives allegro_ttf allegro_image)
