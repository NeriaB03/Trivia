#pragma once

#include "Communicator.h"
#include "IDatabase.h"
#include "RequestHandlerFactory.h"

class Server {
public:
	Server();
	void run();
private:
	IDatabase* _database;
	Communicator _communicator;
	RequestHandlerFactory _requestHandlerFactory;
};