#pragma once

#include "LoginRequestHandler.h"
#include "LoginManager.h"

class RequestHandlerFactory {
public:
	RequestHandlerFactory(LoginManager& loginManager);
	~RequestHandlerFactory();
	class LoginRequestHandler* createLoginRequestHanlder();
	LoginManager& getLoginManager();
private:
	LoginManager _loginManager;
	IDatabase* _database;
};