#pragma once

#include <map>
#include "Question.h"
#include "LoggedUser.h"

struct GameData {
	Question currectQuestion;
	unsigned int correctAnswerCount;
	unsigned int wrongAnswerCount;
	unsigned int averageAnswerTime;
};

class Game {
public:
	Game(std::vector<std::string> users, std::vector<Question> questions);
	~Game();
	void submitAns(std::string user, std::string ans);
	Question getQuestion(std::string user);
	void removePlayer(std::string user);
	std::vector<std::string> getAllPlayers();
private:
	std::vector<Question> _questions;
	std::map<std::string, GameData> _players;
};