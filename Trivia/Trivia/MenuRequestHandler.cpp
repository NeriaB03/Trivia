#include "MenuRequestHandler.h"

MenuRequestHandler::MenuRequestHandler(LoggedUser loggedUser, RoomManager& roomManager, StatisticsManager& statisticsManager, RequestHandlerFactory& requestHandlerFactory):_user(loggedUser),_roomManager(roomManager),_statisticsManager(statisticsManager),_handlerFactory(requestHandlerFactory)
{
}

MenuRequestHandler::~MenuRequestHandler()
{
}

bool MenuRequestHandler::isRequestRelevant(RequestInfo requestInfo)
{
	return false;
}

RequestResult MenuRequestHandler::handleRequest(RequestInfo requestInfo)
{
	return RequestResult();
}

RequestResult MenuRequestHandler::signout(RequestInfo requestInfo)
{
	return RequestResult();
}

RequestResult MenuRequestHandler::getRooms(RequestInfo requestInfo)
{
	return RequestResult();
}

RequestResult MenuRequestHandler::getPlayersInRoom(RequestInfo requestInfo)
{
	return RequestResult();
}

RequestResult MenuRequestHandler::getPersonalStats(RequestInfo requestInfo)
{
	return RequestResult();
}

RequestResult MenuRequestHandler::getHighScore(RequestInfo requestInfo)
{
	return RequestResult();
}

RequestResult MenuRequestHandler::joinRoom(RequestInfo requestInfo)
{
	return RequestResult();
}

RequestResult MenuRequestHandler::createRoom(RequestInfo requestInfo)
{
	return RequestResult();
}