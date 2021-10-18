#ifndef USER_HH
#define USER_HH

#include <iostream>
#include <string>
#include <windows.h>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include "Markup.h"
#include "AuxiliaryMethods.h"

using namespace std;

class User {
	int userId;
	string login;
	string password;
	string name;
	string surname;

public:
	void setUserId(int newId);
	void setLogin(string newLogin);
	void setPassword(string newPassword);
	void setName(string name);
	void setSurname(string surname);

	int getUserId();
	string getLogin();
	string getPassword();
	string getName();
	string getSurname();
};

/////////////////////////////////////////////////////////////////////

class UsersFile
{
	CMarkup xml;
	const string USERS_FILE_NAME="users.xml";	
	vector <User> users;
	User user;

	bool isUsersFileEmpty(fstream &xmlFile);
	bool isUsersFileExists(string usersFileName);
	int getUserIdFromFile();
	string getUserLoginFromFile();
	string getUserPasswordFromFile();
	string getUserNameFromFile();
	string getUserSurnameFromFile();
	User getUsersData();

	
public:
	UsersFile(string usersFileName) : USERS_FILE_NAME(usersFileName) {};	
	void addUserToFile(User user);
	vector <User> loadUsersFromFile();	
};

#endif
