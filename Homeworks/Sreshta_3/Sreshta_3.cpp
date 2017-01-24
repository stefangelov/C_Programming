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
Zadadeni sa tri syprotivleniq R1, R2, R3. Izchislete znachenieto na syprotivlenieto R0 po formulata: 1/R0 = 1/R1+1/R2+1/R3.
�������� �� ��� ������������� R1, R2, R3 . ��������� ���������� �� �������������  R0 �� ���������: 1/R0 = 1/R1+1/R2+1/R3.
*/
int Probl_01() {
	cout << endl;

	cout << "Enter value for R1= ";
	float rOne;
	cin >> (float)rOne;

	cout << "Enter value for R2= ";
	float rTwo;
	cin >> (float)rTwo;

	cout << "Enter value for R3= ";
	float rThree;
	cin >> (float)rThree;

	cout << endl;
	cout << "R0 = " << 1 / (1 / rOne + 1 / rTwo + 1 / rThree);
	cout << endl << endl;

	return 0;
}

// Solution for task 2
/*
Po zadadena obikolka na okryjnost izchislete ploshta na kryga po formula S = pi*R2,
radiusa izchisli po formulata za obikolka na okryvnost: L=2*pi*R
Zabelejka: pi=3.14
�� �������� �������� �� ��������� ��������� ������ �� ����� �� �������  S =  pi*R2, 
������� ������� �� ��������� �� �������� �� ���������: L=2*pi *R
���������: pi = 3.14
*/
int Probl_02(){
	cout << endl;

	cout << "Enter Lenght of Circle: ";
	float lenghtOfCircle;
	cin >> (float)lenghtOfCircle;

	const float pi = 3.14f;

	float radius = lenghtOfCircle / pi / 2;

	cout << endl;
	cout << "Area of the circle: " << pi * radius * radius;
	cout << endl << endl;

	return 0;
}

// Solution for task 3
/*
Zadacha 3: Izchislete izminatoto razstoqnie pri prawolinejno rawnouskoritelno dvijenie po
formulata S = v*t + (a*t2) / 2, kydeto v - skorosta, t - vremeto, a - uskorenie;
������� 3: ��������� ���������� ���������� ��� ������������ ���������������� �������� �� 
������� S = v*t + (a*t2) / 2, ������ v � �������, t � �����, � � ���������.
*/
int Probl_03(){
	cout << endl;

	cout << "Enter value for speed [m/s]: ";
	float speed;
	cin >> (float)speed;

	cout << "Enter value for time [s]: ";
	float time;
	cin >> (float)time;

	cout << "Enter value for acceleration [m/s2]: ";
	float acc;
	cin >> (float)acc;

	cout << endl;
	cout << "Traveled distance in [m] is: " << speed * time + (acc * time * time) / 2;
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
