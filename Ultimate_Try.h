#ifndef ULTIMATE_TRY_H
#define ULTIMATE_TRY_H

#include <iostream>
#include <iomanip>
#include <cctype>
#include <map>
#include <vector>
#include "BoardGame_Classes.h"
#include<algorithm>


using namespace std;
vector<string> boardPositions{"00", "01", "02", "10", "11", "12", "20", "21", "22"};
// Global variables
int x2 = 0;
bool k=true;
vector<vector<char>> sub_board_v(3, vector<char>(3, ' '));

vector<int>valid_positions{1,2,3,4,5,6,7,8,9};

void display_sub_board(const vector<vector<char>>& board) {

    for (int i = 0; i < 3; i++) {
        cout << "\n| ";
        for (int j = 0; j < 3; j++) {
            cout << setw(2) << board[i][j] << " |";
        }
        cout << "\n-------------";
    }
    cout << endl;

}


template <typename T>
class ultimate_tic_tac_toe_main_board : public Board<T> {
public:
    int n_moves2=0;
    bool   alert=true;
    ultimate_tic_tac_toe_main_board();
    bool update_board(int x, int y, T symbol);
    void display_board();
    bool is_win();
    bool is_draw();
    bool game_is_over();
    bool check_sub_board_win(vector<vector<char>> board);
    int  get_sub_board_num();
    void update_main_board(int x, char symbol);



};




// Template class for the player
template <typename T>
class ultimate_tic_tac_toe_main_board_player : public Player<T> {
public:
    ultimate_tic_tac_toe_main_board_player(string name, T symbol);
    void getmove(int& x, int& y);
};

// Template class for the random player
template <typename T>
class ultimate_tic_tac_toe_main_board_random_player : public RandomPlayer<T> {
public:
    ultimate_tic_tac_toe_main_board_random_player(T symbol);
    void getmove(int& x, int& y);
};

// Clear the sub-board
void clear_board() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            sub_board_v[i][j] = ' ';
        }
    }
}

// Implementation details

template <typename T>
ultimate_tic_tac_toe_main_board<T>::ultimate_tic_tac_toe_main_board() {
    this->rows = this->columns = 3;
    this->board = new char*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = ' ';
        }
    }
    this->n_moves = 0;
}

template <typename T>
bool ultimate_tic_tac_toe_main_board<T>::update_board(int x, int y, T mark) {

    if(this->n_moves2 % 2 == 0) {
        mark = 'X'; // Player 1 is 'X'
    } else {
        mark = 'O'; // Player 2 is 'O'
    }
    sub_board_v[x][y] = mark;
    this->n_moves2++;

    return true;
}



template <typename T>
void ultimate_tic_tac_toe_main_board<T>::display_board() {
    cout << "the first board is the sub_board number ("<< x2 << ") the second board is the optimized main_board"<< endl;
    display_sub_board(sub_board_v);
    for (int i = 0; i < this->rows; i++) {
        cout << "\n| ";
        for (int j = 0; j < this->columns; j++) {
            cout << setw(2) << this->board[i][j] << " |";
        }
        cout << "\n---------------";
    }
    cout << endl;

    if(this->n_moves2%2==0 && !check_sub_board_win(sub_board_v ) )
    {
        cout<<"player 1 :please enter the x,y for your move : ";
    }
    if(this->n_moves2%2!=0 &&   !check_sub_board_win(sub_board_v) ){

        cout<<"player 2 :please enter the x,y for your move : ";



    }

}



template <typename T>
bool ultimate_tic_tac_toe_main_board<T>::is_draw() {
    return (this->n_moves == 9 && !is_win());
}

template <typename T>
bool ultimate_tic_tac_toe_main_board<T>::game_is_over() {
    return is_win() || is_draw();
}

template <typename T>
int ultimate_tic_tac_toe_main_board<T>::get_sub_board_num() {
    boardPositions={"00", "01", "02", "10", "11", "12", "20", "21", "22"};
    int num;
    cout << "Choose your sub-board to start playing from (1-9):" << endl;
    for (int i = 0; i < 9; i++) {
        cout << "\n| ";
        for (int j = 0; j < 9; j++) {
            cout << setw(2) << " " << " |";
        }
        cout << "\n---------------------------------------";
    }
    cout << endl;

    while (true) {
        cout << "Please enter the number of the sub-board from (1-9): ";
        cin >> num;
        if (num < 1 || num > 9 || find(valid_positions.begin(), valid_positions.end(), num) == valid_positions.end()) {
            cout << "Invalid choice or sub-board already used. Try again!" << endl;
        } else {
            valid_positions.erase(remove(valid_positions.begin(), valid_positions.end(), num), valid_positions.end());
            break;
        }
    }
    return x2 = num;

}

template <typename T>
void ultimate_tic_tac_toe_main_board<T>::update_main_board(int x, char symbol) {
    vector<string> boardPositions2{"00", "01", "02", "10", "11", "12", "20", "21", "22"};
    map<int, string> boardMap;
    for (size_t i = 0; i < 9; i++) {
        boardMap[i + 1] = boardPositions2[i];
    }
    string index = boardMap[x];
    int row = index[0] - '0';
    int col = index[1] - '0';
    this->board[row][col] = symbol;
}

template <typename T>
bool ultimate_tic_tac_toe_main_board<T>::check_sub_board_win(vector<vector<char>> board) {

    for (int i = 0; i < 3; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            if (board[i][0] == 'X') {
                update_main_board(x2, board[i][0]);

                cout << "Player 1 wins this sub-board!" << endl;
            } else if (board[i][0] == 'O') {
                update_main_board(x2, board[i][0]);
                cout << "Player 2 wins this sub-board!" << endl;
            }
            alert=false;
            clear_board();

            this->n_moves2=0;
            this->n_moves++;

            get_sub_board_num();
            display_board(); // Display the updated main board
            boardPositions={"00", "01", "02", "10", "11", "12", "20", "21", "22"};


            return true;
        }
    }

    for (int j = 0; j < 3; j++) {
        if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            if (board[0][j] == 'X') {
                update_main_board(x2, board[0][j]);
                cout << "Player 1 wins this sub-board!" << endl;
            } else if (board[0][j] == 'O') {
                update_main_board(x2, board[0][j]);
                cout << "Player 2 wins this sub-board!" << endl;
            }
            alert=false;
            clear_board();
            this->n_moves2=0;
            this->n_moves++;
            get_sub_board_num();
            display_board(); // Display the updated main board
            boardPositions={"00", "01", "02", "10", "11", "12", "20", "21", "22"};
            return true;
        }
    }

    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0] == 'X') {
            update_main_board(x2, board[0][0]);
            cout << "Player 1 wins this sub-board!" << endl;
        } else if (board[0][0] == 'O') {
            update_main_board(x2, board[0][0]);
            cout << "Player 2 wins this sub-board!" << endl;
        }
        alert=false;
        clear_board();
        this->n_moves2=0;
        this->n_moves++;
        get_sub_board_num();
        display_board(); // Display the updated main board
        boardPositions={"00", "01", "02", "10", "11", "12", "20", "21", "22"};

        return true;
    }

    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {

        if (board[0][2] == 'X') {
            update_main_board(x2, board[0][2]);
            cout << "Player 1 wins this sub-board!" << endl;
        } else if (board[0][2] == 'O') {
            update_main_board(x2, board[0][2]);
            cout << "Player 2 wins this sub-board!" << endl;
        }
        alert=false;
        clear_board();
        this->n_moves2=0;
        this->n_moves++;
        get_sub_board_num();
        display_board(); // Display the updated main board


        boardPositions={"00", "01", "02", "10", "11", "12", "20", "21", "22"};
        return true;
    }

    return false;
}

template <typename T>
bool ultimate_tic_tac_toe_main_board<T>::is_win() {
    for (int i = 0; i < this->rows; i++) {
        if (this->board[i][0] != ' ' && this->board[i][0] == this->board[i][1] && this->board[i][1] == this->board[i][2]) {
            return true;
        }
    }
    for (int j = 0; j < this->columns; j++) {
        if (this->board[0][j] != ' '&& this->board[0][j] == this->board[1][j] && this->board[1][j] == this->board[2][j]) {
            return true;
        }
    }
    if (this->board[0][0] != ' '&& this->board[0][0] == this->board[1][1] && this->board[1][1] == this->board[2][2]) {
        return true;
    }
    if (this->board[0][2] != ' ' && this->board[0][2] == this->board[1][1] && this->board[1][1] == this->board[2][0]) {
        return true;
    }



    return false;


}
// Player implementations
template <typename T>
ultimate_tic_tac_toe_main_board_player<T>::ultimate_tic_tac_toe_main_board_player(string name, T symbol)
        : Player<T>(name, symbol) {}

template <typename T>
void ultimate_tic_tac_toe_main_board_player<T>::getmove(int& x, int& y) {
    // Available board positions


    while (true)
    {

        cin >> x ;

        // Check if x and y are within the valid range
        if (x < 0 || x > 2) {
            cout << "Invalid move. x coordinate is out of range (0-2). Please try again: " << endl;
            cin>>x;
            continue;
        }
        cin>>y;
        if (y < 0 || y > 2) {
            cout << "Invalid move. y coordinate is out of range (0-2). Please try again: " << endl;
            cin>>y;
            continue;
        }

        // Convert x and y from integers to characters
        char x1 = x + '0';
        char y1 = y + '0';




        // Combine characters into a string
        string s = string(1, x1) + string(1, y1);

        // Check if the string is in the vector
        auto it = find(boardPositions.begin(), boardPositions.end(), s);
        if (it != boardPositions.end()) {
            // If found, remove the string from the vector
            boardPositions.erase(it);
            cout << "Valid move! You entered: " << s << endl;
            break; // Exit the loop after a valid input
        } else {
            cout << "Invalid move. This cell is already taken. Please try again: " << endl;
        }
    }
    // Print remaining board positions for verification
    cout << "Remaining board positions: ";
    for (const auto &pos : boardPositions) {
        cout << pos << " ";
    }
    cout << endl;
}

template <typename T>
ultimate_tic_tac_toe_main_board_random_player<T>::ultimate_tic_tac_toe_main_board_random_player(T symbol)
        : RandomPlayer<T>(symbol) {
    this->dimension = 3;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));
}


template <typename T>
void ultimate_tic_tac_toe_main_board_random_player<T>::getmove(int& x, int& y) {

    int indx = rand() % boardPositions.size();
    x = boardPositions[indx][0]-'0';
    y = boardPositions[indx][0]-'1';


    available_places.erase(remove(available_places.begin(), available_places.end(), available_places[indx]), available_places.end());
    cout<<"the generated random index is "<<x<<' '<<y<<endl;



    // Print remaining board positions for verification
    cout << "Remaining board positions: ";
    for (const auto& pos : boardPositions) {
        cout << pos << " ";
    }
    cout << endl;
}

#endif//
