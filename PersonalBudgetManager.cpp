#include "PersonalBudgetManager.h"

void PersonalBudgetManager::userRegistration() {
	userManager.userRegistration();
}

void PersonalBudgetManager::userLoggingIn() {
	userManager.userLoggingIn();		
}

void PersonalBudgetManager::loggedInUserPasswordChanging() {
	userManager.loggedInUserPasswordChanging();
}

void PersonalBudgetManager::userloggingOut() {
	userManager.userloggingOut();
}

bool PersonalBudgetManager::isUserLoggedIn() {
	bool isLoggedIn;
	isLoggedIn = userManager.isUserLoggedIn();
	if (isLoggedIn == true)
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

void PersonalBudgetManager::displayBalanceSheetForCurrentMonth() {
	userManager.balanceSheetForCurrentMonth();
}

void PersonalBudgetManager::balanceSheetForLatestMonth() {
	userManager.balanceSheetForLatestMonth();
}

void PersonalBudgetManager::balanceSheetForSelectedPeriod() {
	userManager.balanceSheetForSelectedPeriod();
}
