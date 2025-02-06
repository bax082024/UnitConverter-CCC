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

		if (cin.fail()) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Invalid input! Please enter a valid number.\n";
			continue;
		}

		double result = meters * 3.28084;
		cout << meters << " meters is " << result << " feet.\n";
		logConversion(to_string(meters) + " meters = " + to_string(result) + " feet");

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
	char choice;
	do {
		cout << "Enter Celsius: ";
		cin >> celsius;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Invalid input! Please enter a valid number.\n";
			continue;
		}
		double result = (celsius * 9 / 5) + 32;
		cout << celsius << "°C is " << result << "°F.\n";
		logConversion(to_string(celsius) + "°C = " + to_string(result) + "°F");
		cout << "Do another conversion? (y/n): ";
		cin >> choice;
	} while (choice == 'y' || choice == 'Y');
}

void fahrenheitToCelsius() {
	double fahrenheit;
	char choice;
	do {
		cout << "Enter the temperature in Fahrenheit: ";
		cin >> fahrenheit;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Invalid input! Please enter a valid number.\n";
			continue;
		}

		double result = (fahrenheit - 32) * 5 / 9;
		cout << fahrenheit << "°F is " << result << "°C.\n";
		logConversion(to_string(fahrenheit) + "°F = " + to_string(result) + "°C");

		cout << "Do another conversion? (y/n): ";
		cin >> choice;
	} while (choice == 'y' || choice == 'Y');
}

void kilogramsToPounds() {
	double kilograms;
	char choice;
	do {
		cout << "Enter the number of kilograms: ";
		cin >> kilograms;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Invalid input! Please enter a valid number.\n";
			continue;
		}

		double result = kilograms * 2.20462;
		cout << kilograms << " kg is " << result << " pounds.\n";
		logConversion(to_string(kilograms) + " kg = " + to_string(result) + " lbs");

		cout << "Do another conversion? (y/n): ";
		cin >> choice;
	} while (choice == 'y' || choice == 'Y');
}

void poundsToKilograms() {
	double pounds;
	char choice;
	do {
		cout << "Enter the number of pounds: ";
		cin >> pounds;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Invalid input! Please enter a valid number.\n";
			continue;
		}

		double result = pounds * 0.453592;
		cout << pounds << " lbs is " << result << " kg.\n";
		logConversion(to_string(pounds) + " lbs = " + to_string(result) + " kg");

		cout << "Do another conversion? (y/n): ";
		cin >> choice;
	} while (choice == 'y' || choice == 'Y');
}

void litersToGallons() {
	double liters;
	char choice;
	do {
		cout << "Enter the number of liters: ";
		cin >> liters;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Invalid input! Please enter a valid number.\n";
			continue;
		}

		double result = liters * 0.264172;
		cout << liters << " liters is " << result << " gallons.\n";
		logConversion(to_string(liters) + " liters = " + to_string(result) + " gallons");

		cout << "Do another conversion? (y/n): ";
		cin >> choice;
	} while (choice == 'y' || choice == 'Y');
}

void gallonsToLiters() {
	double gallons;
	char choice;
	do {
		cout << "Enter the number of gallons: ";
		cin >> gallons;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Invalid input! Please enter a valid number.\n";
			continue;
		}

		double result = gallons * 3.78541;
		cout << gallons << " gallons is " << result << " liters.\n";
		logConversion(to_string(gallons) + " gallons = " + to_string(result) + " liters");

		cout << "Do another conversion? (y/n): ";
		cin >> choice;
	} while (choice == 'y' || choice == 'Y');
}