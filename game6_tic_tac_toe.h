#ifndef GAME6_TIC_TAC_TOE_H
#define GAME6_TIC_TAC_TOE_H

#include <iostream>
#include "board.h"
#include "managegame.h"
using namespace std;

class game6 : public board<char>
{
public:
    game6(int row,int col, char defaultValue) : board<char>(row,col,defaultValue)
    {

    }

    bool horizontal_check6()
    {
        for(int i=0;i<3;i++)
        {
            if(board1[i][0] == board1[i][1] && board1[i][0] == board1[i][2] && board1[i][0] != '-')
            {
                return true;
            }
        }
        return false;

    }

    bool vertical_check6()
    {
        for(int j=0;j<3;j++)
        {
            if(board1[0][j] == board1[1][j] && board1[0][j] == board1[2][j] && board1[0][j] != '-')
            {
                return true;
            }
        }
        return false;

    }
    bool diagonal1()
    {
        if(board1[0][0]==board1[1][1] && board1[0][0]==board1[2][2] && board1[0][0]!='-')
        {
            return true;
        }
        else
        {
            return false;

        }
    }

    bool diagonal2()
    {
        if(board1[0][2]==board1[1][1] && board1[0][2]==board1[2][0] && board1[0][2]!='-')
        {
            return true;
        }
        else
        {
            return false;

        }
    }

    bool win_check() override
    {
        if(horizontal_check6() || vertical_check6() || diagonal1() || diagonal2())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool check_col(int row, int col)
    {
        return (board1[row][col] == '-');
    };



};


class manage_game6 : public managegame<char>
{
public:
    manage_game6(game6& board, player<vector<char>>& p1, player<vector<char>>& p2) : managegame<char>(board, p1, p2)
    {

    }
    void set_cell(int row, int col, int  value) override
    {

    }
    bool validation_col(int cols) override
    {
        if(cols>=0 && cols<3)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    bool validation_row(int row) override
    {
        if(row>=0 && row<3)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    int validation1 (int row) override
    {
        while(validation_row(row))
        {
            cout<<"Player 1: enter a valid row number: "<<endl;
            cin>>row;
            row--;
        }

        return row;
    }

    int validation2 (int col) override
    {
        while( validation_col(col))
        {
            cout<<"Player 1: enter a valid column number: "<<endl;
            cin>>col;
            col--;
        }
        return col;

    }


    void set_cell(int row, int col, char value) override
    {
        board1.board1[row][col] = value;
    }
    void take_turn() override
    {
        int row,col;
        for (int i = 0; i < (board1.r * board1.c); i++) {
            if (i % 2 == 0) {
                cout << "Player 1: enter row number: ";
                cin >> row;
                row--;
                row= validation1(row);

                cout << "Player 1: enter column number: ";
                cin >> col;

                col--;


                col = validation2(col);



                while (!board1.check_col(row, col)) {
                    cout << "player 1: this place was taken enter another position: ";
                    cout << "Player 1: enter row number: ";
                    cin >> row;
                    row--;
                    row= validation1(row);

                    cout << "Player 1: enter column number: ";
                    cin >> col;

                    col--;


                    col = validation2(col);


                }

                set_cell(row,col, player1.get_symbol()[0]);




                cout<<endl;
                board1.display();
                if(board1.win_check())
                {
                    cout<<"player2 wins"<<endl;
                    break;
                }

            }
            else
            {
                cout << "Player 2: enter row number: ";
                cin >> row;
                row--;
                row= validation1(row);

                cout << "Player 2: enter column number: ";
                cin >> col;

                col--;


                col = validation2(col);


                while (!board1.check_col(row, col)) {
                    cout << "player 2: this place was taken enter another position: ";
                    cout << "Player 2: enter row number: ";
                    cin >> row;
                    row--;
                    row= validation1(row);

                    cout << "Player 2: enter column number: ";
                    cin >> col;

                    col--;


                    col = validation2(col);


                }
                set_cell(row,col, player2.get_symbol()[0]);



                cout<<endl;
                board1.display();
                if(board1.win_check())
                {
                    cout<<"player1 wins"<<endl;
                    break;
                }

            }
        }



    }

};

#endif