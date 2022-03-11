#include "MenuRequestHandler.h"

MenuRequestHandler::MenuRequestHandler(RequestHandlerFactory& requestHandlerFactory,LoggedUser loggedUser):_handlerFactory(requestHandlerFactory),_user(loggedUser)
{
}

MenuRequestHandler::~MenuRequestHandler()
{
}

bool MenuRequestHandler::isRequestRelevant(RequestInfo requestInfo)
{
	if (requestInfo.id == MT_CLIENT_CREATE_ROOM || requestInfo.id == MT_CLIENT_GET_ROOMS || requestInfo.id == MT_CLIENT_GET_PLAYERS_IN_ROOM || requestInfo.id == MT_CLIENT_JOIN_ROOM || requestInfo.id == MT_CLIENT_GET_STATISTICS || requestInfo.id == MT_CLIENT_HIGH_SCORES || requestInfo.id == MT_CLIENT_LOG_OUT) return true;
	return false;
}

RequestResult MenuRequestHandler::handleRequest(RequestInfo requestInfo)
{
	switch (requestInfo.id) {
	case MT_CLIENT_CREATE_ROOM:
		return createRoom(requestInfo);
	case MT_CLIENT_GET_ROOMS:
		return getRooms(requestInfo);
	case MT_CLIENT_GET_PLAYERS_IN_ROOM:
		return getPlayersInRoom(requestInfo);
	case MT_CLIENT_JOIN_ROOM:
		return joinRoom(requestInfo);
	case MT_CLIENT_GET_STATISTICS:
		return getStatistics(requestInfo);
	case MT_CLIENT_LOG_OUT:
		return signout(requestInfo);
	case MT_CLIENT_HIGH_SCORES:
		return getHighScore(requestInfo);
	}
}

RequestResult MenuRequestHandler::signout(RequestInfo requestInfo)
{
	RequestResult requestResult;
	this->_handlerFactory.getLoginManager().logout(this->_user.getUsername());
	LogoutResponse logoutResponse;
	logoutResponse.status = 1;
	requestResult.buffer = JsonResponsePacketSerializer::serializeResponse(logoutResponse);
	requestResult.newHandler = nullptr;
	return requestResult;
}

RequestResult MenuRequestHandler::getRooms(RequestInfo requestInfo)
{
	RequestResult requestResult;
	std::vector<RoomData> roomsVector = this->_handlerFactory.getRoomManager().getRooms();
	std::vector<char> rooms;
	for (auto const& it : roomsVector) {
		for(int i=0;i<it.name.length();i++){
			rooms.push_back(it.name[i]);
		}
		rooms.push_back(',');
	}
	requestResult.buffer = rooms;
	return requestResult;
}

RequestResult MenuRequestHandler::getPlayersInRoom(RequestInfo requestInfo)
{
	RequestResult requestResult;
	return requestResult;
}

RequestResult MenuRequestHandler::getStatistics(RequestInfo requestInfo)
{
	RequestResult requestResult;
	std::vector<std::string> statisticsVector = this->_handlerFactory.getStatisticsManager().getUserStatistics(this->_user.getUsername());
	std::vector<char> statistics;
	for (auto const& it : statisticsVector) {
		for (int i = 0; i < it.length(); i++) {
			statistics.push_back(it[i]);
		}
		statistics.push_back(',');
	}
	requestResult.buffer = statistics;
	return requestResult;
}

RequestResult MenuRequestHandler::getHighScore(RequestInfo requestInfo)
{
	RequestResult requestResult;
	std::vector<std::string> highScoresVector = this->_handlerFactory.getStatisticsManager().getHighScore();
	std::vector<char> highScores;
	for (auto const& it : highScoresVector) {
		for (int i = 0; i < it.length(); i++) {
			highScores.push_back(it[i]);
		}
		highScores.push_back(',');
	}
	requestResult.buffer = highScores;
	return requestResult;
}

RequestResult MenuRequestHandler::joinRoom(RequestInfo requestInfo)
{
	RequestResult requestResult;
	JoinRoomRequest joinRoomRequest;
	joinRoomRequest = JsonRequestPacketDeserializer::deserializeJoinRoomRequest(requestInfo.buffer);
	std::vector<RoomData> rooms = this->_handlerFactory.getRoomManager().getRooms();
	bool isRoomExist = false;
	for (auto const& it : rooms) {
		if (it.name == joinRoomRequest.roomName) {
			isRoomExist = true;
			break;
		}
	}
	JoinRoomResponse joinRoomResponse;
	if (isRoomExist) {
		unsigned int roomId = 0;
		for (auto const& it : rooms) {
			if (it.name == joinRoomRequest.roomName) roomId = it.id;
		}
		if(this->_handlerFactory.getRoomManager().addUserToRoomById(roomId, this->_user)) joinRoomResponse.status = 1;
		else {
			joinRoomResponse.status = 0;
			requestResult.newHandler = nullptr;
		}
	}
	else {
		joinRoomResponse.status = 0;
		requestResult.newHandler = nullptr;
	}
	requestResult.buffer = JsonResponsePacketSerializer::serializeResponse(joinRoomResponse);
	return requestResult;
}

RequestResult MenuRequestHandler::createRoom(RequestInfo requestInfo)
{
	RequestResult requestResult;
	CreateRoomRequest createRoomRequest = JsonRequestPacketDeserializer::deserializeCreateRoomRequest(requestInfo.buffer);
	RoomData roomData = {
		this->_handlerFactory.getRoomManager().getRooms().size() != 0 ? this->_handlerFactory.getRoomManager().getRooms().back().id + 1 : 1,
		createRoomRequest.roomName,
		createRoomRequest.maxUsers,
		createRoomRequest.questionCount,
		createRoomRequest.questionTimeout,
		1,
		false,
	};
	CreateRoomResponse createRoomResponse;
	if (this->_handlerFactory.getRoomManager().createRoom(this->_user, roomData)) createRoomResponse.status = 1;
	else {
		createRoomResponse.status = 0;
		requestResult.newHandler = nullptr;
	}
	requestResult.buffer = JsonResponsePacketSerializer::serializeResponse(createRoomResponse);
	return requestResult;
}