cmake_minimum_required(VERSION 3.12)
project(ariod)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-O3 -Wall)

include_directories(.)

add_executable(asteriod_10w2krandangle
        Hamilton.cpp
        Hamilton.h
        the_asteroids.cpp)
