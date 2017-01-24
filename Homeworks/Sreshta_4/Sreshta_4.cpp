#include <iostream>
#include <string>
using namespace std;

int Probl_01();
int Probl_02();
int Probl_03();
int Probl_04();
int Probl_05();

char UserUI();

// Main function
void main() {

	// first choise of User
	char userChoise = UserUI();

	// main loop of main funciton
	while (userChoise != '6')
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
		case '4':
			Probl_04();
			break;
		case '5':
			Probl_05();
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
Zadacha 1. Potrebitlq nabira na klaviaturata vreme v sekundi. Neobhodimo e da napishtete programa,
koqto da obyrne vyvejdanite ot potrebitelq sekundi w chasove, minuti, sekundi i da gi izvejda na ekran.
������� 1. ������������ ������ �� ������������ ����� � �������. ���������� � �� �������� ��������, 
����� �� ������ ����������� �� ����������� ������� � ������, ������, ������� � �� �� ������� �� �����.
*/
int Probl_01() {
	cout << endl;

	cout << "Enter seconds: ";
	int userSeconds;
	cin >> (int)userSeconds;

	int hours = userSeconds / 3600;
	int reminderMInutesSeconds = userSeconds % 3600;
	int minutes = reminderMInutesSeconds / 60;
	int seconds = reminderMInutesSeconds % 60;

	cout << endl;
	cout << "\tHours: " << hours << endl;
	cout << "\tMinutes: " << minutes << endl;
	cout << "\tSeconds: " << seconds << endl;
	cout << endl << endl;

	return 0;
}

// Solution for task 2
/*
Zadacha 2. Napishete programa, koqto da preobrazuva vyvedeno ot klaviaturata drobno chislo v parichen format.
Naprimer, chisloto 12,5 trqbva da byde preobrazuvano vyv vid 12 lv. i 50 st.
������� 2. �������� ��������, ����� �� ����������� �������� �� ������������ ������ ����� � ������� ������. 
��������, ������� 12,5 ������ �� ���� ������������� ��� ��� 12 ��. 50 ��.
*/
int Probl_02(){
	cout << endl;

	cout << "Enter value to convert: ";
	float userValueToConvert;
	cin >> (float)userValueToConvert;

	unsigned int levas = (int)userValueToConvert;
	unsigned int stotinki = (int)((userValueToConvert - levas) * 100);

	cout << endl;
	cout << levas << " lv." << " and " << stotinki << " st.";
	cout << endl << endl;

	return 0;
}

// Solution for task 3
/*
Zadacha 3. Napishete programa, izchislqvashta s kakva skorost begachyt e probqgal distanciqta.
Preporychitelen vid na ekrana po vreme na izpylnenie na programata e daden po-dolu:

Izchislqvane skorostta na bqgane
Vyvejdane dyljinata na distanciqta (metri) = 1000
Vyvejdane na vreme (min.sek) = 3.25
Distanciq: 1000 m
Vreme: 3 min 25 sek = 205 sek;
Vie bqgahte sys skorost 17.56 km/ch

������� 3. �������� ��������, ����������� � ����� ������� ������� � �������� �����������. 
�������������� ��� �� ������ �� ����� �� ���������� �� ���������� � ����� ��-����:

����������� ��������� �� ������
��������� ��������� �� ����������� (�����) = 1000
��������� �� ����� (���.���) = 3.25
���������: 1000 �
�����: 3 ��� 25 ��� = 205 ���
��� ������� ��� �������  17.56 ��/�

*/
int Probl_03(){
	cout << endl;

	cout << "Enter distance [m]: ";
	float distance;
	cin >> distance;

	cout << "Enter time of running [min.sec]: ";
	float time;
	cin >> time;
	int minutes = time;
	float seconds = (time - minutes);
	if (seconds * 10 < 1)
	{
		seconds = seconds * 10;
	}
	else
	{
		seconds = seconds * 100;
	}
	int timeInSeconds = minutes * 60 + seconds;

	cout << endl;
	cout << "Calculating the speed of running" << endl;
	cout << "Distance [m]: " << distance << endl;
	cout << "Time: " << minutes << " min and " << seconds << " sec = " << timeInSeconds << "sec" << endl;
	cout << "Runing speed: " << distance / timeInSeconds * 3.6 << " km/h" << endl;
	cout << endl << endl;

	return 0;
}


// Solution for task 4
/*
������� 4. ������������ ������� ������ �� 1 ��� �������� ��������� �� ���� 
������� �������� ��� ����, � ���� ����������������� �� ��������� � ������ � 
�������. ���������� � �� �� ������� ��������� �������� �� ���� ��������.
*/
int Probl_04(){
	cout << endl;

	cout << "Enter price for minute [lv/min]: ";
	double price;
	cin >> price;

	cout << "Enter duration of conversation [min.sec]: ";
	double duration;
	cin >> duration;

	int minutes = duration;
	float seconds = (duration - minutes);
	if (seconds * 10 < 1)
	{
		seconds = seconds * 10;
	}
	else
	{
		seconds = seconds * 100;
	}
	double durationInMinutes = minutes + seconds / 60;

	cout << endl;
	cout << "Calculating the price of conversation" << endl;
	cout << "Price for minute [lv/min]: " << price << endl;
	cout << "Duration: " << minutes << " min and " << seconds << " sec = " << durationInMinutes << "min" << endl;
	cout << "Price of conversation: " << price * durationInMinutes << " lv" << endl;
	cout << endl << endl;

	return 0;
}

// Solution for task 4
/*
������� 5. �������� ��������, ����� �� ����������� ��������� �� ����������� 
���� ��� � ���� ����� ������� � �������� ���. ��������, ������������ 
������� 17 ���, ���������� ������ �� ������ �� ������ 2 ������� � 3 ���.
*/

int Probl_05(){
	cout << endl;

	cout << "Enter period [days]: ";
	int period;
	cin >> period;

	int weeks = period / 7;
	int days = period - weeks * 7;

	cout << endl;
	cout << "Period of " << period << " days is " << weeks << " week(s) and " << days << " day(s)";
	cout << endl << endl;

	return 0;
}

// Function to modeling UI ( UI :) )
char UserUI(){
	cout << "Choise Task (1-5) (Exit - 6): ";
	char userChoise;
	cin >> userChoise;
	return userChoise;
}
