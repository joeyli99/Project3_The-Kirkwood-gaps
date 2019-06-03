cmake_minimum_required(VERSION 3.12)
project(Asteriods)

#Set Version Numerber
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)
set(CMAKE_CXX_FLAGS "-O3 -Wall")

include_directories(.)

FIND_PACKAGE(OpenMP)
if(OPENMP_FOUND)
    message("OPENMP FOUND")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()
include_directories(SYSTEM ${OpenMP_INCLUDE_PATH})

add_subdirectory(fmt EXCLUDE_FROM_ALL)
#include_directories(${fmt_INCLUDE_PATH})
set(CMAKE_CXX_STANDARD 17)

add_executable(asteriod_5w2krandangle
        Hamilton.cpp
        Hamilton.h
        the_asteroids.cpp)
target_link_libraries(asteriod_5w2krandangle fmt::fmt)