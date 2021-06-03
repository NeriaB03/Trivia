#include "Communicator.h"

Communicator::Communicator(RequestHandlerFactory& requestHandlerFactory):_requestHandlerFactory(requestHandlerFactory)
{
	// this server use TCP. that why SOCK_STREAM & IPPROTO_TCP
	// if the server use UDP we will use: SOCK_DGRAM & IPPROTO_UDP
	_serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (_serverSocket == INVALID_SOCKET)
		throw std::exception(__FUNCTION__ " - socket");
}

Communicator::~Communicator()
{
	try
	{
		closeAllConnections();
		// the only use of the destructor should be for freeing 
		// resources that was allocated in the constructor
		closesocket(_serverSocket);
	}
	catch (...) {}
}

void Communicator::startHandleRequest()
{
	while (true) bindAndListen();
}

void Communicator::bindAndListen()
{
	struct sockaddr_in sa = { 0 };

	sa.sin_port = htons(PORT); // port that server will listen for
	sa.sin_family = AF_INET;   // must be AF_INET
	sa.sin_addr.s_addr = INADDR_ANY;    // when there are few ip's for the machine. We will use always "INADDR_ANY"

	// again stepping out to the global namespace
	// Connects between the socket and the configuration (port and etc..)
	if (bind(_serverSocket, (struct sockaddr*)&sa, sizeof(sa)) == SOCKET_ERROR)
		throw std::exception(__FUNCTION__ " - bind");

	// Start listening for incoming requests of clients
	if (listen(_serverSocket, SOMAXCONN) == SOCKET_ERROR)
		throw std::exception(__FUNCTION__ " - listen");
	std::cout << "Listening on port " << PORT << std::endl;


	while (true)
	{
		// the main thread is only accepting clients 
		// and add then to the list of handlers
		SOCKET client_socket = ::accept(_serverSocket, NULL, NULL);
		std::thread t(&Communicator::handleNewClient, std::ref(*this), client_socket);
		t.detach();
	}
}

void Communicator::handleNewClient(SOCKET s)
{
	std::string username = "";
	try {
		IRequestHandler* loginRequestHandler = new LoginRequestHandler(this->_requestHandlerFactory);
		std::pair<RequestInfo, std::pair<char, int>> requestInfo = getDataVector(s);
		LoginRequest loginRequest = JsonRequestPacketDeserializer::deserializeLoginRequest(requestInfo.first.buffer);
		LoggedUser loggedUser(loginRequest.username);
		username = loginRequest.username;
		this->_clients[s] = loginRequestHandler;
		bool isFinishLogin = false;
		while (!isFinishLogin) {
			if (requestInfo.second.first == MT_CLIENT_LOG_IN) {
				requestInfo.first.id = int(MT_CLIENT_LOG_IN);
				RequestResult requestResult = loginRequestHandler->handleRequest(requestInfo.first);
				std::string responseAsString = HelperFunctions::convertVectorOfCharsToString(requestResult.buffer);
				const char* responseToSend = responseAsString.c_str();
				if (send(s, responseToSend, responseAsString.size(), 0) == INVALID_SOCKET) throw std::exception("Error while sending message to client");
				if (requestResult.newHandler == nullptr) {
					requestResult.newHandler = new LoginRequestHandler(this->_requestHandlerFactory);
					requestInfo = getDataVector(s);
					loginRequest = JsonRequestPacketDeserializer::deserializeLoginRequest(requestInfo.first.buffer);
					loggedUser.setUsername(loginRequest.username);
				}
				else isFinishLogin = true;
			}
			else if (requestInfo.second.first == MT_CLIENT_SIGN_UP) {
				requestInfo.first.id = int(MT_CLIENT_SIGN_UP);
				RequestResult requestResult = loginRequestHandler->handleRequest(requestInfo.first);
				std::string responseAsString = HelperFunctions::convertVectorOfCharsToString(requestResult.buffer);
				const char* responseToSend = responseAsString.c_str();
				if (send(s, responseToSend, responseAsString.size(), 0) == INVALID_SOCKET) throw std::exception("Error while sending message to client");
				if (requestResult.newHandler == nullptr) {
					requestResult.newHandler = new LoginRequestHandler(this->_requestHandlerFactory);
					requestInfo = getDataVector(s);
					loginRequest = JsonRequestPacketDeserializer::deserializeLoginRequest(requestInfo.first.buffer);
					loggedUser.setUsername(loginRequest.username);
				}
				else isFinishLogin = true;
			}
		}
		IRequestHandler* menuRequestHandler = new MenuRequestHandler(this->_requestHandlerFactory,loggedUser);
		while (requestInfo.second.first != MT_CLIENT_LOG_OUT) {
			requestInfo = getDataVector(s);
			RequestResult requestResult;
			std::string responseAsString = "";
			const char* responseToSend;
			switch (requestInfo.second.first) {
			case MT_CLIENT_LOG_OUT:
				requestInfo.first.id = int(MT_CLIENT_LOG_OUT);
				requestResult = menuRequestHandler->handleRequest(requestInfo.first);
				responseAsString = HelperFunctions::convertVectorOfCharsToString(requestResult.buffer);
				responseToSend = responseAsString.c_str();
				if (send(s, responseToSend, responseAsString.size(), 0) == INVALID_SOCKET) throw std::exception("Error while sending message to client");
				break;
			case MT_CLIENT_JOIN_ROOM:
				requestInfo.first.id = int(MT_CLIENT_JOIN_ROOM);
				requestResult = menuRequestHandler->handleRequest(requestInfo.first);
				responseAsString = HelperFunctions::convertVectorOfCharsToString(requestResult.buffer);
				responseToSend = responseAsString.c_str();
				if (send(s, responseToSend, responseAsString.size(), 0) == INVALID_SOCKET) throw std::exception("Error while sending message to client");
				//handle room as member
				handleMemberInRoom(s,loggedUser);
				break;
			case MT_CLIENT_CREATE_ROOM:
				requestInfo.first.id = int(MT_CLIENT_CREATE_ROOM);
				requestResult = menuRequestHandler->handleRequest(requestInfo.first);
				responseAsString = HelperFunctions::convertVectorOfCharsToString(requestResult.buffer);
				responseToSend = responseAsString.c_str();
				if (send(s, responseToSend, responseAsString.size(), 0) == INVALID_SOCKET) throw std::exception("Error while sending message to client");
				//handle room as admin
				handleAdminInRoom(s,loggedUser);
				break;
			case MT_CLIENT_GET_STATISTICS:
				requestInfo.first.id = int(MT_CLIENT_GET_STATISTICS);
				requestResult = menuRequestHandler->handleRequest(requestInfo.first);
				responseAsString = HelperFunctions::convertVectorOfCharsToString(requestResult.buffer);
				responseToSend = responseAsString.c_str();
				if (send(s, responseToSend, responseAsString.size(), 0) == INVALID_SOCKET) throw std::exception("Error while sending message to client");
				break;
			case MT_CLIENT_HIGH_SCORES:
				requestInfo.first.id = int(MT_CLIENT_HIGH_SCORES);
				requestResult = menuRequestHandler->handleRequest(requestInfo.first);
				responseAsString = HelperFunctions::convertVectorOfCharsToString(requestResult.buffer);
				responseToSend = responseAsString.c_str();
				if (send(s, responseToSend, responseAsString.size(), 0) == INVALID_SOCKET) throw std::exception("Error while sending message to client");
				break;
			}
		}
	}
	catch (std::exception& e) {
		this->_clients.erase(s);
		this->_requestHandlerFactory.getLoginManager().logout(username);
	}

}

void Communicator::closeAllConnections()
{
	for (auto const& it : this->_clients) {
		if(it.second != nullptr) delete it.second;
		closesocket(it.first);
	}
}

std::pair<char,int> Communicator::getCodeAndSize(SOCKET s)
{
	char* sizeOfDataAsCharArr = getPartFromSocket(s, START_OF_DATA_INDEX_IN_PROTOCOL, 0);
	sizeOfDataAsCharArr[START_OF_DATA_INDEX_IN_PROTOCOL] = 0;
	std::string sizeOfDataAsString = std::string(sizeOfDataAsCharArr);
	char code = sizeOfDataAsString[0]; //get the first char in the data (the code by the protocol)
	sizeOfDataAsString.erase(sizeOfDataAsString.begin()); //erase the code from the data recieved (to get only the json size)
	int sizeOfData = std::stoi(sizeOfDataAsString);
	return std::pair<char, int>(code, sizeOfData);
}

std::vector<char> Communicator::getData(SOCKET s,int size)
{
	char* dataRecieved;
	std::vector<char> dataVector;
	dataRecieved = getPartFromSocket(s, size, 0);
	dataRecieved[size] = 0;
	std::string dataRecievedAsString = std::string(dataRecieved);
	for (int i = 0; i < dataRecievedAsString.length(); i++) dataVector.push_back(dataRecievedAsString[i]);
	return dataVector;
}

char* Communicator::getPartFromSocket(SOCKET sc, int bytesNum, int flags)
{
	if (bytesNum == 0)
	{
		return (char*)"";
	}

	char* data = new char[bytesNum + 1];
	int res = recv(sc, data, bytesNum, flags);

	if (res == INVALID_SOCKET)
	{
		std::string s = "Error while recieving from socket: ";
		s += std::to_string(sc);
		throw std::exception(s.c_str());
	}

	data[bytesNum] = 0;
	return data;
}

std::pair<RequestInfo, std::pair<char, int>> Communicator::getDataVector(SOCKET s)
{
	std::pair<char, int> codeAndSize = getCodeAndSize(s);
	std::vector<char> dataVector;
	if(codeAndSize.second != 0) dataVector = getData(s, codeAndSize.second);
	RequestInfo requestInfo;
	requestInfo.buffer = dataVector;
	requestInfo.id = 0;
	requestInfo.receivalTime = std::time(0);
	return std::pair<RequestInfo, std::pair<char, int>>(requestInfo,codeAndSize);
}

void Communicator::handleMemberInRoom(SOCKET s,LoggedUser loggedUser)
{
	IRequestHandler* roomMemberRequestHandler = new RoomMemberRequestHandler(this->_requestHandlerFactory, loggedUser);
	std::pair<RequestInfo, std::pair<char, int>> requestInfo;
	RequestResult requestResult;
	std::string responseAsString = "";
	const char* responseToSend;
	while (requestInfo.second.first != MT_CLIENT_LEAVE_ROOM) {
		requestInfo = getDataVector(s);
		switch (requestInfo.second.first) {
		case MT_CLIENT_CLOSE_ROOM:
			requestInfo.first.id = int(MT_CLIENT_LEAVE_ROOM);
			requestResult = roomMemberRequestHandler->handleRequest(requestInfo.first);
			responseAsString = HelperFunctions::convertVectorOfCharsToString(requestResult.buffer);
			responseToSend = responseAsString.c_str();
			if (send(s, responseToSend, responseAsString.size(), 0) == INVALID_SOCKET) throw std::exception("Error while sending message to client");
			break;
		case MT_CLIENT_GET_ROOM_STATE:
			requestInfo.first.id = int(MT_CLIENT_GET_ROOM_STATE);
			requestResult = roomMemberRequestHandler->handleRequest(requestInfo.first);
			responseAsString = HelperFunctions::convertVectorOfCharsToString(requestResult.buffer);
			responseToSend = responseAsString.c_str();
			if (send(s, responseToSend, responseAsString.size(), 0) == INVALID_SOCKET) throw std::exception("Error while sending message to client");
			break;
		}
	}
}

void Communicator::handleAdminInRoom(SOCKET s,LoggedUser loggedUser)
{
	IRequestHandler* roomAdminRequestHandler = new RoomAdminRequestHandler(this->_requestHandlerFactory, loggedUser);
	std::pair<RequestInfo, std::pair<char, int>> requestInfo;
	RequestResult requestResult;
	std::string responseAsString = "";
	const char* responseToSend;
	while (requestInfo.second.first != MT_CLIENT_CLOSE_ROOM) {
		requestInfo = getDataVector(s);
		switch (requestInfo.second.first) {
		case MT_CLIENT_START_GAME:
			requestInfo.first.id = int(MT_CLIENT_START_GAME);
			requestResult = roomAdminRequestHandler->handleRequest(requestInfo.first);
			responseAsString = HelperFunctions::convertVectorOfCharsToString(requestResult.buffer);
			responseToSend = responseAsString.c_str();
			if (send(s, responseToSend, responseAsString.size(), 0) == INVALID_SOCKET) throw std::exception("Error while sending message to client");
			break;
		case MT_CLIENT_CLOSE_ROOM:
			requestInfo.first.id = int(MT_CLIENT_CLOSE_ROOM);
			requestResult = roomAdminRequestHandler->handleRequest(requestInfo.first);
			responseAsString = HelperFunctions::convertVectorOfCharsToString(requestResult.buffer);
			responseToSend = responseAsString.c_str();
			if (send(s, responseToSend, responseAsString.size(), 0) == INVALID_SOCKET) throw std::exception("Error while sending message to client");
			break;
		case MT_CLIENT_GET_ROOM_STATE:
			requestInfo.first.id = int(MT_CLIENT_GET_ROOM_STATE);
			requestResult = roomAdminRequestHandler->handleRequest(requestInfo.first);
			responseAsString = HelperFunctions::convertVectorOfCharsToString(requestResult.buffer);
			responseToSend = responseAsString.c_str();
			if (send(s, responseToSend, responseAsString.size(), 0) == INVALID_SOCKET) throw std::exception("Error while sending message to client");
			break;
		}
	}
}
