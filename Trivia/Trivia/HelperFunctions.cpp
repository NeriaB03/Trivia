#include "HelperFunctions.h"

std::vector<std::pair<std::string, std::string>> HelperFunctions::runSql(std::string sqlStatement, sqlite3* db)
{
	std::vector<std::pair<std::string, std::string>> callbackRetValues;
	char* messageError = nullptr;
	int res = sqlite3_exec(db, sqlStatement.c_str(), callback, &callbackRetValues, &messageError);
	if (res != SQLITE_OK) {
		sqlite3_free(messageError);
		return callbackRetValues;
	}
	return callbackRetValues;
}

bool HelperFunctions::runSqlWithoutCallback(std::string sqlStatement, sqlite3* db)
{
	char* messageError = nullptr;
	int res = sqlite3_exec(db, sqlStatement.c_str(), nullptr, nullptr, &messageError);
	if (res != SQLITE_OK) {
		std::cout << messageError << std::endl;
		sqlite3_free(messageError);
		return false;
	}
	return true;
}

int HelperFunctions::callback(void* data, int argc, char** argv, char** azColName)
{
	std::vector<std::pair<std::string, std::string>>* values = static_cast<std::vector<std::pair<std::string, std::string>>*>(data);
	for (int i = 0; i < argc; i++) {
		values->push_back(std::pair<std::string, std::string>(azColName[i], argv[i]));
	}
	return 0;
}

std::string HelperFunctions::convertVectorOfCharsToString(std::vector<char> charVector)
{
	std::string vectorAsString = "";
	for (auto const& it : charVector) {
		vectorAsString += it;
	}
	return vectorAsString;
}
