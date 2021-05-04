#pragma once

#include <iostream>

class LoggedUser {
public:
	LoggedUser(std::string username);
	~LoggedUser();
	std::string getUsername() const;
private:
	std::string _username;
};