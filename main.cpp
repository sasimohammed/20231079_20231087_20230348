#include <iostream>
#include "BoardGame_Classes.h"
#include "Pyramid_X_O.h"
#include "Pyramid_X_O_Smart_Player.h"
#include "SUS_X_O.h"
#include "game3.h"
#include "game6.h"
#include "Four-in-a-row.h"
#include "MinMaxPlayer.h"
#include "Numerical-Tic-Tac-Toe.h"
#include "Ultimate_Try.h"

using namespace std;

string player_name1,player_name2;
int choice3,choice4;

int main() {

    char GC_choice;

    do {
        cout << "Welcome to GameCenter!\n";
        cout << "Choose a game to play: \n";
        cout << "1. Pyramid X-O\n";
        cout << "2. Four-in-a-row X_O\n";
        cout<< "3. 5X5 X-O\n";
        cout<< "5. Numerical X-O\n";
        cout<< "6. Misere X_O\n";
        cout<<"8. Ultimate X_O\n";
        cout<<"9.  SUS X_O\n";
        cout << "0. Exit GameCenter\n";
        cin >> GC_choice;

        switch (GC_choice) {
            case '1':
            {
                char replay_choice;
                do {
                    char choice1;
                    Player<char>* pyramid_players[2];
                    Pyramid_X_O_Board<char>* pyramid_board = new Pyramid_X_O_Board<char>();
                    string pyramidplayer1Name, pyramidplayer2Name;

                    cout << "Welcome to Pyramid X-O Game.\n";
                    do {
                        cout << "Setting up Player 1 (X).. Choose Player 1 type:\n";
                        cout << "1. Human\n";
                        cout << "2. Random Computer\n";
                        cout << "3. Smart Computer (AI)\n";
                        cin >> choice1;
                    } while (choice1 != '1' && choice1 != '2' && choice1 != '3');

                    switch (choice1) {
                        case '1':
                            cout << "Enter Player 1 name (X): ";
                            cin >> pyramidplayer1Name;
                            pyramid_players[0] = new Pyramid_X_O_Player<char>(pyramidplayer1Name, 'X');
                            break;
                        case '2':
                            pyramid_players[0] = new Pyramid_X_O_Random_Player<char>('X');
                            break;
                        case '3':
                            pyramid_players[0] = new Pyramid_X_O_MinMax_Player<char>('X');
                            pyramid_players[0]->setBoard(pyramid_board);
                            break;
                        default:
                            cout << "Invalid choice for Player 1. Exiting Pyramid X-O setup.\n";
                            delete pyramid_board;
                            return 1;
                    }

                    do {
                        cout << "Setting up Player 2 (O).. Choose Player 2 type:\n";
                        cout << "1. Human\n";
                        cout << "2. Random Computer\n";
                        cout << "3. Smart Computer (AI)\n";
                        cin >> choice1;
                    } while (choice1 != '1' && choice1 != '2' && choice1 != '3');

                    switch (choice1) {
                        case '1':
                            cout << "Enter Player 2 name (O): ";
                            cin >> pyramidplayer2Name;
                            pyramid_players[1] = new Pyramid_X_O_Player<char>(pyramidplayer2Name, 'O');
                            break;
                        case '2':
                            pyramid_players[1] = new Pyramid_X_O_Random_Player<char>('O');
                            break;
                        case '3':
                            pyramid_players[1] = new Pyramid_X_O_MinMax_Player<char>('O');
                            pyramid_players[1]->setBoard(pyramid_board);
                            break;
                        default:
                            cout << "Invalid choice for Player 2. Exiting Pyramid X-O setup.\n";
                            delete pyramid_board;
                            for (int i = 0; i < 2; ++i) {
                                delete pyramid_players[i];
                            }
                            return 1;
                    }

                    // Create and run the game
                    GameManager<char> Pyramid_game(pyramid_board, pyramid_players);
                    Pyramid_game.run();

                    // Clean up
                    delete pyramid_board;
                    for (int i = 0; i < 2; ++i) {
                        delete pyramid_players[i];
                    }

                    // Replay prompt
                    cout << "Do you want to:\n";
                    cout << "1. Play the same game again\n";
                    cout << "2. Exit this game\n";
                    cout << "3. Exit GameCenter\n";
                    cin >> replay_choice;

                } while (replay_choice == '1');
                if (replay_choice == '3') {
                    GC_choice = '0'; // Exit GameCenter
                }
                break;
            }
            case '2': {
                char replay_choice;
                do {
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
                        players[1] = new four_in_row_Random_Player<char>('O');
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
                    // Replay prompt
                    cout << "Do you want to:\n";
                    cout << "1. Play the same game again\n";
                    cout << "2. Exit this game\n";
                    cout << "3. Exit GameCenter\n";
                    cin >> replay_choice;

                } while (replay_choice == '1');
                if (replay_choice == '3') {
                    GC_choice = '0'; // Exit GameCenter
                }

                break;
            }
            case '3':
            {
                char replay_choice;
                do {
                int choice;
                Player<char>* players[2];
                _5x5_XO_board<char>*B = new  _5x5_XO_board<char>();
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
                    {
                        players[0] = new  _5x5_XO_Player<char>(playerXName, 'X');
                        player_name1 = playerXName;
                        break;
                    }

                    case 2:
                    {
                        players[0] = new _5x5_XO_Random_Player<char>('X');
                        player_name1 = "Random Computer Player";
                        break;
                    }

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
                        players[1] = new _5x5_XO_Player<char>(player2Name, '0');
                        break;
                    case 2:
                        players[1] = new _5x5_XO_Random_Player<char>('0');
                        break;
                    case 3:

                    default:
                        cout << "Invalid choice for Player 2. Exiting the game.\n";
                        return 1;
                }

                GameManager<char> _5X5_tic_tac_toe(B, players);
                _5X5_tic_tac_toe.run();
                delete B;
                for (int i = 0; i < 2; ++i) {
                    delete players[i];
                }
                    // Replay prompt
                    cout << "Do you want to:\n";
                    cout << "1. Play the same game again\n";
                    cout << "2. Exit this game\n";
                    cout << "3. Exit GameCenter\n";
                    cin >> replay_choice;
                } while (replay_choice == '1');
                if (replay_choice == '3') {
                    GC_choice = '0'; // Exit GameCenter
                }
                break;
            }
            case '4':
            {

            }

            case '5':
            {
                char replay_choice;
                do {
                Player<char>* players[2];
                Numerical_Tic_Tac_Toe_board<char>*B = new  Numerical_Tic_Tac_Toe_board<char>();
                string playerXName, player2Name;

                cout << "Enter Player 1 name: ";
                cin >> playerXName;

                cout << "Choose Player 1 type:\n";
                cout << "1. Human\n";
                cout << "2. Random Computer\n";
                cout << "3. Smart Computer (AI)\n";
                cin >> choice3;
                switch(choice3) {
                    case 1:
                        players[0] = new  Numerical_Tic_Tac_Toe_Player<char>(playerXName, 'X');
                        break;
                    case 2:
                        p=false;
                        players[0] = new Numerical_Tic_Tac_Toe_Random_Player<char>('X');

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
                cin >> choice4;
                switch(choice4) {
                    case 1:
                        players[1] = new Numerical_Tic_Tac_Toe_Player<char>(player2Name, '0');
                        break;
                    case 2:
                        p=true;
                        players[1] = new Numerical_Tic_Tac_Toe_Random_Player<char>('0');
                        break;
                    case 3:

                    default:
                        cout << "Invalid choice for Player 2. Exiting the game.\n";
                        return 1;
                }
                if(choice3==2 &&choice4==2){
                    p=false;
                }
                GameManager<char>  Numerical_Tic_Tac_Toe(B, players);
                Numerical_Tic_Tac_Toe.run();
                delete B;
                for (int i = 0; i < 2; ++i) {
                    delete players[i];
                    }
                    // Replay prompt
                    cout << "Do you want to:\n";
                    cout << "1. Play the same game again\n";
                    cout << "2. Exit this game\n";
                    cout << "3. Exit GameCenter\n";
                    cin >> replay_choice;
                } while (replay_choice == '1');
                if (replay_choice == '3') {
                    GC_choice = '0'; // Exit GameCenter
                }

                break;
            }
            case '6':
            {
                char replay_choice;
                do {
                    int choice;
                    Player<char>* players[2];
                    Misere_XO_board<char>*B = new Misere_XO_board<char>();
                    string playerXName, player2Name;

                    cout << "Enter Player 1 name: ";
                    cin >> playerXName;
                    cout << "Enter Player 2 name: ";
                    cin >> player2Name;
                    player_name1 = playerXName;
                    cout << "Choose Player 1 type:\n";
                    cout << "1. Human\n";
                    cout << "2. Random Computer\n";
                    cout << "3. Smart Computer (AI)\n";
                    cin >> choice;
                    switch(choice) {
                        case 1:
                            players[0] = new  Misere_XO_player<char>(player2Name, 'X');
                            break;
                        case 2:

                            players[0] = new Misere_XO_Random_player<char>('X');

                            break;
                        case 3:

                        default:
                            cout << "Invalid choice for Player 1. Exiting the game.\n";
                            return 1;
                    }
                    // Set up player 2

                    player_name2 = player2Name;
                    cout << "Choose Player 2 type:\n";
                    cout << "1. Human\n";
                    cout << "2. Random Computer\n";
                    cout << "3. Smart Computer (AI)\n";
                    cin >> choice;

                    switch(choice) {
                        case 1:

                            players[1] = new Misere_XO_player<char>(playerXName, '0');
                            break;
                        case 2:
                            players[1] = new Misere_XO_Random_player<char>('0');
                            break;
                        case 3:

                        default:
                            cout << "Invalid choice for Player 2. Exiting the game.\n";
                            return 1;
                    }

                    GameManager<char> Misere_tic_tac_toe(B, players);
                    Misere_tic_tac_toe.run();
                    delete B;
                    for (int i = 0; i < 2; ++i) {
                        delete players[i];
                    }
                    // Replay prompt
                    cout << "Do you want to:\n";
                    cout << "1. Play the same game again\n";
                    cout << "2. Exit this game\n";
                    cout << "3. Exit GameCenter\n";
                    cin >> replay_choice;
                } while (replay_choice == '1');
                if (replay_choice == '3') {
                    GC_choice = '0'; // Exit GameCenter
                }
                break;

            }
            case '8':
            {
                char replay_choice;
                do {
                int choice;
                int choice1;
                Player<char>* players[2];
                ultimate_tic_tac_toe_main_board<char>*B = new  ultimate_tic_tac_toe_main_board<char>();
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
                        players[0] = new ultimate_tic_tac_toe_main_board_player<char>(playerXName, 'X');
                        break;
                    case 2:
                        players[0] = new ultimate_tic_tac_toe_main_board_random_player<char>('X');
                        break;
                    case 3:
//            players[0] = new X_O_MinMax_Player<char>('X');
//            players[0]->setBoard(B);
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
                cin >> choice1;
                switch(choice1) {
                    case 1:
                        players[1] = new ultimate_tic_tac_toe_main_board_player<char>(player2Name, 'O');
                        break;
                    case 2:
                        players[1] = new ultimate_tic_tac_toe_main_board_random_player<char>('O');
                        break;
                    case 3:
//            players[1] = new X_O_MinMax_Player<char>('O');
//            players[1]->setBoard(B);
                        break;
                    default:
                        cout << "Invalid choice for Player 2. Exiting the game.\n";
                        return 1;
                }


                GameManager<char> four_in_row(B, players);
                cout<<"You have 9 boards look like this one (3x3) board so choose your one and start playing ,( boards number from (1-9) )"<<endl;
                B->get_sub_board_num();
                four_in_row.run();
                delete B;
                for (int i = 0; i < 2; ++i) {
                    delete players[i];

                }
                    // Replay prompt
                    cout << "Do you want to:\n";
                    cout << "1. Play the same game again\n";
                    cout << "2. Exit this game\n";
                    cout << "3. Exit GameCenter\n";
                    cin >> replay_choice;
                } while (replay_choice == '1');
                if (replay_choice == '3') {
                    GC_choice = '0'; // Exit GameCenter
                }
                break;
            }
            case '9':
            {
                char replay_choice;
                do {
                    char choice2;
                    Player<char>* SUS_players[2];
                    SUS_X_O_Board<char>* SUS_board = new SUS_X_O_Board<char>();
                    string SUSplayer1Name, SUSplayer2Name;

                    cout << "Welcome to S-U-S X_O Game.\n";

                    do {
                        cout << "Setting up Player 1 (S).. Choose Player 1 type:\n";
                        cout << "1. Human\n";
                        cout << "2. Random Computer\n";
                        cin >> choice2;
                    } while (choice2 != '1' && choice2 != '2');

                    switch (choice2) {
                        case '1':
                            cout << "Enter Player 1 name (S): ";
                            cin >> SUSplayer1Name;
                            SUS_players[0] = new SUS_X_O_Player<char>(SUSplayer1Name, 'S');
                            break;
                        case '2':
                            SUS_players[0] = new SUS_X_O_Random_Player<char>('S');
                            break;
                        default:
                            cout << "Invalid choice for Player 1. Exiting SUS X_O setup.\n";
                            delete SUS_board;
                            return 1;
                    }

                    do {
                        cout << "Setting up Player 2 (U).. Choose Player 2 type:\n";
                        cout << "1. Human\n";
                        cout << "2. Random Computer\n";
                        cin >> choice2;
                    } while (choice2 != '1' && choice2 != '2');

                    switch (choice2) {
                        case '1':
                            cout << "Enter Player 2 name (U): ";
                            cin >> SUSplayer2Name;
                            SUS_players[1] = new SUS_X_O_Player<char>(SUSplayer2Name, 'U');
                            break;
                        case '2':
                            SUS_players[1] = new SUS_X_O_Random_Player<char>('U');
                            break;
                        default:
                            cout << "Invalid choice for Player 2. Exiting SUS X_O setup.\n";
                            delete SUS_board;
                            for (int i = 0; i < 2; ++i) {
                                delete SUS_players[i];
                            }
                            return 1;
                    }

                    // Create and run the game
                    GameManager<char> SUS_game(SUS_board, SUS_players);
                    SUS_game.run();

                    // Clean up
                    delete SUS_board;
                    for (int i = 0; i < 2; ++i) {
                        delete SUS_players[i];
                    }

                    // Replay prompt
                    cout << "Do you want to:\n";
                    cout << "1. Play the same game again\n";
                    cout << "2. Exit this game\n";
                    cout << "3. Exit GameCenter\n";
                    cin >> replay_choice;

                } while (replay_choice == '1');
                if (replay_choice == '3') {
                    GC_choice = '0'; // Exit GameCenter
                }
                break;
            }
            case '0':
                cout << "Exiting GameCenter...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (GC_choice != '0');

    return 0;
}
