#include <iostream>
#include <string>
#include "Expenses.h"

using namespace std;

//setters

void Expenses::setExpenseId(int newIncomeId) {
	if (newIncomeId >= 0)
		expenseId = newIncomeId;
}
void Expenses::setUserId(int newId) {
	if (newId >= 0)
		userId = newId;
}
void Expenses::setDate(string newDate) {
	date = newDate;
}
void Expenses::setItem(string newItem) {
	item = newItem;
}
void Expenses::setAmount(int newAmount) {
	amount = newAmount;
}

//getters

int Expenses::getExpenseId() {
	return expenseId;
}
int Expenses::getUserId() {
	return userId;
}
string Expenses::getDate() {
	return date;
}
string Expenses::getItem() {
	return item;
}
int Expenses::getAmount() {
	return amount;
}