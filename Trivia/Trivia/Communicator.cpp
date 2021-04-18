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
	IRequestHandler* loginRequestHandler = new LoginRequestHandler;
	this->_clients[s] = loginRequestHandler;
	std::string messageToSend = "Hello";
	const char* dataToSend = messageToSend.c_str();
	if (send(s, dataToSend, messageToSend.size(), 0) == INVALID_SOCKET) throw std::exception("Error while sending message to client");
	char* dataRecieved = new char[messageToSend.length() + 1];
	if (recv(s, dataRecieved, messageToSend.length(), 0) == INVALID_SOCKET) throw std::exception("Error while reciving message from client");
	else {
		dataRecieved[messageToSend.length()] = 0;
		std::cout << dataRecieved << std::endl;
	}
}

void Communicator::closeAllConnections()
{
	for (auto const& it : this->_clients) {
		if(it.second != nullptr) delete it.second;
		closesocket(it.first);
	}
}
