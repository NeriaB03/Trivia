#include "RequestHandlerFactory.h"

RequestHandlerFactory::RequestHandlerFactory(IDatabase* database,LoginManager& loginManager,StatisticsManager& statisticsManager,RoomManager& roomManager):_loginManager(loginManager),_statisticsManager(statisticsManager),_roomManager(roomManager)
{
	this->_database = database;
}

RequestHandlerFactory::~RequestHandlerFactory()
{
	delete this->_database;
}

LoginRequestHandler* RequestHandlerFactory::createLoginRequestHanlder()
{
	LoginRequestHandler* lrh = new LoginRequestHandler(*this);
	return lrh;
}

LoginManager& RequestHandlerFactory::getLoginManager()
{
	return this->_loginManager;
}

MenuRequestHandler* RequestHandlerFactory::createMenuRequestHandler(LoggedUser loggedUser)
{
	MenuRequestHandler* mrh = new MenuRequestHandler((*this),loggedUser);
	return mrh;
}

StatisticsManager& RequestHandlerFactory::getStatisticsManager()
{
	return this->_statisticsManager;
}

RoomManager& RequestHandlerFactory::getRoomManager()
{
	return this->_roomManager;
}
