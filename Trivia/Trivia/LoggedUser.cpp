#include "LoggedUser.h"

LoggedUser::LoggedUser(std::string username)
{
	this->_username = username;
}

LoggedUser::~LoggedUser()
{
}

std::string LoggedUser::getUsername() const
{
	return this->_username;
}
