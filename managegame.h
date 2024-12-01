#ifndef MANAGEGAME_H
#define MANAGEGAME_H

#include "board.h"
#include "player.h"
#include<vector>
template<typename T>
class managegame {
protected:
    board<T>& board1;
    player<vector<T>>& player1;
    player<vector<T>>& player2;

public:
    managegame(board<T>& b, player<vector<T>>& p1, player<vector<T>>& p2)
            : board1(b), player1(p1), player2(p2) {}

    virtual void set_cell(int row, int col, T value) = 0;
    virtual void take_turn() = 0;
    virtual bool validation_col(int cols){};
    virtual bool validation_row(int rows){};
    virtual int validation1 (int row){};
    virtual int validation2 (int cols){};


};

#endif
