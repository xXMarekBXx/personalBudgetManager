#ifndef USERMANAGER_HH
#define USERMANAGER_HH

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "Markup.h"
#include "AuxiliaryMethods.h"
#include "User.h"
#include "Incomes.h"
#include "Expenses.h"

using namespace std;

class UserManager {	

	CMarkup xml;
	int loggedInUserId;
	vector <User> users;
	UsersFile usersFile;	

	User getNewUserData();
	int getNewUserId();
	bool isLoginExist(string login);	
	
	Incomes incomes;
	string date;

public:	
	UserManager(string usersFileName) : usersFile(usersFileName) {
		loggedInUserId = 0;
		users = usersFile.loadUsersFromFile();		
	};
	
	void changePasswordInFile(string newPassword);
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