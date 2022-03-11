#include "LoginManager.h"

LoginManager::LoginManager(IDatabase* sqliteDatabase)
{
	this->_database = sqliteDatabase;
}

LoginManager::~LoginManager()
{
}

void LoginManager::signup(std::string& username, std::string& password, std::string& email)
{
	this->_database->addNewUser(username,password,email);
}

bool LoginManager::login(std::string username, std::string password)
{
	LoggedUser loggedUser(username);
	for (auto const& it : this->_loggedUsers) {
		if (it.getUsername() == username) return false; //if the user already connected return false
	}
	this->_loggedUsers.push_back(loggedUser);
	return true;
}

void LoginManager::logout(std::string username)
{
	if (this->_database->doesUserExist(username)) {
		for (auto i = this->_loggedUsers.begin(); i != this->_loggedUsers.end(); ++i) {
			if ((*i).getUsername() == username) {
				this->_loggedUsers.erase(i);
				break;
			}
		}
	}
}

IDatabase* LoginManager::getDatabase() const
{
	return this->_database;
}
