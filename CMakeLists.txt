cmake_minimum_required(VERSION 3.21)
project(cwk2)

set(CMAKE_C_STANDARD 11)
set(SDL2_DIR C:/Users/DELL/Downloads/sdl2.0)
include_directories(${SDL2_DIR}/include)
link_directories(${SDL2_DIR}/bin)



add_executable(cwk2
        dij.c
        dij.h
        interface.c
        interface.h
        main.c)
target_link_libraries(cwk2 mingw32 SDL2 SDL2main)
