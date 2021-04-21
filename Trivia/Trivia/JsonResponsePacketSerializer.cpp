#include "JsonResponsePacketSerializer.h"

std::vector<char> JsonResponsePacketSerializer::serializeResponse(ErrorResponse er)
{
    std::vector<char> buffer;
    //create the json object
    nlohmann::json errorJson = {
        {"Message",er.message}
    };
    std::string jsonAsString = errorJson.dump(); //convert the json object to string
    for(int i=0;i<jsonAsString.length();i++) buffer.push_back(jsonAsString[i]); //push every char into the buffer
    return buffer;
}

std::vector<char> JsonResponsePacketSerializer::serializeResponse(LoginResponse lr)
{
    std::vector<char> buffer;
    //create the json object
    nlohmann::json errorJson = {
        {"Message",std::to_string(lr.status)}
    };
    std::string jsonAsString = errorJson.dump(); //convert the json object to string
    for (int i=0;i<jsonAsString.length();i++) buffer.push_back(jsonAsString[i]); //push every char into the buffer
    return buffer;
}

std::vector<char> JsonResponsePacketSerializer::serializeResponse(SignupResponse sr)
{
    std::vector<char> buffer;
    //create the json object
    nlohmann::json errorJson = {
        {"Message",std::to_string(sr.status)}
    };
    std::string jsonAsString = errorJson.dump(); //convert the json object to string
    for (int i=0;i<jsonAsString.length();i++) buffer.push_back(jsonAsString[i]); //push every char into the buffer
    return buffer;
}

std::string JsonResponsePacketSerializer::getPaddedNumber(int num, int digits)
{
    std::ostringstream ostr;
    ostr << std::setw(digits) << std::setfill('0') << num;
    return ostr.str();
}
