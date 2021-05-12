#include "Communicator.h"

Communicator::Communicator()
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
	char* sizeOfDataAsCharArr = getPartFromSocket(s, START_OF_DATA_INDEX_IN_PROTOCOL, 0);
	sizeOfDataAsCharArr[START_OF_DATA_INDEX_IN_PROTOCOL] = 0;
	std::string sizeOfDataAsString = std::string(sizeOfDataAsCharArr);
	char code = sizeOfDataAsString[0]; //get the first char in the data (the code by the protocol)
	sizeOfDataAsString.erase(sizeOfDataAsString.begin()); //erase the code from the data recieved (to get only the json size)
	int sizeOfData = std::stoi(sizeOfDataAsString);
	char* dataRecieved = getPartFromSocket(s, sizeOfData, 0);
	dataRecieved[sizeOfData] = 0;
	std::string dataRecievedAsString = std::string(dataRecieved);
	std::vector<char> dataVector;
	for(int i=0;i<dataRecievedAsString.length();i++) dataVector.push_back(dataRecievedAsString[i]);
	IDatabase* database = new SqliteDatabase();
	LoginManager loginManager(database);
	RequestInfo requestInfo;
	requestInfo.buffer = dataVector;
	requestInfo.id = 0;
	requestInfo.receivalTime = std::time(0);
	LoginRequest loginRequest = JsonRequestPacketDeserializer::deserializeLoginRequest(requestInfo.buffer);
	LoggedUser loggedUser(loginRequest.username);
	StatisticsManager statisticsManager(database);
	RoomManager roomManager;
	RequestHandlerFactory requestHandlerFactory(database,loginManager,loggedUser,statisticsManager,roomManager);
	IRequestHandler* loginRequestHandler = new LoginRequestHandler(requestHandlerFactory);
	this->_clients[s] = loginRequestHandler;
	if (code == MT_CLIENT_LOG_IN) {
		requestInfo.id = int(MT_CLIENT_LOG_IN);
		RequestResult requestResult = loginRequestHandler->handleRequest(requestInfo);
		std::string responseAsString = HelperFunctions::convertVectorOfCharsToString(requestResult.buffer);
		const char* responseToSend = responseAsString.c_str();
		if (send(s, responseToSend, responseAsString.size(), 0) == INVALID_SOCKET) throw std::exception("Error while sending message to client");
	} 
	else {
		requestInfo.id = int(MT_CLIENT_SIGN_UP);
		RequestResult requestResult = loginRequestHandler->handleRequest(requestInfo);
		std::string responseAsString = HelperFunctions::convertVectorOfCharsToString(requestResult.buffer);
		const char* responseToSend = responseAsString.c_str();
		if (send(s, responseToSend, responseAsString.size(), 0) == INVALID_SOCKET) throw std::exception("Error while sending message to client");
	}
}

void Communicator::closeAllConnections()
{
	for (auto const& it : this->_clients) {
		if(it.second != nullptr) delete it.second;
		closesocket(it.first);
	}
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