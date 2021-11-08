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

	int userId;
	int incomeId;	
	int date;
	string item;
	int amount;	

public:	
	
	void setUserId(int newUserId);
	void setIncomeId(int newIncomeId);	
	void setDate(int newDate);
	void setItem(string newItem);
	void setAmount(int newAmount);
	
	int getUserId();
	int getIncomeId();	
	int getDate();
	string getItem();
	int getAmount();	
};

///////////////////////////////////////////////////////////////////////////////////


class IncomesFile
{
	CMarkup xml;
	const string INCOMES_FILE_NAME = "incomes.xml";
	Incomes incomes;
	vector <Incomes> vectorIncomes;	
	   	 
	bool isIncomesFileExists(string incomesFileName);	
	//Incomes getAllDataOneSingleUserFromFile();
	vector <Incomes> loadAllIncomesDataFromFileToVector();	

public:	
	IncomesFile(string incomesFileName) : INCOMES_FILE_NAME(incomesFileName) {};	
	void addIncomeToFile(Incomes incomes);
	vector <Incomes> loadIncomesFromFile();
	int returnVectorSize();
};



#endif
