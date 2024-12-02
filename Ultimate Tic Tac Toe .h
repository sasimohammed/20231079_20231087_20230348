#ifndef SEPARATEGAMES_ULTIMATE_TIC_TAC_TOE_H
#define SEPARATEGAMES_ULTIMATE_TIC_TAC_TOE_H

#include "board.h"
#include "managegame.h"
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iomanip> // For formatting

using namespace std;

class Ultimate_Tic_Tac_Toe_board : public board<char> {
public:
    Ultimate_Tic_Tac_Toe_board(int rows, int cols, char defaultValue)
            : board<char>(rows, cols, defaultValue) {}

    bool win_check() override {
        // Check rows
        for (int i = 0; i < 3; i++) {
            if (board1[i][0] != '-' && board1[i][0] == board1[i][1] && board1[i][1] == board1[i][2]) {
                return true;
            }
        }

        // Check columns
        for (int j = 0; j < 3; j++) {
            if (board1[0][j] != '-' && board1[0][j] == board1[1][j] && board1[1][j] == board1[2][j]) {
                return true;
            }
        }

        // Check main diagonal
        if (board1[0][0] != '-' && board1[0][0] == board1[1][1] && board1[1][1] == board1[2][2]) {
            return true;
        }

        // Check anti-diagonal
        if (board1[0][2] != '-' && board1[0][2] == board1[1][1] && board1[1][1] == board1[2][0]) {
            return true;
        }

        return false;
    }

    bool check_col(int row, int col) override {
        return board1[row][col] != '-';
    }

    int check_row(int col) override {
        return 0;
    }

    void display() {
        cout << "Current Board State:" << endl;
        for (const auto& row : board1) {
            for (const auto& cell : row) {
                cout << setw(3) << cell;
            }
            cout << endl;
        }
        cout << endl;
    }
};

class Ultimate_Tic_Tac_Toe_manage : public managegame<char> {
public:
    vector<vector<char>> mainBoard;
    vector<int> availableBoards{1, 2, 3, 4, 5, 6, 7, 8, 9};

    Ultimate_Tic_Tac_Toe_manage(Ultimate_Tic_Tac_Toe_board& board, player<vector<char>>& p1, player<vector<char>>& p2)
            : managegame<char>(board, p1, p2) {
        mainBoard = vector<vector<char>>(3, vector<char>(3, '-'));
    }

    void set_cell(int row, int col, char value) override {
        board1.board1[row][col] = value;
    }

    void set_cell(int row, int col, int value) override {}

    void set_main_board(int pos, char value) {
        vector<string> boardPositions{"00", "01", "02", "10", "11", "12", "20", "21", "22"};
        map<int, string> boardMap;

        for (size_t i = 0; i < 9; i++) {
            boardMap[i + 1] = boardPositions[i];
        }

        string index = boardMap[pos];
        int row = index[0] - '0';
        int col = index[1] - '0';
        mainBoard[row][col] = value;

        cout << "Updated Main Board:" << endl;
        for (const auto& row : mainBoard) {
            for (const auto& cell : row) {
                cout << setw(3) << cell;
            }
            cout << endl;
        }
        cout << endl;
    }
    bool check_main_board_winner() {
        // Check rows for winner in main board (3x3 grid in mainBoard)
        for (int i = 0; i < 3; i++) {
            if (mainBoard[i][0] != '-' && mainBoard[i][0] == mainBoard[i][1] && mainBoard[i][1] == mainBoard[i][2]) {
                return true;
            }
        }

        // Check columns for winner in main board
        for (int j = 0; j < 3; j++) {
            if (mainBoard[0][j] != '-' && mainBoard[0][j] == mainBoard[1][j] && mainBoard[1][j] == mainBoard[2][j]) {
                return true;
            }
        }

        // Check main diagonal for winner in main board
        if (mainBoard[0][0] != '-' && mainBoard[0][0] == mainBoard[1][1] && mainBoard[1][1] == mainBoard[2][2]) {
            return true;
        }

        // Check anti-diagonal for winner in main board
        if (mainBoard[0][2] != '-' && mainBoard[0][2] == mainBoard[1][1] && mainBoard[1][1] == mainBoard[2][0]) {
            return true;
        }

        return false;
    }

    void take_turn() override {
        cout << "Ultimate Tic-Tac-Toe Game\n";
        cout << "-------------------------\n";
        cout << "Game Start! Here's the initial 9x9 board layout:\n";
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << '-'<<" ";
            }
            cout << endl;
        }

        bool game_won = false;

        while (!game_won) {
            cout << "Choose your 3x3 board to start play (1-9):" << endl;
            int num;
            cin >> num;
            while(find(availableBoards.begin(), availableBoards.end(), num) == availableBoards.end()){
                cout << "The board is already taken. Enter a valid board number (1-9):" << endl;
                cin >> num;
            }
            auto it = remove(availableBoards.begin(), availableBoards.end(), num);
            availableBoards.erase(it, availableBoards.end());

            cout << "You selected Board " << num << ". Here's the current state:\n";
            board1.display();

            int row, col;
            for (int i = 0; i < (board1.r * board1.c); i++) {
                if (i % 2 == 0) {
                    cout << "Player 1's turn.\n";
                } else {
                    cout << "Player 2's turn.\n";
                }

                cout << "Enter row number (0-2): ";
                cin >> row;
                cout << "Enter column number (0-2): ";
                cin >> col;

                while (row < 0 || row >= 3 || col < 0 || col >= 3 ) {
                    cout<<"invalid row and column"<<endl;
                    cin >> row >> col;
                }
                while(board1.check_col(row, col)){
                    cout << "already occupied cell. Please enter valid row and column numbers (0-2): "<<endl;

                    cout << "Enter row number (0-2): ";
                    cin >> row;
                    cout << "Enter column number (0-2): ";
                    cin >> col;
                }

                char symbol = (i % 2 == 0) ? player1.get_symbol()[0] : player2.get_symbol()[0];
                set_cell(row, col, symbol);
                board1.display();

                if (board1.win_check()) {
                    cout << "Player " << (i % 2 == 0 ? "1" : "2") << " wins this sub-board!\n";
                    set_main_board(num, symbol);

                    board1 = Ultimate_Tic_Tac_Toe_board(3, 3, '-');  // Clear the sub-board
                    if (check_main_board_winner()) {
                        cout << "Player " << (i % 2 == 0 ? "1" : "2") << " wins the game!\n";
                        game_won = true;
                        break;
                    }
                    break;
                }
            }

            if (!game_won) {
                cout << "Next turn! Choose a new sub-board (1-9):" << endl;
            }
        }
    }


};

#endif
