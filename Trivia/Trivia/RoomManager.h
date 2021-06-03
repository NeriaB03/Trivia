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
private:
	std::map<unsigned int,Room> _rooms;
	bool checkIfRoomExist(unsigned int id) const;
	bool checkIfRoomExist(std::string name) const;
};