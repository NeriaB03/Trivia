#pragma once

#include "Room.h"

class RoomManager {
public:
	RoomManager();
	~RoomManager();
	bool createRoom(LoggedUser loggedUser,RoomData data);
	void deleteRoom(unsigned int id);
	unsigned int getRoomState(int id);
	std::vector<RoomData> getRooms() const;
	Room getRoomById(unsigned int id) const;
	Room getRoomByPlayerInTheRoom(std::string username);
	bool addUserToRoomById(unsigned int id,LoggedUser loggedUser);
	bool removeUserFromRoomById(unsigned int id, LoggedUser loggedUser);
	void setRoomState(unsigned int id,unsigned int newState);
	void startGame(unsigned int id);
private:
	std::map<unsigned int,Room> _rooms;
	bool checkIfRoomExist(unsigned int id) const;
	bool checkIfRoomExist(std::string name) const;
};