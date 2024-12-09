#include <iostream>
#include "BoardGame_Classes.h"
#include "Pyramid_X_O.h"
#include "Pyramid_X_O_Smart_Player.h"
#include "SUS_X_O.h"
using namespace std;

int main() {
    char GC_choice;

    do {
        cout << "Welcome to GameCenter!\n";
        cout << "Choose a game to play: \n";
        cout << "1. Pyramid X-O\n";
        cout << "2. SUS X_O\n";
        cout << "3. Exit GameCenter\n";
        cin >> GC_choice;

        switch (GC_choice) {
            case '1': {
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
                    GC_choice = '3'; // Exit GameCenter
                }
                break;
            }
            case '2': {
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
                    GC_choice = '3'; // Exit GameCenter
                }
                break;
            }
            case '3':
                cout << "Exiting GameCenter...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (GC_choice != '3');

    return 0;
}
