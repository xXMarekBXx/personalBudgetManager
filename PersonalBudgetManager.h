#ifndef PERSONALBUDGETMANAGER_HH
#define PERSONALBUDGETMANAGER_HH

#include <iostream>
#include "UserManager.h"

using namespace std;

class PersonalBudgetManager {

	const string USERS_FILE_NAME = "users.xml";
	UserManager userManager;

public:
	PersonalBudgetManager(string usersFileName)
	: userManager(usersFileName), USERS_FILE_NAME(usersFileName){}
	~PersonalBudgetManager(){}

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
