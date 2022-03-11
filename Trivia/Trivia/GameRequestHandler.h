#pragma once

#include "IRequestHandler.h"
#include "GameManager.h"
#include "RequestHandlerFactory.h"

class GameRequestHandler : public IRequestHandler {
public:
	GameRequestHandler(class RequestHandlerFactory& handlerFactory,LoggedUser loggedUser);
	~GameRequestHandler();
	virtual bool isRequestRelevant(RequestInfo requestInfo);
	virtual RequestResult handleRequest(RequestInfo requestInfo);
private:
	LoggedUser _user;
	class RequestHandlerFactory& _handlerFactory;
	RequestResult getQuestion(RequestInfo requestInfo);
	RequestResult submitAnswer(RequestInfo requestInfo);
	RequestResult getGameResults(RequestInfo requestInfo);
	RequestResult leaveGame(RequestInfo requestInfo);
};