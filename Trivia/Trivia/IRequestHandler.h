#pragma once

#include <iostream>
#include <time.h>
#include <vector>
#include "LoginManager.h"
#include "RequestHandlerFactory.h"
#include "JsonRequestPacketDeserializer.h"
#include "MenuRequestHandler.h"
#include "JsonResponsePacketSerializer.h"

struct RequestInfo {
	int id;
	time_t receivalTime;
	std::vector<char> buffer;
};

struct RequestResult {
	std::vector<char> buffer;
	class IRequestHandler* newHandler;
};

class IRequestHandler {
public:
	virtual bool isRequestRelevant(RequestInfo) = 0;
	virtual RequestResult handleRequest(RequestInfo) = 0;
};