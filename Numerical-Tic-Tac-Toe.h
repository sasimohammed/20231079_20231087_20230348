
#ifndef MAD2_NUMERICAL_TIC_TAC_TOE_H
#define MAD2_NUMERICAL_TIC_TAC_TOE_H
#include <iostream>
#include <iomanip>
#include <cctype>
#include<algorithm>
#include "BoardGame_Classes.h"
using namespace std;

template <typename T>
class  Numerical_Tic_Tac_Toe_board:public Board<T>{

public:
    Numerical_Tic_Tac_Toe_board();
    bool update_board (int x , int y , T symbol);
    void display_board () ;
    bool is_win() ;
    bool is_draw();
    bool game_is_over();
    int get_num(int x);



};
template <typename T>
class   Numerical_Tic_Tac_Toe_Player:public Player<T> {
public:
    Numerical_Tic_Tac_Toe_Player (string name, T symbol);
    void getmove(int& x, int& y) ;
};
template <typename T>
class Numerical_Tic_Tac_Toe_Random_Player : public RandomPlayer<T>{
public:
    Numerical_Tic_Tac_Toe_Random_Player  (T symbol);
    void getmove(int &x, int &y) ;
};

//--------------------------------------- IMPLEMENTATION
template <typename T>
Numerical_Tic_Tac_Toe_board<T>::Numerical_Tic_Tac_Toe_board(){
    this->rows =  this->columns=3;
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
bool Numerical_Tic_Tac_Toe_board<T>::update_board(int x, int y, T symbol) {
    symbol=get_num(this->n_moves);
    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) &&
        (this->board[x][y] == 0 || symbol == 0)) {
        if (symbol == 0) {
            this->n_moves--;
            this->board[x][y] = 0;
        } else {
            this->n_moves++;
            this->board[x][y] = (symbol)+'0';
        }
        return true;
    }
    return false;
}

template <typename T>
void Numerical_Tic_Tac_Toe_board<T>::display_board() {
    cout<<"player 1: { 1, 3, 5, 7, 9 }"<<endl;
    cout<<"player 2: { 2, 4, 6, 8 }"<<endl;
    for (int i = 0; i < this->rows; i++) {
        cout << "\n|";
        for (int j = 0; j < this->columns; j++) {
            cout << setw(2) << this->board[i][j] << "|";
        }
        cout << "\n----------";
    }
    cout << endl;
}
template <typename T>
bool Numerical_Tic_Tac_Toe_board<T>::is_win() {
    for (int i = 0; i < 3; i++) {
        int rowSum = 0;
        for (int j = 0; j < 3; j++) {
            rowSum += this->board[i][j]-'0';
        }
        if (rowSum == 15) {
            return true;
        }
    }

    // Check columns
    for (int j = 0; j < 3; j++) {
        int colSum = 0;
        for (int i = 0; i < 3; i++) {
            colSum += this->board[i][j]-'0';
        }
        if (colSum == 15) {
            return true;
        }
    }

    // Check main diagonal
    int diag1Sum = 0;
    for (int i = 0; i < 3; i++) {
        diag1Sum += this->board[i][i]-'0';
    }
    if (diag1Sum == 15) {
        return true;
    }

    // Check secondary diagonal
    int diag2Sum = 0;
    for (int i = 0; i < 3; i++) {
        diag2Sum += this->board[i][2 - i]-'0';
    }
    if (diag2Sum == 15) {
        return true;
    }

    return false;

}
template <typename T>
bool Numerical_Tic_Tac_Toe_board<T>::is_draw() {
    return (this->n_moves == 9 && !is_win());;
}

template <typename T>
bool Numerical_Tic_Tac_Toe_board<T>::game_is_over() {
    return is_win() || is_draw();
}

template <typename T>
Numerical_Tic_Tac_Toe_Player<T>::Numerical_Tic_Tac_Toe_Player(string name, T symbol) : Player<T>(name, symbol){

}

template <typename T>
void Numerical_Tic_Tac_Toe_Player<T>::getmove(int& x, int& y) {
    cout << "\nPlease enter your move x & y dimensions seperated with space (0 to 2) : "<<endl;
    cin >> x>>y;
    cout<<endl;
}



template <typename T>
int  Numerical_Tic_Tac_Toe_board<T>::get_num(int x) {
    int num;
    if(this->n_moves %2==0){
        vector<int>v1{1,3,5,7,9};
        cout<<"Player1 : Enter your number  {1 ,3 ,5 ,7 ,9}:"<<endl;
        cin>>num;
        while(find(v1.begin(),v1.end(),num)==v1.end()){
            cout<<"please Enter a value within {1 ,3 ,5 ,7 ,9}"<<endl;
            cin>>num;
        }

    }
    else{
        vector<int>v1{2,4,6,8};
        cout<<"Player2 : Enter your number  {2 , 4, 6, 8}:"<<endl;
        cin>>num;

        while(find(v1.begin(),v1.end(),num)==v1.end()){
            cout<<"please Enter a value within {2,4,6,8}"<<endl;
            cin>>num;
        }

    }


    return num;
}


template <typename T>
Numerical_Tic_Tac_Toe_Random_Player<T>::Numerical_Tic_Tac_Toe_Random_Player(T symbol) : RandomPlayer<T>(symbol) {
    this->dimension = 3;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator
}
template <typename T>
void  Numerical_Tic_Tac_Toe_Random_Player<T>::getmove(int& x, int& y) {

    x = rand() % this->dimension;
    y = rand() %( this->dimension);
}



#endif
