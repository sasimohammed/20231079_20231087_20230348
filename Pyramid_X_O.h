#ifndef _3X3X_O_H
#define _3X3X_O_H

#include "BoardGame_Classes.h"

template <typename T>
class Pyramid_X_O_Board:public Board<T> {
public:
    Pyramid_X_O_Board ();
    ~Pyramid_X_O_Board();
    bool update_board (int x , int y , T symbol);
    void display_board () ;
    bool is_win() ;
    bool is_draw();
    bool game_is_over();
};

template <typename T>
class Pyramid_X_O_Player : public Player<T> {
public:
    Pyramid_X_O_Player (string name, T symbol);
    void getmove(int& x, int& y) ;
    string getname();
};

template <typename T>
class Pyramid_X_O_Random_Player : public RandomPlayer<T>{
    int dimension2;
public:
    Pyramid_X_O_Random_Player (T symbol);
    void getmove(int &x, int &y) ;
};

//--------------------------------------- IMPLEMENTATION

#include <iostream>
#include <iomanip>
#include <cctype>  // for toupper()

using namespace std;

//pyramid X_O_Board Constructor
template <typename T>
Pyramid_X_O_Board<T>::Pyramid_X_O_Board() {
    this->rows = 3;
    this->columns = 5;
    this->board = new char*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 0;
        }
    }
    this->n_moves = 0;
    this->board[0][0] = this->board[0][1] = this->board[1][0] = '#';
    this->board[0][3] = this->board[0][4] = this->board[1][4] = '#';
}

template <typename T>
bool Pyramid_X_O_Board<T>::update_board(int x, int y, T mark) {
    //checking valid move
    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && (this->board[x][y] == 0|| mark == 0)) {
        if (mark == 0){
            this->n_moves--;
            this->board[x][y] = 0;
        }
        else {
            this->n_moves++;
            this->board[x][y] = toupper(mark);
        }

        return true;
    }
    return false;
}

template <typename T>
void Pyramid_X_O_Board<T>::display_board() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if (this->board[i][j] != '#') {
                if(i == 0){
                    cout <<  "|" << "(0,0) " << setw(0) << this->board[i][j] << "|";
                }
                if (i == 1){
                    cout <<  "|" << "(" << i << "," << j-1 << ") " << setw(0) << this->board[i][j] << "|";

                }
                if (i == 2) {
                    cout <<  "|" << "(" << i << "," << j << ") " << setw(0) << this->board[i][j] << "|";
                }
            }
            else {
                cout << setw(9) << " ";
            }
        }
        cout << endl;
    }
    cout << "------------------------------------------------\n";
}

template <typename T>
bool Pyramid_X_O_Board<T>::is_win() {
    auto check_win = [&](int x1 , int y1 , int x2 , int y2 , int x3, int y3){
        return this->board[x1][y1] == this->board[x2][y2] &&
               this->board[x2][y2] == this->board[x3][y3] &&
               this->board[x1][y1] != 0;
    };
    //horizontal win
    if (check_win(1,1,1,2,1,3)) return true;
    if (check_win(2,0,2,1,2,2)) return true;
    if (check_win(2,1,2,2,2,3)) return true;
    if (check_win(2,2,2,3,2,4)) return true;

    //diagonal win
    if (check_win(0,2,1,1,2,0)) return true;
    if (check_win(0,2,1,3,2,4)) return true;

    //vertical win
    if (check_win(0,2,1,2,2,2)) return true;

    return false;
}

template <typename T>
bool Pyramid_X_O_Board<T>::is_draw() {
    return (this->n_moves == 9 && !is_win());
}

template <typename T>
bool Pyramid_X_O_Board<T>::game_is_over() {
    return is_win() || is_draw();
}

//pyramid X_O_Board destructor
template <typename T>
Pyramid_X_O_Board<T>::~Pyramid_X_O_Board() {
    for (int i = 0; i < this->rows; i++) {
        delete[] this->board[i];
    }
    delete[] this->board;
}

//--------------------------------------

//pyramid X_O_Player Constructor
template <typename T>
Pyramid_X_O_Player<T>::Pyramid_X_O_Player(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
string Pyramid_X_O_Player<T>::getname() {
    return this->name;
}

template <typename T>
void Pyramid_X_O_Player<T>::getmove(int& x, int& y) {
    cout << this->getname() << "'s turn.\n";
    cout << "Enter a valid move (x and y separated by a space):\n";
    cin >> x >> y;
    if(x == 0) y += 2;
    if(x == 1) y += 1;
}

//pyramid X_O_Random_Player Constructor
template <typename T>
Pyramid_X_O_Random_Player<T>::Pyramid_X_O_Random_Player(T symbol) : RandomPlayer<T>(symbol) {
    this->name = "Random Computer Player";
    this->dimension = 3;
    this->dimension2 = 5;
    srand(static_cast<unsigned int>(time(0)));
}

template <typename T>
void Pyramid_X_O_Random_Player<T>::getmove(int& x, int& y) {
    x = rand() % this->dimension;
    y = rand() % this->dimension2;
}

#endif //_3X3X_O_H

