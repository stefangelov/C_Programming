#include <iostream>
#include <string>
using namespace std;

int Probl_01();
int Probl_02();
char UserUI();

// Main function
void main() {

	// first choise of User
	char userChoise = UserUI();

	// main loop of main funciton
	while (userChoise != '3')
	{
		switch (userChoise)
		{
		case '1':
			Probl_01();
			break;
		case '2':
			Probl_02();
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
Задание 1.
Потребителят въвежда от клавиатурата времето в секунди, изминало от началото на деня. 
Изведете на екрана текущото време в часове, минути и секунди. Изчислете колко часа, 
минути и секунди остават до полунощ.
*/
int Probl_01() {
	cout << endl;

	int timeFromDayStartSeconds = -1;
	int counter = 0;

	while (timeFromDayStartSeconds < 0 || timeFromDayStartSeconds > 86400)
	{
		if (counter > 0)
		{
			cout << endl << "Entered value is out of range!" << endl << endl;
		}

		cout << "Enter time from day start [sec (0-86400)]: ";
		cin >> (int)timeFromDayStartSeconds;

		counter++;
	}

	int hoursForDayStart = timeFromDayStartSeconds / 3600;
	int minutesForDayStart = (timeFromDayStartSeconds - hoursForDayStart * 3600) / 60;
	int secondsForDayStart = (timeFromDayStartSeconds - hoursForDayStart * 3600 - minutesForDayStart * 60);

	int timeToDayEndSeconds = 86400 - timeFromDayStartSeconds;
	int hoursForDayEnd = timeToDayEndSeconds / 3600;
	int minutesForDayEnd = (timeToDayEndSeconds - hoursForDayEnd * 3600) / 60;
	int secondsForDayEnd = (timeToDayEndSeconds - hoursForDayEnd * 3600 - minutesForDayEnd * 60);

	cout << endl;
	cout << hoursForDayStart << " hours, " << minutesForDayStart << " minutes and " << secondsForDayStart << " seconds have passed since the start of the day!" << endl;
	cout << hoursForDayEnd << " hours, " << minutesForDayEnd << " minutes and " << secondsForDayEnd << " seconds have remaining to the end of the day!" << endl;
	cout << endl << endl;

	return 0;
}

// Solution for task 2
/*
Задание 2.
Потребителят въвежда от клавиатурата времето в секунди, изминало от началото на работния ден. 
Изчислете, колко цели часа остават до края на работното време при 8-часов работен ден.
*/
int Probl_02(){
	cout << endl;

	int timeFromWorkDayStartSeconds = -1;
	int counter = 0;

	while (timeFromWorkDayStartSeconds < 0 || timeFromWorkDayStartSeconds > 28800)
	{
		if (counter > 0)
		{
			cout << endl << "Entered value is out of range!" << endl << endl;
		}

		cout << "Enter time from work day start [sec (0-28800)]: ";
		cin >> (int)timeFromWorkDayStartSeconds;

		counter++;
	}


	int reminingTimeToEndWorkDay = 28800 - timeFromWorkDayStartSeconds;

	cout << endl;
	cout << "To the END of work day remaining " << (int)reminingTimeToEndWorkDay / 3600 << " whole hours!";
	cout << endl << endl;

	return 0;
}


// Function to modeling UI ( UI :) )
char UserUI(){
	cout << "Choise Task (1-2) (Exit - 3): ";
	char userChoise;
	cin >> userChoise;
	return userChoise;
}
