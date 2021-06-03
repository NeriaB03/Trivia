#pragma once

#include "MenuRequestHandler.h"
#include "LoginManager.h"
#include "LoginRequestHandler.h"

class RequestHandlerFactory {
public:
	RequestHandlerFactory(IDatabase* database,LoginManager& loginManager,StatisticsManager& statisticsManager,RoomManager& roomManager);
	~RequestHandlerFactory();
	class LoginRequestHandler* createLoginRequestHanlder();
	LoginManager& getLoginManager();
	class MenuRequestHandler* createMenuRequestHandler(LoggedUser loggedUser);
	StatisticsManager& getStatisticsManager();
	RoomManager& getRoomManager();
private:
	LoginManager _loginManager;
	IDatabase* _database;
	RoomManager& _roomManager;
	StatisticsManager& _statisticsManager;
};