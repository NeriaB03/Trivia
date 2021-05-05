#pragma once

#include "Communicator.h"
#include "IDatabase.h"
#include "RequestHandlerFactory.h"

#define EXIT_COMMAND "EXIT"

class Server {
public:
	Server();
	~Server();
	void run();
private:
	Communicator _communicator;
};