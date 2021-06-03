#include "StatisticsManager.h"

StatisticsManager::StatisticsManager(IDatabase* database)
{
	this->_database = database;
}

StatisticsManager::~StatisticsManager()
{
}

std::vector<std::string> StatisticsManager::getUserStatistics(std::string username)
{
	std::string sqlStatement = "SELECT * FROM STATISTICS WHERE NAME LIKE '" + username + "';";
	std::vector<std::pair<std::string, std::string>> statistics = HelperFunctions::runSql(sqlStatement, this->_database->getDatabase());
	std::vector<std::string> userStatistics;
	for (auto const& it : statistics) {
		std::cout << statistics.front().second << std::endl;
		userStatistics.push_back(statistics.front().second);
		statistics.erase(statistics.begin());
	}
	return userStatistics;
}

std::vector<std::string> StatisticsManager::getHighScore()
{
	std::string sqlStatement = "SELECT NAME FROM STATISTICS ORDER BY HIGHEST_SCORE DESC LIMIT 3;";
	std::vector<std::pair<std::string,std::string>> highestScoresUsername = HelperFunctions::runSql(sqlStatement, this->_database->getDatabase());
	std::vector<std::string> highestScores;
	for (auto const& it : highestScoresUsername) {
		highestScores.push_back(it.second); //add the username to the vector
	}
	return highestScores;
}
