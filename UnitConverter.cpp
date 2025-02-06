
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
void kmPerHourToMph();
void mphToKmPerHour();
void minutesToHour();
void hoursToMinutes();
void pascalsToAtmospheres();
void atmospheresToPascals();
void joulesToCalories();
void caloriesToJoules();
void megabytesToGigabytes();
void gigabytesToMegabytes();
void bitsToBytes();

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
			case 11: kmPerHourToMph(); break;
			case 12: mphToKmPerHour(); break;
			case 13: minutesToHour(); break;
			case 14: hoursToMinutes(); break;
			case 15: pascalsToAtmospheres(); break;
			case 16: atmospheresToPascals(); break;
			case 17: joulesToCalories(); break;
			case 18: caloriesToJoules(); break;
			case 19: megabytesToGigabytes(); break;
			case 20: gigabytesToMegabytes(); break;
			case 21: bitsToBytes(); break;

			case 25: viewHistory(); break;
			case 26: cout << "Exiting program. Goodbye!\n"; break;
			default: cout << "Invalid choice! Please select a valid option.\n";
			
		}

	} while (choice != 12);
	return 0;
	
}


void showMenu() {
	cout << "\n=========================================\n";
	cout << "          UNIT CONVERTER MENU         \n";
	cout << "=========================================\n";

	cout << "\n LENGTH CONVERSIONS:\n";
	cout << "  1. Convert Meters to Feet\n";
	cout << "  2. Convert Feet to Meters\n";
	cout << "  3. Convert Kilometers to Miles\n";
	cout << "  4. Convert Miles to Kilometers\n";

	cout << "\n TEMPERATURE CONVERSIONS:\n";
	cout << "  5. Convert Celsius to Fahrenheit\n";
	cout << "  6. Convert Fahrenheit to Celsius\n";

	cout << "\n WEIGHT CONVERSIONS:\n";
	cout << "  7. Convert Kilograms to Pounds\n";
	cout << "  8. Convert Pounds to Kilograms\n";

	cout << "\n VOLUME CONVERSIONS:\n";
	cout << "  9. Convert Liters to Gallons\n";
	cout << " 10. Convert Gallons to Liters\n";

	cout << "\n SPEED CONVERSIONS:\n";
	cout << " 11. Convert Kilometers per Hour to Miles per Hour\n";
	cout << " 12. Convert Miles per Hour to Kilometers per Hour\n";

	cout << "\n TIME CONVERSIONS:\n";
	cout << " 13. Convert Minutes to Hours\n";
	cout << " 14. Convert Hours to Minutes\n";

	cout << "\n PRESSURE CONVERSIONS:\n";
	cout << " 15. Convert Pascals to Atmospheres\n";
	cout << " 16. Convert Atmospheres to Pascals\n";

	cout << "\n ENERGY CONVERSIONS:\n";
	cout << " 17. Convert Joules to Calories\n";
	cout << " 18. Convert Calories to Joules\n";

	cout << "\n STORAGE CONVERSIONS:\n";
	cout << " 19. Convert Megabytes to Gigabytes\n";
	cout << " 20. Convert Gigabytes to Megabytes\n";
	cout << " 21. Convert Bits to Bytes\n";

	cout << "\n OTHER OPTIONS:\n";
	cout << " 30. View Conversion History\n";
	cout << " 31. Exit\n";

	cout << "=========================================\n";
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
		cout << "\n-------------------------------------------\n";
		cout << feet << " feet is " << result << " meters.\n";
		cout << "-------------------------------------------\n";
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
		cout << "\n-------------------------------------------\n";
		cout << kilometers << " kilometers is " << result << " miles.\n";
		cout << "-------------------------------------------\n";
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
		cout << "\n-------------------------------------------\n";
		cout << miles << " miles is " << result << " kilometers.\n";
		cout << "-------------------------------------------\n";
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
		cout << "\n-------------------------------------------\n";
		cout << celsius << "°C is " << result << "°F.\n";
		cout << "-------------------------------------------\n";
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
		cout << "\n-------------------------------------------\n";
		cout << fahrenheit << "°F is " << result << "°C.\n";
		cout << "-------------------------------------------\n";
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
		cout << "\n-------------------------------------------\n";
		cout << kilograms << " kg is " << result << " pounds.\n";
		cout << "-------------------------------------------\n";
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
		cout << "\n-------------------------------------------\n";
		cout << pounds << " lbs is " << result << " kg.\n";
		cout << "-------------------------------------------\n";
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
		cout << "\n-------------------------------------------\n";
		cout << liters << " liters is " << result << " gallons.\n";
		cout << "-------------------------------------------\n";
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
		cout << "\n-------------------------------------------\n";
		cout << gallons << " gallons is " << result << " liters.\n";
		cout << "-------------------------------------------\n";
		logConversion(to_string(gallons) + " gallons = " + to_string(result) + " liters");

		cout << "Do another conversion? (y/n): ";
		cin >> choice;
	} while (choice == 'y' || choice == 'Y');
}

void kmPerHourToMph() {
	string input;
	char choice;

	do {
		cout << "Enter speed in km/h (or type 'b' to go back): ";
		cin >> input;

		if (input == "b" || input == "B") {
			cout << "Returning to main menu...\n";
			return;
		}

		double kmph;
		try {
			kmph = stod(input);
		}
		catch (exception&) {
			cout << "Invalid input! Please enter a valid number.\n";
			continue;
		}

		double result = kmph * 0.621371;
		cout << "\n-------------------------------------------\n";
		cout << kmph << " km/h is " << result << " mph.\n";
		cout << "-------------------------------------------\n";
		logConversion(input + " km/h = " + to_string(result) + " mph");

		cout << "Do another conversion? (y/n): ";
		cin >> choice;
	} while (choice == 'y' || choice == 'Y');
}

void mphToKmPerHour() {
	string input;
	char choice;
	do {
		cout << "Enter speed in mph (or type 'b' to go back): ";
		cin >> input;
		if (input == "b" || input == "B") {
			cout << "Returning to main menu...\n";
			return;
		}
		double mph;
		try {
			mph = stod(input);
		}
		catch (exception&) {
			cout << "Invalid input! Please enter a valid number.\n";
			continue;
		}
		double result = mph * 1.60934;
		cout << "\n-------------------------------------------\n";
		cout << mph << " mph is " << result << " km/h.\n";
		cout << "-------------------------------------------\n";
		logConversion(input + " mph = " + to_string(result) + " km/h");
		cout << "Do another conversion? (y/n): ";
		cin >> choice;
	} while (choice == 'y' || choice == 'Y');
}

void minutesToHour() {
	string input;
	char choice;

	do {
		cout << "Enter minutes (or type 'b' to go back): ";
		cin >> input;
		if (input == "b" || input == "B") {
			cout << "Returning to main menu...\n";
			return;
		}
		double minutes;
		try {
			minutes = stod(input);
		}
		catch (exception&) {
			cout << "Invalid input! Please enter a valid number.\n";
			continue;
		}
		double result = minutes / 60;
		cout << "\n-------------------------------------------\n";
		cout << minutes << " minutes is " << result << " hours.\n";
		cout << "-------------------------------------------\n";
		logConversion(input + " minutes = " + to_string(result) + " hours");
		cout << "Do another conversion? (y/n): ";
		cin >> choice;
	} while (choice == 'y' || choice == 'Y');
}

void hoursToMinutes() {
	string input;
	char choice;
	do {
		cout << "Enter hours (or type 'b' to go back): ";
		cin >> input;
		if (input == "b" || input == "B") {
			cout << "Returning to main menu...\n";
			return;
		}
		double hours;
		try {
			hours = stod(input);
		}
		catch (exception&) {
			cout << "Invalid input! Please enter a valid number.\n";
			continue;
		}
		double result = hours * 60;
		cout << "\n-------------------------------------------\n";
		cout << hours << " hours is " << result << " minutes.\n";
		cout << "-------------------------------------------\n";
		logConversion(input + " hours = " + to_string(result) + " minutes");
		cout << "Do another conversion? (y/n): ";
		cin >> choice;
	} while (choice == 'y' || choice == 'Y');
}

void pascalsToAtmospheres() {
	string input;
	char choice;

	do {
		cout << "Enter pressure in Pascals (or type 'b' to go back): ";
		cin >> input;

		if (input == "b" || input == "B") {
			cout << "Returning to main menu...\n";
			return;
		}

		double pascals;
		try {
			pascals = stod(input);
		}
		catch (exception&) {
			cout << "Invalid input! Please enter a valid number.\n";
			continue;
		}

		double result = pascals / 101325;
		cout << "\n-------------------------------------------\n";
		cout << pascals << " Pascals is " << result << " atmospheres.\n";
		cout << "-------------------------------------------\n";
		logConversion(input + " Pascals = " + to_string(result) + " atm");

		cout << "Do another conversion? (y/n): ";
		cin >> choice;
	} while (choice == 'y' || choice == 'Y');
}

void atmospheresToPascals() {
	string input;
	char choice;

	do {
		cout << "Enter pressure in atmospheres (or type 'b' to go back): ";
		cin >> input;

		if (input == "b" || input == "B") {
			cout << "Returning to main menu...\n";
			return;
		}

		double atmospheres;
		try {
			atmospheres = stod(input);
		}
		catch (exception&) {
			cout << "Invalid input! Please enter a valid number.\n";
			continue;
		}

		double result = atmospheres * 101325;
		cout << "\n-------------------------------------------\n";
		cout << atmospheres << " atmospheres is " << result << " Pascals.\n";
		cout << "-------------------------------------------\n";
		logConversion(input + " atmospheres = " + to_string(result) + " Pascals");
		cout << "Do another conversion? (y/n): ";
		cin >> choice;
	} while (choice == 'y' || choice == 'Y');
}

void joulesToCalories() {
	string input;
	char choice;

	do {
		cout << "Enter energy in Joules (or type 'b' to go back): ";
		cin >> input;

		if (input == "b" || input == "B") {
			cout << "Returning to main menu...\n";
			return;
		}

		double joules;
		try {
			joules = stod(input);
		}
		catch (exception&) {
			cout << "Invalid input! Please enter a valid number.\n";
			continue;
		}

		double result = joules * 0.239006;
		cout << "\n-------------------------------------------\n";
		cout << joules << " Joules is " << result << " Calories.\n";
		cout << "-------------------------------------------\n";
		logConversion(input + " Joules = " + to_string(result) + " Calories");

		cout << "Do another conversion? (y/n): ";
		cin >> choice;
	} while (choice == 'y' || choice == 'Y');
}

void caloriesToJoules() {
	string input;
	char choice;

	do {
		cout << "Enter energy in Calories (or type 'b' to go back): ";
		cin >> input;

		if (input == "b" || input == "B") {
			cout << "Returning to main menu...\n";
			return;
		}

		double calories;
		try {
			calories = stod(input);
		}
		catch (exception&) {
			cout << "Invalid input! Please enter a valid number.\n";
			continue;
		}

		double result = calories * 4.184;
		cout << "\n-------------------------------------------\n";
		cout << calories << " Calories is " << result << " Joules.\n";
		cout << "-------------------------------------------\n";
		logConversion(input + " Calories = " + to_string(result) + " Joules");

		cout << "Do another conversion? (y/n): ";
		cin >> choice;
	} while (choice == 'y' || choice == 'Y');
}

void megabytesToGigabytes() {
	string input;
	char choice;

	do {
		cout << "Enter storage in Megabytes (MB) (or type 'b' to go back): ";
		cin >> input;

		if (input == "b" || input == "B") {
			cout << "Returning to main menu...\n";
			return;
		}

		double megabytes;
		try {
			megabytes = stod(input);
		}
		catch (exception&) {
			cout << "Invalid input! Please enter a valid number.\n";
			continue;
		}

		double result = megabytes / 1024;
		cout << "\n-------------------------------------------\n";
		cout << megabytes << " MB is " << result << " GB.\n";
		cout << "-------------------------------------------\n";
		logConversion(input + " MB = " + to_string(result) + " GB");

		cout << "Do another conversion? (y/n): ";
		cin >> choice;
	} while (choice == 'y' || choice == 'Y');
}

void gigabytesToMegabytes() {
	string input;
	char choice;

	do {
		cout << "Enter storage in Gigabytes (GB) (or type 'b' to go back): ";
		cin >> input;

		if (input == "b" || input == "B") {
			cout << "Returning to main menu...\n";
			return;
		}

		double gigabytes;
		try {
			gigabytes = stod(input);
		}
		catch (exception&) {
			cout << "Invalid input! Please enter a valid number.\n";
			continue;
		}

		double result = gigabytes * 1024;
		cout << "\n-------------------------------------------\n";
		cout << gigabytes << " GB is " << result << " MB.\n";
		cout << "-------------------------------------------\n";
		logConversion(input + " GB = " + to_string(result) + " MB");

		cout << "Do another conversion? (y/n): ";
		cin >> choice;
	} while (choice == 'y' || choice == 'Y');
}

void bitsToBytes() {
	string input;
	char choice;

	do {
		cout << "Enter data size in Bits (or type 'b' to go back): ";
		cin >> input;

		if (input == "b" || input == "B") {
			cout << "Returning to main menu...\n";
			return;
		}

		double bits;
		try {
			bits = stod(input);
		}
		catch (exception&) {
			cout << "Invalid input! Please enter a valid number.\n";
			continue;
		}

		double result = bits / 8;
		cout << "\n-------------------------------------------\n";
		cout << "   " << bits << " Bits  =  " << result << " Bytes  \n";
		cout << "-------------------------------------------\n";
		logConversion(input + " Bits = " + to_string(result) + " Bytes");

		cout << "Do another conversion? (y/n): ";
		cin >> choice;
	} while (choice == 'y' || choice == 'Y');
}



