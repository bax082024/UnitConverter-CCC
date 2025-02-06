// UnitConverter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

// Functions
void showMenu();
void metersToFeet();
void feetToMeters();
void kilometersToMiles();
void milesToKilometers();
void celsiusToFahrenheit();
void fahrenheitToCelsius();
void kilogramsToPounds();
void poundsToKilograms();
void litersToGallons();
void gallonsToLiters();

int main() {
	int choice;

	do {
		showMenu();
		cout << "Enter your choice: ";
		cin >> choice;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid input. Please enter a number." << endl;
			continue;
		}

		switch (choice)	{
			case 1: metersToFeet(); break;
			case 2: feetToMeters(); break;
			case 3: kilometersToMiles(); break;
			case 4: milesToKilometers(); break;
			case 5: celsiusToFahrenheit(); break;
			case 6: fahrenheitToCelsius(); break;
			case 7: kilogramsToPounds(); break;
			case 8: poundsToKilograms(); break;
			case 9: litersToGallons(); break;
			case 10: gallonsToLiters(); break;
			case 11: cout << "Exiting program. Goodbye!\n"; break;
			default: cout << "Invalid choice! Please select a valid option.\n";
			
		}

	} while (choice != 11);
	return 0;
	
}


void showMenu() {
	cout << "1. Convert meters to feet\n" ;
	cout << "2. Convert feet to meters\n" ;
	cout << "3. Convert kilometers to miles\n" ;
	cout << "4. Convert miles to kilometers\n" ;
	cout << "5. Convert Celsius to Fahrenheit\n" ;
	cout << "6. Convert Fahrenheit to Celsius\n" ;
	cout << "7. Convert kilograms to pounds\n" ;
	cout << "8. Convert pounds to kilograms\n" ;
	cout << "9. Convert liters to gallons\n" ;
	cout << "10. Convert gallons to liters\n" ;
	cout << "11. Exit\n" ;
}

void metersToFeet() {
	double meters;
	cout << "Enter the number of meters: ";
	cin >> meters;
	cout << meters << " meters is equal to " << meters * 3.28084 << " feet.\n";
}

void feetToMeters() {
	double feet;
	cout << "Enter the number of feet: ";
	cin >> feet;
	cout << feet << " feet is equal to " << feet / 0.3048 << " meters.\n";
}

void kilometersToMiles() {
	double kilometers;
	cout << "Enter the number of kilometers: ";
	cin >> kilometers;
	cout << kilometers << " kilometers is equal to " << kilometers * 0.621371 << " miles.\n";
}