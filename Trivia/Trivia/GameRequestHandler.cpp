#include "GameRequestHandler.h"

GameRequestHandler::GameRequestHandler(class RequestHandlerFactory& handlerFactory,LoggedUser loggedUser):_handlerFactory(handlerFactory),_user(loggedUser)
{
}

GameRequestHandler::~GameRequestHandler()
{
}
bool GameRequestHandler::isRequestRelevant(RequestInfo requestInfo)
{
	if (requestInfo.id == MT_CLIENT_LEAVE_GAME || requestInfo.id == MT_CLIENT_GET_QUESTION || requestInfo.id == MT_CLIENT_SUBMIT_ANSWER || requestInfo.id == MT_CLIENT_GET_GAME_RESULT) return true;
	return false;
}

RequestResult GameRequestHandler::handleRequest(RequestInfo requestInfo)
{
	switch (requestInfo.id) {
	case MT_CLIENT_LEAVE_GAME:
		return leaveGame(requestInfo);
	case MT_CLIENT_GET_QUESTION:
		return getQuestion(requestInfo);
	case MT_CLIENT_SUBMIT_ANSWER:
		return submitAnswer(requestInfo);
	case MT_CLIENT_GET_GAME_RESULT:
		return getGameResults(requestInfo);
	}
}

RequestResult GameRequestHandler::getQuestion(RequestInfo requestInfo)
{
	RequestResult requestResult;
	GetQuestionResponse getQuestionResponse;
	//get next question with game manager
	//if there is no more questions => status = 0
	//else => status = 1
	requestResult.buffer = JsonResponsePacketSerializer::serializeResponse(getQuestionResponse);
	requestResult.newHandler = nullptr;
	return requestResult;
}

RequestResult GameRequestHandler::submitAnswer(RequestInfo requestInfo)
{
	RequestResult requestResult;
	SubmitAnswerRequest submitAnswerRequest = JsonRequestPacketDeserializer::deserializeSubmitAnswerRequest(requestInfo.buffer);
	//set game data info with game manager (submit the answer)
	SubmitAnswerResponse submitAnswerResponse = {
		1,//status
		submitAnswerRequest.answerId,//answer id
	};
	requestResult.buffer = JsonResponsePacketSerializer::serializeResponse(submitAnswerResponse);
	requestResult.newHandler = nullptr;
	return requestResult;
}

RequestResult GameRequestHandler::getGameResults(RequestInfo requestInfo)
{
	RequestResult requestResult;
	GetGameResultsResponse getGameResultsResponse;
	//if game over => status = 1, get game data of each player in this game
	//else => status = 0
	requestResult.buffer = JsonResponsePacketSerializer::serializeResponse(getGameResultsResponse);
	requestResult.newHandler = nullptr;
	return requestResult;
}

RequestResult GameRequestHandler::leaveGame(RequestInfo requestInfo)
{
	RequestResult requestResult;
	LeaveGameResponse leaveGameResponse;
	if (this->_handlerFactory.getRoomManager().removeUserFromRoomById(this->_handlerFactory.getRoomManager().getRoomByPlayerInTheRoom(this->_user.getUsername()).getRoomData().id, this->_user))
		leaveGameResponse.status = 1;
	else leaveGameResponse.status = 0;
	requestResult.buffer = JsonResponsePacketSerializer::serializeResponse(leaveGameResponse);
	requestResult.newHandler = nullptr;
	return requestResult;
}
