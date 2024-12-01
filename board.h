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
    virtual void increment_player1(int x)
    {

    }
    virtual void increment_player2(int x)
    {

    }

    virtual bool check_col(int row, int col)
    {

    };
    virtual int check_row(int col)
    {

    };

    virtual int vertical_check()
    {

    };

    virtual int horizontal_check()
    {

    };

    virtual int inc_diagonal_check( )
    {

    };

    virtual int dec_diagonal_check()
    {

    };


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
