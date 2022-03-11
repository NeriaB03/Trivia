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

struct GetPlayersInRoomRequest {
	unsigned int roomId;
};

struct JoinRoomRequest {
	std::string roomName;
};

struct CreateRoomRequest {
	std::string roomName;
	unsigned int maxUsers;
	unsigned int questionCount;
	unsigned int questionTimeout;
};

struct SubmitAnswerRequest {
	unsigned int answerId;
};

class JsonRequestPacketDeserializer {
public:
	static LoginRequest deserializeLoginRequest(std::vector<char> buffer);
	static SignupRequest deserializeSignupRequest(std::vector<char> buffer);
	static GetPlayersInRoomRequest deserializeGetPlayersInRoomRequest(std::vector<char> buffer);
	static JoinRoomRequest deserializeJoinRoomRequest(std::vector<char> buffer);
	static CreateRoomRequest deserializeCreateRoomRequest(std::vector<char> buffer);
	static SubmitAnswerRequest deserializeSubmitAnswerRequest(std::vector<char> buffer);
};