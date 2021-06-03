#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <sstream>
#include "Room.h"
#include "json/single_include/nlohmann/json.hpp"

#define PROTOCOL_DATA_LENGTH_SIZE 4

enum Response
{
	MT_CLIENT_LOG_IN = '2',
	MT_CLIENT_SIGN_UP = '3',
	MT_SERVER_ERROR = '7',
	MT_CLIENT_CREATE_ROOM = '9',
	MT_CLIENT_GET_ROOMS = '5',
	MT_CLIENT_GET_PLAYERS_IN_ROOM = '1',
	MT_CLIENT_JOIN_ROOM = '4',
	MT_CLIENT_GET_STATISTICS = '6',
	MT_CLIENT_LOG_OUT = '8',
	MT_CLIENT_HIGH_SCORES = '0',
};

struct ErrorResponse {
	std::string message;
};

struct LoginResponse {
	unsigned int status;
};

struct SignupResponse {
	unsigned int status;
};

struct LogoutResponse {
	unsigned int status;
};

struct GetRoomResponse {
	std::vector<RoomData> rooms;
};

struct GetPlayersInRoomResponse {
	std::vector<std::string> players;
};

struct GetStatisticsResponse {
	std::vector<std::string> statistics;
};

struct GetHighScoresResponse {
	std::vector<std::string> highScores;
};

struct JoinRoomResponse {
	unsigned int status;
};

struct CreateRoomResponse {
	unsigned int status;
};

class JsonResponsePacketSerializer {
public:
	static std::vector<char> serializeResponse(ErrorResponse er);
	static std::vector<char> serializeResponse(LoginResponse lr);
	static std::vector<char> serializeResponse(SignupResponse sr);
	static std::vector<char> serializeResponse(LogoutResponse lr);
	static std::vector<char> serializeResponse(GetRoomResponse rr);
	static std::vector<char> serializeResponse(GetPlayersInRoomResponse pr);
	static std::vector<char> serializeResponse(JoinRoomResponse jr);
	static std::vector<char> serializeResponse(CreateRoomResponse cr);
	static std::vector<char> serializeResponse(GetStatisticsResponse sr);
	static std::vector<char> serializeResponse(GetHighScoresResponse hsr);
private:
	static std::string getPaddedNumber(int num, int digits);
};

#ifdef _DEBUG // vs add this define in debug mode
#include <stdio.h>
// Q: why do we need traces ?
// A: traces are a nice and easy way to detect bugs without even debugging
// or to understand what happened in case we miss the bug in the first time
#define TRACE(msg, ...) printf(msg "\n", __VA_ARGS__);
// for convenient reasons we did the traces in stdout
// at general we would do this in the error stream like that
// #define TRACE(msg, ...) fprintf(stderr, msg "\n", __VA_ARGS__);

#else // we want nothing to be printed in release version
#define TRACE(msg, ...) printf(msg "\n", __VA_ARGS__);
#define TRACE(msg, ...) // do nothing
#endif