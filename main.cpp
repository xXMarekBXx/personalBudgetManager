#include <iostream>
#include "PersonalBudgetManager.h"

using namespace std;

int main() {
		
	PersonalBudgetManager personalBudgetManager("users.xml");

	while (true)
	{
		if (personalBudgetManager.isUserLoggedIn() == false)
		{
			system("cls");
			cout << "    >>> MENU <<<" << endl;
			cout << "-----------------------------" << endl;
			cout << "1. Registration" << endl;
			cout << "2. Log in" << endl;
			cout << "9. Close the program" << endl;
			cout << "Your choice: ";
			int choice;			
			choice = AuxiliaryMethods::readInteger();

			switch (choice)
			{
			case 1:
				personalBudgetManager.userRegistration();
				break;
			case 2:
				personalBudgetManager.userLoggingIn();
				break;
			case 9:
				exit(0);
				break;
			default:
				cout << endl << "There is no such option on the menu." << endl << endl;
				system("pause");
				exit(0);
				break;
			}
		}
		else {
			system("cls");
			cout << " >>> USER MENU <<<" << endl;
			cout << "---------------------------" << endl;
			cout << "1. Add Income" << endl;
			cout << "2. Add an Expense" << endl;
			cout << "3. Balance sheet for the current month" << endl;
			cout << "4. Balance sheet for the latest month" << endl;
			cout << "5. Balance sheet for the selected period" << endl;
			cout << "---------------------------" << endl;			
			cout << "6. Change Password" << endl;
			cout << "7. Log out" << endl;
			cout << "---------------------------" << endl;
			cout << "Your choice: ";
			int choice;
			cin >> choice;

			switch (choice)
			{
			case 1:
				;//personalBudgetManager.addIncome();
				break;
			case 2:
				;//personalBudgetManager.addExpense();
				break;
			case 3:
				;//personalBudgetManager.balanceSheetForCurrentMonth();
				break;
			case 4:
				;//personalBudgetManager.balanceSheetForLatestMonth();
				break;
			case 5:
				;//personalBudgetManager.balanceSheetForSelectedPeriod();
				break;
			case 6:
				personalBudgetManager.loggedInUserPasswordChanging(); // teraz to -> plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
				break;
			case 7:
				personalBudgetManager.userloggingOut();
				break;			
			}
		}
	}
}
