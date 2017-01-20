/*
Ask user for dimensions of square array. Add random int values from 0 to 99 in array.
Trim it in sand glass shape and show the max value in Sand Glass shape.
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

// function to generete pointer to 2D array
int ** Generate2DIntArr(int row, int col) {
	// pointer to return
	int ** theArr;
	// alocate memory for arr implement rows of array
	theArr = (int **)malloc(sizeof(int *) * row);
	// alocate memory for the items of rows of array
	for (int i = 0; i < col; i++)
	{
		theArr[i] = (int *)malloc(sizeof(int)* col);
	}

	// add zero values of arr elements
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			theArr[i][j] = 0;
		}
	}
	return theArr;
}

void main() {
	// to be numbers random
	srand(time(NULL));

	int n;
	cout << "Enter value for dim of Arr: ";
	cin >> (int)n;
	int row = n;
	int col = n;

	// the arr
	int **arr = Generate2DIntArr(row, col);

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			arr[i][j] = rand() % 100; // random values from 0 to 99
			cout << arr[i][j] << "\t";
		}
		cout << endl << endl;
	}
	cout << endl;

	// hold max value in searhing area
	int maxValue = arr[0][0];

	// print searching area on console
	cout << "Searching area: " << endl << endl;
	for (int i = 0; i < row; i++)
	{
		int j = 0;
		int endJ = 0; // for j under middle row

					  // LEFT free area
					  // check if we pass middle row
		if (i < row / 2)
		{
			for (; j < i; j++)
			{
				cout << "\t";
			}
		}
		else // if we pass middle row
		{
			endJ = row - i - 1;
			for (; j < endJ; j++)
			{
				cout << "\t";
			}
		}

		// print area with numbers
		// check if we are above middlerow
		if (i < row / 2)
		{
			for (; j < col - i; j++)
			{
				cout << arr[i][j] << "\t";
				// check if current number is greater than maxValue
				if (maxValue < arr[i][j])
				{
					maxValue = arr[i][j];
				}
			}
		}
		// if we are under middle row
		else
		{
			for (; j < col - endJ; j++)
			{
				cout << arr[i][j] << "\t";
				if (maxValue < arr[i][j])
				{
					maxValue = arr[i][j];
				}
			}
		}


		//RIGHT free area
		for (; j < col; j++)
		{
			cout << "\t";
		}
		cout << endl << endl;
	}

	// print max value in printed area
	cout << "Max Value is: " << maxValue;
	cout << endl << endl;
}