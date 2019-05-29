cmake_minimum_required(VERSION 3.12)
project(ariod)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(asteriod_2hour
        Hamilton.cpp
        Hamilton.h
        the_asteroids.cpp)
