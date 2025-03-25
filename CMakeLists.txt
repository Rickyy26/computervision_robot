cmake_minimum_required(VERSION 3.30)
project(code)

set(CMAKE_CXX_STANDARD 20)

add_executable(code main.cpp
        vision_processing.cpp
        vision_processing.h
        refresh_timer.cpp
        refresh_timer.h
        image_processing.cpp
        image_processing.h)
