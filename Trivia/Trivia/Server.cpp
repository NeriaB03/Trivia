#include "Server.h"

Server::Server()
{
}

Server::~Server()
{
}

void Server::run()
{
	IDatabase* database = new SqliteDatabase();
	StatisticsManager statisticsManager(database);
	RoomManager roomManager;
	LoginManager loginManager(database);
	RequestHandlerFactory requestHandlerFactory(database, loginManager, statisticsManager, roomManager);
	Communicator communicator(requestHandlerFactory);
	std::thread t_connector(&Communicator::startHandleRequest, std::ref(communicator));
	t_connector.detach();
	while (true) {
		std::string cmd = "";
		std::cin >> cmd;
		if (cmd == EXIT_COMMAND) break;
	}
}
