#include <iostream>
#include <string>
using namespace std;

int Probl_01();
int Probl_02();
int Probl_03();
char UserUI();

// Main function
void main() {
	
	// first choise of User
	char userChoise = UserUI();
	
	// main loop of main funciton
	while (userChoise != '4')
	{
		switch (userChoise)
		{
		case '1':
			Probl_01();
			break;
		case '2':
			Probl_02();
			break;
		case '3':
			Probl_03();
			break;
		default:
			cout << endl << "Your choise is out of range!" << endl << endl;
			break;
		}

		userChoise = UserUI();
	}

	// if User choise exit we go here
	cout << "Bye!" << endl;
	exit(0);
}

// Solution for task 1
/*
Zadacha 1: Izvedete na ekrana edin pasaj ot lyubimo stihotvorenie ili pese kato posochite avtora ili izpylnitlq.
izpolzwajte excape-posledovatelnostite za formtirane.
Задание 1: Изведете на екрана един пасаж от любимо стихотворение или песен като посочите  автора или изпълнителя.
Използвайте escape-последователностите за форматиране.
*/
int Probl_01() {
	cout << endl;
	cout << "The Vengeful One" << endl << endl;
	cout << "Disturbed" << endl << endl;
	cout << "He is assuming the chaos, taking in the lack of raw humanity\nIt\'s as if the entire world\'s fallen in love with their insanity\nHear the innocent voices scream\nAs their tormentors laugh through all of it\nNo forgiveness from all I\'ve seen\nThe degradation I cannot forget";
	cout << endl << endl;

	return 0;
}

// Solution for task 2
/*
Zadacha 2: Izvedete na ekrana stihotworenieto «Every hunter wants…» taka, che vseki "cvqt" da
zapochva na now red i sys syotvetniq broj tabulacii.
Задание 2: Изведете на екрана стихотворението «Every hunter wants…» така, че всеки „цвят“ да
започва на нов ред и със съответния брой табулации.
*/
int Probl_02(){
	cout << endl;
	cout << "Not implemented!";
	cout << endl << endl;

	return 0;
}

// Solution for task 3
/*
Zadacha 3: Napishete obqva za prodavane na neshto i izvedete obqvata na ekrana vyv vida,
v koito trqbva da izblejda.
Задание 3: Напишете обява за продаване на нещо и изведете обявата на екрана във вида,
в който трябва да изглежда.
*/
int Probl_03(){
	cout << endl;
	cout << "Prodavam Avtomobil." << endl;
	cout << "Prodavam: Opel Astra" << endl;
	cout << "Dopylnitelna Informacia: Pochti v systoianie da se dviji." << endl;
	cout << "Tel: 00359 886 12 68";
	cout << endl << endl;

	return 0;
}

// Function to modeling UI ( UI :) )
char UserUI(){
	cout << "Choise Task (1-3) (Exit - 4): ";
	char userChoise;
	cin >> userChoise;
	return userChoise;
}
