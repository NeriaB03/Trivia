#include "LoginManager.h"

LoginManager::LoginManager(IDatabase* db, std::vector<LoggedUser> loggedUsers)
{
	this->_database = db;
	this->_loggedUsers = loggedUsers;
}

void LoginManager::signup(std::string username, std::string password, std::string email)
{
	this->_database->addNewUser(username,password,email);
}

void LoginManager::login(std::string username, std::string password)
{
	if (this->_database->doesPasswordMatch(username, password)) {
		LoggedUser loggedUser(username);
		this->_loggedUsers.push_back(loggedUser);
	}
}

void LoginManager::logout(std::string username)
{
	if (this->_database->doesUserExist(username)) {
		for (auto i = this->_loggedUsers.begin(); i != this->_loggedUsers.end(); ++i) {
			if ((*i).getUsername() == username) {
				this->_loggedUsers.erase(i);
				i--;
			}
		}
	}
}
