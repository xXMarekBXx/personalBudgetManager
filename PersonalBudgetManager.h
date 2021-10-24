#ifndef PERSONALBUDGETMANAGER_HH
#define PERSONALBUDGETMANAGER_HH

#include <iostream>
#include "UserManager.h"

using namespace std;

class PersonalBudgetManager {

	const string USERS_FILE_NAME = "users.xml";
	const string INCOMES_FILE_NAME = "incomes.xml";
	UserManager userManager;
	IncomesFile *incomesFile;

public:
	PersonalBudgetManager(string usersFileName, string incomesFileName)
		: userManager(usersFileName, incomesFileName), USERS_FILE_NAME(usersFileName), INCOMES_FILE_NAME(incomesFileName)
	{
		incomesFile = NULL;
	};	

	~PersonalBudgetManager()
	{
		delete incomesFile;
		incomesFile = NULL;
	}

	void userRegistration();
	void userLoggingIn();
	void loggedInUserPasswordChanging();
	void userloggingOut();
	bool isUserLoggedIn();
	void addIncome();
	void addExpense();
	void balanceSheetForCurrentMonth();
	void balanceSheetForLatestMonth();
	void balanceSheetForSelectedPeriod();
};

#endif
