#ifndef PERSONALBUDGETMANAGER_HH
#define PERSONALBUDGETMANAGER_HH

#include <iostream>
#include "UserManager.h"

using namespace std;

class PersonalBudgetManager {

	UserManager userManager;

public:
	PersonalBudgetManager() {}
	~PersonalBudgetManager()	{}

	void userRegistration();
	bool userLoggingIn();
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
