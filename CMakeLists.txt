cmake_minimum_required(VERSION 4.1)
project(Raytracing)

set(CMAKE_CXX_STANDARD 20)

add_executable(Raytracing src/main.cpp
        src/vec3.h
)
