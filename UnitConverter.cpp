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
		}
		else {
			switch (choice) {
			case 1:
				metersToFeet();
				break;
			case 2:
				feetToMeters();
				break;
			case 3:
				kilometersToMiles();
				break;
			case 4:
				milesToKilometers();
				break;
			case 5:
				celsiusToFahrenheit();
				break;
			case 6:
				fahrenheitToCelsius();
				break;
			case 7:
				kilogramsToPounds();
				break;
			case 8:
				poundsToKilograms();
				break;
			case 9:
				litersToGallons();
				break;
			case 10:
				gallonsToLiters();
				break;
			case 11:
				cout << "Exiting program..." << endl;
				break;
			default:
				cout << "Invalid choice. Please enter a number between 1 and 11." << endl;
				break;
			}
		}