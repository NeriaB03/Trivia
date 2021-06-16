#include "RequestHandlerFactory.h"

RequestHandlerFactory::RequestHandlerFactory(IDatabase* database,LoginManager& loginManager,StatisticsManager& statisticsManager,RoomManager& roomManager,GameManager& gameManager):_loginManager(loginManager),_statisticsManager(statisticsManager),_roomManager(roomManager),_gameManager(gameManager)
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

RoomAdminRequestHandler* RequestHandlerFactory::createRoomAdminRequestHandler(LoggedUser loggedUser)
{
	RoomAdminRequestHandler* rarh = new RoomAdminRequestHandler((*this), loggedUser);
	return rarh;
}

RoomMemberRequestHandler* RequestHandlerFactory::createRoomMemberRequestHandler(LoggedUser loggedUser)
{
	RoomMemberRequestHandler* rmrh = new RoomMemberRequestHandler((*this), loggedUser);
	return rmrh;
}

GameRequestHandler* RequestHandlerFactory::createGameRequestHandler(LoggedUser loggedUser)
{
	GameRequestHandler* grh = new GameRequestHandler((*this),loggedUser);
	return grh;
}

GameManager& RequestHandlerFactory::getGameManager()
{
	return this->_gameManager;
}