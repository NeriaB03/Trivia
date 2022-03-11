#pragma once

#include <iostream>
#include <WinSock2.h>
#include <Windows.h>
#include <map>
#include <thread>
#include <string>
#include "LoginRequestHandler.h"
#include "RequestHandlerFactory.h"
#include "JsonRequestPacketDeserializer.h"
#include "JsonResponsePacketSerializer.h"
#include <mutex>

#define PORT 666
#define BUFFER 1024
#define START_OF_DATA_INDEX_IN_PROTOCOL 5

class Communicator {
public:
	Communicator(RequestHandlerFactory& requestHandlerFactory);
	~Communicator();
	void startHandleRequest();
private:
	void handleAdminInRoom(SOCKET s,LoggedUser loggedUser);
	void handleMemberInRoom(SOCKET s,LoggedUser loggedUser);
	SOCKET _serverSocket;
	std::map<SOCKET,IRequestHandler*> _clients;
	void bindAndListen();
	void handleNewClient(SOCKET s);
	void closeAllConnections();
	std::pair<char,int> getCodeAndSize(SOCKET s);
	std::vector<char> getData(SOCKET s,int size);
	char* getPartFromSocket(SOCKET sc, int bytesNum, int flags);
	std::pair<RequestInfo,std::pair<char,int>> getDataVector(SOCKET s);
	RequestHandlerFactory& _requestHandlerFactory;
	bool checkIfRoomAlive(LoggedUser loggedUser);
	void handleGetRoomStateRequest(SOCKET s, LoggedUser loggedUser);
};