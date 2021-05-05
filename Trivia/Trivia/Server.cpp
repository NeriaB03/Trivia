#include "Server.h"

Server::Server()
{
}

Server::~Server()
{
}

void Server::run()
{
	Communicator communicator;
	this->_communicator = communicator;
	std::thread t_connector(&Communicator::startHandleRequest, std::ref(this->_communicator));
	t_connector.detach();
	while (true) {
		std::string cmd = "";
		std::cin >> cmd;
		if (cmd == EXIT_COMMAND) break;
	}
}
