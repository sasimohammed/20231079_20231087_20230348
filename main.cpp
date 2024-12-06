#include <iostream>
#include "BoardGame_Classes.h"
#include "3x3X_O.h"
#include "MinMaxPlayer.h"
#include "Four-in-a-row.h"
#include "numerical_tic_tac_toe_board.h"
#include "Numerical-Tic-Tac-Toe.h"
using namespace std;

int main() {
    cout << "Welcome to FCAI  Games. :)\n";
    cout<<"1) four_in_row_game"<<endl;
    cout<<"2) Numerical_Tic_Tac_Toe_board"<<endl;
    cout<<"-------------------choose your game to start----------------------"<<endl;
    int gamenum;
    cin>>gamenum;
    if(gamenum==1){
        int choice;
        Player<char>* players[2];
        four_in_row_board<char>*B = new  four_in_row_board<char>();
        string playerXName, player2Name;
        cout << "Enter Player 1 name: ";
        cin >> playerXName;
        cout << "Choose Player 1 type:\n";
        cout << "1. Human\n";
        cout << "2. Random Computer\n";
        cout << "3. Smart Computer (AI)\n";
        cin >> choice;

        switch(choice) {
            case 1:
                players[0] = new  four_in_row_Player<char>(playerXName, 'X');
                break;
            case 2:
                players[0] = new four_in_row_Random_Player<char>('X');
                break;
            case 3:
                players[0] = new X_O_MinMax_Player<char>('X');
                players[0]->setBoard(B);
                break;
            default:
                cout << "Invalid choice for Player 1. Exiting the game.\n";
                return 1;
        }
        // Set up player 2
        cout << "Enter Player 2 name: ";
        cin >> player2Name;
        cout << "Choose Player 2 type:\n";
        cout << "1. Human\n";
        cout << "2. Random Computer\n";
        cout << "3. Smart Computer (AI)\n";
        cin >> choice;

        switch(choice) {
            case 1:
                players[1] = new four_in_row_Player<char>(player2Name, 'O');
                break;
            case 2:
                players[1] = new X_O_Random_Player<char>('O');
                break;
            case 3:
                players[1] = new X_O_MinMax_Player<char>('O');
                players[1]->setBoard(B);
                break;
            default:
                cout << "Invalid choice for Player 2. Exiting the game.\n";
                return 1;
        }
        GameManager<char> four_in_row(B, players);
        four_in_row.run();
        delete B;
        for (int i = 0; i < 2; ++i) {
            delete players[i];
        }
    }
    else if(gamenum==2){
        int choice;
        Player<char>* players[2];
        Numerical_Tic_Tac_Toe_board<char>*B = new  Numerical_Tic_Tac_Toe_board<char>();
        string playerXName, player2Name;

        cout << "Enter Player 1 name: ";
        cin >> playerXName;
        cout << "Choose Player 1 type:\n";
        cout << "1. Human\n";
        cout << "2. Random Computer\n";
        cout << "3. Smart Computer (AI)\n";
        cin >> choice;
        switch(choice) {
            case 1:
                players[0] = new  Numerical_Tic_Tac_Toe_Player<char>(playerXName, '0');
                break;
            case 2:

                players[0] = new Numerical_Tic_Tac_Toe_Random_Player<char>('0');

                break;
            case 3:

            default:
                cout << "Invalid choice for Player 1. Exiting the game.\n";
                return 1;
        }
        // Set up player 2
        cout << "Enter Player 2 name: ";
        cin >> player2Name;
        cout << "Choose Player 2 type:\n";
        cout << "1. Human\n";
        cout << "2. Random Computer\n";
        cout << "3. Smart Computer (AI)\n";
        cin >> choice;

        switch(choice) {
            case 1:

                players[1] = new Numerical_Tic_Tac_Toe_Player<char>(player2Name, '0');
                break;
            case 2:
                players[1] = new Numerical_Tic_Tac_Toe_Random_Player<char>('0');
                break;
            case 3:

            default:
                cout << "Invalid choice for Player 2. Exiting the game.\n";
                return 1;
        }
        GameManager<char>  Numerical_Tic_Tac_Toe(B, players);
        Numerical_Tic_Tac_Toe.run();
        delete B;
        for (int i = 0; i < 2; ++i) {
            delete players[i];
        }
    }



    return 0;
}


