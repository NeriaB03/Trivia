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
    nlohmann::json signupJson = nlohmann::json::parse(bufferAsString);
    sr.username = signupJson["username"];
    sr.password = signupJson["password"];
    sr.email = signupJson["email"];
    return sr;
}

GetPlayersInRoomRequest JsonRequestPacketDeserializer::deserializeGetPlayersInRoomRequest(std::vector<char> buffer)
{
    GetPlayersInRoomRequest gpr;
    std::string bufferAsString = std::string(buffer.begin(), buffer.end());
    nlohmann::json getPlayersJson = nlohmann::json::parse(bufferAsString);
    gpr.roomId = getPlayersJson["roomId"];
    return gpr;
}

JoinRoomRequest JsonRequestPacketDeserializer::deserializeJoinRoomRequest(std::vector<char> buffer)
{
    JoinRoomRequest jrr;
    std::string bufferAsString = std::string(buffer.begin(), buffer.end());
    nlohmann::json joinRoomJson = nlohmann::json::parse(bufferAsString);
    jrr.roomName = joinRoomJson["roomName"];
    return jrr;
}

CreateRoomRequest JsonRequestPacketDeserializer::deserializeCreateRoomRequest(std::vector<char> buffer)
{
    CreateRoomRequest crr;
    std::string bufferAsString = std::string(buffer.begin(), buffer.end());
    nlohmann::json createRoomJson = nlohmann::json::parse(bufferAsString);
    crr.roomName = createRoomJson["roomName"];
    crr.questionCount = createRoomJson["questionCount"];
    crr.maxUsers = createRoomJson["maxUsers"];
    crr.questionTimeout = createRoomJson["questionTimeout"];
    return crr;
}
