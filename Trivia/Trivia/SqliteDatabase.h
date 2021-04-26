#pragma once

#include "IDatabase.h"

class SqliteDatabase : public IDatabase {
public:
	SqliteDatabase();
	virtual bool doesUserExist(std::string username);
	virtual bool doesPasswordMatch(std::string username, std::string password);
	virtual void addNewUser(std::string username, std::string password, std::string email);
private:
	virtual bool openTable();
	sqlite3* _db;
	std::string _dbFileName = "DB.sqlite";
};