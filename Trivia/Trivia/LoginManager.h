#pragma once

#include <vector>
#include "LoggedUser.h"
#include "SqliteDatabase.h"

class LoginManager {
public:
	LoginManager(IDatabase* sqliteDatabase);
	~LoginManager();
	void signup(std::string& username,std::string& password,std::string& email);
	bool login(std::string username,std::string password);
	void logout(std::string username);
	IDatabase* getDatabase() const;
private:
	IDatabase* _database;
	std::vector<LoggedUser> _loggedUsers;
};