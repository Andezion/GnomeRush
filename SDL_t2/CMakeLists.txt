cmake_minimum_required(VERSION 3.23)
project(SDL_t2 C)

set(CMAKE_C_STANDARD 23)

set(SDL2_INCLUDE_DIR C:\\Libs\\SDL\\include)
set(SDL2_LIB_DIR C:\\Libs\\SDL\\lib)

set(SDL2_IMAGE_INCLUDE_DIR C:\\Libs\\SDL_image\\include)
set(SDL2_IMAGE_LIB_DIR C:\\Libs\\SDL_image\\lib)

set(SDL2_MIXER_INCLUDE_DIR C:\\Libs\\SDL_mixer\\include)
set(SDL2_MIXER_LIB_DIR C:\\Libs\\SDL_mixer\\lib)

set(SDL2_TTF_INCLUDE_DIR C:\\Libs\\SDL2_ttf\\x86_64-w64-mingw32\\include)
set(SDL2_TTF_LIB_DIR C:\\Libs\\SDL2_ttf\\x86_64-w64-mingw32\\lib)

include_directories(${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2_TTF_INCLUDE_DIR} ${SDL2_MIXER_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR} ${SDL2_IMAGE_LIB_DIR} ${SDL2_TTF_LIB_DIR} ${SDL2_MIXER_LIB_DIR})

add_executable(SDL_t2 main.c handler_of_screen.c handler_of_screen.h)

target_link_libraries(SDL_t2 SDL2main SDL2 SDL2_image SDL2_ttf SDL2_mixer)
