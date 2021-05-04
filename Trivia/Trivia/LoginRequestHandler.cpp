#include "LoginRequestHandler.h"

LoginRequestHandler::LoginRequestHandler(RequestHandlerFactory& handlerFactory):_handlerFactory(handlerFactory),_loginManager(handlerFactory.getLoginManager())
{
}

LoginRequestHandler::~LoginRequestHandler()
{
}

bool LoginRequestHandler::isRequestRelevant(RequestInfo requestInfo)
{
    if (requestInfo.id == MT_CLIENT_LOG_IN || requestInfo.id == MT_CLIENT_SIGN_UP) return true;
    return false;
}

RequestResult LoginRequestHandler::handleRequest(RequestInfo requestInfo)
{
    if (requestInfo.id == MT_CLIENT_LOG_IN) {
        return login(requestInfo);
    }
    else if (requestInfo.id == MT_CLIENT_SIGN_UP) {
        return signup(requestInfo);
    }
}

RequestResult LoginRequestHandler::login(RequestInfo requestInfo)
{
    LoginRequest loginRequest = JsonRequestPacketDeserializer::deserializeLoginRequest(requestInfo.buffer);
    RequestResult requestResult;
    if (this->_handlerFactory.getLoginManager().getDatabase()->doesUserExist(loginRequest.username)) {
        if (this->_handlerFactory.getLoginManager().getDatabase()->doesPasswordMatch(loginRequest.username, loginRequest.password)) {
            this->_handlerFactory.getLoginManager().login(loginRequest.username, loginRequest.password);
            LoginResponse loginResponse;
            loginResponse.status = 1;
            requestResult.buffer = JsonResponsePacketSerializer::serializeResponse(loginResponse);
            requestResult.newHandler = this->_handlerFactory.createLoginRequestHanlder();
        }
        else {
            ErrorResponse errorResponse;
            errorResponse.message = "Password does not match...";
            requestResult.buffer = JsonResponsePacketSerializer::serializeResponse(errorResponse);
            requestResult.newHandler = nullptr;
        }
    }
    else {
        ErrorResponse errorResponse;
        errorResponse.message = "User does not match...";
        requestResult.buffer = JsonResponsePacketSerializer::serializeResponse(errorResponse);
        requestResult.newHandler = nullptr;
    }
    return requestResult;
}

RequestResult LoginRequestHandler::signup(RequestInfo requestInfo)
{
    SignupRequest signupRequest = JsonRequestPacketDeserializer::deserializeSignupRequest(requestInfo.buffer);
    RequestResult requestResult;
    if (!this->_handlerFactory.getLoginManager().getDatabase()->doesUserExist(signupRequest.username)) {
        this->_handlerFactory.getLoginManager().signup(signupRequest.username, signupRequest.password, signupRequest.email);
        SignupResponse signupResponse;
        signupResponse.status = 1;
        requestResult.buffer = JsonResponsePacketSerializer::serializeResponse(signupResponse);
        requestResult.newHandler = this->_handlerFactory.createLoginRequestHanlder();
    }
    else {
        ErrorResponse errorResponse;
        errorResponse.message = "User already exist...";
        requestResult.buffer = JsonResponsePacketSerializer::serializeResponse(errorResponse);
        requestResult.newHandler = nullptr;
    }
    return requestResult;
}