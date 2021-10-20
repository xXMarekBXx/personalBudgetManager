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

User UsersFile::getAllDataOneSingleUserFromFile() {

	xml.Load(USERS_FILE_NAME);
	xml.FindElem();
	xml.IntoElem();
	xml.FindElem();
	xml.IntoElem();

	xml.FindElem("UserId");
	string userId;
	userId = xml.GetData();	
	user.setUserId(AuxiliaryMethods::convertStringToInt(userId));

	xml.FindElem("Login");
	string login;
	login = xml.GetData();
	user.setLogin(login);

	xml.FindElem("Password");
	string password;
	password = xml.GetData();
	user.setPassword(password);

	xml.FindElem("Name");
	string name;
	name = xml.GetData();
	user.setName(name);

	xml.FindElem("Surame");
	string surname;
	surname = xml.GetData();
	user.setSurname(surname);

	return user;
}

vector <User> UsersFile::loadAllUsersDataFromFileToVector()
{
	xml.Load("users.xml");

	xml.FindElem("Users");
	xml.IntoElem();

	while (xml.FindElem("User"))
	{
		xml.IntoElem();

		xml.FindElem("UserId");
		string userId;
		userId = xml.GetData();
		user.setUserId(AuxiliaryMethods::convertStringToInt(userId));

		xml.FindElem("Login");
		string login;
		login = xml.GetData();
		user.setLogin(login);

		xml.FindElem("Password");
		string password;
		password = xml.GetData();
		user.setPassword(password);

		xml.FindElem("Name");
		string name;
		name = xml.GetData();
		user.setName(name);

		xml.FindElem("Surame");
		string surname;
		surname = xml.GetData();
		user.setSurname(surname);

		users.push_back(user);
		xml.OutOfElem();		
	}	
	return users;
}

vector <User> UsersFile::loadUsersFromFile() {		
	loadAllUsersDataFromFileToVector();		
	return users;
}
