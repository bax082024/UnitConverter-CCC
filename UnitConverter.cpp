// UnitConverter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream> // for file handling
#include <string> // for string handling

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
void viewHistory();
void logConversion(const string& conversion);

const string historyFile = "history.txt";

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
			case 11: viewHistory(); break;
			case 12: cout << "Exiting program. Goodbye!\n"; break;
			default: cout << "Invalid choice! Please select a valid option.\n";
			
		}

	} while (choice != 12);
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
	cout << "11. View conversion history\n";
	cout << "12. Exit\n" ;
}

void logConversion(const string& conversion) {
	ofstream file(historyFile, ios::app);
	if (file.is_open()) {
		file << conversion << endl;
		file.close();
	}
	else {
		cout << "Error: Unable to save conversion history.\n";
	}
}

void viewHistory() {
	ifstream file(historyFile);
	if (!file) {
		cout << "No history found.\n";
		return;
	}

	cout << "\n--- Conversion History ---\n";
	string line;
	while (getline(file, line)) {
		cout << line << endl;
	}
	file.close();
}

void metersToFeet() {
	double meters;
	char choice;

	do {
		cout << "Enter meters: ";
		cin >> meters;

		// Input validation
		if (cin.fail()) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Invalid input! Please enter a valid number.\n";
			continue;
		}

		double result = meters * 3.28084;
		cout << meters << " meters is " << result << " feet.\n";
		logConversion(to_string(meters) + " meters = " + to_string(result) + " feet");

		// Ask if the user wants another conversion
		cout << "Do another conversion? (y/n): ";
		cin >> choice;

	} while (choice == 'y' || choice == 'Y');
}


void feetToMeters() {
	double feet;
	char choice;
	do {
		cout << "Enter feet: ";
		cin >> feet;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Invalid input! Please enter a valid number.\n";
			continue;
		}

		double result = feet * 0.3048;
		cout << feet << " feet is " << result << " meters.\n";
		logConversion(to_string(feet) + " feet = " + to_string(result) + " meters");

		cout << "Do another conversion? (y/n): ";
		cin >> choice;
	} while (choice == 'y' || choice == 'Y');
}

void kilometersToMiles() {
	double kilometers;
	char choice;
	do {
		cout << "Enter kilometers: ";
		cin >> kilometers;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Invalid input! Please enter a valid number.\n";
			continue;
		}

		double result = kilometers * 0.621371;
		cout << kilometers << " kilometers is " << result << " miles.\n";
		logConversion(to_string(kilometers) + " km = " + to_string(result) + " miles");

		cout << "Do another conversion? (y/n): ";
		cin >> choice;
	} while (choice == 'y' || choice == 'Y');
}

void milesToKilometers() {
	double miles;
	char choice;
	do {
		cout << "Enter miles: ";
		cin >> miles;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Invalid input! Please enter a valid number.\n";
			continue;
		}
		double result = miles * 1.60934;
		cout << miles << " miles is " << result << " kilometers.\n";
		logConversion(to_string(miles) + " miles = " + to_string(result) + " km");
		cout << "Do another conversion? (y/n): ";
		cin >> choice;
	} while (choice == 'y' || choice == 'Y');
}

void celsiusToFahrenheit() {
	double celsius;
	cout << "Enter the temperature in Celsius: ";
	cin >> celsius;
	cout << celsius << " degrees Celsius is equal to " << celsius * 9 / 5 + 32 << " degrees Fahrenheit.\n";
}

void fahrenheitToCelsius() {
	double fahrenheit;
	cout << "Enter the temperature in Fahrenheit: ";
	cin >> fahrenheit;
	cout << fahrenheit << " degrees Fahrenheit is equal to " << (fahrenheit - 32) * 5 / 9 << " degrees Celsius.\n";
}

void kilogramsToPounds() {
	double kilograms;
	cout << "Enter the number of kilograms: ";
	cin >> kilograms;
	cout << kilograms << " kilograms is equal to " << kilograms * 2.20462 << " pounds.\n";
}

void poundsToKilograms() {
	double pounds;
	cout << "Enter the number of pounds: ";
	cin >> pounds;
	cout << pounds << " pounds is equal to " << pounds / 0.453592 << " kilograms.\n";
}

void litersToGallons() {
	double liters;
	cout << "Enter the number of liters: ";
	cin >> liters;
	cout << liters << " liters is equal to " << liters * 0.264172 << " gallons.\n";
}

void gallonsToLiters() {
	double gallons;
	cout << "Enter the number of gallons: ";
	cin >> gallons;
	cout << gallons << " gallons is equal to " << gallons / 3.78541 << " liters.\n";
}