#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>

using namespace std;

int *GenerateArr(int dim);
void AddRandValuesToArr(int *arr, int size);
void UserRange(int *range, int sizeOfArr);
void PrintArr(int *arr, int size);
double CalcAverageInRange(int *arr, int *range);

/*
Da se nameri sredno aritmetichno na stoinostite ot masiv popadashti
v podaden obhvat ot polzvatelia.
*/
void ReplaceWithZeros(int *targetArr, int targetSize, int *keyArr, int keySize);


void main(){
	// to be numbers random
	srand(time(NULL));
	cout << "Please Enter dim of Arr: ";
	int size;
	cin >> (int)size;

	int *arr = GenerateArr(size);
	AddRandValuesToArr(arr, size);
	PrintArr(arr, size);

	int *range = GenerateArr(2);
	UserRange(range, size);
	cout << endl;
	cout << "User Range is: ";
	PrintArr(range, 2);

	cout << endl;
	cout << "The average in the range is: " << CalcAverageInRange(arr, range);

	
	cout << endl << endl;

	free(arr);
	free(range);
}

double CalcAverageInRange(int *arr, int *range) {
	double sum = 0;
	for (int i = *range - 1; i < *(range + 1); i++)
	{
		sum = sum + *(arr + i);
	}
	sum = sum / (*(range + 1) - *range + 1);
	return sum;
}

void UserRange(int *range, int size) { // size is the size of the ARR
	bool rangeTest = false;

	int startTempRange = 0;
	int endTempRange = 0;
	
	do
	{
		cout << "Enter Range Start: (1-" << size << "): ";
		cin >> (int)startTempRange;
		if (startTempRange >= 1 && startTempRange <= size)
		{
			rangeTest = true;
		}
		else
		{
			cout << "Value MUST be in range( 1-" << size << ")!" << endl;
		}

	} while (!rangeTest);

	rangeTest = false;

	do
	{
		cout << "Enter Range End: (1-" << size << "): ";
		cin >> (int)endTempRange;
		if (endTempRange >= 1 && endTempRange <= size)
		{
			rangeTest = true;
		}
		else
		{
			cout << "Value MUST be in range( 1-" << size << ")!" << endl;
		}
	} while (!rangeTest);

	if (startTempRange <= endTempRange)
	{
		*range = startTempRange;
		*range++;
		*range = endTempRange;
	}
	else
	{
		*range = endTempRange;
		*range++;
		*range = startTempRange;
	}
}

void ReplaceWithZeros(int *targetArr, int targetSize, int *keyArr, int keySize) {
	for (int t = 0; t < targetSize; t++)
	{
		for (int k = 0; k < keySize; k++)
		{
			if (*keyArr == *targetArr)
			{
				*targetArr = 0;
			}
			*keyArr++;
		}
		*targetArr++;
		for (int i = 0; i < keySize; i++)
		{
			*keyArr--;
		}
	}
}

int *GenerateArr(int dim) {
	int *theArr;
	theArr = (int *)malloc(sizeof(int)* dim);

	for (int i = 0; i < dim; i++)
	{
		theArr[i] = 0;
	}
	return theArr;
}

void AddRandValuesToArr(int *arr, int size) {
	for (int i = 0; i < size; i++)
	{
		*arr = rand() % 10; // random values from 0 to 9
		*arr++;
	}
}

void PrintArr(int *arr, int size) {
	for (int i = 0; i < size; i++)
	{
		cout << *arr << "  ";
		*arr++;
	}
	cout << endl;
}