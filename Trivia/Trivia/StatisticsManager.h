#pragma once

#include "IDatabase.h"

class StatisticsManager {
public:
	StatisticsManager(IDatabase* database);
	~StatisticsManager();
	std::vector<std::string> getHighScore();
	std::vector<std::string> getUserStatistics(std::string username);
private:
	IDatabase* _database;
};