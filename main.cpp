#include<iostream>
using namespace std;

char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char current_marker;
int current_player;
void drawboard()
{

    cout<<" "<<board[0][0]<<" | "<< board[0][1]<<" | "<<board[0][2]<<"\n";
    cout<<"__________\n";
    cout<<" "<<board[1][0]<<" | "<< board[1][1]<<" | "<<board[1][2]<<"\n";
    cout<<"__________\n";
    cout<<" "<<board[2][0]<<" | "<< board[2][1]<<" | "<<board[2][2]<<"\n";
    cout<<"__________\n";

}
bool placemarker( int slot)
{
    int row,col;
    if(slot%3==0)
    {
        row=(slot/3)-1;
        col=2;
    }
    else
    {
        row=slot/3;
        col=(slot%3)-1;
    }


     if(board[row][col]!= 'x' && board[row][col]!='0')
     {
         board[row][col]=current_marker;
         return true;
     }
     else
        return false;

}
int  winner()
{

    for(int i=0;i<3;i++)
    {
    if(board[i][0]==board[i][1] && board [i][1]==board[i][2]) return current_player;
    if(board[0][i]==board[1][i] && board [1][i]==board[2][i]) return current_player;
    }
        if(board[0][0]==board[1][1] && board [1][1]==board[2][2])
        return current_player;
        if(board[2][0]==board[1][1] && board [1][1]==board[0][2])
        return current_player;

        return 0;
}
void swap_p()
{
    if (current_marker=='x')
        current_marker='0';
    else

        current_marker='x';
    if (current_player==1)
        current_player=2;
    else
        current_player=1;
}
void game()
{
cout<<"Player 1,choose your marker: \n";
char marker_p1;
cin>>marker_p1;
current_player=1;
current_marker=marker_p1;
drawboard();
int player_won;

    for(int i = 0; i < 9; i++)
    {
        cout << "It`s player " << current_player << "`s turn. Enter your slot: ";
        int slot;
        cin >> slot;
        if(slot<1 ||slot>9)
        {
           cout<<"This slot is invalid.Try another slot\n";
            i--;
            continue;
        }
         if (!placemarker(slot))
         {
            cout<<"This slot is occupied.Try another slot\n";
            i--;
            continue;
         }
         drawboard();
         player_won=winner();

        if(player_won == 1)
        {
            cout << "Player one won! Congratulations!";
              break;
        }
        if(player_won == 2)
        {
            cout << "Player two won! Congratulations!"; break;
        }
           swap_p();

    }
    if(player_won == 0)
    {
        cout << "That is a Tie!";
    }


}

int main()

{
    drawboard();
   game();

    return 0;
}
