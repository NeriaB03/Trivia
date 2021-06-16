#include "RoomAdminRequestHandler.h"

RoomAdminRequestHandler::RoomAdminRequestHandler(RequestHandlerFactory& handlerFactory, LoggedUser loggedUser):_handlerFactory(handlerFactory),_loggedUser(loggedUser),_room(handlerFactory.getRoomManager().getRoomByPlayerInTheRoom(loggedUser.getUsername()))
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
	this->_handlerFactory.getRoomManager().setRoomState(this->_room.getRoomData().id, 0);
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
	this->_handlerFactory.getRoomManager().startGame(this->_room.getRoomData().id);
	StartGameResponse startGameResponse{
		1,
	};
	requestResult.buffer = JsonResponsePacketSerializer::serializeResponse(startGameResponse);
	requestResult.newHandler = nullptr;
	return requestResult;
}

RequestResult RoomAdminRequestHandler::getRoomState(RequestInfo requestInfo)
{
	RequestResult requestResult;
	GetRoomStateResponse getRoomStateResponse{
		1,
		this->_handlerFactory.getRoomManager().getRoomByPlayerInTheRoom(this->_loggedUser.getUsername()).getRoomData().isActive,
		this->_handlerFactory.getRoomManager().getRoomByPlayerInTheRoom(this->_loggedUser.getUsername()).getRoomData().hasGameBegun,
		this->_handlerFactory.getRoomManager().getRoomByPlayerInTheRoom(this->_loggedUser.getUsername()).getAllUsers(),
		this->_room.getRoomData().numOfQuestionsInGame,
		this->_room.getRoomData().timePerQuestion,
		this->_room.getRoomData().name,
		this->_room.getAllUsers().front(),
		this->_room.getRoomData().maxPlayers,
	};
	requestResult.buffer = JsonResponsePacketSerializer::serializeResponse(getRoomStateResponse);
	requestResult.newHandler = nullptr;
	return requestResult;
}