
/*
This is an animated version of the algorithm 
for solving Tower of Hanoi problem.

User need to enter number of the disks and 
the delays between stages in seconds.

If User choose '0' for the delay will be 
necessary to press key for each stage of 
the solution.
*/

#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

#pragma region UI   
string startArr[64];  // hold infor for firs rod
string *A = startArr; // pointer to first rod
int numDisk_A = 0;	  // number of disk of first rod
int *An = &numDisk_A; // pointer to numbers of disk on first rod

string midArr[64];     // hold infor for second rod
string *B = midArr;	   // pointer to second rod
int numDisk_B = 0;	   // number of disk of second rod
int * Bn = &numDisk_B; // pointer to numbers of disk on second rod

string endArr[64];     // hold infor for third rod
string *C = endArr;	   // pointer to third rod
int numDisk_C = 0;	   // number of disk of third rod
int *Cn = &numDisk_C;  // pointer to numbers of disk on third rod

// hold number of iterations
int numberOfIterations = 0;

// user choise about number of disks
int uChND;

// user choise about delay betwenn iterations
int moveDelay = 0; 
#pragma endregion GlobalVariables

#pragma region Functions
// User interface :)
void UI();
// Print explanation for this APP
void ExpNotePrint();
// Load strings in firs rod arr
void LoadStartArr();
// Print all rods with them disks on console
void PrintScheme();
// Function which is responsible for the delay 
void MoveDelay();
// Function that implement the Tower of Hanoi Solve (TOHS) 
void TOHS(int, string *, string *, string *, int *, int *, int *);
// Function that implement disk moving from one to other rot
void MoveDiskFromTo(string *, string *, int *, int *);
#pragma endregion Functions

void main(){
	ExpNotePrint();
	UI();
	LoadStartArr();
	PrintScheme();
	TOHS(uChND, A, C, B, An, Cn, Bn);
}

void MoveDiskFromTo(string* from, string* to, int* numFrom, int* numTo)
{
	// temp variable helping swap disks between the rod
	string temp;
	// take disk to transfer
	temp = from[(*numFrom) - 1];
	// take disk from distance rod
	from[(*numFrom) - 1] = to[(*numTo)];
	// reducing number of disk on start rod
	(*numFrom) = (*numFrom) - 1;
	// distination rod take transfered disk
	to[(*numTo)] = temp;
	// increase disk number on distinatin rod
	(*numTo) = (*numTo) + 1;
	// increase iteration variable
	numberOfIterations++;

	// print all rods on console
	PrintScheme();
}

void TOHS(int diskNum, string* from, string* to, string* mid, int* fromN, int* toN, int* midN) {
	if (diskNum == 1)
	{
		MoveDiskFromTo(from, to, fromN, toN);
		return;
	}
	else
	{
		TOHS(diskNum - 1, from, mid, to, fromN, midN, toN);
		MoveDiskFromTo(from, to, fromN, toN);
		TOHS(diskNum - 1, mid, to, from, midN, toN, fromN);
	}
}

void MoveDelay(){
	// if user chose 0 then mast press key to continue
	if (moveDelay == 0)
	{
		cout << "Press key to continue...";
		getwchar();
	}
	// in other case use this delay
	else
	{
		_sleep(60 * moveDelay);
	}
}

void ExpNotePrint(){
	cout << "This App solve Tower of Hanoi" << endl << endl;
}

void UI(){
	int numberOfDisks;
	bool isInputOk = false;
	// take number of disk from User
	while (!isInputOk)
	{	
		cout << "It looks good at a maximum of 12 disk!" << endl << endl;
		cout << "Please enter number of disks (1-64): ";
		cin >> (int)numberOfDisks;
		if (numberOfDisks > 0 && numberOfDisks <= 64)
		{
			isInputOk = true;
		}
		else
		{
			cout << endl << "Value must be between 1 and 64!!!" << endl;
		}
	}
	isInputOk = false;

	// take delay from User
	int delay;
	while (!isInputOk)
	{
		cout << "Please enter time to delay (0 - for manual [s]): ";
		cin >> (int)delay;
		if (delay > -1)
		{
			isInputOk = true;
		}
		else
		{
			cout << endl << "Delay must be >= 0!" << endl;
		}
	}

	moveDelay = delay;
	uChND = numberOfDisks;
}

void LoadStartArr(){
	// load Arreys
	string loadStringF = "";
	string loadStringME = "";
	for (int i = 0; i < uChND; i++)
	{
		int maxJ = uChND * 2 - 1;
		int halfMaxJ = maxJ / 2;
		for (int j = 0; j < halfMaxJ - i; j++)
		{
			loadStringF = loadStringF + " ";
			loadStringME = loadStringME + " ";
		}
		int rangeOfDisks = 2 * i + 1;
		int j = 0;
		for (; j < rangeOfDisks; j++)
		{
			if (j % 2 == 0)
			{
				loadStringF = loadStringF + "+";
				loadStringME = loadStringME + " ";
			}
			else
			{
				loadStringF = loadStringF + " ";
				loadStringME = loadStringME + " ";
			}
		}
		for (int j = 0; j < halfMaxJ - i; j++)
		{
			loadStringF = loadStringF + " ";
			loadStringME = loadStringME + " ";
		}
		startArr[uChND - i - 1] = loadStringF;
		midArr[i] = endArr[i] = loadStringME;
		loadStringF = loadStringME = "";
	}
	numDisk_A = uChND;
}

void PrintScheme(){
	MoveDelay();
	system("cls");
	cout << "Iteration: " << numberOfIterations << endl << endl;
	for (int i = uChND; i >= 0; i--)
	{
		cout << startArr[i] << "\t";
		cout << midArr[i] << "\t";
		cout << endArr[i] << "\t";
		cout << endl;
	}
	cout << endl;
}