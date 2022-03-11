#pragma once

#include "IRequestHandler.h"
#include "RequestHandlerFactory.h"

class LoginRequestHandler : public IRequestHandler {
public:
	LoginRequestHandler(class RequestHandlerFactory& handlerFactory);
	~LoginRequestHandler();
	virtual bool isRequestRelevant(RequestInfo requestInfo);
	virtual RequestResult handleRequest(RequestInfo requestInfo);
private:
	RequestResult login(RequestInfo requestInfo);
	RequestResult signup(RequestInfo requestInfo);
	LoginManager& _loginManager;
	class RequestHandlerFactory& _handlerFactory;
};