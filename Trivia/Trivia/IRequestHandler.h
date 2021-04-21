#pragma once

#include <iostream>
#include <time.h>
#include <vector>

struct RequestInfo {
	int id;
	time_t receivalTime;
	std::vector<char> buffer;
};

struct RequestResult {
	std::vector<char> buffer;
	//IRequestHandler* newHandler;
};

class IRequestHandler {
public:
	virtual bool isRequestRelevant(RequestInfo) = 0;
	virtual RequestResult handleRequest(RequestInfo) = 0;
};