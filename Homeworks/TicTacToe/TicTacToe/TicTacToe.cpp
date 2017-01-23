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
}