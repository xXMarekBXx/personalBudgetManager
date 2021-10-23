#ifndef INCOMES_HH
#define INCOMES_HH

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <windows.h>
#include "User.h"
#include "Markup.h"
#include "AuxiliaryMethods.h"

using namespace std;

class Incomes {

	CMarkup xml;
	const string INCOMES_FILE_NAME = "incomes.xml";

	int incomeId;
	int userId;
	string date;
	string item;
	float amount;	

public:

	bool isIncomesFileExists(string usersFileName);
	void addIncomeToFile();
	void todayOrAnyOtherDateMenu();
	string getTodaysDate();
	void getAllDataToIncome();

	void setIncomeId(int newIncomeId);
	void setUserId(int newUserId);
	void setDate(string newDate);
	void setItem(string newItem);
	void setAmount(float newAmount);
	
	int getIncomeId();
	int getUserId();
	string getDate();
	string getItem();
	float getAmount();	
};

#endif
