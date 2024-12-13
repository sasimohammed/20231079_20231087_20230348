
#ifndef GAME3_H
#define GAME3_H

#include "BoardGame_Classes.h"

extern string player_name1;

bool flag =false;
template <typename T>
class _5x5_XO_board:public Board<T> {
    int count_player1;
    int count_player2;
    char arr2 [5][5];


public:
    int counter ;
    _5x5_XO_board() ;
    _5x5_XO_board(Player<T>* p1, Player<T>* p2);

    bool update_board (int x , int y , T symbol);
    void display_board () ;
    bool is_win() ;
    bool is_draw();
    bool game_is_over();

};


template <typename T>
class _5x5_XO_Player : public Player<T> {
    vector<string>names;
public:
    _5x5_XO_Player(string name, T symbol);
    void getmove(int& x, int& y) ;

};

template <typename T>
class _5x5_XO_Random_Player : public RandomPlayer<T>{
public:
    _5x5_XO_Random_Player (T symbol);
    void getmove(int &x, int &y) ;
};





//--------------------------------------- IMPLEMENTATION

#include <iostream>
#include <iomanip>
#include <cctype>  // for toupper()
#include <vector>
#include<map>

using namespace std;

string s;

// Constructor for X_O_Board
template <typename T>
_5x5_XO_board<T>::_5x5_XO_board() {

    count_player1 = 0;
    count_player2 = 0;
    counter=0;
    this->rows = this->columns = 5;
    this->board = new char*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 0;
            arr2[i][j] = 0;
        }
    }
    this->n_moves = 0;
}



template <typename T>
bool _5x5_XO_board<T>::update_board(int x, int y, T mark) {
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
void _5x5_XO_board<T>::display_board() {
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
bool _5x5_XO_board<T>::is_win() {




    if(counter==24)
    {
        //horizontal check
        for(int i=0;i<5;i++)
        {
            for(int j=1;j<4;j++)
            {
                if((this->board[i][j]==this->board[i][j+1] )&& (this->board[i][j]==this->board[i][j-1]) &&this->board[i][j]!=0 )
                {
                    arr2[i][j]='*';
                    arr2[i][j+1]='*';
                    arr2[i][j-1]='*';
                    if(this->board[i][j]=='X')
                    {
                        count_player1++;
                    }
                    else if (this->board[i][j]=='0')
                    {
                        count_player2++;

                    }

                }
            }

        }
        //vertical check
        for(int i=1;i<4;i++)
        {
            for(int j=0;j<5;j++)
            {
                if((this->board[i][j]==this->board[i+1][j] )&& (this->board[i][j]==this->board[i-1][j])&&this->board[i][j]!=0 )
                {
                    arr2[i][j]='*';
                    arr2[i+1][j]='*';
                    arr2[i-1][j]='*';
                    if(this->board[i][j]=='X')
                    {
                        count_player1++;
                    }
                    else if (this->board[i][j]=='0')
                    {
                        count_player2++;

                    }

                }
            }
        }
        //inc diagonal check
        for(int i=2;i<5;i++)
        {
            for(int j=0;j<=2;j++)
            {
                if(((this->board[i][j]==this->board[i-1][j+1]) && (this->board[i][j]==this->board[i-2][j+2]) && this->board[i][j]!=0 ))
                {
                    arr2[i][j]='*';
                    arr2[i-2][j+2]='*';
                    arr2[i-1][j+1]='*';
                    if(this->board[i][j]=='X')
                    {

                        count_player1++;
                    }
                    else if (this->board[i][j]=='0')
                    {

                        count_player2++;

                    }

                }
            }
        }
        //dec diagonal check
        for(int i=0;i<=2;i++)
        {
            for(int j=0;j<=2;j++)
            {
                if(((this->board[i][j]==this->board[i+1][j+1]) && (this->board[i][j]==this->board[i+2][j+2]) &&this->board[i][j]!=0 ))
                {

                    if(this->board[i][j]=='X' )
                    {

                        count_player1++;
                    }
                    else if (this->board[i][j]=='0'  )
                    {

                        count_player2++;

                    }


                }
            }
        }




        if(count_player2>count_player1)
        {
            counter = 25;
            return true;
        }
        else if(count_player2<count_player1)
        {
            cout << player_name1 << " wins\n";
            counter = 25;
            return false;

        }

    }

    return false;

}

// Return true if 24 moves are done and no winner
template <typename T>
bool _5x5_XO_board<T>::is_draw() {
    if(counter==24 && this->count_player1 == this->count_player2)
    {
        return true;
    }
    else
    {
        return false;
    }

}

template <typename T>
bool _5x5_XO_board<T>::game_is_over() {
    cout<<"counter: "<<counter<<endl;
    if(this->counter<25)
    {

        return false;
    }

    else if(this->counter==25)
    {
        return true;
    }

}

//--------------------------------------

// Constructor for X_O_Player
template <typename T>
_5x5_XO_Player<T>::_5x5_XO_Player(string name, T symbol) : Player<T>(name, symbol) {
    names.push_back(name);
}

vector<string>available_places{"00","01","02","03","04","10","11","12","13","14","20","21","22","23","24","30","31","32","33","34","40","41","42","43","44"};
template <typename T>
void _5x5_XO_Player<T>::getmove(int& x, int& y) {
    cout << "\nPlease enter your move x and y (0 to 2) separated by spaces: ";
    cin >> x >> y;

}

// Constructor for X_O_Random_Player
template <typename T>
_5x5_XO_Random_Player<T>::_5x5_XO_Random_Player(T symbol) : RandomPlayer<T>(symbol) {
    this->dimension = 3;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator
}

template <typename T>
void _5x5_XO_Random_Player <T>::getmove(int& x, int& y) {
    int random_index = rand() % available_places.size();
    x = available_places[random_index][0]-'0';
    y = available_places[random_index][1]-'0';
    available_places.erase(remove(available_places.begin(), available_places.end(), available_places[random_index]), available_places.end());
    cout<<"the generated random index is "<<x<<' '<<y<<endl;
}


#endif //GAME3_H
