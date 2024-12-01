cmake_minimum_required(VERSION 3.26)
project(seperategames)

set(CMAKE_CXX_STANDARD 17)

add_executable(seperategames main.cpp
        board.h
        player.h
        managegame.h
        four_in_row_board.h
        numerical_tic_tac_toe_board.h
        Tic_tac_toe5_board.h
        game6_tic_tac_toe.h
)
