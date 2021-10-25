#include <iostream>
#include <string>
#include "Incomes.h"

using namespace std;

//setters

void Incomes::setUserId(int newId) {
	if (newId >= 0)
		userId = newId;
}
void Incomes::setIncomeId(int newIncomeId) {
	if (newIncomeId >= 0)
		incomeId = newIncomeId;
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

int Incomes::getUserId() {
	return userId;
}
int Incomes::getIncomeId() {
	return incomeId;
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

///////////////////////////////////////////////////////////////////////////////

bool IncomesFile::isIncomesFileExists(string incomesFileName) {

	if (xml.Load(incomesFileName))
	{
		return true;
	}
	else {
		return false;
	}
	return false;
}

int IncomesFile::getLastIncomeId() {
		
	xml.Load(INCOMES_FILE_NAME);
	
	while (xml.FindElem("Incomes"))
	{
		xml.IntoElem();

		xml.FindElem("incomeId");
		string incomeId;
		incomeId = xml.GetData();
		return AuxiliaryMethods::convertStringToInt(incomeId);
		xml.OutOfElem();
	}
	
	if (!xml.Load(INCOMES_FILE_NAME))
		return 0;
}

int IncomesFile::getNextIncomeId()
{
	int newIncomeId = 0;
	newIncomeId = getLastIncomeId() + 1;
	return newIncomeId;
}

int IncomesFile::getNewIncomeId() {
	return vectorIncomes.back().getIncomeId() + 1;
	if (vectorIncomes.empty())
		return 1;
}

void IncomesFile::increaseIncomeId(Incomes incomes)
{
	incomes.setIncomeId(getNewIncomeId());
	vectorIncomes.push_back(incomes);
}

void IncomesFile::addIncomeToFile(Incomes incomes) {
	
	if (isIncomesFileExists(INCOMES_FILE_NAME) == true)
		xml.Load(INCOMES_FILE_NAME);
	else if (!isIncomesFileExists(INCOMES_FILE_NAME))
	{
		xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
		xml.AddElem("Incomes");
	}
	
	xml.FindElem("Incomes");
	xml.IntoElem();		
	xml.AddElem("userId", incomes.getUserId());	
	increaseIncomeId(incomes);
	xml.AddElem("incomeId", incomes.getIncomeId());
	xml.AddElem("date", incomes.getDate());
	xml.AddElem("item", incomes.getItem());
	xml.AddElem("amount", incomes.getAmount());

	xml.Save("incomes.xml");
	
	cout << "Income added" << endl;
	system("Pause");
}

vector <Incomes> IncomesFile::loadAllIncomesDataFromFileToVector()
{
	xml.Load("incomes.xml");

	xml.FindElem("Incomes");
	xml.IntoElem();

	xml.FindElem("userId");
	string userId;
	userId = xml.GetData();
	incomes.setUserId(AuxiliaryMethods::convertStringToInt(userId));
	
	xml.FindElem("incomeId");
	string incomeId;
	incomeId = xml.GetData();
	incomes.setIncomeId(AuxiliaryMethods::convertStringToInt(incomeId));
	
	xml.FindElem("date");
	string date;
	date = xml.GetData();
	incomes.setDate(date);

	xml.FindElem("item");
	string item;
	item = xml.GetData();
	incomes.setItem(item);

	xml.FindElem("amount");
	string amount;
	incomeId = xml.GetData();
	incomes.setAmount(AuxiliaryMethods::convertStringToInt(incomeId));
	
	vectorIncomes.push_back(incomes);
	
	return vectorIncomes;
}


vector <Incomes> IncomesFile::loadIncomesFromFile() {
	loadAllIncomesDataFromFileToVector();
	return vectorIncomes;
}

