cmake_minimum_required(VERSION 3.27)
project(MCI-Slayer)

set(CMAKE_CXX_STANDARD 17)

add_executable(mci-slayer main.cpp
        hero.cpp
        hero.h
        character.cpp
        character.h
        item.cpp
        item.h
        GameConfig.cpp
        GameConfig.h
        inventory.cpp
        inventory.h
        schurke.cpp
        schurke.h)
