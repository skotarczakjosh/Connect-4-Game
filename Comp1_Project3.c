//##########################################################################################
//##
//## Title : DESIGN PROJECT 3
//## Course : CPET 121: COMPUTATINAL PROBLEM SOLVING 1
//## DEVELOPER: Joshua Skotarczak
//## Date: 10-26-2020
//## Description: FOUR-IN-A-ROW GAME
//##
//##########################################################################################
// LIBRARIES
#include<iomanip>
#include<iostream>
#include<cstdlib> // included for random number generator
#include<ctime>  //  included for randon number generator
// CONSTANTS
#define R 6
#define C 7
using namespace std;
//##########################################################################################
//Prototypes
void displaymessage();  //FOR DISPALY MESSAGE
void gameboard(char board[R][C]); // MAKES GAME BOARD
void Eraseboard(char board[R][C]); // CLEARS BOARD AFTER RESET
int CorrectInputPlayer1(int Player1Input); // CHECKS FOR CORRECT PLAYER 1 INPUT
int CorrectInputPlayer2(int Player2Input); // CHECKS FOR CORRECT PLAYER 2 INPUT
int FullColumnP1(char board[R][C], int Player1Input); // CHECKS IF COLUMN IS FULL FOR PLAYER 1
int FullColumnP2(char board[R][C], int Player2Input); // CHECKS IF COLUMN IS FULL FOR PLAYER 2
int Player1Win(char board[R][C]); // CHECKS FOR PLAYER 1 WIN
int Player2Win(char board[R][C]); // CHECKS FOR PLAYER 2 WIN
int Player1Drop(int Player1Input, char board[R][C]); // PLACES PLAYER 1 PEICE
int Player2Drop(int Player2Input, char board[R][C]); // PLACES PLAYER 2 PEICE
//##########################################################################################
//MAIN
int main(){
char board[R][C];       // For Game Board
int Player1Input;       //Player One Input
int Player2Input;       //Player Two Input
int P1_ValidInput;      //Checks For Valid Player Input
int P2_ValidInput;      //Checks for Valid Player Input
char reset = 'y';          //Checks for Reset of the Game
bool GameActive = true; //Checks if Game is Currently in Progress
int p1_wins = 0;        //If Player 1 Wins Asks If They Want to Play Again
int p2_wins = 0;        //If Player 2 Wins Asks If They Want to Play Again
int PiecesPlaced = 0;   //Keeps Track of Pieces Placed if 42 means Tie
int tallyP1Wins = 0;    // Tally Player 1 Wins
int tallyP2Wins = 0;    // Tally Player 2 Wins
int tallyGameTies = 0;   // Tally Game Ties
bool columnFreeP1 = false; // If Column is Free for Player 1
bool columnFreeP2 = false; // If Column is Free for Player 2
srand(time(NULL)); // Needed for Random Player Selection
int player =rand ()% 2 + 1; //Random Number Generator 1 or 2
displaymessage();  // DISPLAYS WELCOME MESSAGE
    cout<<"Player #"<<player<<" was selected to go first"<<endl<<endl; //Shows Which player was chosen to go first
   Eraseboard(board);
 gameboard(board);

 // GAME LOOP
    while (GameActive == true) //While Game is Active
	{
    	if(player== 1)  // IF Player Is 1 To Start it chooses this Loop
    	{
    	while(reset == 'Y' || reset == 'y')
    	{
			while((p1_wins == 0)&&(p2_wins == 0)&&(PiecesPlaced != 42))
			{
				while(columnFreeP1== false)
				{
					cout<<"Player #1's Turn (X) : Enter Your Move :";
					cin>> Player1Input;
					P1_ValidInput = CorrectInputPlayer1(Player1Input);
					while(P1_ValidInput == 0)
						{
							cout<<"Illegal Position, Please Reenter:";
							cin>>Player1Input;
							P1_ValidInput = CorrectInputPlayer1(Player1Input);
						}
					columnFreeP1= FullColumnP1(board,Player1Input);
					Player1Drop(Player1Input, board);
						break;
				}
				columnFreeP1= false;
				p1_wins = Player1Win(board);
				if(p1_wins == 1)
					{
						tallyP1Wins  = tallyP1Wins  + 1;
						break;
					}
					PiecesPlaced ++ ;
				while(columnFreeP2 == false)
				{
					cout<<"Player #2's Turn (O) : Enter Your Move :";
					cin>> Player2Input;
					P2_ValidInput = CorrectInputPlayer2(Player2Input);
					while(P2_ValidInput == 0)
						{
							cout<<"Illegal Position, Please Reenter:";
							cin>>Player2Input;
							P2_ValidInput = CorrectInputPlayer2(Player2Input);
						}
					columnFreeP2 = FullColumnP2(board,Player2Input);
					Player2Drop(Player2Input, board);
					p2_wins = Player2Win(board);
						if(p2_wins == 1)
						{
							tallyP2Wins  = tallyP2Wins  + 1;
							break;
						}
						PiecesPlaced ++ ;
						break;
				}
						columnFreeP2 = false;
			}
		   if(PiecesPlaced == 42)
		   {
			   tallyGameTies ++ ;
			   cout<<"The Game Ended In a Tie"<<endl<<endl<<endl;
			   cout<<"Would You Like To Play Again [Y/N]";
			   cin>> reset;
			   if(reset == 'Y' || reset == 'y')
				   {
					   Eraseboard(board);
					   gameboard(board);
					   p1_wins = 0;
					   p2_wins = 0;
					   PiecesPlaced = 0;
				   }
				   if(reset == 'N' || reset == 'n')
				   {
                   GameActive = false;
				   }
		   }
		   if(p1_wins == 1)
		   {
			   cout<<"Player 1 won!"<<endl<<endl<<endl;
			   cout<<"Would You Like To Play Again [Y/N]";
			   cin>> reset;
			   if(reset == 'Y' || reset == 'y')
				   {
					   Eraseboard(board);
					   gameboard(board);
					   p1_wins = 0;
					   p2_wins = 0;
					   PiecesPlaced = 0;
				   }
				   if(reset == 'N' || reset == 'n')
				   {
                   GameActive = false;
				   }

		   }
		   if(p2_wins == 1)
		   {
			   cout<<"Player #2 Was The Winner"<<endl<<endl<<endl;
			   cout<<"Would You Like To Play Again [Y/N]";
			   cin>> reset;
			   if(reset == 'Y' || reset == 'y')
				   {
					   Eraseboard(board);
					   gameboard(board);
					   p1_wins = 0;
					   p2_wins = 0;
					   PiecesPlaced = 0;
				   }
				   if(reset == 'N' || reset == 'n')
				   {
                   GameActive = false;
				   }
		   	   }
            break;
    		}
    	}
    	if(player== 2) // If Player is 2 Than Its It Chooses This Place Loop
    	{
        	while(reset == 'Y' || reset == 'y')
        	{
    			while((p1_wins == 0)&&(p2_wins == 0)&&(PiecesPlaced != 42))
    			{
    				while(columnFreeP2 == false)
    				{
					cout<<"Player #2's Turn (O) : Enter Your Move :";
					cin>> Player2Input;
					P2_ValidInput = CorrectInputPlayer2(Player2Input);
					while(P2_ValidInput == 0)
    						{
    							cout<<"Illegal Position, Please Reenter";
    							cin>>Player2Input;
    							P2_ValidInput = CorrectInputPlayer2(Player2Input);
    						}
    					columnFreeP2 = FullColumnP2(board,Player2Input);
    					Player2Drop(Player2Input, board);
    						break;
    				}
    				columnFreeP2 = false;
    				p2_wins = Player2Win(board);
    				if(p2_wins == 1)
    					{
    						tallyP2Wins  = tallyP2Wins  + 1;
    						break;
    					}
    					PiecesPlaced = PiecesPlaced + 1 ;
    				while(columnFreeP1== false)
    				{
    					cout<<"Player #1's Turn (X) : Enter Your Move :";
    					cin>> Player1Input;
    					P1_ValidInput = CorrectInputPlayer1(Player1Input);
    					while(P1_ValidInput == 0)
    						{
    							cout<<"Illegal Position, Please Reenter:";
    							cin>>Player1Input;
    							P1_ValidInput = CorrectInputPlayer1(Player1Input);
    						}
    					columnFreeP1= FullColumnP2(board,Player1Input);
    					Player1Drop(Player1Input, board);
    					p1_wins = Player1Win(board);
    						if(p1_wins == 1)
    						{
    							tallyP1Wins  = tallyP1Wins  + 1;
    							break;
    						}
    						PiecesPlaced++ ;
    						break;
    				}
    					columnFreeP1= false;
    			}
    		   if(PiecesPlaced == 42)
    		   {
    			   tallyGameTies ++ ;
    			   cout<<"The GameActive Ended In A Tie"<<endl<<endl;
    			   cout<<"Would You Like To Play Again [Y/N]";
    			   cin>> reset;
    			   if(reset == 1)
    				   {
    					   Eraseboard(board);
    					   gameboard(board);
    					   p1_wins = 0;
    					   p2_wins = 0;
    					   PiecesPlaced = 0;
    				   }
    				   if(reset == 2)
    				   {
    					   GameActive = false;
    				   }
    		   }
    		   if(p1_wins == 1)
    		   {
    			   cout<<"Player #1 Was the Winner"<<endl<<endl<<endl;
    			   cout<<"Would You Like To Play Again [Y/N]";
    			   cin>> reset;
    			   if(reset == 'Y' || reset == 'y')
    				   {
    					   Eraseboard(board);
    					   gameboard(board);
    					   p1_wins = 0;
    					   p2_wins = 0;
    					   PiecesPlaced = 0;
    				   }
    				   if(reset == 'N' || reset == 'n')
    				   {
                       GameActive = false;
    				   }
    		   }
    		   if(p2_wins == 1)
    		   {
    			   cout<<"Player #2 Was The Winner"<<endl<<endl<<endl;
    			   cout<<"Would You Like To Play Again [Y/N]";
    			   cin>> reset;
    			   if(reset == 'Y' || reset == 'y')
    				   {
    					   Eraseboard(board);
    					   gameboard(board);
    					   p1_wins = 0;
    					   p2_wins = 0;
    					   PiecesPlaced = 0;
    				   }
    				   if(reset == 'N' || reset == 'n')
    				   {
    					   GameActive = false;
    				   }
    		   }
                break;
        	}
    	}
	}
    cout<<"#############ScoreBoard###############"<<endl;
    cout<<"        Player 1 Score : " << tallyP1Wins<<endl;
    cout<<"        Player 2 Score : " << tallyP2Wins<<endl;
    cout<<"        Number of Ties : "<<tallyGameTies<<endl;
}
//##########################################################################################
// Draw GameBoard
void gameboard(char board[R][C])
{
    {
	cout<<"  1   2   3   4   5   6   7"<<endl<<endl;
	for(int i = 0; i < 6; i ++)
	{
		cout<<"|";
		for(int j = 0; j < 7; j ++)
		{
			cout<<" "<< board[i][j]<<" |";
		}
		cout<<endl;
        cout<<"+---+---+---+---+---+---+---+"<<endl;
	}
}
}
//##########################################################################################
// EraseBoard
void Eraseboard(char board[R][C])
{
for(int j = 0; j < 6; j++)
{
    for(int k = 0; k < 7; k++ )
    {
        board[j][k] = ' ';
        }
    }
}
//##########################################################################################
//Display Message
void displaymessage()
{
cout<<endl;
cout<<"           Welcome to Four-in-a-Row           "<<endl;
cout<<" The goal of Four-in-a-Row is to be the first "<<endl;
cout<<"player to place four checkers in a row, either"<<endl;
cout<<"   horizontally, vertically or diagonally.    "<<endl;
cout<<endl<<endl;
}
//##########################################################################################
// Check For Full Column For Player 1

int FullColumnP1(char board[R][C], int Player1Input)
{
    bool columnFreeP1 = false;
    if((board[0][Player1Input - 1] == 'X') || (board[0][Player1Input -1 ] == 'O'))
    {
        columnFreeP1 = true;
        cout<<"Move Not Available, You Lost Your Turn"<<endl;
    }
    else
    {
        columnFreeP1 = false;
    }
    return columnFreeP1;
}
//##########################################################################################
// Check For Full Column For Player 2
int FullColumnP2(char board[R][C], int Player2Input)
{
    bool columnFreeP2 = false;
    if((board[0][Player2Input - 1] == 'X') || (board[0][Player2Input -1 ] == 'O'))
    {
        columnFreeP2 = true;
        cout<<"Move Not Available, You Lost Your Turn"<<endl;
    }
    else
    {
        columnFreeP2 = false;
    }
    return columnFreeP2;
}
//##########################################################################################
// Check For Vaild Input Player 1
int CorrectInputPlayer1(int Player1Input)
{
    int P1_ValidInput = 0;
    if ((Player1Input < 1) || (Player1Input > 7))
    {
        P1_ValidInput = 0;
    }
    else
    {
        P1_ValidInput = 1;
    }
    return (P1_ValidInput);
}
//##########################################################################################
// Place X into Gameboard
int Player1Drop(int Player1Input, char board[R][C])
{
switch(Player1Input)
	{
case 1:
    case 2:
        case 3 :
            case 4:
               case 5:
                   case 6:
	                  case 7:	for(int j = 5; j >=0; j --)
			{
				char Space = board[j][Player1Input - 1];
				if ((Space == 'X')||(Space == 'O'))
				{

				}
				else
				{
					board[j][Player1Input - 1] = 'X';
					gameboard(board);
					break;
				}
			}

	break;
}
}
//#########################################################################################
// Correct Player 2 Input
int CorrectInputPlayer2(int Player2Input)
{
   int P2_ValidInput = 0;
    if ((Player2Input < 1) || (Player2Input > 7))
    {
        P2_ValidInput = 0;
    }
    else
    {
        P2_ValidInput = 1;
    }
    return P2_ValidInput;
}
//#########################################################################################
//Place O into Gameboard
int Player2Drop(int Player2Input, char board[R][C])
{
switch(Player2Input)
	{
case 1:
    case 2:
        case 3 :
            case 4:
               case 5:
                   case 6:
	                  case 7:	for(int j = 5; j >=0; j --)
			{
				char Space = board[j][Player2Input - 1];
				if ((Space == 'X')||(Space == 'O'))
				{

				}
				else
				{
					board[j][Player2Input - 1] = 'O';
					gameboard(board);
					break;
				}
			}

	break;
}
}
//#########################################################################################
// Check For Player 1 Wins
int Player1Win(char board[R][C])
{
   int p1_win = 0;

   for (int j = 0; j< R; j ++)
   {
       for(int k = 0; k < C; k++)
       {
           if((board[j][k] == 'X') && (board[j +1][k] == 'X') && (board[j + 2][k] == 'X') && (board[j + 3][k] == 'X')) //Vertical
       {
            p1_win = 1;
       }
   if((board[j][k] == 'X') && (board[j][k + 1] == 'X') && (board[j][k + 2] == 'X') && (board[j][k +3] == 'X')) // Horizontal
    {
    p1_win = 1;
    }
    if((board[j][k] == 'X') && (board[j - 1 ][k +1] == 'X') && (board[j - 2][k + 2] == 'X') && (board[j - 3][k + 3] == 'X')) // Diagonal Right
    {
        p1_win = 1;
    }
    if((board[j][k] == 'X') && (board[j - 1 ][k -1] == 'X') && (board[j - 2][k - 2] == 'X') && (board[j - 3][k -3] == 'X')) // Diagonal Left
    {
        p1_win = 1;
    }
       }
   }
   return p1_win;
}

//#########################################################################################
// Check For Player 2 Wins
int Player2Win(char board[R][C])
{
   int p2_win = 0;

   for (int j = 0; j< R; j ++)
   {
       for(int k = 0; k < C; k++)
       {
           if((board[j][k] == 'O') && (board[j + 1][k] == 'O') && (board[j + 2][k] == 'O') && (board[j + 3][k] == 'O')) //Vertical
       {
            p2_win = 1;
       }
   if((board[j][k] == 'O') && (board[j][k + 1] == 'O') && (board[j][k + 2] == 'O') && (board[j][k +3] == 'O')) // Horizontal
    {
    p2_win = 1;
    }
    if((board[j][k] == 'O') && (board[j - 1 ][k +1] == 'O') && (board[j - 2][k + 2] == 'O') && (board[j - 3][k +3] == 'O')) // Diagonal Right
    {
        p2_win = 1;
    }
     if((board[j][k] == 'O') && (board[j - 1 ][k - 1] == 'O') && (board[j -2][k - 2] == 'O') && (board[j - 3][k -3] == 'O')) // Diagonal Left
    {
        p2_win = 1;
    }
       }
   }
   return p2_win;
}
//#######################################################################################
