#pragma once

#include "MenuRequestHandler.h"
#include "LoginManager.h"
#include "LoginRequestHandler.h"
#include "RoomMemberRequestHandler.h"
#include "RoomAdminRequestHandler.h"
#include "GameRequestHandler.h"

class RequestHandlerFactory {
public:
	RequestHandlerFactory(IDatabase* database,LoginManager& loginManager,StatisticsManager& statisticsManager,RoomManager& roomManager,GameManager& gameManager);
	~RequestHandlerFactory();
	class LoginRequestHandler* createLoginRequestHanlder();
	LoginManager& getLoginManager();
	class MenuRequestHandler* createMenuRequestHandler(LoggedUser loggedUser);
	StatisticsManager& getStatisticsManager();
	RoomManager& getRoomManager();
	class RoomAdminRequestHandler* createRoomAdminRequestHandler(LoggedUser loggedUser);
	class RoomMemberRequestHandler* createRoomMemberRequestHandler(LoggedUser loggedUser);
	class GameRequestHandler* createGameRequestHandler(LoggedUser loggedUser);
	GameManager& getGameManager();
private:
	LoginManager _loginManager;
	IDatabase* _database;
	RoomManager& _roomManager;
	StatisticsManager& _statisticsManager;
	GameManager& _gameManager;
};