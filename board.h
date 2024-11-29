#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include<iostream>
using namespace std;
template<typename T>
class board {
public:
    int r, c;
    std::vector<std::vector<T>> board1;

    board(int rows, int cols, T defaultValue)
            : r(rows), c(cols), board1(rows, std::vector<T>(cols, defaultValue)) {}

    virtual bool win_check() = 0;
    virtual bool check_col(int col, int row) = 0;
    virtual int check_row(int col) = 0;

    void display() const {
        for (const auto& row : board1) {
            for (const auto& elem : row) {
                if constexpr (is_integral<T>::value) {
                    if (elem == 45) {
                        cout << '-' << ' ';
                    } else {
                        cout << elem << ' ';
                    }
                } else {
                    cout << elem << ' ';
                }
            }
            cout << endl;
        }
    }

};

#endif
