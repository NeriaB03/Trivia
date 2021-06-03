#include "RoomAdminRequestHandler.h"

RoomAdminRequestHandler::RoomAdminRequestHandler(RequestHandlerFactory& handlerFactory, LoggedUser loggedUser):_handlerFactory(handlerFactory),_loggedUser(loggedUser),_roomManager(_handlerFactory.getRoomManager()),_room(_roomManager.getRoomByPlayerInTheRoom(_loggedUser.getUsername()))
{
}

RoomAdminRequestHandler::~RoomAdminRequestHandler()
{
}

bool RoomAdminRequestHandler::isRequestRelevant(RequestInfo requestInfo)
{
	if (requestInfo.id == MT_CLIENT_CLOSE_ROOM || requestInfo.id == MT_CLIENT_START_GAME || requestInfo.id == MT_CLIENT_GET_ROOM_STATE) return true;
	return false;
}

RequestResult RoomAdminRequestHandler::handleRequest(RequestInfo requestInfo)
{
	switch (requestInfo.id) {
	case MT_CLIENT_CLOSE_ROOM:
		return closeRoom(requestInfo);
	case MT_CLIENT_START_GAME:
		return startGame(requestInfo);
	case MT_CLIENT_GET_ROOM_STATE:
		return getRoomState(requestInfo);
	}
}

RequestResult RoomAdminRequestHandler::closeRoom(RequestInfo requestInfo)
{
	RequestResult requestResult;
	for (auto const& it : this->_room.getAllUsers()) {
		RoomMemberRequestHandler* roomMemberRequestHandler = this->_handlerFactory.createRoomMemberRequestHandler(LoggedUser(it));
		roomMemberRequestHandler->handleRequest(requestInfo);

	}
	CloseRoomResponse closeRoomResponse{
		1,
	};
	requestResult.buffer = JsonResponsePacketSerializer::serializeResponse(closeRoomResponse);
	requestResult.newHandler = nullptr;
	return requestResult;
}

RequestResult RoomAdminRequestHandler::startGame(RequestInfo requestInfo)
{
	RequestResult requestResult;
	for (auto const& it : this->_room.getAllUsers()) {
		RoomMemberRequestHandler* roomMemberRequestHandler = this->_handlerFactory.createRoomMemberRequestHandler(LoggedUser(it));
		roomMemberRequestHandler->handleRequest(requestInfo);

	}
	StartGameResponse startGameResponse{
		1,
	};
	requestResult.buffer = JsonResponsePacketSerializer::serializeResponse(startGameResponse);
	requestResult.newHandler = nullptr;
	return requestResult;
}

RequestResult RoomAdminRequestHandler::getRoomState(RequestInfo requestInfo)
{
	return HelperFunctions::getRoomState(this->_room);
}