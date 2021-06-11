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
	bool hasGameBegun;
};

class Room {
public:
	Room();
	Room(RoomData data);
	~Room();
	bool addUser(LoggedUser loggedUser);
	bool removeUser(LoggedUser loggedUser);
	std::vector<std::string> getAllUsers();
	RoomData getRoomData() const;
	void setRoomState(unsigned int newState);
	void startGame();
private:
	RoomData _metadata;
	std::vector<LoggedUser> _users;
	bool checkIfUserConnected(std::string username);
};