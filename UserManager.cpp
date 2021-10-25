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
	User user;

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

void UserManager::todayOrAnyOtherDateMenu()
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
		getAllDataToIncome();
		incomesFile.addIncomeToFile(incomes);		
		break;
	case 2:
		;
		break;
	default:
		cout << endl << "There is no such option on the menu." << endl << endl;
		system("pause");
		break;
	}
}

void UserManager::getAllDataToIncome()
{	
	incomes.setUserId(loggedInUserId);	
	incomes.setIncomeId(incomesFile.getNextIncomeId());
	incomes.setDate(AuxiliaryMethods::getTodaysDate());

	cout << "Enter the name of the income: ";
	string item;
	item = AuxiliaryMethods::readLine();
	cout << item << endl;
	incomes.setItem(item);

	cout << "Enter the amount of the income: ";
	float amount;
	cin >> amount;
	cout << amount << endl;
	incomes.setAmount(amount);
}

void UserManager::addIncome() {

	todayOrAnyOtherDateMenu();
}

void UserManager::addExpense() {

}

void UserManager::balanceSheetForCurrentMonth() {

}

void UserManager::balanceSheetForLatestMonth() {

}

void UserManager::balanceSheetForSelectedPeriod() {

}
