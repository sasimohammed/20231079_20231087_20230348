
#ifndef GAME6_H
#define GAME6_H

#include "BoardGame_Classes.h"

extern string player_name1;
extern string player_name2;
bool flag1 =false;
template <typename T>
class Misere_XO_board:public Board<T> {

public:
    int counter ;
    Misere_XO_board() ;
    Misere_XO_board(Player<T>* p1, Player<T>* p2);

    bool update_board (int x , int y , T symbol);
    void display_board () ;
    bool is_win() ;
    bool is_draw();
    bool game_is_over();

};


template <typename T>
class Misere_XO_player : public Player<T> {
    vector<string>names;
public:
    Misere_XO_player(string name, T symbol);
    void getmove(int& x, int& y) ;

};

template <typename T>
class Misere_XO_Random_player : public RandomPlayer<T>{
public:
    Misere_XO_Random_player (T symbol);
    void getmove(int &x, int &y) ;
};





//--------------------------------------- IMPLEMENTATION

#include <iostream>
#include <iomanip>
#include <cctype>  // for toupper()
#include <vector>
#include<map>

using namespace std;



// Constructor for X_O_Board
template <typename T>
Misere_XO_board<T>::Misere_XO_board() {


    counter=0;
    this->rows = this->columns = 3;
    this->board = new char*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 0;

        }
    }
    this->n_moves = 0;
}



template <typename T>
bool Misere_XO_board<T>::update_board(int x, int y, T mark) {
    // Only update if move is valid

    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && (this->board[x][y] == 0|| mark == 0)) {
        if (mark == 0){
            this->n_moves--;
            this->board[x][y] = 0;

        }
        else {
            this->n_moves++;
            this->board[x][y] = toupper(mark);
        }
        counter++;
        return true;
    }
    return false;
}

// Display the board and the pieces on it
template <typename T>
void Misere_XO_board<T>::display_board() {
    if(flag1)
    {

    }
    for (int i = 0; i < this->rows; i++) {
        cout << "\n| ";
        for (int j = 0; j < this->columns; j++) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << this->board[i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << endl;
}


// Returns true if there is any winner
template <typename T>
bool Misere_XO_board<T>::is_win()
{
    //horizontal check
    for(int i=0;i<3;i++)
    {
        if(this->board[i][0] == this->board[i][1] && this->board[i][0] == this->board[i][2] && this->board[i][0] != 0)
        {


            flag = true;

            return true;
        }
    }

    //vertical check
    for(int j=0;j<3;j++)
    {
        if(this->board[0][j] == this->board[1][j] && this->board[0][j] == this->board[2][j] && this->board[0][j] != 0)
        {

            flag1 = true;

            return true;
        }
    }

    //decreasing diagonal check
    if(this->board[0][0]==this->board[1][1] && this->board[0][0]==this->board[2][2] && this->board[0][0]!=0)
    {

        flag1 = true;

        return true;
    }

    //increasing diagonal check
    if(this->board[0][2]==this->board[1][1] && this->board[0][2]==this->board[2][0] && this->board[0][2]!=0)
    {

        flag1 = true;

        return true;
    }

    return false;


}

// Return true if 9 moves are done and no winner
template <typename T>
bool Misere_XO_board<T>::is_draw()
{
    if(counter==9 && !flag1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename T>
bool Misere_XO_board<T>::game_is_over()
{
    if(flag1)
    {
        return true;
    }
    else
    {
        return false;
    }

}

//--------------------------------------

// Constructor for X_O_Player
template <typename T>
Misere_XO_player<T>::Misere_XO_player(string name, T symbol) : Player<T>(name, symbol) {
    names.push_back(name);
}


template <typename T>
void Misere_XO_player<T>::getmove(int& x, int& y) {
    cout << "\nPlease enter your move x and y (0 to 2) separated by spaces: ";
    cin >> x >> y;

}

vector<string>available_places1{"00","01","02","10","11","12","20","21","22"};
// Constructor for X_O_Random_Player
template <typename T>
Misere_XO_Random_player<T>::Misere_XO_Random_player(T symbol) : RandomPlayer<T>(symbol) {
    this->dimension = 3;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator
}

template <typename T>
void Misere_XO_Random_player <T>::getmove(int& x, int& y) {
    int random_index = rand() % available_places1.size();
    x = available_places1[random_index][0]-'0';
    y = available_places1[random_index][1]-'0';
    available_places1.erase(remove(available_places1.begin(), available_places1.end(), available_places1[random_index]), available_places1.end());
    cout<<"the generated random index is "<<x<<' '<<y<<endl;
}







#endif //GAME6_H

