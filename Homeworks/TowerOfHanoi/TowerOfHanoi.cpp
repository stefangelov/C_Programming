#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
using namespace std;

string startArr[64];
string midArr[64];
string endArr[64];

int numberOfIterations = 0;

int uChND; // user choise for number of disks

void UserChoise();
void ExpNotePrint();
void SolTowerOfHanoi(int numOfDisks);
void LoadStartArr();
void PrintScheme();
void MoveDiskFromStartToEnd();

void main(){
	ExpNotePrint();
	UserChoise();
	LoadStartArr();
	PrintScheme();
	getchar(); 
	getchar();
	SolTowerOfHanoi(uChND);
}

void SolTowerOfHanoi(int numOfDisks){
	if (numOfDisks == 1)
	{
		MoveDiskFromStartToEnd();
		PrintScheme();
	}
}

void MoveDiskFromStartToEnd(){
	string tempString = startArr[0];
	startArr[0] = endArr[0];
	endArr[0] = tempString;
}

void ExpNotePrint(){
	cout << "This App solve Tower of Hanoi" << endl;
}

void UserChoise(){
	int numberOfDisks;
	bool isInputOk = false;
	while (!isInputOk)
	{
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
		for (int j = 0; j < rangeOfDisks; j++)
		{
			if (j % 2 == 0)
			{
				loadStringF = loadStringF + "-";
				loadStringME = loadStringME + " ";
			}
			else
			{
				loadStringF = loadStringF + " ";
				loadStringME = loadStringME + " ";
			}
		}
		startArr[i] = loadStringF;
		midArr[i] = endArr[i] = loadStringME;
		loadStringF = loadStringME = "";
	}
}

void PrintScheme(){
	system("cls");
	cout << "Iteration: " << numberOfIterations << endl << endl;
	for (int i = 0; i < uChND; i++)
	{
		cout << startArr[i] << "\t";
		cout << midArr[i] << "\t";
		cout << endArr[i] << "\t";
		cout << endl;
	}
	cout << endl;
}