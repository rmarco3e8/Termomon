cmake_minimum_required(VERSION 3.22.1)

set(This Termomon)

project(${This} CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(googletest)

set(Headers
    inc/battle.h
    inc/game.h
    inc/map.h
    #inc/monster.h
    inc/move.h
    inc/player.h
    inc/termomon.h
    inc/typeHelper.h
)
set(Sources
    src/app.cpp
    src/battle.cpp
    src/game.cpp
    src/map.cpp
    #src/monster.cpp
    src/move.cpp
    src/player.cpp
    src/termomon.cpp
    src/typeHelper.cpp
)

add_library(${This} ${Sources} ${Headers})
target_link_libraries(${This} ncurses)

add_subdirectory(gtest)