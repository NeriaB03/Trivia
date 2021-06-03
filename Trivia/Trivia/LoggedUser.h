#pragma once

#include <iostream>

class LoggedUser {
public:
	LoggedUser(std::string username);
	~LoggedUser();
	std::string getUsername() const;
	void setUsername(std::string username);
private:
	std::string _username;
};