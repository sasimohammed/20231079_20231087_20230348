#ifndef NUMERICAL_TIC_TAC_TOE_BOARD_H
#define NUMERICAL_TIC_TAC_TOE_BOARD_H
#include "board.h"
#include "managegame.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class numirecal_tic_tac_toe_board : public board<int> {
public:
    numirecal_tic_tac_toe_board(int rows, int cols, int defaultValue)
            : board<int>(rows, cols, defaultValue) {}

    bool win_check() override {

        for (int i = 0; i < r; i++) {
            int rowSum = 0;
            for (int j = 0; j < c; j++) {
                rowSum += board1[i][j];
            }
            if (rowSum == 15) {
                return true;
            }
        }

        for (int j = 0; j < c; j++) {
            int colSum = 0;
            for (int i = 0; i < r; i++) {
                colSum += board1[i][j];
            }
            if (colSum == 15) {
                return true;
            }
        }

        int diag1Sum = 0;
        for (int i = 0; i < r; i++) {
            diag1Sum += board1[i][i];
        }
        if (diag1Sum == 15) {
            return true;
        }

        int diag2Sum = 0;
        for (int i = 0; i < r; i++) {
            diag2Sum += board1[i][r - 1 - i];
        }
        if (diag2Sum == 15) {
            return true;
        }

        return false;

    }

    bool check_col(int col, int row) override {
        return board1[row][col] == 45;
    }

    int check_row(int col) override {
        return -1;
    }
};

class numirecal_tic_tac_toe_manage : public managegame<int> {
    vector<int> v1{1, 3, 5, 7, 9};
    vector<int> v2{2, 4, 6, 8};

public:
    numirecal_tic_tac_toe_manage(numirecal_tic_tac_toe_board& board, player<vector<int>>& p1, player<vector<int>>& p2)
            : managegame<int>(board, p1, p2) {}

    void set_cell(int row, int col, int value) override {
        board1.board1[row][col] = value;
    }

    void check_value(int& num1, int& num2, int& i) {
        if (i % 2 == 0) {
            while (find(v1.begin(), v1.end(), num1) == v1.end()) {
                cout << "Enter a valid number from : { ";
                for (int j = 0; j < v1.size(); j++) {
                    cout << v1[j];
                    if (j != v1.size() - 1) {
                        cout << ", ";
                    }
                }
                cout << " }" << endl;
                cin >> num1;
            }
        } else {
            while (find(v2.begin(), v2.end(), num2) == v2.end()) {
                cout << "Enter a valid number from : { ";
                for (int j = 0; j < v2.size(); j++) {
                    cout << v2[j];
                    if (j != v2.size() - 1) {
                        cout << ", ";
                    }
                }
                cout << " }" << endl;
                cin >> num2;
            }
        }
    }

    void take_turn() override {
        int num1 = 0, num2 = 0;
        int row;
        int col;
        int count=0;
        for (int i = 0; i < (board1.r * board1.c); i++) {

            if (i % 2 == 0) {
                cout << "Player 1: enter number from";
                cout << " {";
                for (int i = 0; i < v1.size(); i++) {
                    cout << v1[i];
                    if (i != v1.size() - 1) {
                        cout << ", ";
                    }
                }
                cout << " }" << endl;
                cin >> num1;
                check_value(num1, num2, i);
                v1.erase(remove(v1.begin(), v1.end(), num1), v1.end());
                cout << "Enter the number for row: ";
                cin >> row;
                cout << "Enter the number for column: ";
                cin >> col;
                while (!board1.check_col(col, row)) {
                    cout << "Enter a valid vertex: ";
                    cout << "Enter the number for row: ";
                    cin >> row;
                    cout << "Enter the number for column: ";
                    cin >> col;
                }
                set_cell(row, col, num1);
                board1.display();
                if (board1.win_check()) {
                    cout << "Player 1 wins!" << endl;
                    break;
                }
                else{
                    count++;
                }

            } else {
                cout << "Player 2: enter number from ";
                cout << " {";
                for (int i = 0; i < v2.size(); i++) {
                    cout << v2[i];
                    if (i != v2.size() - 1) {
                        cout << ", ";
                    }
                }
                cout << " }" << endl;
                cin >> num2;
                check_value(num1, num2, i);
                v2.erase(remove(v2.begin(), v2.end(), num2), v2.end());
                cout << "Enter the number for row: ";
                cin >> row;
                cout << "Enter the number for column: ";
                cin >> col;
                while (!board1.check_col(col, row)) {
                    cout << "Enter a valid vertex: ";
                    cout << "Enter the number for row: ";
                    cin >> row;
                    cout << "Enter the number for column: ";
                    cin >> col;
                }
                set_cell(row, col, num2);
                board1.display();
                if (board1.win_check()) {
                    cout << "Player 2 wins!" << endl;
                    break;
                }
                else{
                    count++;
                }
            }
        }
        if(count==9){
            cout<<"it is a draw"<<endl;
        }
    }
};

#endif
