#include "SqliteDatabase.h"

SqliteDatabase::SqliteDatabase()
{
	if(!openTable()) throw std::exception(__FUNCTION__ " - Failed while open database!");
}

SqliteDatabase::~SqliteDatabase()
{
	sqlite3_close(this->_db);
	this->_db = nullptr;
	delete this->_db;
}

bool SqliteDatabase::doesUserExist(std::string& username)
{
	std::string sqlStatement = "SELECT * FROM USERS WHERE NAME LIKE '" + username + "';";
	std::vector<std::pair<std::string, std::string>> usersVector = HelperFunctions::runSql(sqlStatement, this->_db);
	if (usersVector.size() == 0) return false;
	return true;
}

bool SqliteDatabase::doesPasswordMatch(std::string& username, std::string& password)
{
	std::string sqlStatement = "SELECT * FROM USERS WHERE NAME LIKE '" + username + "' AND PASSWORD LIKE '" + password + "';";
	std::vector<std::pair<std::string, std::string>> usersVector = HelperFunctions::runSql(sqlStatement, this->_db);
	if (usersVector.size() == 0) return false;
	return true;
}

void SqliteDatabase::addNewUser(std::string& username, std::string& password, std::string& email)
{
	std::string sqlStatement = "INSERT INTO USERS('NAME','PASSWORD','EMAIL')VALUES('" + username + "','" + password + "','" + email + "');";
	HelperFunctions::runSqlWithoutCallback(sqlStatement, this->_db);
}

bool SqliteDatabase::openTable()
{
	int doesFileExist = _access(this->_dbFileName.c_str(), 0);
	int res = sqlite3_open(this->_dbFileName.c_str(), &this->_db);
	std::string sqlStatement = "";
	if (res != SQLITE_OK) {
		this->_db = nullptr;
		return false;
	}
	if (doesFileExist != 0) {
		sqlStatement = "CREATE TABLE USERS (NAME TEXT PRIMARY KEY NOT NULL, PASSWORD TEXT NOT NULL, EMAIL TEXT NOT NULL);";
		if (!HelperFunctions::runSqlWithoutCallback(sqlStatement, this->_db)) return false;
	}
	return true;
}
