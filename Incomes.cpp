#include <iostream>
#include <string>
#include "Incomes.h"

using namespace std;

//setters

void Incomes::setIncomeId(int newIncomeId) {
	if (newIncomeId >= 0)
		incomeId = newIncomeId;
}
void Incomes::setUserId(int newId) {
	if (newId >= 0)
		userId = newId;
}
void Incomes::setDate(string newDate) {
	date = newDate;
}
void Incomes::setItem(string newItem) {
	item = newItem;
}
void Incomes::setAmount(int newAmount) {
	amount = newAmount;
}

//getters

int Incomes::getIncomeId() {
	return incomeId;
}
int Incomes::getUserId() {
	return userId;
}
string Incomes::getDate() {
	return date;
}
string Incomes::getItem() {
	return item;
}
int Incomes::getAmount() {
	return amount;
}