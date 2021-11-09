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
void Incomes::setDate(int newDate) {
	date = newDate;
}
void Incomes::setItem(string newItem) {
	item = newItem;
}
void Incomes::setAmount(int newAmount) {
	amount = newAmount;
}

//getters

int Incomes::getUserId() {
	return userId;
}
int Incomes::getIncomeId() {
	return incomeId;
}
int Incomes::getDate() {
	return date;
}
string Incomes::getItem() {
	return item;
}
int Incomes::getAmount() {
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

int IncomesFile::returnVectorSize()
{
	int vectorSize = vectorIncomes.size();

	if (vectorSize == 0)
	{
		return 0;
	}
	else {
		return vectorSize;
	}
}

void IncomesFile::addIncomeToFile(Incomes incomes) {	

	if (isIncomesFileExists(INCOMES_FILE_NAME) == true)
		xml.Load(INCOMES_FILE_NAME);
	else if (!isIncomesFileExists(INCOMES_FILE_NAME))
	{
		xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
		xml.AddElem("Incomes");
	}	

	xml.FindElem();
	xml.IntoElem();	
	xml.AddElem("Income");
	xml.IntoElem();
	xml.AddElem("userId", incomes.getUserId());		
	xml.AddElem("incomeId", incomes.getIncomeId());	
	
	int intDate = 0;
	intDate = incomes.getDate();	
	string stringDate ="";		
	stringDate = AuxiliaryMethods::dateConnectorConverter(intDate);	
	xml.AddElem("date", stringDate);

	xml.AddElem("item", incomes.getItem());
	xml.AddElem("amount", incomes.getAmount());
		

	xml.Save("incomes.xml");
	
	//vectorIncomes.push_back(incomes);
	
	cout << "Income added" << endl;
	system("Pause");
}

vector <Incomes> IncomesFile::loadAllIncomesDataFromFileToVector() {
	xml.Load("incomes.xml");

	xml.FindElem("Incomes");
	xml.IntoElem();

	while (xml.FindElem("Income"))
	{
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
		string stringDate;
		stringDate = xml.GetData();		
		int intDate;
		intDate = AuxiliaryMethods::convertDate(stringDate);
		incomes.setDate(intDate);

		xml.FindElem("item");
		string item;
		item = xml.GetData();
		incomes.setItem(item);

		xml.FindElem("amount");
		string amount;
		amount = xml.GetData();
		incomes.setAmount(AuxiliaryMethods::convertStringToInt(amount));
				
		vectorIncomes.push_back(incomes);
		xml.OutOfElem();
	}
	return vectorIncomes;
}

vector <Incomes> IncomesFile::loadIncomesFromFile() {
	loadAllIncomesDataFromFileToVector();
	return vectorIncomes;
}

