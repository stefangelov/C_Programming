/* This is The Game Tic Tac Toe*/
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
//This array will be the 3 by 3 game board
char arr[3][3] = { { ' ', ' ', ' ' },
{ ' ', ' ', ' ' },
{ ' ', ' ', ' ' } };
//These are the two Players respective X and 0
char player1 = 'X';
char player2 = '0';
//This variable holds the player which needs to make his turn
char activePlayer;
//
bool positionFree;
//This variable holds the position selected by the active player
int position;

// NEW GLOBAL VARIABLE
// hold how many times has chosen position
int choiseCounter = 0;

/*
|X|
-+-+-
0| |
-+-+-
0| |X
*/
// 'X'
// '0'
// ' '
// 1 2 3
// 4 5 6
// 7 8 9

void drawChartA(); //Function that draws the array to game board the simple way
void drawChartB(); //Function that draws the array to game board the prety way
void drawPositions(); //This functions display the position 1 to 9 that the players need to enter
void switchPlayer(); //This function changes the active player to the one that need to makes his/her turn
bool insertChar(char player, int position); // This function inserts 'X' or '0' depends on the active player to the corresponding position
void randomizePlayers(); // Indicates which players star first
bool isGameFinished(); // Indicates whether there is a winner or game is draw


void main() {
	// to be first player choice really random
	srand(time(NULL));
	drawPositions();

	

	while (! isGameFinished())
	{
		choiseCounter++; //Increase the times that make choise
		system("cls"); // clear screen
		drawChartA(); // draw chart with selected positions
		// 
		cout << endl << "Now playing player " << (activePlayer == 'X' ? "Player 1 - " : "Player 2 - '") << activePlayer << "\'" << endl;
		
		// ask User for choise of position
		do
		{
			cout << endl << "Please select position: ";
			cin >> position;
			positionFree = insertChar(activePlayer, position);
		} while ( ! positionFree );

		// swich players
		switchPlayer();
	}

	cout << endl;
	drawChartA();

	// mesage for Game over
	cout << endl << "G A M E  I S  O V E R !" << endl << endl;

	if (!isGameFinished() && choiseCounter == 9 )
	{
		cout << "\tNO Winner!" << endl << endl;
	}
	else
	{
		switchPlayer(); // siwch players to be active winner playwer
		cout << "\t*** The winner is " << (activePlayer == 'X' ? "Player 1 - " : "Player 2 - ") << activePlayer << " ***" << endl << endl;
	}

}

void drawPositions() {
	cout << "This is simpe Tic Tak Toe  Game played by two player." << endl;
	cout << "The one player put \'0\' and the other \'X\'" << endl << endl;
	
	cout << "Sample view of game board:" << endl << endl;
	cout << "\t |X| " << endl 
		 << "\t-+-+-" << endl 
		 << "\t0| | " << endl 
		 << "\t-+-+-" << endl 
		 << "\t0| |X" << endl << endl;
	
	cout << "Posible position numbers are:" << endl << endl;
	cout << "\t1|2|3" << endl
		<< "\t-+-+-" << endl
		<< "\t4|5|6" << endl
		<< "\t-+-+-" << endl
		<< "\t7|8|9" << endl << endl;

	// insert Player sumbols
	cout << "\tPlayer 1 - \'" << player1 << "\'" << endl;
	cout << "\tPlayer 2 - \'" << player2 << "\'" << endl << endl;

	// set first player
	randomizePlayers();
	cout << "First player to play: " << (activePlayer == 'X' ? "Player 1 - " : "Player 2 - ") << "'" << activePlayer << "'"<< endl << endl;
	cout << "To continue pres eny key..." << endl;
	
	// wait for user to pres key
	getchar();
}

void drawChartA(){
	for (int i = 0; i < 3; i++)
	{
		if (i > 0)
		{
			cout << "\t-+-+-" << endl;
		}
		cout << "\t";
		for (int j = 0; j < 3; j++)
		{
			if (j % 2 == 0)
			{
				cout << arr[i][j];
			}
			else
			{
				cout << "|" << arr[i][j] << "|";
			}
		}
		cout << endl;
	}
}

void drawChartB(){
	// Not Implement
}

void randomizePlayers() {
	if (rand() % 2 != 0)
	{
		activePlayer = player1;
	}
	else
	{
		activePlayer = player2;
	}
}

bool isGameFinished(){
	// check how meny times has played
	if (choiseCounter == 9)
	{
		return true;
	}

	// check rows
	for (int i = 0; i < 3; i++)
	{
		if (' ' != arr[i][0] && 
			arr[i][0] == arr[i][1] && 
			arr[i][1] == arr[i][2])
		{
			return true;
		}
	}
	
	// check colums
	for (int i = 0; i < 3; i++)
	{
		if (' ' != arr[0][i] && 
			arr[0][i] == arr[1][i] && 
			arr[1][i] == arr[2][i])
		{
			return true;
		}
	}

	// check diagonals
	if (' ' != arr[0][0] && 
		arr[0][0] == arr[1][1] &&
		arr[1][1] == arr[2][2])
	{
		return true;
	}
	if (' ' != arr[0][2] &&
		arr[0][2] == arr[1][1] &&
		arr[1][1] == arr[2][0])
	{
		return true;
	}

	// in all other cases return false
	return false;
}

bool insertChar(char player, int position){
	// check if choise is in range 1 - 9
	if (position < 1 || position > 9 )
	{
		cout << "Your choise must be in range 1 - 9 !" << endl;
		return false;
	}

	// check if the position is free
	int posCounter = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			posCounter++;
			if (posCounter == position)
			{
				if (arr[i][j] != ' ')
				{
					cout << "Position " << position << " not available" << endl;
					return false;
				}
				else
				{
					arr[i][j] = player;
					return true;
				}
			}
		}
	}
}

void switchPlayer(){
	activePlayer == player1 ? activePlayer = player2 : activePlayer = player1;
}