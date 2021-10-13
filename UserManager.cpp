#include "UserManager.h"
#include "User.h"

int UserManager::getNewUserId() {
	return loggedInUserId;
}

void UserManager::userRegistration() {

	User user = getNewUserData();

	users.push_back(user);
	//plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

	cout << "Account created successfully" << endl << endl;
	system("pause");
}

User UserManager::getNewUserData() {

	User user;

	user.setUserId(getNewUserId());

	string login;

	do
	{
		cout << "Enter your login: ";
		cin >> login;

		user.setLogin(login);

	} while (isLoginExist(user.getLogin()) == true);

	cout << "Enter your password: ";
	string haslo;
	cin >> haslo;
	user.setPassword(haslo);

	return user;
}

int  UserManager::getLoggedInUserId() {

	if (users.empty() == true)
		return 1;
	else
		return users.back().getUserId() + 1;
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

void UserManager::loggedInUserPasswordChanging() {
	User user;

	string newPassword = "";

	cout << "Enter new password: ";

	cin >> newPassword;
		
	for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
	{
		if (itr->getUserId() == loggedInUserId)
		{
			itr->setPassword(newPassword);
			cout << "Password has been changed." << endl << endl;
			system("pause");
		}
	}
	//plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}

int UserManager::userloggingOut() {
	loggedInUserId = 0;
	return loggedInUserId;
}

bool UserManager::isRightWholeDate(string date) {
	string year = AuxiliaryMethods::dateDividerYear(date);
	string month = AuxiliaryMethods::dateDividerMonth(date);
	string day = AuxiliaryMethods::dateDividerDay(date);

	if (AuxiliaryMethods::isRightYear(year) && AuxiliaryMethods::isRightMonth(month) && AuxiliaryMethods::isRightDay(day))
	{
		cout << "Right Date!" << endl;
		return true;
	}

	return false;
}

int UserManager::dateMergerConverter(string date) {
	string year = "";
	string month = "";
	string day = "";
	string wholeDate = "";
	int intWholeDate = 0;

	year = AuxiliaryMethods::dateDividerYear(date);
	month = AuxiliaryMethods::dateDividerMonth(date);
	day = AuxiliaryMethods::dateDividerDay(date);
	wholeDate = year + month + day;
	intWholeDate = AuxiliaryMethods::convertStringToInt(wholeDate);

	return intWholeDate;
}

int UserManager::convertDate(string date) {

	if (isRightWholeDate(date))	{

		return dateMergerConverter(date);
	}
	return 0;
}

void UserManager::addIncome() {

}

void UserManager::addExpense() {

}

void UserManager::balanceSheetForCurrentMonth() {

}

void UserManager::balanceSheetForLatestMonth() {

}

void UserManager::balanceSheetForSelectedPeriod() {

}
