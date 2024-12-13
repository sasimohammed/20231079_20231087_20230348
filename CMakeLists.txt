cmake_minimum_required(VERSION 3.28)
project(untitled15)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled15 main.cpp
        BoardGame_Classes.h
        Pyramid_X_O.h
        Pyramid_X_O_Smart_Player.h
        SUS_X_O.h
        game3.h
        game6.h
        Four-in-a-row.h
        MinMaxPlayer.h
        Numerical-Tic-Tac-Toe.h
        Ultimate_Try.h
)
