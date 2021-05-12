#include "RequestHandlerFactory.h"

RequestHandlerFactory::RequestHandlerFactory(IDatabase* database,LoginManager& loginManager,LoggedUser& loggedUser,StatisticsManager& statisticsManager,RoomManager& roomManager):_loginManager(loginManager),_loggedUser(loggedUser),_statisticsManager(statisticsManager),_roomManager(roomManager)
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

MenuRequestHandler* RequestHandlerFactory::createMenuRequestHandler()
{
	MenuRequestHandler* mrh = new MenuRequestHandler(this->_loggedUser,getRoomManager(),getStatisticsManager(),(*this));
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
