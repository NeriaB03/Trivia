#pragma once

#include "IRequestHandler.h"
#include "RoomManager.h"
#include "RequestHandlerFactory.h"

class RoomMemberRequestHandler : public IRequestHandler {
public:
	RoomMemberRequestHandler(class RequestHandlerFactory& handlerFactory,LoggedUser loggedUser);
	virtual ~RoomMemberRequestHandler();
	virtual bool isRequestRelevant(RequestInfo requestInfo);
	virtual RequestResult handleRequest(RequestInfo requestInfo);
private:
	Room _room;
	LoggedUser _loggedUser;
	RoomManager& _roomManager;
	class RequestHandlerFactory& _handlerFactory;
	virtual RequestResult leaveRoom(RequestInfo requestInfo);
	virtual RequestResult getRoomState(RequestInfo requestInfo);
	virtual RequestResult startGame(RequestInfo requestInfo);
};