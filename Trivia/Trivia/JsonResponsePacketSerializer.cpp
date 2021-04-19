#include "JsonResponsePacketSerializer.h"

std::vector<char> JsonResponsePacketSerializer::serializeResponse(ErrorResponse er)
{
    std::vector<char> buffer;
    //create the json object
    nlohmann::json errorJson = {
        {"Code",MT_SERVER_ERROR},
        {"Data Length",getPaddedNumber(er.message.length(),PROTOCOL_DATA_LENGTH_SIZE)},
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
        {"Code",MT_CLIENT_LOG_IN},
        {"Data Length",getPaddedNumber(std::to_string(lr.status).length(),PROTOCOL_DATA_LENGTH_SIZE)},
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
        {"Code",MT_CLIENT_SIGN_UP},
        {"Data Length",getPaddedNumber(std::to_string(sr.status).length(),PROTOCOL_DATA_LENGTH_SIZE)},
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
