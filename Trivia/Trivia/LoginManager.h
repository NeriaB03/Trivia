#pragma once

#include <vector>
#include "IDatabase.h"
#include "LoggedUser.h"

class LoginManager {
public:
	LoginManager(IDatabase* db,std::vector<LoggedUser> loggedUsers);
	void signup(std::string username,std::string password,std::string email);
	void login(std::string username,std::string password);
	void logout(std::string username);
private:
	IDatabase* _database;
	std::vector<LoggedUser> _loggedUsers;
};