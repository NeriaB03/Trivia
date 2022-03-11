#include "GameManager.h"

GameManager::GameManager(IDatabase* database)
{
	this->_database = database;
}

GameManager::~GameManager()
{
	delete this->_database;
}

Game GameManager::createGame(Room room)
{
	std::list<Question> questionsList = this->_database->getQuestions(room.getRoomData().numOfQuestionsInGame);
	std::vector<Question> questionsVector;
	for (auto const& question : questionsList) {
		questionsVector.push_back(question);
	}
	this->_games.push_back(Game(room.getAllUsers(), questionsVector));
	return this->_games.back();
}

void GameManager::deleteGame(Room room)
{
	std::vector<Game> newGamesVector;
	for (auto& game : this->_games) {
		this->_games.erase(this->_games.begin());
		if (game.getAllPlayers() == room.getAllUsers()) {
			for (auto const& player : game.getAllPlayers()) {
				game.removePlayer(player);
			}
		}
		else newGamesVector.push_back(game);
	}
	this->_games = newGamesVector;
}