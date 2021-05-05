#include "RequestHandlerFactory.h"

RequestHandlerFactory::RequestHandlerFactory(LoginManager& loginManager):_loginManager(loginManager)
{
}

RequestHandlerFactory::~RequestHandlerFactory()
{
}

LoginRequestHandler* RequestHandlerFactory::createLoginRequestHanlder()
{
	LoginRequestHandler* lrh = new LoginRequestHandler(*this);
	return lrh;
}

LoginManager& RequestHandlerFactory::getLoginManager()
{
	return this->_loginManager;
}
