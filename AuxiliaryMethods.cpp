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
	} else {
		cout << "Not the correct year!" << endl;
		system("Pause");		
		return false;
	}	
}

bool AuxiliaryMethods::isRightMonth(string month) {
	SYSTEMTIME currentDate;
	GetSystemTime(&currentDate);

	int intText = convertStringToInt(month);

	if ((isNumber(month)) && (howManyDigits(intText) >= 1) && (howManyDigits(intText) <= 2) && (intText >= 0) && (intText <= 12))
	{
		return true;
	} else {
		cout << "Not the correct month!" << endl;
		system("Pause");
		return false;
	}
}

int AuxiliaryMethods::howManyDaysInMonth(int year, int month)
{
	int daysQuantity;
	int monthNumber = month;	
	
	if (monthNumber == 4 || monthNumber == 6 || monthNumber == 9 || monthNumber == 11)
		daysQuantity = 30;
	else if (monthNumber == 1 || monthNumber == 3 || monthNumber == 5 || monthNumber == 7 || monthNumber == 8 || monthNumber == 10 || monthNumber == 12)
		daysQuantity = 31;
	else if (monthNumber == 2)
	{
		if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
		{
			daysQuantity = 29;
		}
		else
			daysQuantity = 28;
	}

	return daysQuantity;
}

bool AuxiliaryMethods::isRightDay(string year, string month, string day) {
	SYSTEMTIME currentDate;
	GetSystemTime(&currentDate);

	int intYear = convertStringToInt(year);
	int intMonth = convertStringToInt(month);
	int intDay = convertStringToInt(day);

	int amountOfDays = howManyDaysInMonth(intYear, intMonth);
	   	  	
	if (amountOfDays == 31)	{
		if ((isNumber(day)) && (howManyDigits(intDay) >= 1) && (howManyDigits(intDay) <= 2) && (intDay >= 0) && (intDay <= 31))
		{
			return true;
		} else {
			cout << "Not the correct day!" << endl;			
			system("Pause");
			return false;
		}
	} else if (amountOfDays == 30) {
		if ((isNumber(day)) && (howManyDigits(intDay) >= 1) && (howManyDigits(intDay) <= 2) && (intDay >= 0) && (intDay <= 30))
		{
			return true;
		} else {
			cout << "Not the correct day!" << endl;			
			system("Pause");
			return false;
		}
	} else if (amountOfDays == 29) {
		if ((isNumber(day)) && (howManyDigits(intDay) >= 1) && (howManyDigits(intDay) <= 2) && (intDay >= 0) && (intDay <= 29))
		{
			return true;
		} else {
		cout << "Not the correct day!" << endl;
		system("Pause");
		return false;
	}
	} else if (amountOfDays == 28) {
		if ((isNumber(day)) && (howManyDigits(intDay) >= 1) && (howManyDigits(intDay) <= 2) && (intDay >= 0) && (intDay <= 28))
		{
			return true;
		}
		else {
			cout << "Not the correct day!" << endl;
			system("Pause");
			return false;
		}
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

bool AuxiliaryMethods::isRightWholeDate(string date) {
	string year = dateDividerYear(date);
	string month = dateDividerMonth(date);
	string day = dateDividerDay(date);

	if (isRightYear(year) && isRightMonth(month) && isRightDay(year, month, day))
	{
		//cout << "Right Date!" << endl;
		return true;
	}

	return false;
}

int AuxiliaryMethods::dateMergerConverter(string date) {
	string year = "";
	string month = "";
	string day = "";
	string wholeDate = "";
	int intWholeDate = 0;

	year = dateDividerYear(date);
	month = dateDividerMonth(date);
	day = dateDividerDay(date);
	wholeDate = year + month + day;
	intWholeDate = convertStringToInt(wholeDate);

	return intWholeDate;
}

int AuxiliaryMethods::convertDate(string date) {

	if (isRightWholeDate(date)) {

		return dateMergerConverter(date);
	}
	return 0;
}

string  AuxiliaryMethods::getTodaysDate()
{
	string date = "";
	string year = "";
	string month = "";
	string day = "";

	SYSTEMTIME currentDate;
	GetSystemTime(&currentDate);

	cout << endl;
	cout << "Today's date: " << currentDate.wYear << "-" << currentDate.wMonth << "-" << currentDate.wDay << endl;

	year = to_string(currentDate.wYear);
	month = to_string(currentDate.wMonth);
	day = to_string(currentDate.wDay);

	date = year + "-" + month + "-" + day;
	cout << date << endl;
	
	return date;
}
