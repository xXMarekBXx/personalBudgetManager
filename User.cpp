#include "User.h"

using namespace std;

void User::setUserId(int newId) {
	if(newId >=0)
		userId = newId;
}
void User::setLogin(string newLogin) {
	login = newLogin;
}
void User::setPassword(string newPassword) {
	password = newPassword;
}
void User::setName(string newName) {
	name = newName;
}
void User::setSurname(string newSurname) {
	surname = newSurname;
}
int User::getUserId() {
	return userId;
}
string User::getLogin() {
	return login;
}
string User::getPassword() {
	return password;
}
string User::getName() {
	return name;
}
string User::getSurname() {
	return surname;
}

///////////////////////////////////////////////////////////

bool UsersFile::isUsersFileEmpty(fstream &xmlFile) {
	xmlFile.seekg(0, ios::end);
	if (xmlFile.tellg() == 0)
		return true;
	else
		return false;
}

bool UsersFile::isUsersFileExists(string usersFileName) {
	bool fileExists;
	
	if (xml.Load(usersFileName))
	{
		return true;
	}
	else {
		return false;
	}	
	return false;
}

void UsersFile::addUserToFile(User user) {
	if(isUsersFileExists(USERS_FILE_NAME)==true)
	xml.Load(USERS_FILE_NAME);
	else if (!isUsersFileExists(USERS_FILE_NAME))
	{
		xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
		xml.AddElem("Users");
	}	

	xml.FindElem();
	xml.IntoElem();
	xml.AddElem("User");
	xml.IntoElem();	
	xml.AddElem("UserId", user.getUserId());
	xml.AddElem("Login", user.getLogin());
	xml.AddElem("Password", user.getPassword());
	xml.AddElem("Name", user.getName());
	xml.AddElem("Surname", user.getSurname());

	xml.Save("users.xml");	
}

int UsersFile::getUserIdFromFile() {
	xml.Load(USERS_FILE_NAME);
	xml.FindElem();
	xml.IntoElem();
	xml.FindElem();
	xml.IntoElem();
	xml.FindElem("UserId");
	int userId;
	userId  = AuxiliaryMethods::convertStringToInt(xml.GetData());

	return userId;
}

string UsersFile::getUserLoginFromFile() {
	xml.Load(USERS_FILE_NAME);
	xml.FindElem();
	xml.IntoElem();
	xml.FindElem();
	xml.IntoElem();
	xml.FindElem("Login");
	string login;
	login = xml.GetData();

	return login;
}

string UsersFile::getUserPasswordFromFile() {
	xml.Load(USERS_FILE_NAME);
	xml.FindElem();
	xml.IntoElem();
	xml.FindElem();
	xml.IntoElem();
	xml.FindElem("Password");
	string password;
	password = xml.GetData();

	return password;
}

string UsersFile::getUserNameFromFile() {
	xml.Load(USERS_FILE_NAME);
	xml.FindElem();
	xml.IntoElem();
	xml.FindElem();
	xml.IntoElem();
	xml.FindElem("Name");
	string name;
	name = xml.GetData();

	return name;
}

string UsersFile::getUserSurnameFromFile() {
	xml.Load(USERS_FILE_NAME);
	xml.FindElem();
	xml.IntoElem();
	xml.FindElem();
	xml.IntoElem();
	xml.FindElem("Surname");
	string surname;
	surname = xml.GetData();

	return surname;
}

User UsersFile::getUsersData()
{
	user.setUserId(getUserIdFromFile());
	user.setLogin(getUserLoginFromFile());
	user.setPassword(getUserPasswordFromFile());
	user.setName(getUserNameFromFile());
	user.setSurname(getUserSurnameFromFile());

	return user;
}

vector <User> UsersFile::loadUsersFromFile()
{	
	xml.Load(USERS_FILE_NAME);		
	
	user = getUsersData();
	users.push_back(user);
		
	return users;
}