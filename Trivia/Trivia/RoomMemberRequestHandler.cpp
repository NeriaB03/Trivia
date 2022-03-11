#include "RoomMemberRequestHandler.h"

RoomMemberRequestHandler::RoomMemberRequestHandler(RequestHandlerFactory& handlerFactory, LoggedUser loggedUser):_handlerFactory(handlerFactory),_loggedUser(loggedUser),_roomManager(handlerFactory.getRoomManager()),_room(handlerFactory.getRoomManager().getRoomByPlayerInTheRoom(loggedUser.getUsername()))
{
}

RoomMemberRequestHandler::~RoomMemberRequestHandler()
{
}

bool RoomMemberRequestHandler::isRequestRelevant(RequestInfo requestInfo)
{
	if (requestInfo.id == MT_CLIENT_LEAVE_ROOM || requestInfo.id == MT_CLIENT_GET_ROOM_STATE) return true;
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
	LeaveRoomResponse leaveRoomResponse;
	if (this->_handlerFactory.getRoomManager().removeUserFromRoomById(this->_handlerFactory.getRoomManager().getRoomByPlayerInTheRoom(this->_loggedUser.getUsername()).getRoomData().id, this->_loggedUser))
		leaveRoomResponse.status = 1;
	else leaveRoomResponse.status = 0;
	requestResult.buffer = JsonResponsePacketSerializer::serializeResponse(leaveRoomResponse);
	requestResult.newHandler = nullptr;
	return requestResult;
}

RequestResult RoomMemberRequestHandler::getRoomState(RequestInfo requestInfo)
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
