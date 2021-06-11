#include "Room.h"

Room::Room()
{
}

Room::Room(RoomData data)
{
	this->_metadata = data;
}

Room::~Room()
{
}

bool Room::addUser(LoggedUser loggedUser)
{
	if (!checkIfUserConnected(loggedUser.getUsername())) {
		this->_users.push_back(loggedUser);
		return true;
	}
	return false;
}

bool Room::removeUser(LoggedUser loggedUser)
{
	for (auto i = this->_users.begin(); i != this->_users.end(); ++i) {
		if ((*i).getUsername() == loggedUser.getUsername()) {
			this->_users.erase(i);
			return true;
		}
	}
	return false;
}

std::vector<std::string> Room::getAllUsers()
{
	std::vector<std::string> vectorToReturn;
	for (auto const& it : this->_users) {
		vectorToReturn.push_back(it.getUsername());
	}
	return vectorToReturn;
}

RoomData Room::getRoomData() const
{
	return this->_metadata;
}

void Room::setRoomState(unsigned int newState)
{
	this->_metadata.isActive = newState;
}

void Room::startGame()
{
	this->_metadata.hasGameBegun = true;
}

bool Room::checkIfUserConnected(std::string username)
{
	for (auto const& it : this->_users) {
		if (it.getUsername() == username) return true;
	}
	return false;
}
