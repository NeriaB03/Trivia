#pragma once

#include "Game.h"
#include "IDatabase.h"
#include "Room.h"

class GameManager {
public:
	GameManager(IDatabase* database);
	~GameManager();
	Game createGame(Room room);
	void deleteGame(Room room);
private:
	IDatabase* _database;
	std::vector<Game> _games;
};