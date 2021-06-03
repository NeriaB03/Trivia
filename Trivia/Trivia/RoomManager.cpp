#include "RoomManager.h"

RoomManager::RoomManager()
{
}

RoomManager::~RoomManager()
{
}

bool RoomManager::createRoom(LoggedUser loggedUser, RoomData data)
{
	if (!checkIfRoomExist(data.name)) {
		this->_rooms.insert(std::pair<unsigned int, Room>(data.id, Room(data)));
		return true;
	}
	return false;
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

Room RoomManager::getRoomById(unsigned int id) const
{
	for (auto const& it : this->_rooms) {
		if (it.second.getRoomData().id == id) {
			return it.second;
		}
	}
	throw std::exception("Error - Room is not exist");
}

bool RoomManager::checkIfRoomExist(unsigned int id) const
{
	return this->_rooms.find(id) != this->_rooms.end(); //if the room exist the room is not equal to the end of the rooms map
}

bool RoomManager::checkIfRoomExist(std::string name) const
{
	for (auto const& it : this->_rooms)
		if (it.second.getRoomData().name == name) return true;
	return false;
}

