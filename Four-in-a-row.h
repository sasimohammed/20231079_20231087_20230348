
#ifndef FOUR_IN_A_ROW_H
#define FOUR_IN_A_ROW_H

#include <iostream>
#include <iomanip>
#include <cctype>
#include "BoardGame_Classes.h"
using namespace std;

template <typename T>
class four_in_row_board:public Board<T>{
public:
    four_in_row_board ();
    bool update_board (int x , int y , T symbol);
    void display_board () ;
    bool is_win() ;
    bool is_draw();
    bool game_is_over();

};
template <typename T>
class  four_in_row_Player : public Player<T> {
public:
    four_in_row_Player (string name, T symbol);
    void getmove(int& x, int& y) ;
};
template <typename T>
class four_in_row_Random_Player : public RandomPlayer<T>{
public:
    four_in_row_Random_Player  (T symbol);
    void getmove(int &x, int &y) ;
};

//--------------------------------------- IMPLEMENTATION
template <typename T>
four_in_row_board<T>::four_in_row_board(){
    this->rows =  6;this->columns=7;
    this->board=  new char*[this->rows];
    for(int i=0;i<this->rows;i++){
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 0;
        }
    }
    this->n_moves = 0;

}
template <typename T>
bool four_in_row_board<T>::update_board(int x, int y, T symbol) {
    for (int i = this->rows - 1; i >= 0; i--) {
        if (this->board[i][y] == 0) {
            x = i;
            break;
       } }
    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) &&
        (this->board[x][y] == 0 || symbol == 0)) {
        if (symbol == 0) {
            this->n_moves--;
            this->board[x][y] = 0;
        } else {
            this->n_moves++;
            this->board[x][y] = toupper(symbol);
        }
        return true;
    }
    return false;
}

template <typename T>
void four_in_row_board<T>::display_board() {
    cout<<"player 1: X"<<endl;
    cout<<"player 2: O"<<endl;
    for (int i = 0; i < this->rows; i++) {
        cout << "\n| ";
        for (int j = 0; j < this->columns; j++) {
            cout << setw(2) << this->board[i][j] << " |";
        }
        cout << "\n------------------------------";
    }
    cout << endl;
}
template <typename T>
bool four_in_row_board<T>::is_win() {
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->columns - 3; j++) {
            if (this->board[i][j] != 0 &&
                this->board[i][j] == this->board[i][j + 1] &&
                this->board[i][j] == this->board[i][j + 2] &&
                this->board[i][j] == this->board[i][j + 3]) {
                return true;
            }
        }
    }

    for (int j = 0; j < this->columns; j++) {
        for (int i = 0; i < this->rows - 3; i++) {
            if (this->board[i][j] != 0 &&
                this->board[i][j] == this->board[i + 1][j] &&
                this->board[i][j] == this->board[i + 2][j] &&
                this->board[i][j] == this->board[i + 3][j]) {
                return true;
            }
        }
    }

    for (int i = 0; i < this->rows - 3; i++) {
        for (int j = 0; j < this->columns - 3; j++) {
            if (this->board[i][j] != 0 &&
                this->board[i][j] == this->board[i + 1][j + 1] &&
                this->board[i][j] == this->board[i + 2][j + 2] &&
                this->board[i][j] == this->board[i + 3][j + 3]) {
                return true;
            }
        }
    }

    for (int i = 0; i < this->rows - 3; i++) {
        for (int j = 3; j < this->columns; j++) {
            if (this->board[i][j] != 0 &&
                this->board[i][j] == this->board[i + 1][j - 1] &&
                this->board[i][j] == this->board[i + 2][j - 2] &&
                this->board[i][j] == this->board[i + 3][j - 3]) {
                return true;
            }
        }
    }


    return false;

}
template <typename T>
bool four_in_row_board<T>::is_draw() {
     return (this->n_moves == 42 && !is_win());;
}

template <typename T>
bool four_in_row_board<T>::game_is_over() {
    if(is_win()||is_draw()){

        return true;
    }

   return false;
}

template <typename T>
four_in_row_Player<T>::four_in_row_Player(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void four_in_row_Player<T>::getmove(int& x, int& y) {
    cout << "\nPlease enter your move y dimension (0 to 6) : ";
    cin >> y;
}

template <typename T>
four_in_row_Random_Player<T>::four_in_row_Random_Player(T symbol) : RandomPlayer<T>(symbol) {
    this->dimension = 6;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator
}
template <typename T>
void  four_in_row_Random_Player<T>::getmove(int& x, int& y) {
    x = rand() % this->dimension;
    y = rand() %( this->dimension+1);
}



#endif
