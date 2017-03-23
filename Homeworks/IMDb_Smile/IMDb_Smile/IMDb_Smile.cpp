#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

using namespace std;

struct theFilm {
	int rating;
	char name[20];
	int year;
};

theFilm *CreateArr(int size);
void TakeFilmData(theFilm *filmArr, int row);
void PrintFilmData(theFilm *filmArr, int size);
void SortFilmsByRating(theFilm *filmArr, int size);
void SortFilms(theFilm *filmArr, int size, int sortBy);
void SortFilmsByName(theFilm *filmArr, int size);
void SortFilmsByYear(theFilm *filmArr, int size);
void UISorting(theFilm *filmArr, int size);
int TakeUserChoiseForSorting();
int CompareByName(const void * a, const void * b);

void main() {

	printf_s("Enter number of films: ");
	int size;
	char temp[20];
	gets_s(temp, 20);
	size = atoi(temp);
	theFilm* filmData = new theFilm[size];
	TakeFilmData(filmData, size);

	UISorting(filmData, size);

	delete[] filmData;
}

void UISorting(theFilm *filmArr, int size) {
	while (true)
	{
		int userChoiseForSorting = TakeUserChoiseForSorting();
		if (userChoiseForSorting == 0)
		{
			return;
		}
		SortFilms(filmArr, size, userChoiseForSorting);
		PrintFilmData(filmArr, size);
	}
}

int TakeUserChoiseForSorting() {
	bool test = false;
	char temp[20];
	int userChoise;

	while (!test)
	{
		printf_s("Sort By: \n");
		printf_s("1 - Sort By Name \n");
		printf_s("2 - Sort By Year \n");
		printf_s("3 - Sort By Rating \n");
		printf_s("0 - Quit \n");
		printf_s("Please Select: ");

		gets_s(temp, 20);
		userChoise = atoi(temp);

		if (userChoise == 0 || userChoise == 1 || userChoise == 2 || userChoise == 3)
		{
			test = true;
		}
		else
		{
			printf_s("Please enter correct value! \n");
		}
	}
	return userChoise;
}

void SortFilms(theFilm *filmArr, int size, int sortBy) {
	switch (sortBy)
	{
	case 1:
		SortFilmsByName(filmArr, size);
		break;
	case 2:
		SortFilmsByYear(filmArr, size);
		break;
	case 3:
		SortFilmsByRating(filmArr, size);
	default:
		break;
	}
}

void SortFilmsByRating(theFilm *filmArr, int siz) {
	for (int x = 0; x < siz; x++)
	{
		for (int y = 0; y<siz - 1; y++)
		{
			if (filmArr[y].rating>filmArr[y + 1].rating)
			{
				theFilm temp = filmArr[y + 1];
				filmArr[y + 1] = filmArr[y];
				filmArr[y] = temp;
			}
		}
	}
}

void SortFilmsByYear(theFilm *filmArr, int siz) {
	for (int x = 0; x < siz; x++)
	{
		for (int y = 0; y<siz - 1; y++)
		{
			if (filmArr[y].year>filmArr[y + 1].year)
			{
				theFilm temp = filmArr[y + 1];
				filmArr[y + 1] = filmArr[y];
				filmArr[y] = temp;
			}
		}
	}
}

int CompareByName(const void * a, const void * b) {
	theFilm *filmA = (theFilm *)a;
	theFilm *filmB = (theFilm *)b;

	return strcmp(filmA->name, filmB->name);
}

void SortFilmsByName(theFilm *filmArr, int siz) {
	qsort(filmArr, siz, sizeof(struct theFilm), CompareByName);

	for (int i = 0; i < siz / 2; i++)
	{
		theFilm temp = filmArr[i];
		filmArr[i] = filmArr[siz - i - 1];
		filmArr[siz - i - 1] = temp;
	}
}

int GetNumbOfFilms() {
	int size;
	char *tmp = new char[100];
	gets_s(tmp, 100);
	size = atoi(tmp);
	delete tmp;
	return size;
}

void PrintFilmData(theFilm *filmData, int size) {
	cout << endl;
	cout << "---===  Films sorted by Rating  ===---" << endl << endl;
	for (int i = size - 1; i >= 0; i--)
	{
		cout << "  Name: " << filmData[i].name << ", ";
		cout << "  Year: " << filmData[i].year << ", ";
		cout << "  Rating: ";
		for (int j = 0; j < filmData[i].rating; j++)
		{
			cout << "*";
		}
		cout << endl << endl;
	}
	cout << "---===   End of List  ===---" << endl;
}

void TakeFilmData(theFilm *filmArr, int row) {
	for (int i = 0; i < row; i++)
	{
		char tempStr[20];
		printf_s("\tEnter film %d rating: ", i + 1);
		gets_s(tempStr, 20);
		filmArr[i].rating = atoi(tempStr);

		printf_s("\tEnter film %d name: ", i + 1);
		gets_s(filmArr[i].name, 20);

		printf_s("\tEnter film %d year: ", i + 1);
		gets_s(tempStr, 20);
		filmArr[i].year = atoi(tempStr);

		cout << endl;
	}
}

theFilm *CreateArr(int size) {
	theFilm *filmArr = new theFilm[size];
	return filmArr;
}