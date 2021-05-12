#pragma once

#include <vector>
#include <map>
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
	Room();
	Room(RoomData data);
	~Room();
	void addUser(LoggedUser loggedUser);
	void removeUser(LoggedUser loggedUser);
	std::vector<std::string> getAllUsers();
	RoomData getRoomData() const;
private:
	RoomData _metadata;
	std::vector<LoggedUser> _users;
	bool checkIfUserConnected(std::string username);
};