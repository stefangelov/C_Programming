#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>

using namespace std;

int *GenerateArr(int dim);
void AddRandValuesToArr(int *arr, int size);
void PrintArr(int *arr, int size);
void TakeUserValuesToSearch(int *arr, int size);

/*
Da se realizira funkcia koto namira stoinostite v masiv
(1-4 na bori razlichni stoinosti) i gi podmenia s 0.
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

	cout << "Enter how meny values to search (1-4): ";
	int numOfValues;
	cin >> (int)numOfValues;
	int *keyArr = GenerateArr(numOfValues);
	TakeUserValuesToSearch(keyArr, numOfValues);
	ReplaceWithZeros(arr, size, keyArr, numOfValues);

	cout << "Result: " << endl;
	PrintArr(arr, size);

	cout << endl << endl;

	free(arr);
	free(keyArr);
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

void TakeUserValuesToSearch(int *arr, int size) {
	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << ": ";
		cin >> (int)(*arr);
		*arr++;
	}
}