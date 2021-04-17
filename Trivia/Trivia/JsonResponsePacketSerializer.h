#pragma once

#include <iostream>
#include <vector>

struct ErrorResponse {
	std::string message;
};

struct LoginResponse {
	unsigned int status;
};

struct SignupResponse {
	unsigned int status;
};

class JsonResponsePacketSerializer {
public:
	static std::vector<char> serializeResponse(ErrorResponse);
	static std::vector<char> serializeResponse(LoginResponse);
	static std::vector<char> serializeResponse(SignupResponse);
};