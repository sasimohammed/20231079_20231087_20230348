#ifndef TIC_TAC_TOE5_BOARD_H
#define TIC_TAC_TOE5_BOARD_H

#include<iostream>
#include "board.h"
#include "managegame.h"
#include <vector>

using namespace std;

class game5 :  public board<char>
{
    vector<vector<char>> board2;
    int count_player1 ;
    int count_player2 ;


public:


    game5(int rows, int cols, char defaultValue) : board<char>(rows, cols, defaultValue)
    {
        board2={{'-','-','-','-','-'},{'-','-','-','-','-'},{'-','-','-','-','-'},{'-','-','-','-','-'},{'-','-','-','-','-'}};

        count_player1=0;
        count_player2=0;


    }
    void increment_player1(int x)
    {
        count_player1+=x;
    }
    void increment_player2(int x)
    {
        count_player2+=x;
    }

    int getter_player1()
    {
        return count_player1;
    }
    int getter_player2()
    {
        return count_player2;
    }

    bool win_check() override
    {

        if(getter_player1()>getter_player2())
        {
            cout<<"player 1 wins"<<endl;
        }
        else if(getter_player1()<getter_player2())
        {
            cout<<"player 2 wins"<<endl;
        }
        else
        {
            cout<<"TIE"<<endl;
        }
        return true;
    }

    int vertical_check() override
    {
        int counter=0;
        for(int i=1;i<4;i++)
        {
            for(int j=0;j<5;j++)
            {
                if((board1[i][j]==board1[i+1][j] )&& (board1[i][j]==board1[i-1][j])&&board1[i][j]!='-' && (board2[i][j] != '*' || board2[i-1][j] != '*' || board2[i+1][j] != '*'))
                {
                    board2[i][j]='*';
                    board2[i+1][j]='*';
                    board2[i-1][j]='*';
                    counter++;

                }

            }
        }
        return counter;
    }

    int horizontal_check() override
    {
        int count=0;
        for(int i=0;i<5;i++)
        {
            for(int j=1;j<4;j++)
            {
                if((board1[i][j]==board1[i][j+1] )&& (board1[i][j]==board1[i][j-1]) &&board1[i][j]!='-' && (board2[i][j] != '*' || board2[i][j+1] != '*' || board2[i][j-1] != '*'))
                {
                    board2[i][j]='*';
                    board2[i][j+1]='*';
                    board2[i][j-1]='*';
                    count++;
                }
            }

        }
        return count;

    }
    int inc_diagonal_check() override
    {
        int count=0;
        for(int i=2;i<5;i++)
        {
            for(int j=0;j<=2;j++)
            {
                if(((board1[i][j]==board1[i-1][j+1]) && (board1[i][j]==board1[i-2][j+2]) && board1[i][j]!='-' )&&  (board2[i-1][j+1] != '*' || board2[i][j] != '*' || board2[i-2][j+2] != '*'))
                {
                    board2[i][j]='*';
                    board2[i-2][j+2]='*';
                    board2[i-1][j+1]='*';
                    count++;

                }
            }
        }
        return count;
    }

    int  dec_diagonal_check( ) override
    {
        int count=0;
        for(int i=0;i<=2;i++)
        {
            for(int j=0;j<=2;j++)
            {
                if(((board1[i][j]==board1[i+1][j+1]) && (board1[i][j]==board1[i+2][j+2]) &&board1[i][j]!='-' )&& (board2[i][j] != '*' || board2[i+1][j+1] != '*' || board2[i+2][j+2] != '*'))
                {
                    board2[i][j]='*';
                    board2[i+1][j+1]='*';
                    board2[i+2][j+2]='*';
                   count++;
                }
            }
        }
        return count;
    }



    bool check_col(int row, int col) override
    {
        return (board1[row][col] == '-');
    }



};


class manage_game5 : public managegame<char>
{
public:

    manage_game5(game5& board, player<vector<char>>& p1, player<vector<char>>& p2) : managegame<char>(board, p1, p2)
    {

    }

    void set_cell(int row, int col, char value) override
    {
        board1.board1[row][col] = value;
    }

    bool validation_row(int rows)
    {
        if((rows>=0 && rows<5))
        {
            return false;

        }
        else
        {
            return true;
        }
    }

    bool validation_col(int cols) override
    {
        if( (cols>=0 && cols<5))
        {
            return false;

        }
        else
        {
            return true;
        }
    }

    int validation1 (int row)
    {
        while(validation_row(row))
        {
            cout<<"Player 1: enter a valid row number: "<<endl;
            cin>>row;
            row--;
        }

        return row;
    }

    int validation2 (int col)
    {
        while( validation_col(col))
        {
            cout<<"Player 1: enter a valid column number: "<<endl;
            cin>>col;
            col--;
        }
        return col;

    }


    void take_turn() override {
        int row, col;

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

                board1.increment_player1(board1.inc_diagonal_check());

                board1.increment_player1(board1.dec_diagonal_check());
                board1.increment_player1(board1.vertical_check());
                board1.increment_player1(board1.horizontal_check());


                cout<<endl;
                board1.display();

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
                board1.increment_player2(board1.inc_diagonal_check());

                board1.increment_player2(board1.dec_diagonal_check());
                board1.increment_player2(board1.vertical_check());
                board1.increment_player2(board1.horizontal_check());



                cout<<endl;
                board1.display();

            }
        }
        board1.win_check();


    }






};




#endif