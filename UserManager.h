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
	Incomes incomes;
	vector <Incomes> vectorIncomes;
	IncomesFile incomesFile;

	User getNewUserData();
	int getNewUserId();
	bool isLoginExist(string login);	

	void getAllDataToIncome();
	void todayOrAnyOtherDateMenu();
	
	string date;

public:	
	UserManager(string usersFileName, string incomesFileName) : usersFile(usersFileName), incomesFile(incomesFileName) {
		loggedInUserId = 0;
		users = usersFile.loadUsersFromFile();
		vectorIncomes = incomesFile.loadIncomesFromFile();
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