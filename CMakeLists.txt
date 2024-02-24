cmake_minimum_required(VERSION 3.27)
project(exercise_1_1)

set(CMAKE_CXX_STANDARD 17)

add_executable(exercise_1_1 main.cpp
        hero.cpp
        hero.h
        character.cpp
        character.h
        item.cpp
        item.h)
