#include <iostream>
#include "four_in_row_board.h"
#include "numerical_tic_tac_toe_board.h"
#include "Tic_tac_toe5_board.h"
#include "game6_tic_tac_toe.h"
#include "Ultimate Tic Tac Toe .h"

using namespace std;

int main() {
    cout << "Hello in our board games" << endl;
    cout << "Choose your game:" << endl;
    cout << "1) Four in a Row" << endl;
    cout << "2) Numerical Tic Tac Toe" << endl;
    cout << "3) 5x5 Tic Tac Toe" << endl;
    cout << "4) Misere Tic Tac Toe" << endl;
    cout << "5) Ultimate Tic Tac Toe" << endl;

    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "Player 1: X" << endl;
        cout << "Player 2: O" << endl;
        four_in_row_board game_board(7, 6, '-');
        game_board.display();
        vector<char> player1_s = {'X'};
        vector<char> player2_s = {'O'};
        player<vector<char>> player1(player1_s);
        player<vector<char>> player2(player2_s);
        four_in_row_manage game_manager(game_board, player1, player2);
        game_manager.take_turn();
    }
    else if (choice == 2) {
        numirecal_tic_tac_toe_board game_board(3, 3, 45);
        game_board.display();
        cout << "Player 1 numbers: 1, 3, 5, 7" << endl;
        vector<int> player1_numbers = {1, 3, 5, 7};
        player<vector<int>> player1(player1_numbers);
        cout << "Player 2 numbers: 2, 4, 6, 8" << endl;
        vector<int> player2_numbers = {2, 4, 6, 8};
        player<vector<int>> player2(player2_numbers);
        numirecal_tic_tac_toe_manage game_manager(game_board, player1, player2);
        game_manager.take_turn();
    }
    else if (choice == 3) {
        cout << "Player 1: X" << endl;
        cout << "Player 2: O" << endl;
        game5 game_board(5, 5, '-');
        game_board.display();
        vector<char> player1_s = {'X'};
        vector<char> player2_s = {'O'};
        player<vector<char>> player1(player1_s);
        player<vector<char>> player2(player2_s);
        manage_game5 game_manager(game_board, player1, player2);
        game_manager.take_turn();
    }
    else if (choice == 4) {
        cout << "Player 1: X" << endl;
        cout << "Player 2: O" << endl;
        game6 game_board(3, 3, '-');
        game_board.display();
        vector<char> player1_s = {'X'};
        vector<char> player2_s = {'O'};
        player<vector<char>> player1(player1_s);
        player<vector<char>> player2(player2_s);
        manage_game6 game_manager(game_board, player1, player2);
        game_manager.take_turn();
    }
    else if (choice == 5) {
        cout << "player1: X" << endl;
        cout << "player2: O" << endl;
        Ultimate_Tic_Tac_Toe_board main_board(3, 3, '-');
        Ultimate_Tic_Tac_Toe_board game_board(3, 3, '-');
        vector<char> player1_s = {'X'};
        vector<char> player2_s = {'O'};
        player<vector<char>> player1(player1_s);
        player<vector<char>> player2(player2_s);
        Ultimate_Tic_Tac_Toe_manage game_board_manager(game_board, player1, player2);
        game_board_manager.take_turn();
    }
    else {
        cout << "Invalid choice! Please select a valid game option." << endl;
    }

    return 0;
}
