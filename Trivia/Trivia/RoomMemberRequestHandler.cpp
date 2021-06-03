#include "RoomMemberRequestHandler.h"

RoomMemberRequestHandler::RoomMemberRequestHandler(RequestHandlerFactory& handlerFactory, LoggedUser loggedUser):_handlerFactory(handlerFactory),_loggedUser(loggedUser),_roomManager(_handlerFactory.getRoomManager()),_room(_roomManager.getRoomByPlayerInTheRoom(_loggedUser.getUsername()))
{
}

RoomMemberRequestHandler::~RoomMemberRequestHandler()
{
}

bool RoomMemberRequestHandler::isRequestRelevant(RequestInfo requestInfo)
{
	if (requestInfo.id == MT_CLIENT_LEAVE_ROOM || requestInfo.id == MT_CLIENT_GET_ROOM_STATE || requestInfo.id == MT_CLIENT_START_GAME) return true;
	return false;
}

RequestResult RoomMemberRequestHandler::handleRequest(RequestInfo requestInfo)
{
	switch (requestInfo.id) {
	case MT_CLIENT_LEAVE_ROOM:
		return leaveRoom(requestInfo);
	case MT_CLIENT_GET_ROOM_STATE:
		return getRoomState(requestInfo);
	case MT_CLIENT_START_GAME:
		return startGame(requestInfo);
	}
}

RequestResult RoomMemberRequestHandler::leaveRoom(RequestInfo requestInfo)
{
	RequestResult requestResult;
	this->_room.removeUser(this->_loggedUser);
	LeaveRoomResponse leaveRoomResponse{
		1,
	};
	requestResult.buffer = JsonResponsePacketSerializer::serializeResponse(leaveRoomResponse);
	requestResult.newHandler = nullptr;
	return requestResult;
}

RequestResult RoomMemberRequestHandler::startGame(RequestInfo requestInfo)
{
	RequestResult requestResult;
	StartGameResponse startGameResponse{
		1,
	};
	requestResult.buffer = JsonResponsePacketSerializer::serializeResponse(startGameResponse);
	requestResult.newHandler = nullptr;
	return requestResult;
}

RequestResult RoomMemberRequestHandler::getRoomState(RequestInfo requestInfo)
{
	return HelperFunctions::getRoomState(this->_room);
}
