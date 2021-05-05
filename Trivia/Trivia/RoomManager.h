#pragma once

#include "Room.h"

class RoomManager {
public:
	RoomManager();
	~RoomManager();
	void createRoom(LoggedUser loggedUser,RoomData data);
	void deleteRoom(unsigned int id);
	unsigned int getRoomState(int id);
	std::vector<RoomData> getRooms() const;
private:
	std::map<unsigned int,Room> _rooms;
	bool checkIfRoomExist(unsigned int id) const;
};