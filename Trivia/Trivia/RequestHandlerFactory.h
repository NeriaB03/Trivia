#pragma once

#include "MenuRequestHandler.h"
#include "LoginManager.h"
#include "LoginRequestHandler.h"
#include "RoomMemberRequestHandler.h"
#include "RoomAdminRequestHandler.h"

class RequestHandlerFactory {
public:
	RequestHandlerFactory(IDatabase* database,LoginManager& loginManager,StatisticsManager& statisticsManager,RoomManager& roomManager);
	~RequestHandlerFactory();
	class LoginRequestHandler* createLoginRequestHanlder();
	LoginManager& getLoginManager();
	class MenuRequestHandler* createMenuRequestHandler(LoggedUser loggedUser);
	StatisticsManager& getStatisticsManager();
	RoomManager& getRoomManager();
	RoomAdminRequestHandler* createRoomAdminRequestHandler(LoggedUser loggedUser);
	RoomMemberRequestHandler* createRoomMemberRequestHandler(LoggedUser loggedUser);
private:
	LoginManager _loginManager;
	IDatabase* _database;
	RoomManager& _roomManager;
	StatisticsManager& _statisticsManager;
};