#include "RoomManager.h"

RoomManager::RoomManager()
{
}

RoomManager::~RoomManager()
{
}

void RoomManager::createRoom(LoggedUser loggedUser, RoomData data)
{
	if (!checkIfRoomExist(data.id)) this->_rooms.insert(std::pair<unsigned int, Room>(data.id,Room(data)));
}

void RoomManager::deleteRoom(unsigned int id)
{
	if(checkIfRoomExist(id)) this->_rooms.erase(id);
}

unsigned int RoomManager::getRoomState(int id)
{
	if (checkIfRoomExist(id)) return this->_rooms[id].getRoomData().isActive;
	return 0;
}

std::vector<RoomData> RoomManager::getRooms() const
{
	std::vector<RoomData> vectorToReturn;
	for (auto const& room : this->_rooms) {
		vectorToReturn.push_back(room.second.getRoomData());
	}
	return vectorToReturn;
}

bool RoomManager::checkIfRoomExist(unsigned int id) const
{
	return this->_rooms.find(id) != this->_rooms.end(); //if the room exist the room is not equal to the end of the rooms map
}
