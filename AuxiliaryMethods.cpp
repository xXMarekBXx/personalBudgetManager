#include "AuxiliaryMethods.h"

string AuxiliaryMethods::convertIntToString(int number) {
	ostringstream ss;
	ss << number;
	string str = ss.str();
	return str;
}

int AuxiliaryMethods::convertStringToInt(string number) {
	int intNumber;
	istringstream iss(number);
	iss >> intNumber;

	return intNumber;
}

string AuxiliaryMethods::readLine() {	
	string data = "";
	//cin.ignore();
	getline(cin, data);
	return data;
}

char AuxiliaryMethods::readChar() {
	string data = "";
	char sign = { 0 };

	while (true)
	{
		getline(cin, data);

		if (data.length() == 1)
		{

			sign = data[0];
			break;
		}
		cout << "It is not a single character. Please retype." << endl;
	}
	return sign;
}

int AuxiliaryMethods::readInteger() {
	string data = "";
	int number = 0;

	while (true)
	{
		//cin.ignore();
		getline(cin, data);

		stringstream myStream(data);
		if (myStream >> number)
			break;
		cout << "It is not a number. Please retype." << endl;
	}
	return number;
}


bool AuxiliaryMethods::isNumber(string text) {

	for (int i = 0; i < text.length(); i++) if (text[i] > '9' || text[i] < '0') return false;

	return true;
}

int AuxiliaryMethods::howManyDigits(int number) {
	int howManyDigits = (int)log10(number) + 1;
	return howManyDigits;
}

bool AuxiliaryMethods::isRightYear(string year) {
	SYSTEMTIME currentDate;
	GetSystemTime(&currentDate);

	int intText = convertStringToInt(year);

	if ((isNumber(year)) && (howManyDigits(intText) == 4) && (intText >= 2000) && (intText <= currentDate.wYear))
	{
		return true;
	}

	return false;
}

bool AuxiliaryMethods::isRightMonth(string month) {
	SYSTEMTIME currentDate;
	GetSystemTime(&currentDate);

	int intText = convertStringToInt(month);

	if ((isNumber(month)) && (howManyDigits(intText) >= 1) && (howManyDigits(intText) <= 2) && (intText >= 0) && (intText <= 12) && (intText <= currentDate.wMonth))
	{
		return true;
	}

	return false;
}

bool AuxiliaryMethods::isRightDay(string day) {
	SYSTEMTIME currentDate;
	GetSystemTime(&currentDate);

	int intText = convertStringToInt(day);

	if ((isNumber(day)) && (howManyDigits(intText) >= 1) && (howManyDigits(intText) <= 2) && (intText >= 0) && (intText <= 31))
	{
		return true;
	}

	return false;
}

string AuxiliaryMethods::dateDividerYear(string date) {
	string year;

	for (int i = 0; i < 4; i++)
	{
		year += date[i];
	}

	return year;
}

string AuxiliaryMethods::dateDividerMonth(string date) {
	string month;

	for (int i = 5; i < 7; i++)
	{
		month += date[i];
	}

	return month;
}

string AuxiliaryMethods::dateDividerDay(string date) {
	string day;

	for (int i = 8; i < 10; i++)
	{
		day += date[i];
	}

	return day;
}


