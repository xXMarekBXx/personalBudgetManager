#ifndef EXPENSES_HH
#define EXPENSES_HH

#include <iostream>
#include <string>

using namespace std;

class Expenses {
	int expenseId;
	int userId;
	string date;
	string item;
	int amount;

public:
	void setExpenseId(int newExpenseId);
	void setUserId(int newUserId);
	void setDate(string newDate);
	void setItem(string newItem);
	void setAmount(int newAmount);

	int getExpenseId();
	int getUserId();
	string getDate();
	string getItem();
	int getAmount();
};

#endif
