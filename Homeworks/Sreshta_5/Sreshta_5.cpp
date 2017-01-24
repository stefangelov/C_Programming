#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int Probl_01();
int Probl_02();
int Probl_03();
int Probl_02_Support(double theTime); //use it for time calculations
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
Zadacha 1.
Potrebitelq vyvejda ot klaviaturata razstoqnie do letishteto i vremeto,
za koeto trqbva da stigne. Izchislete skorostta, s kqto trqbva da se dviji.

Задание 1.
Потребителят въвежда от клавиатурата разстоянието до летището и времето, 
за което трябва да стигне. Изчислете скоростта, с която трябва да се движи.

*/
int Probl_01() {
	cout << endl;

	cout << "Enter distance to airport [km]: ";
	double distance;
	cin >> distance;

	cout << "Enter travel time [min]: ";
	int duration;
	cin >> duration;
	int hours = duration / 60;
	int minutes = duration - hours * 60;
	double durationInHours = hours + (double)minutes / 60;
	
	cout << endl;
	cout << "Distance to travel: " << distance << " km" << endl;
	cout << "Time to travel: " << hours << " h. and " << minutes << " minutes = " << durationInHours << " hours" << endl;
	cout << "It is necessary to travel at speeds: " << distance / durationInHours << " km/h";
	cout << endl << endl;

	return 0;
}

// Solution for task 2
/*
Zadacha 2.
Potrebitelq vyvyejda ot klaviaturata vreme na nachaloto i vreme na kraq na telefonno obavdane (chasove, minuti, sekundi).
Smetnete kolko shte struva razgovoryt, ako cenata na 1 minuta e - 30 stotinki.

Задание 2.
Потребителят въвежда от клавиатурата време на началото и време на края на телефонно обаждане (часове, минути и секунди). 
Сметнете колко ще струва разговорът, ако цената за 1 минута е – 30 стотинки.
*/
int Probl_02(){

	cout << endl;
	
	int startTimeInMinutes = 1;
	int endTimeInMinutes = 0;
	int counter = 0;

	while (startTimeInMinutes >= endTimeInMinutes)
	{
		if (counter > 0)
		{
			cout << endl << "END time mast be after START time!" << endl << endl;
		}

		cout << "Enter START time of call [h.min]: ";
		double startTime;
		cin >> startTime;
		startTimeInMinutes= (int)Probl_02_Support(startTime);

		cout << "Enter END time of call [h.min]: ";
		double endTime;
		cin >> endTime;
		endTimeInMinutes = (int)Probl_02_Support(endTime);

		counter++;
	}

	int callDuration = endTimeInMinutes - startTimeInMinutes;

	cout << endl;

	cout << "Call duration in [min] is: " << callDuration << endl;
	cout << "Price of call is [lv] is: " << callDuration * 0.30;
	cout << endl << endl;

	return 0;
}

// Solution for task 3
/*
Zadacha 3.
Potrebitelqt vyvejda ot klaviaturata razstoqni, razhod na benzi na 100 km i cenite na tri vida benzin.
Izvedete na ekrana sravnitelna tablica sys stojnostta na pytuvaneto s vseki ot trite vida benzin.

Задание 3.
Потребителят въвежда от клавиатурата разстояние, разход на бензин на 100 км и цените на три вида бензин. 
Изведете на екрана сравнителна таблица със стойността на пътуването с всеки от трите вида бензин.
*/
int Probl_03(){
	cout << endl;

	cout << "Enter Travel Length [km]: ";
	double travelLength;
	cin >> travelLength;

	cout << "Enter fuel consumption [l/100 km]: ";
	double fuelConsum;
	cin >> fuelConsum;

	cout << "Enter Price for 1 liter fuel H95 [lv]: ";
	double h95Price;
	cin >> h95Price;

	cout << "Enter Price for 1 liter fuel H98 [lv]: ";
	double h98Price;
	cin >> h98Price;

	cout << "Enter Price for 1 liter fuel H100 [lv]: ";
	double h100Price;
	cin >> h100Price;

	double travelInHectom = travelLength / 100;
	double fuelUsage = travelInHectom * fuelConsum;

	cout << endl;
	cout << "Price of the trip in terms of fuel" << endl;
	cout << "Fuel H95\t" << (fuelUsage * h95Price) << " lv." << endl;
	cout << "Fuel H98\t" << (fuelUsage * h98Price) << " lv." << endl;
	cout << "Fuel H100\t" << (fuelUsage * h100Price) << " lv." << endl;
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


// use it for time calculations
int Probl_02_Support(double theTime) {
	
	int theTimeInMinutes = (int)theTime;
	theTimeInMinutes = theTimeInMinutes * 60;
	double theTimeReminder = theTime - theTimeInMinutes / 60;

	theTimeInMinutes = theTimeInMinutes + theTimeReminder * 100;

	return theTimeInMinutes;
}
