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
void Expenses::setDate(int newDate) {
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
int Expenses::getDate() {
	return date;
}
string Expenses::getItem() {
	return item;
}
int Expenses::getAmount() {
	return amount;
}

///////////////////////////////////////////////////////////////////////////////

bool ExpensesFile::isExpensesFileExists(string expensesFileName) {

	if (xml.Load(expensesFileName))
	{
		return true;
	}
	else {
		return false;
	}
	return false;
}

int ExpensesFile::returnVectorSize() {
	int vectorSize = vectorExpenses.size();

	if (vectorSize == 0)
	{
		return 0;
	}
	else {
		return vectorSize;
	}
}

void ExpensesFile::addExpenseToFile(Expenses expenses) {

	if (isExpensesFileExists(EXPENSES_FILE_NAME) == true)
		xml.Load(EXPENSES_FILE_NAME);
	else if (!isExpensesFileExists(EXPENSES_FILE_NAME))
	{
		xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
		xml.AddElem("Expenses");
	}

	xml.FindElem();
	xml.IntoElem();
	xml.AddElem("Expense");
	xml.IntoElem();
	xml.AddElem("userId", expenses.getUserId());
	xml.AddElem("expenseId", expenses.getExpenseId());
	
	int intDate;
	intDate = expenses.getDate();	
	string stringDate;
	stringDate = AuxiliaryMethods::dateConnectorConverter(intDate);	
	xml.AddElem("date", stringDate);
	
	xml.AddElem("item", expenses.getItem());
	xml.AddElem("amount", expenses.getAmount());

	xml.Save("expenses.xml");

	vectorExpenses.push_back(expenses);

	cout << "Expense added" << endl;
	system("Pause");
}

vector <Expenses> ExpensesFile::loadAllExpensesDataFromFileToVector() {
	xml.Load(EXPENSES_FILE_NAME);

	xml.FindElem("Expenses");
	xml.IntoElem();

	while (xml.FindElem("Expense"))
	{
		xml.IntoElem();

		xml.FindElem("userId");
		string userId;
		userId = xml.GetData();
		expenses.setUserId(AuxiliaryMethods::convertStringToInt(userId));

		xml.FindElem("expenseId");
		string expenseId;
		expenseId = xml.GetData();
		expenses.setExpenseId(AuxiliaryMethods::convertStringToInt(expenseId));

		xml.FindElem("date");
		string stringDate;
		stringDate = xml.GetData();		
		int intDate;
		intDate = AuxiliaryMethods::convertDate(stringDate);
		expenses.setDate(intDate);
		
		xml.FindElem("item");
		string item;
		item = xml.GetData();
		expenses.setItem(item);

		xml.FindElem("amount");
		string amount;
		amount = xml.GetData();
		expenses.setAmount(AuxiliaryMethods::convertStringToInt(amount));

		vectorExpenses.push_back(expenses);
		xml.OutOfElem();
	}
	return vectorExpenses;
}


vector <Expenses> ExpensesFile::loadExpensesFromFile() {
	loadAllExpensesDataFromFileToVector();
	return vectorExpenses;
}

