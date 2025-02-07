
#include <iostream>
#include <iomanip>
#include <fstream> 
#include <sstream>
#include <string>
#include <stdexcept>
#include <bitset>
#include <vector>
#include <unordered_map>

using namespace std;

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
void bytesToBits();
void binaryToDecimal();
void decimalToBinary();
void textToBinary();
void binaryToText();
void textToHexadecimal();
void hexadecimalToText();
void textToBase64();
void base64ToText();
void textToROT13();
void rot13ToText();
void textToMorse();
void morseToText();
void caesarCipherEncrypt();
void caesarCipherDecrypt();

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
			case 22: bytesToBits(); break;
			case 23: binaryToDecimal(); break;
			case 24: decimalToBinary(); break;
			case 25: textToBinary(); break;
			case 26: binaryToText(); break;
			case 27: textToHexadecimal(); break;
			case 30: hexadecimalToText(); break;
			case 31: textToBase64(); break;
			case 32: base64ToText(); break;
			case 33: textToROT13(); break;
			case 34: rot13ToText(); break;
			case 35: textToMorse(); break;
			case 36: morseToText(); break;

			case 50: caesarCipherEncrypt(); break;
			case 51: caesarCipherDecrypt(); break;

			case 40: viewHistory(); break;
			case 41: cout << "Exiting program. Goodbye!\n"; break;
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
	cout << " 22. Convert Bytes to Bits\n";

	cout << "\n DIGITAL CONVERSIONS:\n";
	cout << " 23. Binary to Decimal\n";
	cout << " 24. Decimal to Binary\n";
	cout << " 25. Text to Binary\n";
	cout << " 26. Binary to Text\n";
	cout << " 27. Hexadecimal to Text\n";
	cout << " 28. Text to Hexadecimal\n";
	cout << " 29. Text to Base64\n";
	cout << " 30. Base64 to Text\n";
	cout << " 31. Text to ROT13\n";
	cout << " 32. ROT13 to Text\n";
	cout << " 33. Text to Morse\n";
	cout << " 34. Morse to Text\n";

	

	cout << "\n Text Encryption/Decryption:\n";
	cout << " 50. Text to Caesar Cipher\n";
	cout << " 51. Caesar Cipher to Text\n";


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
		cout << "Enter speed in km/h : ";
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
		cout << "Enter speed in mph : ";
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
		cout << "Enter minutes : ";
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
		cout << "Enter hours : ";
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
		cout << "Enter pressure in Pascals : ";
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
		cout << "Enter pressure in atmospheres : ";
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
		cout << "Enter energy in Joules : ";
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
		cout << "Enter energy in Calories : ";
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
		cout << "Enter storage in Megabytes (MB) : ";
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
		cout << "Enter storage in Gigabytes (GB) : ";
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
		cout << "Enter data size in Bits : ";
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

void bytesToBits() {
	string input;
	char choice;

	do {
		cout << "Enter data size in Bytes : ";
		cin >> input;

		if (input == "b" || input == "B") {
			cout << "Returning to main menu...\n";
			return;
		}

		double bytes;
		try {
			bytes = stod(input);
		}
		catch (exception&) {
			cout << "Invalid input! Please enter a valid number.\n";
			continue;
		}

		double result = bytes * 8;
		cout << "\n-------------------------------------------\n";
		cout << "   " << bytes << " Bytes  =  " << result << " Bits  \n";
		cout << "-------------------------------------------\n";
		logConversion(input + " Bytes = " + to_string(result) + " Bits");

		cout << "Do another conversion? (y/n): ";
		cin >> choice;
	} while (choice == 'y' || choice == 'Y');
}

void binaryToDecimal() {
	string binaryInput;
	char choice;

	do {
		cout << "Enter a binary number : ";
		cin >> binaryInput;

		if (binaryInput == "b" || binaryInput == "B") {
			cout << "Returning to main menu...\n";
			return;
		}

		bool validBinary = true;
		for (char c : binaryInput) {
			if (c != '0' && c != '1') {
				validBinary = false;
				break;
			}
		}

		if (!validBinary) {
			cout << "Invalid binary number! Please enter only 0s and 1s.\n";
			continue;
		}

		int decimalValue = stoi(binaryInput, nullptr, 2);
		cout << "\n-------------------------------------------\n";
		cout << "   Binary: " << binaryInput << "  =  Decimal: " << decimalValue << "\n";
		cout << "-------------------------------------------\n";

		logConversion(binaryInput + " (binary) = " + to_string(decimalValue) + " (decimal)");

		cout << "Do another conversion? (y/n): ";
		cin >> choice;
	} while (choice == 'y' || choice == 'Y');
}

void decimalToBinary() {
	string input;
	char choice;

	do {
		cout << "Enter a decimal number : ";
		cin >> input;

		if (input == "b" || input == "B") {
			cout << "Returning to main menu...\n";
			return;
		}

		int decimal;
		try {
			decimal = stoi(input);
		}
		catch (exception&) {
			cout << "Invalid input! Please enter a valid number.\n";
			continue;
		}

		string binary = bitset<32>(decimal).to_string();

		binary.erase(0, binary.find_first_not_of('0'));

		cout << "\n-------------------------------------------\n";
		cout << "   Decimal: " << decimal << "  =  Binary: " << binary << "\n";
		cout << "-------------------------------------------\n";

		logConversion(to_string(decimal) + " (decimal) = " + binary + " (binary)");

		cout << "Do another conversion? (y/n): ";
		cin >> choice;
	} while (choice == 'y' || choice == 'Y');
}

void textToBinary() {
	string text;
	char choice;

	do {
		cout << "Enter text : ";
		cin.ignore(); 
		getline(cin, text);

		if (text == "b" || text == "B") {
			cout << "Returning to main menu...\n";
			return;
		}

		string binaryOutput = "";
		for (char c : text) {
			binaryOutput += bitset<8>(c).to_string() + " "; 
		}

		cout << "\n-------------------------------------------\n";
		cout << "   Text: " << text << "  →  Binary: " << binaryOutput << "\n";
		cout << "-------------------------------------------\n";

		logConversion(text + " (text) = " + binaryOutput + " (binary)");

		cout << "Do another conversion? (y/n): ";
		cin >> choice;
	} while (choice == 'y' || choice == 'Y');
}

void binaryToText() {
	string binaryInput;
	char choice;

	do {
		cout << "Enter a binary string (8-bit groups, space-separated) : ";
		cin.ignore();
		getline(cin, binaryInput);

		if (binaryInput == "b" || binaryInput == "B") {
			cout << "Returning to main menu...\n";
			return;
		}

		stringstream ss(binaryInput);
		string binaryChunk;
		string textOutput = "";

		while (ss >> binaryChunk) {
			if (binaryChunk.length() != 8 || binaryChunk.find_first_not_of("01") != string::npos) {
				cout << "Invalid binary format! Enter 8-bit groups separated by spaces.\n";
				continue;
			}

			char character = static_cast<char>(bitset<8>(binaryChunk).to_ulong());
			textOutput += character;
		}

		cout << "\n-------------------------------------------\n";
		cout << "   Binary: " << binaryInput << "  →  Text: " << textOutput << "\n";
		cout << "-------------------------------------------\n";

		logConversion(binaryInput + " (binary) = " + textOutput + " (text)");

		cout << "Do another conversion? (y/n): ";
		cin >> choice;
	} while (choice == 'y' || choice == 'Y');
}

void textToHexadecimal() {
	string text;
	char choice;

	do {
		cout << "Enter text : ";
		cin.ignore();
		getline(cin, text);

		if (text == "b" || text == "B") {
			cout << "Returning to main menu...\n";
			return;
		}

		stringstream hexStream;
		hexStream << hex << uppercase;

		for (char c : text) {
			hexStream << setw(2) << setfill('0') << static_cast<int>(c) << " ";
		}

		string hexOutput = hexStream.str();

		cout << "\n-------------------------------------------\n";
		cout << "   Text: " << text << "  →  Hexadecimal: " << hexOutput << "\n";
		cout << "-------------------------------------------\n";

		logConversion(text + " (text) = " + hexOutput + " (hex)");

		cout << "Do another conversion? (y/n): ";
		cin >> choice;
	} while (choice == 'y' || choice == 'Y');
}

void hexadecimalToText() {
	string hexInput;
	char choice;

	do {
		cout << "Enter a hexadecimal string (2-character pairs, space-separated) : ";
		cin.ignore();
		getline(cin, hexInput);

		if (hexInput == "b" || hexInput == "B") {
			cout << "Returning to main menu...\n";
			return;
		}

		stringstream ss(hexInput);
		string hexChunk;
		string textOutput = "";

		while (ss >> hexChunk) {
			if (hexChunk.length() != 2 || hexChunk.find_first_not_of("0123456789ABCDEFabcdef") != string::npos) {
				cout << "Invalid hexadecimal format! Enter 2-character hex pairs separated by spaces.\n";
				continue;
			}

			int asciiValue;
			stringstream converter;
			converter << hex << hexChunk;
			converter >> asciiValue;

			textOutput += static_cast<char>(asciiValue);
		}

		cout << "\n-------------------------------------------\n";
		cout << "   Hexadecimal: " << hexInput << "  →  Text: " << textOutput << "\n";
		cout << "-------------------------------------------\n";

		logConversion(hexInput + " (hex) = " + textOutput + " (text)");

		cout << "Do another conversion? (y/n): ";
		cin >> choice;
	} while (choice == 'y' || choice == 'Y');
}

const string base64_chars =
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz"
"0123456789+/";

string encodeBase64UTF8(const string& input) {
	vector<unsigned char> bytes(input.begin(), input.end());
	string output;
	int val = 0, bits = -6;

	for (unsigned char c : bytes) {
		val = (val << 8) + c;
		bits += 8;
		while (bits >= 0) {
			output.push_back(base64_chars[(val >> bits) & 0x3F]);
			bits -= 6;
		}
	}

	if (bits > -6) {
		output.push_back(base64_chars[((val << 8) >> (bits + 8)) & 0x3F]);
	}
	while (output.size() % 4) {
		output.push_back('=');
	}

	return output;
}

void textToBase64() {
	string text;
	char choice;

	do {
		cout << "Enter text to convert to Base64 : ";
		cin.ignore();
		getline(cin, text);

		if (text == "b" || text == "B") {
			cout << "Returning to main menu...\n";
			return;
		}

		string encodedBase64 = encodeBase64UTF8(text);

		cout << "\n-------------------------------------------\n";
		cout << "   Text: " << text << "  →  Base64: " << encodedBase64 << "\n";
		cout << "-------------------------------------------\n";

		logConversion(text + " (text) = " + encodedBase64 + " (Base64)");

		cout << "Do another conversion? (y/n): ";
		cin >> choice;
	} while (choice == 'y' || choice == 'Y');
}

string decodeBase64UTF8(const string& input) {
	string output;
	vector<int> T(256, -1);
	for (int i = 0; i < 64; i++) T[base64_chars[i]] = i;

	int val = 0, bits = -8;
	for (unsigned char c : input) {
		if (T[c] == -1) break;
		val = (val << 6) + T[c];
		bits += 6;

		if (bits >= 0) {
			output.push_back(char((val >> bits) & 0xFF));
			val &= (1 << bits) - 1;
			bits -= 8;
		}
	}
	return output;
}

void base64ToText() {
	string base64Input;
	char choice;

	do {
		cout << "Enter Base64 text to decode : ";
		cin.ignore();
		getline(cin, base64Input);

		if (base64Input == "b" || base64Input == "B") {
			cout << "Returning to main menu...\n";
			return;
		}

		try {
			string decodedText = decodeBase64UTF8(base64Input);
			cout << "\n-------------------------------------------\n";
			cout << "   Base64: " << base64Input << "  →  Text: " << decodedText << "\n";
			cout << "-------------------------------------------\n";

			logConversion(base64Input + " (Base64) = " + decodedText + " (text)");
		}
		catch (const invalid_argument& e) {
			cout << "Error: Invalid Base64 input!\n";
		}

		cout << "Do another conversion? (y/n): ";
		cin >> choice;
	} while (choice == 'y' || choice == 'Y');
}

string applyROT13(const string& input) {
	string output = input;
	for (char& c : output) {
		if (isalpha(c)) {
			char base = isupper(c) ? 'A' : 'a';
			c = (c - base + 13) % 26 + base;
		}
	}
	return output;
}

void textToROT13() {
	string text;
	char choice;

	do {
		cout << "Enter text to encode using ROT13 : ";
		cin.ignore();
		getline(cin, text);

		if (text == "b" || text == "B") {
			cout << "Returning to main menu...\n";
			return;
		}

		string encodedText = applyROT13(text);
		cout << "\n-------------------------------------------\n";
		cout << "   Original Text: " << text << "  →  ROT13 Encoded: " << encodedText << "\n";
		cout << "-------------------------------------------\n";

		logConversion(text + " (text) = " + encodedText + " (ROT13)");

		cout << "Do another conversion? (y/n): ";
		cin >> choice;
	} while (choice == 'y' || choice == 'Y');
}

void rot13ToText() {
	string text;
	char choice;

	do {
		cout << "Enter ROT13 encoded text to decode : ";
		cin.ignore();
		getline(cin, text);

		if (text == "b" || text == "B") {
			cout << "Returning to main menu...\n";
			return;
		}

		string decodedText = applyROT13(text);
		cout << "\n-------------------------------------------\n";
		cout << "   ROT13 Encoded: " << text << "  →  Decoded Text: " << decodedText << "\n";
		cout << "-------------------------------------------\n";

		logConversion(text + " (ROT13) = " + decodedText + " (text)");

		cout << "Do another conversion? (y/n): ";
		cin >> choice;
	} while (choice == 'y' || choice == 'Y');
}

unordered_map<char, string> morseCode = {
	{'A', ".-"},   {'B', "-..."}, {'C', "-.-."}, {'D', "-.."},  {'E', "."},
	{'F', "..-."}, {'G', "--."},  {'H', "...."}, {'I', ".."},   {'J', ".---"},
	{'K', "-.-"},  {'L', ".-.."}, {'M', "--"},   {'N', "-."},   {'O', "---"},
	{'P', ".--."}, {'Q', "--.-"}, {'R', ".-."},  {'S', "..."},  {'T', "-"},
	{'U', "..-"},  {'V', "...-"}, {'W', ".--"},  {'X', "-..-"}, {'Y', "-.--"},
	{'Z', "--.."},{'Æ', ".-.-" }, {'Ø', "---." }, {'Å', ".--.-" },
	{'1', ".----"},{'2', "..---"},{'3', "...--"},{'4', "....-"},{'5', "....."},
	{'6', "-...."},{'7', "--..."},{'8', "---.."},{'9', "----."},{'0', "-----"},
	{' ', "/"} 
};

unordered_map<string, char> morseToChar;
void initializeMorseToChar() {
	for (const auto& pair : morseCode) {
		morseToChar[pair.second] = pair.first;
	}
}

void textToMorse() {
	string text;
	char choice;

	do {
		cout << "Enter text to convert to Morse Code : ";
		cin.ignore();
		getline(cin, text);

		if (text == "b" || text == "B") {
			cout << "Returning to main menu...\n";
			return;
		}

		string morseOutput;
		for (char c : text) {
			c = toupper(c);
			if (morseCode.count(c)) {
				morseOutput += morseCode[c] + " ";
			}
			else {
				morseOutput += "? ";
			}
		}

		cout << "\n-------------------------------------------\n";
		cout << "   Text: " << text << "  →  Morse Code: " << morseOutput << "\n";
		cout << "-------------------------------------------\n";

		logConversion(text + " (text) = " + morseOutput + " (Morse)");

		cout << "Do another conversion? (y/n): ";
		cin >> choice;
	} while (choice == 'y' || choice == 'Y');
}

void morseToText() {
	string morseInput;
	char choice;

	do {
		cout << "Enter Morse Code to convert to text (use spaces between codes, '/' for spaces) : ";
		cin.ignore();
		getline(cin, morseInput);

		if (morseInput == "b" || morseInput == "B") {
			cout << "Returning to main menu...\n";
			return;
		}

		stringstream ss(morseInput);
		string morseSymbol, textOutput = "";

		while (ss >> morseSymbol) {
			if (morseToChar.count(morseSymbol)) {
				textOutput += morseToChar[morseSymbol];
			}
			else if (morseSymbol == "/") {
				textOutput += " ";
			}
			else {
				textOutput += "?";
			}
		}

		cout << "\n-------------------------------------------\n";
		cout << "   Morse Code: " << morseInput << "  →  Text: " << textOutput << "\n";
		cout << "-------------------------------------------\n";

		logConversion(morseInput + " (Morse) = " + textOutput + " (text)");

		cout << "Do another conversion? (y/n): ";
		cin >> choice;
	} while (choice == 'y' || choice == 'Y');
}

void caesarCipherEncrypt() {
	string input;
	int shift;
	char choice;

	do {
		cout << "Enter text to encrypt: ";
		cin.ignore();
		getline(cin, input);

		cout << "Enter shift value (1-25): ";
		cin >> shift;

		if (cin.fail() || shift < 1 || shift > 25) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Invalid input! Please enter a valid shift value between 1 and 25.\n";
			continue;
		}

		string encryptedText = "";
		for (char c : input) {
			if (isalpha(c)) {
				char base = isupper(c) ? 'A' : 'a';
				encryptedText += static_cast<char>(((c - base + shift) % 26) + base);
			}
			else {
				encryptedText += c;
			}
		}

		cout << "\n-------------------------------------------\n";
		cout << "   Original: " << input << "\n   Encrypted: " << encryptedText << "\n";
		cout << "-------------------------------------------\n";

		logConversion(input + " (original) -> " + encryptedText + " (Caesar encrypted)");

		cout << "Do another encryption? (y/n): ";
		cin >> choice;
	} while (choice == 'y' || choice == 'Y');
}

void caesarCipherDecrypt() {
	string input;
	int shift;
	char choice;

	do {
		cout << "Enter text to decrypt: ";
		cin.ignore();
		getline(cin, input);

		cout << "Enter shift value (1-25): ";
		cin >> shift;

		if (cin.fail() || shift < 1 || shift > 25) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Invalid input! Please enter a valid shift value between 1 and 25.\n";
			continue;
		}

		string decryptedText = "";
		for (char c : input) {
			if (isalpha(c)) {
				char base = isupper(c) ? 'A' : 'a';
				decryptedText += static_cast<char>(((c - base - shift + 26) % 26) + base);
			}
			else {
				decryptedText += c;
			}
		}

		cout << "\n-------------------------------------------\n";
		cout << "   Encrypted: " << input << "\n   Decrypted: " << decryptedText << "\n";
		cout << "-------------------------------------------\n";

		logConversion(input + " (Caesar encrypted) -> " + decryptedText + " (original)");

		cout << "Do another decryption? (y/n): ";
		cin >> choice;
	} while (choice == 'y' || choice == 'Y');
}

void textToTernary() {
	string text;
	char choice;

	do {
		cout << "Enter text: ";
		cin.ignore();
		getline(cin, text);

		if (text == "b" || text == "B") {
			cout << "Returning to main menu...\n";
			return;
		}

		string ternaryOutput = "";

		for (char c : text) {
			int asciiValue = static_cast<int>(c);
			string ternary = "";

			if (asciiValue == 0) {
				ternary = "0";
			}
			else {
				int num = asciiValue;
				while (num > 0) {
					ternary = to_string(num % 3) + ternary;
					num /= 3;
				}
			}

			ternaryOutput += ternary + " ";
		}

		cout << "\n-------------------------------------------\n";
		cout << "   Text: " << text << "  →  Ternary: " << ternaryOutput << "\n";
		cout << "-------------------------------------------\n";

		logConversion(text + " (text) = " + ternaryOutput + " (ternary)");

		cout << "Do another conversion? (y/n): ";
		cin >> choice;
	} while (choice == 'y' || choice == 'Y');
}











