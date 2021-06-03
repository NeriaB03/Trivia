#pragma once

#include <iostream>
#include <vector>
#include "sqlite3.h"
#include "Room.h"

class HelperFunctions {
public:
	static std::vector<std::pair<std::string, std::string>> runSql(std::string sqlStatement, sqlite3* db);
	static bool runSqlWithoutCallback(std::string sqlStatement, sqlite3* db);
	static int callback(void* data, int argc, char** argv, char** azColName);
	static std::string convertVectorOfCharsToString(std::vector<char> charVector);
	static RequestResult getRoomState(Room room);
};