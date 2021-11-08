#ifndef AUXILIARYMETHODS_HH
#define AUXILIARYMETHODS_HH

#include <iostream>
#include <sstream>
#include <windows.h>
#include <algorithm>

using namespace std;

class AuxiliaryMethods {
	
public:
	
	static string convertIntToString(int number);
	static int convertStringToInt(string number);	
	static string readLine();
	static char readChar();
	static int readInteger();

	static bool isNumber(string text);
	static int howManyDigits(int number);

	static bool isRightYear(string year);
	static bool isRightMonth(string month);
	static bool isRightDay(string year, string month, string day);
	static int howManyDaysInMonth(int year, int month);

	static string getTodaysDate();


	static string dateDividerYear(string date);
	static string dateDividerMonth(string date);	
	static string dateDividerDay(string date);

	static string dateConnectorDay(string date);
	static string dateConnectorMonth(string date);
	static string dateConnectorYear(string date);

	static bool isRightWholeDate(string date);
	static int dateMergerConverter(string date);
	static int convertDate(string date);
	static string dateConnectorConverter(int intDate);
	
};

#endif