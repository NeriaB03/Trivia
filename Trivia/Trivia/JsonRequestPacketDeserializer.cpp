#include "JsonRequestPacketDeserializer.h"

LoginRequest JsonRequestPacketDeserializer::deserializeLoginRequest(std::vector<char> buffer)
{
    LoginRequest lr;
    std::string bufferAsString = std::string(buffer.begin(), buffer.end());
    nlohmann::json loginJson = nlohmann::json::parse(bufferAsString);
    lr.username = loginJson["username"];
    lr.password = loginJson["password"];
    return lr;
}

SignupRequest JsonRequestPacketDeserializer::deserializeSignupRequest(std::vector<char> buffer)
{
    SignupRequest sr;
    std::string bufferAsString = std::string(buffer.begin(), buffer.end());
    nlohmann::json loginJson = nlohmann::json::parse(bufferAsString);
    sr.username = loginJson["username"];
    sr.password = loginJson["password"];
    sr.email = loginJson["mail"];
    return sr;
}
