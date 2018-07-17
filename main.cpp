#include <iostream>
#include<cstdlib>
using namespace std;

int choice;
    char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    char Turn ;
    int row, column;
    bool draw =false;



int display_board() {
    cout << "   T I C  T A C  G A M E  " << endl;
    cout<<"================================="<<endl;
    cout<<"   PLAYER 1 = [x]" <<endl;

    cout<<"   PLAYER 2 = [o]"<< endl;


    cout<<"\n";
    cout<<"     "<<"     |       |       "<<endl;
    cout<<"     "<<"  "<<board[0][0]<<"  |   "<<board[0][1]<<"   |   "<<board[0][2]<<"   "<<endl;
    cout<<"   "<<"_______|_______|_______"<<endl;
    cout<<"     "<<"     |       |       "<<endl;
    cout<<"     "<<"  "<<board[1][0]<<"  |   "<<board[1][1]<<"   |   "<<board[1][2]<<"   "<<endl;
    cout<<"   "<<"_______|_______|_______"<<endl;
    cout<<"     "<<"     |       |       "<<endl;
    cout<<"     "<<"  "<<board[2][0]<<"  |   "<<board[2][1]<<"   |   "<<board[2][2]<<"   "<<endl;
    cout<<"     "<<"     |       |       "<<endl;
    cout<<"\n";
return 0;

};

int turn() {


    if(Turn == 'o'){
    cout<< " PLAYER 1 turn"<<endl;
    Turn ='x';
    }


    else if (Turn == 'x'){
    cout<< " PLAYER 2 turn "<<endl;
    Turn = 'o';
    }
    return 0;
  }
bool game_over(){



    for(int i=0;i<3;i++)
    {
        if((board[i][0]==board[i][1]&&board[i][1]==board[i][2])||(board[0][i]==board[1][i]&&board[1][i]==board[2][i])||(board[0][0]==board[1][1]&&board[1][1]==board[2][2])||(board[2][0]==board[1][1]&&board[1][1]==board[0][2]))
        {
        return false;
        }
    }

     for(int i=0;i<3;i++)
     {
        for(int j=0;j<3;j++)
        {
            if (board[i][j]!='x')
            {
                if(board[i][j]!='o')
                {
                    return true;
                }
            }
            else if (board[i][j]!='o')
            {
                if(board[i][j]!='x')
                {
                    return true;
                }
            }
        }
    }
    cout<<"Game Drawn!!\n";
    draw = true;
    return false;

}
int player_turn() {
    cin>>choice;
    switch(choice){
        case 1 :
            row = 0 ; column = 0;
            break;
        case 2 :
            row = 0 ; column = 1;

            break;
        case 3 :
            row = 0 ; column = 2;
            break;
        case 4 :
            row = 1 ; column = 0;
            break;
        case 5 :
            row = 1 ; column = 1;
            break;
        case 6 :
            row = 1 ; column = 2;
            break;
        case  7:
            row = 2 ; column = 0;
            break;
        case 8 :
            row = 2 ; column = 1;
            break;
        case 9 :
            row = 2 ; column = 2;
            break;
        default:
            cout<<" invalid entry";

    }
            if(Turn =='x'&& board[row][column]!='x'&& board[row][column]!='o')  {
             board[row][column]='x';

             }
            else if(Turn =='o'&& board[row][column]!='x'&& board[row][column]!='o') {
             board[row][column]='o';
            }
            else {

            cout<<"already entered\n please try again\n";
            cout<<"====================================="<<endl;
            player_turn();
            }

        display_board();

    return 0;

};



int main()
{

    Turn = 'o';
    while(game_over()){
    display_board();
    turn();
    player_turn();
    }

    if(Turn == 'x'&& draw == false)
    cout<<"Player1 !!!!!!!!!! wins congratulations"<<endl;
    if(Turn == 'o'&& draw == false)
    cout<<"Player2 !!!!!!!!!! wins congratulations"<<endl;
    if(draw == true)
    cout<<"game is draw";

    return 0;
}
