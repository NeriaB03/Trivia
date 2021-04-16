#include "LoggedUser.h"

LoggedUser::LoggedUser(std::string username)
{
	this->_username = username;
}

std::string LoggedUser::getUsername() const
{
	return this->_username;
}
