#ifndef USERMANAGER_HH
#define USERMANAGER_HH

#include <iostream>
#include <algorithm>
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
	Expenses expenses;
	vector <Expenses> vectorExpenses;
	ExpensesFile expensesFile;

	User getNewUserData();
	int getNewUserId();
	bool isLoginExist(string login);	
	
	void todayOrAnyOtherDateIncomeMenu();
	void getAllDataToTodaysIncome();
	void getAllDataToSelectedIncome();	

	void todayOrAnyOtherDateExpenseMenu();
	void getAllDataToTodaysExpense();
	void getAllDataToSelectedExpense();

public:	
	UserManager(string usersFileName, string incomesFileName, string expensesFileName) : usersFile(usersFileName), incomesFile(incomesFileName), expensesFile(expensesFileName) {
		loggedInUserId = 0;
		users = usersFile.loadUsersFromFile();
		vectorIncomes = incomesFile.loadIncomesFromFile();
		vectorExpenses = expensesFile.loadExpensesFromFile();
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

	/////////////////////////////////////////////////
	void loadFromFile();
	void showAllIncomes();
};

#endif