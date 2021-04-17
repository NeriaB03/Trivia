#pragma once

#include "LoginManager.h"
#include "LoginRequestHandler.h"

class RequestHandlerFactory {
public:
	RequestHandlerFactory();
	LoginRequestHandler createLoginRequestHandler();
private:
	LoginManager _loginManager;
	IDatabase* _database;
};