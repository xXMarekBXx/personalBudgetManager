#include "PersonalBudgetManager.h"

void PersonalBudgetManager::userRegistration() {
	userManager.userRegistration();
}

bool PersonalBudgetManager::userLoggingIn() {
	userManager.userLoggingIn(); // loggedInUserId
	if ((userManager.isUserLoggedIn())==true)
	{
		return true;
	}	
	return false;
}

void PersonalBudgetManager::loggedInUserPasswordChanging() {
	userManager.loggedInUserPasswordChanging();
}

void PersonalBudgetManager::userloggingOut() {
	userManager.userloggingOut();
}

bool PersonalBudgetManager::isUserLoggedIn() {
	if (userManager.isUserLoggedIn() > 0)
		return true;
	else
		return false;
}

void PersonalBudgetManager::addIncome() {
	userManager.addIncome();
}

void PersonalBudgetManager::addExpense() {
	userManager.addExpense();
}

void PersonalBudgetManager::balanceSheetForCurrentMonth() {
	userManager.balanceSheetForCurrentMonth();
}

void PersonalBudgetManager::balanceSheetForLatestMonth() {
	userManager.balanceSheetForLatestMonth();
}

void PersonalBudgetManager::balanceSheetForSelectedPeriod() {
	userManager.balanceSheetForSelectedPeriod();
}
