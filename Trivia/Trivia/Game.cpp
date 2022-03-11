#include "Game.h"

Game::Game(std::vector<std::string> users, std::vector<Question> questions)
{
	//for (auto const& it : users) {
	//	GameData gameData = {
	//		getQuestion(it),
	//		1,//always only one correct answer
	//		getQuestion(it).getAnswers().size(),//get amount of incorrect answers
	//		0,//the user didn't answer any question yet
	//	};
	//	this->_players[it] = gameData;
	//}
	//this->_questions = questions;
}

Game::~Game()
{
}

void Game::submitAns(std::string user, std::string ans)
{
	//if (ans == this->_players[user].currectQuestion.getCorrectAnswer()) this->_players[user].correctAnswerCount++;
	//else this->_players[user].wrongAnswerCount++;
}

Question Game::getQuestion(std::string user)
{
	if (this->_questions.size() != 0) {
		Question q(this->_questions.front());
		this->_questions.erase(this->_questions.begin());
		return q;
	}
	throw std::exception("Error - No more questions");
}

void Game::removePlayer(std::string user)
{
	this->_players.erase(user);
}

std::vector<std::string> Game::getAllPlayers()
{
	std::vector<std::string> allPlayers;
	for (auto const& it : this->_players) {
		allPlayers.push_back(it.first);
	}
	return allPlayers;
}