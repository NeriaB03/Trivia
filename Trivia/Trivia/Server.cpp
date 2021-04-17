#include "Server.h"

Server::Server()
{
	Communicator c;
	this->_communicator = c;
}

void Server::run()
{
	this->_communicator.startHandleRequest();
}
