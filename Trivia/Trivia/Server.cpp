#include "Server.h"

Server::Server()
{
}

void Server::run()
{
	Communicator c;
	this->_communicator = c;
	this->_communicator.startHandleRequest();
}
