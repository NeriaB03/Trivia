#pragma once

#include <iostream>
#include <WinSock2.h>
#include <Windows.h>
#include <map>
#include <thread>
#include <string>
#include "LoginRequestHandler.h"
#include "RequestHandlerFactory.h"

#define PORT 666

class Communicator {
public:
	Communicator();
	~Communicator();
	void startHandleRequest();
private:
	SOCKET _serverSocket;
	std::map<SOCKET,IRequestHandler*> _clients;
	void bindAndListen();
	void handleNewClient(SOCKET s);
	void closeAllConnections();
};