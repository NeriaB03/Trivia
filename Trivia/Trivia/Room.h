#pragma once

#include <vector>
#include "LoggedUser.h"

struct RoomData {
	unsigned int id;
	std::string name;
	unsigned int maxPlayers;
	unsigned int numOfQuestionsInGame;
	unsigned int timePerQuestion;
	unsigned int isActive;
};

class Room {
public:
	Room(RoomData data);
	bool addUser(LoggedUser loggedUser);
	bool removeUser(LoggedUser loggedUser);
	std::vector<std::string> getAllUsers();
private:
	RoomData _metadata;
	std::vector<LoggedUser> _users;
	bool checkIfUserConnected(std::string username);
};