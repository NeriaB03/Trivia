#pragma once

#include <iostream>

class LoggedUser {
public:
	LoggedUser(std::string username);
	std::string getUsername() const;
private:
	std::string _username;
};