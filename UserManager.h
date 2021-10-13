#ifndef USERMANAGER_HH
#define USERMANAGER_HH

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "AuxiliaryMethods.h"
#include "User.h"
#include "Incomes.h"
#include "Expenses.h"

using namespace std;

class UserManager {
	
	int loggedInUserId;
	vector <User> users;	

	User getNewUserData();
	int getNewUserId();
	bool isLoginExist(string login);	
	bool isRightWholeDate(string date);
	int dateMergerConverter(string date);
	int convertDate(string date);

	string date;

public:	
	UserManager() {
		loggedInUserId = 0;
		
	};

	int getLoggedInUserId();
	void userRegistration();
	int userLoggingIn();
	void loggedInUserPasswordChanging();
	int userloggingOut();
	bool isUserLoggedIn();
	void showAllUsers();	
	void addIncome();
	void addExpense();
	void balanceSheetForCurrentMonth();
	void balanceSheetForLatestMonth();
	void balanceSheetForSelectedPeriod();
};

#endif