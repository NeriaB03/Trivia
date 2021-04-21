#pragma once

#include <iostream>
#include <vector>
#include "json/single_include/nlohmann/json.hpp"

struct LoginRequest {
	std::string username;
	std::string password;
};

struct SignupRequest {
	std::string username;
	std::string password;
	std::string email;
};

class JsonRequestPacketDeserializer {
public:
	static LoginRequest deserializeLoginRequest(std::vector<char> buffer);
	static SignupRequest deserializeSignupRequest(std::vector<char> buffer);
};