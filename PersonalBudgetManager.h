#ifndef PERSONALBUDGETMANAGER_HH
#define PERSONALBUDGETMANAGER_HH

#include <iostream>
#include "UserManager.h"

using namespace std;

class PersonalBudgetManager {

	const string USERS_FILE_NAME = "users.xml";
	const string INCOMES_FILE_NAME = "incomes.xml";
	const string EXPENSES_FILE_NAME = "expenses.xml";
	UserManager userManager;
	IncomesFile *incomesFile;
	ExpensesFile *expensesFile;		

public:
	PersonalBudgetManager(string usersFileName, string incomesFileName, string expensesFileName)
		: userManager(usersFileName, incomesFileName, expensesFileName), USERS_FILE_NAME(usersFileName), INCOMES_FILE_NAME(incomesFileName), EXPENSES_FILE_NAME(expensesFileName)
	{
		incomesFile = NULL;	
		expensesFile = NULL;
	};	

	~PersonalBudgetManager()
	{
		delete incomesFile;
		incomesFile = NULL;		

		delete expensesFile;
		expensesFile = NULL;
	}

	void userRegistration();
	void userLoggingIn();
	void loggedInUserPasswordChanging();
	void userloggingOut();
	bool isUserLoggedIn();
	void addIncome();
	void addExpense();
	void balanceSheetForCurrentMonth();

	void showAllIncomes();


	void balanceSheetForLatestMonth();
	void balanceSheetForSelectedPeriod();
};

#endif
