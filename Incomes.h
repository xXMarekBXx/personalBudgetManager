#ifndef INCOMES_HH
#define INCOMES_HH

#include <iostream>
#include <string>

using namespace std;

class Incomes {
	int incomeId;
	int userId;
	string date;
	string item;
	int amount;	

public:
	void setIncomeId(int newIncomeId);
	void setUserId(int newUserId);
	void setDate(string newDate);
	void setItem(string newItem);
	void setAmount(int newAmount);
	
	int getIncomeId();
	int getUserId();
	string getDate();
	string getItem();
	int getAmount();	
};

#endif
