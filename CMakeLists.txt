cmake_minimum_required(VERSION 3.26)
project(GraphEx)

set(CMAKE_CXX_STANDARD 17)

add_executable(GraphEx graphObject.cpp
        graphObject.h
        main.cpp
)