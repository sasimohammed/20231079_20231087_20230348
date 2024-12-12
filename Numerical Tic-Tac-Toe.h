
#ifndef MAD2_NUMERICAL_TIC_TAC_TOE_H
#define MAD2_NUMERICAL_TIC_TAC_TOE_H
#include <iostream>
#include <iomanip>
#include <cctype>
#include<algorithm>
#include "BoardGame_Classes.h"
using namespace std;
bool p;
vector<int>v3{1,3,5,7,9};
vector<int>v2{2,4,6,8};
vector<string> positions = {
        "00", "01", "02",
        "10", "11", "12",
        "20", "21", "22"
};
extern int choice;
extern int choice1;

template <typename T>
class  Numerical_Tic_Tac_Toe_board:public Board<T> {

public:
    Numerical_Tic_Tac_Toe_board();

    bool update_board(int x, int y, T symbol);

    void display_board();

    bool is_win();

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
        symbol = get_num(this->n_moves);
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
    cout << "\nPlease enter your move x & y dimensions separated with space (0 to 2): " << endl;
    cin >> x >> y;

    // Generate the position string in the format "xy"
    string position = to_string(x) + to_string(y);

    // Remove the position from the vector
    auto it = find(positions.begin(), positions.end(), position);
    if (it != positions.end()) {
        positions.erase(it);
    }

}



template <typename T>
int  Numerical_Tic_Tac_Toe_board<T>::get_num(int x) {
    int num;
    if (choice1 == 2 && choice == 1 || choice==2 && choice1==1) {
        if (p) {
            if (this->n_moves % 2 == 0) {  // Player 1's turn
                cout << "Player 1: Enter a number from: ";
                cout << "{ ";
                for (size_t i = 0; i < v3.size(); ++i) {
                    cout << v3[i];
                    if (i < v3.size() - 1) {
                        cout << ", ";
                    }
                }
                cout << " }" << endl;

                cin >> num;

                // Check if the number is valid
                while (find(v3.begin(), v3.end(), num) == v3.end()) {
                    // Display remaining valid numbers if the input is invalid
                    cout << "Please enter a value within :";
                    cout << "{ ";
                    for (size_t i = 0; i < v3.size(); ++i) {
                        cout << v3[i];
                        if (i < v3.size() - 1) {
                            cout << ", ";
                        }
                    }
                    cout << " }" << endl;
                    cin >> num;
                }

                // Remove the chosen number from the vector
                auto it = find(v3.begin(), v3.end(), num);
                if (it != v3.end()) {
                    v3.erase(it);  // Erase the number from the vector
                }
            } else {  // Player 2's turn
                cout << "Player 2: Enter a number from:";
                cout << "{ ";
                for (size_t i = 0; i < v2.size(); ++i) {
                    cout << v2[i];
                    if (i < v2.size() - 1) {
                        cout << ", ";
                    }
                }
                cout << " }" << endl;

                // Display the vector of valid numbers each time input is invalid
                cin >> num;
                while (find(v2.begin(), v2.end(), num) == v2.end()) {
                    // Display remaining valid numbers if the input is invalid
                    cout << "Please enter a value within:";
                    cout << "{ ";
                    for (size_t i = 0; i < v2.size(); ++i) {
                        cout << v2[i];
                        if (i < v2.size() - 1) {
                            cout << ", ";
                        }
                    }
                    cout << " }" << endl;
                    cin >> num;
                }

                // Remove the chosen number from the vector
                auto it = find(v2.begin(), v2.end(), num);
                if (it != v2.end()) {
                    v2.erase(it);  // Erase the number from the vector
                }
            }
            p = false;
            return num;
        } else {
            // Random player's turn
            int y;
            int sym;

            if (this->n_moves % 2 == 0) {

                // Random selection from v3
                do {
                    y = rand() % v3.size();
                    sym = v3[y];
                } while (find(v3.begin(), v3.end(), sym) == v3.end());  // Ensure valid random number
            } else {
                // Random selection from v2
                do {
                    y = rand() % v2.size();
                    sym = v2[y];
                } while (find(v2.begin(), v2.end(), sym) == v2.end());  // Ensure valid random number
            }
            p = true;

            // Remove the chosen number from the vector
            if (this->n_moves % 2 == 0) {
                v3.erase(v3.begin() + y);  // Remove the random choice from v3
            } else {
                v2.erase(v2.begin() + y);  // Remove the random choice from v2
            }

            return sym;
        }
    }

        if (choice1 == 2 && choice == 2) {
            int y;
            int sym;
            if (this->n_moves % 2 == 0) {

                // Random selection from v3
                do {
                    y = rand() % v3.size();
                    sym = v3[y];
                } while (find(v3.begin(), v3.end(), sym) == v3.end());  // Ensure valid random number
            } else {
                // Random selection from v2
                do {
                    y = rand() % v2.size();
                    sym = v2[y];
                } while (find(v2.begin(), v2.end(), sym) == v2.end());  // Ensure valid random number

            }
            // Remove the chosen number from the vector
            if (this->n_moves % 2 == 0) {
                v3.erase(v3.begin() + y);  // Remove the random choice from v3
            } else {
                v2.erase(v2.begin() + y);  // Remove the random choice from v2
            }

            return sym;
        }
        else {
            if (this->n_moves % 2 == 0) {  // Player 1's turn
                cout << "Player 1: Enter a number from: ";
                cout << "{ ";
                for (size_t i = 0; i < v3.size(); ++i) {
                    cout << v3[i];
                    if (i < v3.size() - 1) {
                        cout << ", ";
                    }
                }
                cout << " }" << endl;

                cin >> num;

                // Check if the number is valid
                while (find(v3.begin(), v3.end(), num) == v3.end()) {
                    // Display remaining valid numbers if the input is invalid
                    cout << "Please enter a value within :";
                    cout << "{ ";
                    for (size_t i = 0; i < v3.size(); ++i) {
                        cout << v3[i];
                        if (i < v3.size() - 1) {
                            cout << ", ";
                        }
                    }
                    cout << " }" << endl;
                    cin >> num;
                }

                // Remove the chosen number from the vector
                auto it = find(v3.begin(), v3.end(), num);
                if (it != v3.end()) {
                    v3.erase(it);  // Erase the number from the vector
                }
            } else {  // Player 2's turn
                cout << "Player 2: Enter a number from:";
                cout << "{ ";
                for (size_t i = 0; i < v2.size(); ++i) {
                    cout << v2[i];
                    if (i < v2.size() - 1) {
                        cout << ", ";
                    }
                }
                cout << " }" << endl;

                // Display the vector of valid numbers each time input is invalid
                cin >> num;
                while (find(v2.begin(), v2.end(), num) == v2.end()) {
                    // Display remaining valid numbers if the input is invalid
                    cout << "Please enter a value within:";
                    cout << "{ ";
                    for (size_t i = 0; i < v2.size(); ++i) {
                        cout << v2[i];
                        if (i < v2.size() - 1) {
                            cout << ", ";
                        }
                    }
                    cout << " }" << endl;
                    cin >> num;
                }

                // Remove the chosen number from the vector
                auto it = find(v2.begin(), v2.end(), num);
                if (it != v2.end()) {
                    v2.erase(it);  // Erase the number from the vector
                }
            }

            return num;

        }



}


template <typename T>
Numerical_Tic_Tac_Toe_Random_Player<T>::Numerical_Tic_Tac_Toe_Random_Player(T symbol) : RandomPlayer<T>(symbol) {
    this->dimension = 3;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator
}

template <typename T>
void Numerical_Tic_Tac_Toe_Random_Player<T>::getmove(int& x, int& y) {
    // Pick a random index from the positions vector
    int randIndex = rand() % positions.size();

    // Get the random position as a string, e.g., "00", "11"
    string position = positions[randIndex];

    // Convert the position string to x, y coordinates
    x = position[0] - '0'; // First character is the x-coordinate
    y = position[1] - '0'; // Second character is the y-coordinate

    // Remove the position from the positions vector
    positions.erase(positions.begin() + randIndex); // Remove the selected position
}



#endif
