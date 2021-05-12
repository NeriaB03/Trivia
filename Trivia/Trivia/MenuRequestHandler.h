#pragma once

#include "IRequestHandler.h"
#include "RoomManager.h"
#include "StatisticsManager.h"

class MenuRequestHandler : public IRequestHandler{
public:
	MenuRequestHandler(LoggedUser loggedUser,RoomManager& roomManager,StatisticsManager& statisticsManager,class RequestHandlerFactory& requestHandlerFactory);
	~MenuRequestHandler();
	virtual bool isRequestRelevant(RequestInfo requestInfo);
	virtual RequestResult handleRequest(RequestInfo requestInfo);
private:
	LoggedUser _user;
	RoomManager& _roomManager;
	StatisticsManager& _statisticsManager;
	class RequestHandlerFactory& _handlerFactory;
	RequestResult signout(RequestInfo requestInfo);
	RequestResult getRooms(RequestInfo requestInfo);
	RequestResult getPlayersInRoom(RequestInfo requestInfo);
	RequestResult getPersonalStats(RequestInfo requestInfo);
	RequestResult getHighScore(RequestInfo requestInfo);
	RequestResult joinRoom(RequestInfo requestInfo);
	RequestResult createRoom(RequestInfo requestInfo);
};