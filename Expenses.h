#ifndef EXPENSES_HH
#define EXPENSES_HH

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

class Expenses {

	int userId;
	int expenseId;	
	int date;
	string item;
	int amount;

public:
	void setUserId(int newUserId);
	void setExpenseId(int newExpenseId);	
	void setDate(int newDate);
	void setItem(string newItem);
	void setAmount(int newAmount);

	int getUserId();
	int getExpenseId();	
	int getDate();
	string getItem();
	int getAmount();
};

///////////////////////////////////////////////////////////////////////////////////

class ExpensesFile
{
	CMarkup xml;
	const string EXPENSES_FILE_NAME = "expenses.xml";
	Expenses expenses;
	vector <Expenses> vectorExpenses;

	bool isExpensesFileExists(string expensesFileName);	
	vector <Expenses> loadAllExpensesDataFromFileToVector();

public:
	ExpensesFile(string expensesFileName) : EXPENSES_FILE_NAME(expensesFileName) {};
	void addExpenseToFile(Expenses expenses);
	vector <Expenses> loadExpensesFromFile();
	int returnVectorSize();
};
#endif
