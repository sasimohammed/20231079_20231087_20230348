cmake_minimum_required(VERSION 3.26)
project(mad2)

set(CMAKE_CXX_STANDARD 17)

add_executable(mad2 main.cpp
        BoardGame_Classes.h
        3x3X_O.h
        Four-in-a-row.h
        Numerical-Tic-Tac-Toe.h

        game3.h
)
