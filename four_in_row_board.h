#ifndef FOUR_IN_ROW_GAME_H
#define FOUR_IN_ROW_GAME_H
#include "board.h"
#include "managegame.h"
#include <iostream>
#include <vector>
using namespace std;


class four_in_row_board : public board<char> {
public:
    four_in_row_board(int rows, int cols, char defaultValue)
            : board<char>(rows, cols, defaultValue) {}

    bool win_check() override {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c - 3; j++) {
                if (board1[i][j] != '-' && board1[i][j] == board1[i][j + 1] &&
                    board1[i][j] == board1[i][j + 2] && board1[i][j] == board1[i][j + 3]) {
                    return true;
                }
            }
        }

        for (int j = 0; j < c; j++) {
            for (int i = 0; i < r - 3; i++) {
                if (board1[i][j] != '-' && board1[i][j] == board1[i + 1][j] &&
                    board1[i][j] == board1[i + 2][j] && board1[i][j] == board1[i + 3][j]) {
                    return true;
                }
            }
        }

        for (int i = 0; i < r - 3; i++) {
            for (int j = 0; j < c - 3; j++) {
                if (board1[i][j] != '-' && board1[i][j] == board1[i + 1][j + 1] &&
                    board1[i][j] == board1[i + 2][j + 2] && board1[i][j] == board1[i + 3][j + 3]) {
                    return true;
                }
            }
        }

        for (int i = 0; i < r - 3; i++) {
            for (int j = 3; j < c; j++) {
                if (board1[i][j] != '-' && board1[i][j] == board1[i + 1][j - 1] &&
                    board1[i][j] == board1[i + 2][j - 2] && board1[i][j] == board1[i + 3][j - 3]) {
                    return true;
                }
            }
        }

        return false;
    }

    bool check_col(int col, int row = 0) override {
        return board1[0][col] != '-';
    }

    int check_row(int col) override {
        for (int i = r - 1; i >= 0; i--) {
            if (board1[i][col] == '-') {
                return i;
            }
        }
        return -1;
    }
};

class four_in_row_manage : public managegame<char> {
public:
    four_in_row_manage(four_in_row_board& board, player<vector<char>>& p1, player<vector<char>>& p2)
            : managegame<char>(board, p1, p2) {}

    void set_cell(int row, int col, int value) override {
        board1.board1[row][col] = value;
    }
    virtual void set_cell(int row, int col, char value )override {};

    void take_turn() override {
        int col1, col2;
        for (int i = 0; i < (board1.r * board1.c); i++) {
            if (i % 2 == 0) {
                cout << "Player 1: enter column number: ";
                cin >> col1;
                while (board1.check_col(col1, 0)) {
                    cout << "Enter a valid column: ";
                    cin >> col1;
                }
                set_cell(board1.check_row(col1), col1, player1.get_symbol()[0]);
                board1.display();
                if (board1.win_check()) {
                    cout << "Player 1 wins!" << endl;
                    break;
                }
            } else {
                cout << "Player 2: enter column number: ";
                cin >> col2;
                while (board1.check_col(col2, 0)) {
                    cout << "Enter a valid column: ";
                    cin >> col2;
                }
                set_cell(board1.check_row(col2), col2, player2.get_symbol()[0]);
                board1.display();
                if (board1.win_check()) {
                    cout << "Player 2 wins!" << endl;
                    break;
                }
            }
        }
    }

};

#endif
