#include "UserManager.h"
#include "User.h"

int UserManager::getLoggedInUserId()
{
	return loggedInUserId;
}

int UserManager::getNewUserId() {	
	return users.back().getUserId() + 1;
	if (users.empty())
		return 1;
}

void UserManager::userRegistration() {

	cout << endl << endl << endl;
	cout << "YOUR NEW ACCOUNT CREATOR" << endl;
	cout << "------------------------" << endl;	
	User user = getNewUserData();

	users.push_back(user);
	usersFile.addUserToFile(user);

	cout << "Account created successfully" << endl << endl;
	system("pause");
}

User UserManager::getNewUserData() {

	User user;

	user.setUserId(getNewUserId());

	string login;

	do
	{
		cin.ignore();
		cout << "Enter your login: ";
		login = AuxiliaryMethods::readLine();

		user.setLogin(login);

	} while (isLoginExist(user.getLogin()) == true);

	cout << "Enter your password: ";
	string passwrord;	
	passwrord = AuxiliaryMethods::readLine();
	user.setPassword(passwrord);

	cout << "Enter your name: ";
	string name;
	name = AuxiliaryMethods::readLine();
	user.setName(name);

	cout << "Enter your surname: ";
	string surname;
	surname = AuxiliaryMethods::readLine();
	user.setSurname(surname);

	return user;
}

bool UserManager::isLoginExist(string login) {

	int lengthVectorUsers = users.size();

	for (int i = 0; i < lengthVectorUsers; i++) {
		if (users[i].getLogin() == login)
		{
			cout << endl << "Login not available" << endl;
			return true;
		}
	}
	return false;
}

void UserManager::showAllUsers() {
	int lengthVectorUsers = users.size();

	for (int i = 0; i < lengthVectorUsers; i++) {

		cout << users[i].getUserId() << endl;
		cout << users[i].getLogin() << endl;
		cout << users[i].getPassword() << endl;
	}
}

bool UserManager::isUserLoggedIn() {
	if (loggedInUserId > 0)
		return true;
	else
		return false;
}

int UserManager::userLoggingIn() {

	string login = "", password = "";

	cout << endl << "Enter your login: ";	
	cin >> login;

	vector <User>::iterator itr = users.begin();
	while (itr != users.end())
	{
		if (itr->getLogin() == login)
		{
			for (int attemptsNumber = 3; attemptsNumber > 0; attemptsNumber--)
			{
				cout << "Enter your password. Trouble left: " << attemptsNumber << ": ";
				cin >> password;

				if (itr->getPassword() == password)
				{
					cout << endl << "You have logged in correctly." << endl << endl;
					system("pause");
					loggedInUserId = itr->getUserId();					
					return loggedInUserId;
				}
			}
			cout << "Wrong password entered 3 times." << endl;
			system("pause");
			return 0;
		}
		itr++;
	}
	cout << "There is no user with such a login" << endl << endl;
	system("pause");
	return 0;
}

void UserManager::changePasswordInFile(string newPassword) {

	xml.Load("users.xml");
	xml.FindElem("Users");
	xml.IntoElem();

	while (xml.FindElem("User")) {
		xml.IntoElem();

		xml.FindElem("UserId");
		string id;
		id = xml.GetData();		

		int idValue = AuxiliaryMethods::convertStringToInt(id);

		if (idValue == loggedInUserId) {
			
			xml.FindElem("Password");
			xml.RemoveElem();
			xml.AddElem("Password",newPassword);
			xml.Save("users.xml");
			break;
		}
	}
}

void UserManager::loggedInUserPasswordChanging() {
	
	string newPassword = "";

	cout << "Enter new password: ";

	cin.ignore();
	newPassword = AuxiliaryMethods::readLine();
		
	for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
	{
		if (itr->getUserId() == loggedInUserId)
		{
			itr->setPassword(newPassword);
			cout << "Password has been changed." << endl << endl;
			system("pause");
		}
	}
	changePasswordInFile(newPassword);
}

int UserManager::userloggingOut() {
	loggedInUserId = 0;
	return loggedInUserId;
}

void UserManager::todayOrAnyOtherDateIncomeMenu()
{
	system("cls");
	cout << "Adding Income" << endl;
	cout << "1. Add today's income" << endl;
	cout << "2. Add income witch other date" << endl;
	cout << "Your choice: ";

	int choice;
	cin.ignore();
	choice = AuxiliaryMethods::readInteger();

	switch (choice)
	{
	case 1:
		getAllDataToTodaysIncome();//tu problem
		vectorIncomes.push_back(incomes);
		incomesFile.addIncomeToFile(incomes);		
		break;
	case 2:
		getAllDataToSelectedIncome();
		vectorIncomes.push_back(incomes);
		incomesFile.addIncomeToFile(incomes);
		break;
	default:
		cout << endl << "There is no such option on the menu." << endl << endl;
		system("pause");
		break;
	}
}

void UserManager::getAllDataToTodaysIncome()
{	
	incomes.setUserId(loggedInUserId);	

	int newIncomeId = 0;	
	newIncomeId = incomesFile.returnVectorSize();	
	newIncomeId++;	
	incomes.setIncomeId(newIncomeId);	
		
	string stringDate;
	stringDate = AuxiliaryMethods::getTodaysDate();
	int intDate = AuxiliaryMethods::convertDate(stringDate);
	incomes.setDate(intDate);	
	
	cout << "Enter the name of the income: ";
	string item;
	item = AuxiliaryMethods::readLine();	
	incomes.setItem(item);	

	cout << "Enter the amount of the income: ";
	int amount;
	cin >> amount;	
	incomes.setAmount(amount);		
}

void UserManager::getAllDataToSelectedIncome()
{
	incomes.setUserId(loggedInUserId);

	int newIncomeId = incomesFile.returnVectorSize() + 1;
	incomes.setIncomeId(newIncomeId);

	cout << "Enter the date of the income in the format: yyyy-mm-dd: " << endl;
	string date;

	do 
	{
		cin >> date;

	} while (!AuxiliaryMethods::isRightWholeDate(date));	
	
	//incomes.setDate(date);
	int intDate;
	intDate = AuxiliaryMethods::convertDate(date);	
	incomes.setDate(intDate);			

	cout << "Enter the name of the income: ";
	string item;
	cin >> item;	
	incomes.setItem(item);

	cout << "Enter the amount of the income: ";
	int amount;
	cin >> amount;	
	incomes.setAmount(amount);
}

void UserManager::todayOrAnyOtherDateExpenseMenu()
{
	system("cls");
	cout << "Adding Expense" << endl;
	cout << "1. Add today's expense" << endl;
	cout << "2. Add expense witch other date" << endl;
	cout << "Your choice: ";

	int choice;
	cin.ignore();
	choice = AuxiliaryMethods::readInteger();

	switch (choice)
	{
	case 1:
		getAllDataToTodaysExpense();
		expensesFile.addExpenseToFile(expenses);		
		break;
	case 2:
		getAllDataToSelectedExpense();
		expensesFile.addExpenseToFile(expenses);
		break;
	default:
		cout << endl << "There is no such option on the menu." << endl << endl;
		system("pause");
		break;
	}
}

void UserManager::getAllDataToTodaysExpense()
{
	expenses.setUserId(loggedInUserId);

	int newExpenseId = expensesFile.returnVectorSize() + 1;
	expenses.setExpenseId(newExpenseId);

	//expenses.setDate(AuxiliaryMethods::getTodaysDate());	
	string stringDate;
	stringDate = AuxiliaryMethods::getTodaysDate();
	int intDate = AuxiliaryMethods::convertDate(stringDate);
	expenses.setDate(intDate);	

	cout << "Enter the name of the expense: ";
	string item;
	item = AuxiliaryMethods::readLine();
	expenses.setItem(item);

	cout << "Enter the amount of the expense: ";
	int amount;
	cin >> amount;
	expenses.setAmount(amount);
}

void UserManager::getAllDataToSelectedExpense()
{
	expenses.setUserId(loggedInUserId);

	int newExpenseId = expensesFile.returnVectorSize() + 1;
	expenses.setExpenseId(newExpenseId);

	cout << "Enter the date of the income in the format: yyyy-mm-dd: " << endl;
	string date;

	do
	{
		cin >> date;

	} while (!AuxiliaryMethods::isRightWholeDate(date));

	//expenses.setDate(date);
	int intDate;
	intDate = AuxiliaryMethods::convertDate(date);
	expenses.setDate(intDate);

	cout << "Enter the name of the expense: ";
	string item;
	cin >> item;
	expenses.setItem(item);

	cout << "Enter the amount of the expense: ";
	int amount;
	cin >> amount;
	expenses.setAmount(amount);
}

void UserManager::addIncome() {

	todayOrAnyOtherDateIncomeMenu();
}

void UserManager::addExpense() {
	todayOrAnyOtherDateExpenseMenu();
}

void UserManager::loadFromFile() {		
	xml.Load("incomes.xml");

	xml.FindElem("Incomes");
	xml.IntoElem();

	while (xml.FindElem("Income"))
	{
		xml.IntoElem();

		xml.FindElem("userId");
		string userId;
		userId = xml.GetData();

		int intUserId;
		intUserId = AuxiliaryMethods::convertStringToInt(userId);

		if (intUserId == loggedInUserId) {
			xml.FindElem("date");
			string date;
			date = xml.GetData();
			cout << "Data: " << date << endl;

			xml.FindElem("item");
			string item;
			item = xml.GetData();
			cout << "item: " << item << endl;

			xml.FindElem("amount");
			string amount;
			amount = xml.GetData();
			cout << "amount: " << amount << endl << endl;
		}
		xml.OutOfElem();
	}
	
}

void UserManager::showAllSortedIncomes() {
		
	system("cls");
	cout << "Incomes list" << endl;
	cout << "-------------------------" << endl;

	int size = 0;
	for (vector <Incomes>::iterator itr = vectorIncomes.begin(); itr != vectorIncomes.end(); itr++)
	{
		if (itr->getUserId() == loggedInUserId)
		{
			size++;
		}
	}

	int *tab;
	tab = new int[size];	
	int placeInDateArray = 0;
		
	for (vector <Incomes>::iterator itr = vectorIncomes.begin(); itr != vectorIncomes.end(); itr++)
	{
		if (itr->getUserId() == loggedInUserId)
		{	
			int intDate = itr->getDate();
			tab[placeInDateArray] = intDate;
			placeInDateArray++;
		}			
	}		

	AuxiliaryMethods::quickSort(tab, 0, size-1);	

	for (int i = 0; i < size; i++)
	{
		for (vector <Incomes>::iterator itr = vectorIncomes.begin(); itr != vectorIncomes.end(); itr++)
		{
			if (itr->getUserId() == loggedInUserId)
			{
				if (itr->getDate() == tab[i])
				{
					int intDate = itr->getDate();
					string stringDate = AuxiliaryMethods::dateConnectorConverter(intDate);
					cout << "Data: " << stringDate << endl;

					string item = "";
					item = itr->getItem();
					cout << "item: " << item << endl;

					int amount = 0;
					amount = itr->getAmount();
					cout << "amount: " << amount << endl << endl;
				}
			}
		}
	}

	delete[] tab;
	system("Pause");
}

void UserManager::balanceSheetForCurrentMonth() {

}

void UserManager::balanceSheetForLatestMonth() {

}

void UserManager::balanceSheetForSelectedPeriod() {

}
