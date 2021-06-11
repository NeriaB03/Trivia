#pragma once

#include "IRequestHandler.h"
#include "RoomManager.h"
#include "RequestHandlerFactory.h"

class RoomAdminRequestHandler : public IRequestHandler {
public:
	RoomAdminRequestHandler(class RequestHandlerFactory& handlerFactory,LoggedUser loggedUser);
	virtual ~RoomAdminRequestHandler();
	virtual bool isRequestRelevant(RequestInfo requestInfo);
	virtual RequestResult handleRequest(RequestInfo requestInfo);
private:
	Room _room;
	LoggedUser _loggedUser;
	RoomManager& _roomManager;
	class RequestHandlerFactory& _handlerFactory;
	virtual RequestResult closeRoom(RequestInfo requestInfo);
	virtual RequestResult startGame(RequestInfo requestInfo);
	virtual RequestResult getRoomState(RequestInfo requestInfo);
};