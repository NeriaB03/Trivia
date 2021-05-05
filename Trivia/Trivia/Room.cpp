#include "Room.h"

Room::Room(RoomData data)
{
	this->_metadata = data;
}

Room::~Room()
{
}

void Room::addUser(LoggedUser loggedUser)
{
	if (!checkIfUserConnected(loggedUser.getUsername())) this->_users.push_back(loggedUser);
}

void Room::removeUser(LoggedUser loggedUser)
{
	for (auto i = this->_users.begin(); i != this->_users.end(); ++i) {
		if ((*i).getUsername() == loggedUser.getUsername()) {
			this->_users.erase(i);
			i--;
		}
	}
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

bool Room::checkIfUserConnected(std::string username)
{
	for (auto const& it : this->_users) {
		if (it.getUsername() == username) return true;
	}
	return false;
}
