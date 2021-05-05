#include "Room.h"

Room::Room(RoomData data)
{
	this->_metadata = data;
}

bool Room::addUser(LoggedUser loggedUser)
{
	if (checkIfUserConnected(loggedUser.getUsername())) return false; //if user already connected return false
	this->_users.push_back(loggedUser);
	return true;
}

bool Room::removeUser(LoggedUser loggedUser)
{
	for (auto i = this->_users.begin(); i != this->_users.end(); ++i) {
		if ((*i).getUsername() == loggedUser.getUsername()) {
			this->_users.erase(i);
			i--;
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

bool Room::checkIfUserConnected(std::string username)
{
	for (auto const& it : this->_users) {
		if (it.getUsername() == username) return true;
	}
	return false;
}
