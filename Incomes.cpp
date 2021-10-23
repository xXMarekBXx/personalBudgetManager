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
void Incomes::setAmount(float newAmount) {
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
float Incomes::getAmount() {
	return amount;
}

// other methods

bool Incomes::isIncomesFileExists(string incomesFileName) {

	if (xml.Load(incomesFileName))
	{
		return true;
	}
	else {
		return false;
	}
	return false;
}

void Incomes::addIncomeToFile() {
	
	if (isIncomesFileExists(INCOMES_FILE_NAME) == true)
		xml.Load(INCOMES_FILE_NAME);
	else if (!isIncomesFileExists(INCOMES_FILE_NAME))
	{
		xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
		xml.AddElem("Incomes");
	}
	
	xml.FindElem();
	xml.IntoElem();	
	xml.AddElem("incomeId", getIncomeId());
	xml.AddElem("userId", getUserId());
	xml.AddElem("date", getDate());
	xml.AddElem("item", getItem());
	xml.AddElem("amount", getAmount());

	xml.Save("incomes.xml");
	
}


void Incomes::getAllDataToIncome()
{	
	setDate(getTodaysDate());

	cout << "Enter the name of the income: ";
	string item;
	item = AuxiliaryMethods::readLine();
	cout << item << endl;
	setItem(item);

	cout << "Enter the amount of the income: ";
	float amount;
	cin >> amount;
	cout << amount << endl;
	setAmount(amount);

	system("pause");
}

string Incomes::getTodaysDate()
{
	string date = "";
	string year = "";
	string month = "";
	string day = "";

	SYSTEMTIME currentDate;
	GetSystemTime(&currentDate);

	cout << endl;
	cout << "Today's date: " << currentDate.wYear << "-" << currentDate.wMonth << "-" << currentDate.wDay << endl;

	year = to_string(currentDate.wYear);
	month = to_string(currentDate.wMonth);
	day = to_string(currentDate.wDay);

	date = year + "-" + month + "-" + day;
	cout << date << endl;
	system("pause");
	return date;
}

void Incomes::todayOrAnyOtherDateMenu()
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
		addIncomeToFile();
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
