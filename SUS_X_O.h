#ifndef SUS_X_O_SUS_X_O_H
#define SUS_X_O_SUS_X_O_H
#include "BoardGame_Classes.h"
#include <iomanip>
using namespace std;


template <typename T>
class SUS_X_O_Board : public Board<T>{
    int win_count_p1;
    int win_count_p2;
    int r1 , r2 , r3 , c1, c2 , c3 , d1 , d2;
    int swtch;
public:
    SUS_X_O_Board();
    bool update_board(int x , int y, T symbol);
    void display_board();
    bool is_win();
    bool is_draw();
    bool game_is_over();
    ~SUS_X_O_Board();
};

template <typename T>
class SUS_X_O_Player : public Player<T>{
public:
    SUS_X_O_Player(string n,T letter);
    void getmove(int& x, int& y);
    string getname();
};

template <typename T>
class SUS_X_O_Random_Player : public RandomPlayer<T>{
public:
    SUS_X_O_Random_Player(T symbol);
    void getmove(int& x, int& y);
};

//-------------------------------------Implementation

template <typename T>
SUS_X_O_Board<T>::SUS_X_O_Board() {
    this->r1 = this->r2 = this->r3 = 1;
    this->c1 = this->c2 = this->c3 = 1;
    this->d1 = this->d2 = 1;
    this->rows = 3;
    this->columns = 3;
    this->board = new char*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 0;
        }
    }
    this->n_moves = 0;
    this->swtch = 0;
    this->win_count_p1 = this->win_count_p2 = 0;
}

template <typename T>
bool SUS_X_O_Board<T>::update_board(int x, int y, T symbol) {
    if(this->n_moves == 9) {
        this->swtch ++;
        return true;
    }
    if(x >= 0 && x < 3 && y >= 0 && y < 3 && this->board[x][y] == 0){
        this->board[x][y]= toupper(symbol);
        this->swtch++;
        this->n_moves++;
        return true;
    }
    return false;
}

template <typename T>
void SUS_X_O_Board<T>::display_board() {
    if (this->n_moves == 9 && this->swtch == 10) return;
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->columns; j++) {
            cout << "|(" << i << "," << j << ") " << this->board[i][j] << " |";
        }
        cout << endl;
    }
    cout << "---------------------------------\n";

}

template <typename T>
bool SUS_X_O_Board<T>::is_draw() {
    return (this->n_moves == 9 && this->win_count_p1 == this->win_count_p2);
}

template <typename T>
bool SUS_X_O_Board<T>::game_is_over() {
    return (this->n_moves == 9 && is_win() || this->n_moves == 9 && is_draw());
}

template <typename T>
bool SUS_X_O_Board<T>::is_win() {
    //why not bool?
    auto check_win=[&](int x1, int y1, int x2, int y2, int x3, int y3){
        return this->board[x1][y1] == 'S' &&
        this->board[x2][y2] == 'U' && this->board[x3][y3] == 'S';
    };
    //Horizontal win
    if (check_win(0,0,0,1,0,2) && r1 == 1){
        r1 = 0;
        if (this->swtch % 2 != 0) this->win_count_p1++;
        if (this->swtch % 2 == 0) this->win_count_p2++;
    }
    if (check_win(1,0,1,1,1,2) && r2 == 1){
        r2 = 0;
        if (this->swtch % 2 != 0) this->win_count_p1++;
        if (this->swtch % 2 == 0) this->win_count_p2++;
    }
    if (check_win(2,0,2,1,2,2) && r3 == 1){
        r3 = 0;
        if (this->swtch % 2 != 0) this->win_count_p1++;
        if (this->swtch % 2 == 0) this->win_count_p2++;
    }
    //Vertical win
    if (check_win(0,0,1,0,2,0) && c1 == 1){
        c1 = 0;
        if (this->swtch % 2 != 0) this->win_count_p1++;
        if (this->swtch % 2 == 0) this->win_count_p2++;
    }
    if (check_win(0,1,1,1,2,1) && c2 == 1){
        c2 = 0;
        if (this->swtch % 2 != 0) this->win_count_p1++;
        if (this->swtch % 2 == 0) this->win_count_p2++;
    }
    if (check_win(0,2,1,2,2,2) && c3 == 1){
        c3 = 0;
        if (this->swtch % 2 != 0) this->win_count_p1++;
        if (this->swtch % 2 == 0) this->win_count_p2++;
    }
    //Diagonal win
    if (check_win(0,0,1,1,2,2) && d1 == 1){
        d1 = 0;
        if (this->swtch % 2 != 0) this->win_count_p1++;
        if (this->swtch % 2 == 0) this->win_count_p2++;
    }
    if (check_win(0,2,1,1,2,0) && d2 == 1){
        d2 = 0;
        if (this->swtch % 2 != 0) this->win_count_p1++;
        if (this->swtch % 2 == 0) this->win_count_p2++;
    }
    cout << "Player 1 : " << this->win_count_p1 << " Point(s)\n";
    cout << "Player 2 : " << this->win_count_p2 << " Point(s)\n";
    cout << "---------------------------------\n";
    if (this->n_moves == 9) {
        if (this->win_count_p1 > this->win_count_p2) return true;
        if (this->win_count_p2 > this->win_count_p1 && this->swtch % 2 == 0) return true;
        if (this->win_count_p2 > this->win_count_p1 && this->swtch % 2 != 0) return false;
    }
    return false;
}

//SUS X_O_Board destructor
template <typename T>
SUS_X_O_Board<T>::~SUS_X_O_Board() {
    for (int i = 0; i < this->rows; i++) {
        delete[] this->board[i];
    }
    delete[] this->board;
}
//------------------------------------------
template <typename T>
SUS_X_O_Player<T>::SUS_X_O_Player(string n,T letter) : Player<T>(n , letter) {}

template <typename T>
string SUS_X_O_Player<T>::getname() {
    return this->name;
}

template <typename T>
void SUS_X_O_Player<T>::getmove(int &x, int &y) {
    //if (this->boardPtr->n_moves== 9) return;
    cout << this->getname() << "'s turn.\n";
    cout << "Enter a valid move (x and y separated by a space):\n";
    cin >> x >> y;
}

template <typename T>
SUS_X_O_Random_Player<T>::SUS_X_O_Random_Player(T letter) : RandomPlayer<T>(letter){
    this->name = "Random Computer Player";
    this->dimension = 3;
    srand(static_cast<unsigned int>(time(0)));
}

template <typename T>
void SUS_X_O_Random_Player<T>::getmove(int &x, int &y) {
    //if (this->boardPtr->n_moves == 9) return;
    x = rand() % this->dimension;
    y = rand() % this->dimension;
}

#endif //SUS_X_O_SUS_X_O_H
