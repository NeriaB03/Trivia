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
    nlohmann::json loginJson = {
        {"Status",std::to_string(lr.status)}
    };
    std::string jsonAsString = loginJson.dump(); //convert the json object to string
    for (int i=0;i<jsonAsString.length();i++) buffer.push_back(jsonAsString[i]); //push every char into the buffer
    return buffer;
}

std::vector<char> JsonResponsePacketSerializer::serializeResponse(SignupResponse sr)
{
    std::vector<char> buffer;
    //create the json object
    nlohmann::json signupJson = {
        {"Status",std::to_string(sr.status)}
    };
    std::string jsonAsString = signupJson.dump(); //convert the json object to string
    for (int i=0;i<jsonAsString.length();i++) buffer.push_back(jsonAsString[i]); //push every char into the buffer
    return buffer;
}

std::vector<char> JsonResponsePacketSerializer::serializeResponse(LogoutResponse lr)
{
    std::vector<char> buffer;
    //create the json object
    nlohmann::json logoutJson = {
        {"Status",std::to_string(lr.status)}
    };
    std::string jsonAsString = logoutJson.dump(); //convert the json object to string
    for (int i = 0; i < jsonAsString.length(); i++) buffer.push_back(jsonAsString[i]); //push every char into the buffer
    return buffer;
}

std::vector<char> JsonResponsePacketSerializer::serializeResponse(GetRoomResponse rr)
{
    std::vector<char> buffer;
    //create the json object
    std::string rooms = "";
    for (auto const& it : rr.rooms) {
        rooms += it.name + ",";
    }
    nlohmann::json roomsJson = {
        {"Rooms",rooms}
    };
    std::string jsonAsString = roomsJson.dump(); //convert the json object to string
    for (int i = 0; i < jsonAsString.length(); i++) buffer.push_back(jsonAsString[i]); //push every char into the buffer
    return buffer;
}

std::vector<char> JsonResponsePacketSerializer::serializeResponse(GetPlayersInRoomResponse pr)
{
    std::vector<char> buffer;
    //create the json object
    std::string players = "";
    for (auto const& it : pr.players) {
        players += it + ",";
    }
    nlohmann::json playersJson = {
        {"PlayersInRoom",players}
    };
    std::string jsonAsString = playersJson.dump(); //convert the json object to string
    for (int i = 0; i < jsonAsString.length(); i++) buffer.push_back(jsonAsString[i]); //push every char into the buffer
    return buffer;
}

std::vector<char> JsonResponsePacketSerializer::serializeResponse(JoinRoomResponse jr)
{
    std::vector<char> buffer;
    //create the json object
    nlohmann::json joinJson = {
        {"Status",std::to_string(jr.status)}
    };
    std::string jsonAsString = joinJson.dump(); //convert the json object to string
    for (int i = 0; i < jsonAsString.length(); i++) buffer.push_back(jsonAsString[i]); //push every char into the buffer
    return buffer;
}

std::vector<char> JsonResponsePacketSerializer::serializeResponse(CreateRoomResponse cr)
{
    std::vector<char> buffer;
    //create the json object
    nlohmann::json createJson = {
        {"Status",std::to_string(cr.status)}
    };
    std::string jsonAsString = createJson.dump(); //convert the json object to string
    for (int i = 0; i < jsonAsString.length(); i++) buffer.push_back(jsonAsString[i]); //push every char into the buffer
    return buffer;
}

std::vector<char> JsonResponsePacketSerializer::serializeResponse(GetStatisticsResponse sr)
{
    std::vector<char> buffer;
    //create the json object
    std::string statistics = "";
    for (auto const& it : sr.statistics) {
        statistics += it + ",";
    }
    nlohmann::json statisticsJson = {
        {"UserStatistics",statistics}
    };
    std::string jsonAsString = statisticsJson.dump(); //convert the json object to string
    for (int i = 0; i < jsonAsString.length(); i++) buffer.push_back(jsonAsString[i]); //push every char into the buffer
    return buffer;
}

std::vector<char> JsonResponsePacketSerializer::serializeResponse(GetHighScoresResponse hsr)
{
    std::vector<char> buffer;
    std::string highScores = "";
    for (auto const& it : hsr.highScores) {
        highScores += it + ",";
    }
    nlohmann::json highScoresJson = {
        {"HighScores",highScores}
    };
    std::string jsonAsString = highScoresJson.dump();
    for (int i = 0; i < jsonAsString.length(); i++) buffer.push_back(jsonAsString[i]);
    return buffer;
}

std::vector<char> JsonResponsePacketSerializer::serializeResponse(CloseRoomResponse crr)
{
    std::vector<char> buffer;
    //create the json object
    nlohmann::json joinJson = {
        {"Status",std::to_string(crr.status)}
    };
    std::string jsonAsString = joinJson.dump(); //convert the json object to string
    for (int i = 0; i < jsonAsString.length(); i++) buffer.push_back(jsonAsString[i]); //push every char into the buffer
    return buffer;
}

std::vector<char> JsonResponsePacketSerializer::serializeResponse(StartGameResponse sgr)
{
    std::vector<char> buffer;
    //create the json object
    nlohmann::json joinJson = {
        {"Status",std::to_string(sgr.status)}
    };
    std::string jsonAsString = joinJson.dump(); //convert the json object to string
    for (int i = 0; i < jsonAsString.length(); i++) buffer.push_back(jsonAsString[i]); //push every char into the buffer
    return buffer;
}

std::vector<char> JsonResponsePacketSerializer::serializeResponse(GetRoomStateResponse grsr)
{
    std::vector<char> buffer;
    std::string allPlayers = "";
    for (auto const& it : grsr.players) {
        allPlayers += it;
        allPlayers += ',';
    }
    //create the json object
    nlohmann::json joinJson = {
        {"Status",std::to_string(grsr.status)},{"hasGameBegun",std::to_string(grsr.hasGameBegun)},{"isActive",std::to_string(grsr.isActive)},{"players",allPlayers},{"questionCount",std::to_string(grsr.questionCount)},{"answerTimeout",std::to_string(grsr.answerTimeout)},{"name",grsr.roomName},{"admin",grsr.admin},{"maxPlayers",grsr.maxNumOfPlayers}
    };
    std::string jsonAsString = joinJson.dump(); //convert the json object to string
    for (int i = 0; i < jsonAsString.length(); i++) buffer.push_back(jsonAsString[i]); //push every char into the buffer
    return buffer;
}

std::vector<char> JsonResponsePacketSerializer::serializeResponse(LeaveRoomResponse lrr)
{
    std::vector<char> buffer;
    //create the json object
    nlohmann::json joinJson = {
        {"Status",std::to_string(lrr.status)}
    };
    std::string jsonAsString = joinJson.dump(); //convert the json object to string
    for (int i = 0; i < jsonAsString.length(); i++) buffer.push_back(jsonAsString[i]); //push every char into the buffer
    return buffer;
}

std::vector<char> JsonResponsePacketSerializer::serializeResponse(GetGameResultsResponse ggrr)
{
    std::vector<char> buffer;
    //create the json object
    nlohmann::json resultsJson;
    if (ggrr.status == 1) {
        std::string results;
        for (auto const& it : ggrr.results) {
            results += it.username;
            results += ",";
            results += std::to_string(it.correctAnswerCount);
            results += ",";
            results += std::to_string(it.wrongAnswerCount);
            results += ",";
            results += std::to_string(it.averageAnswerTime);
            results += ";";
        }
        resultsJson = {
            {"Status",std::to_string(ggrr.status)},{"Results",results}
        };
    }
    else {
        resultsJson = {
            {"Status",std::to_string(ggrr.status)},{"Results","NULL"}
        };
    }
    std::string jsonAsString = resultsJson.dump(); //convert the json object to string
    for (int i = 0; i < jsonAsString.length(); i++) buffer.push_back(jsonAsString[i]); //push every char into the buffer
    return buffer;
}

std::vector<char> JsonResponsePacketSerializer::serializeResponse(SubmitAnswerResponse sar)
{
    std::vector<char> buffer;
    //create the json object
    nlohmann::json submitAnswerJson = {
        {"Status",std::to_string(sar.status)}
    };
    std::string jsonAsString = submitAnswerJson.dump(); //convert the json object to string
    for (int i = 0; i < jsonAsString.length(); i++) buffer.push_back(jsonAsString[i]); //push every char into the buffer
    return buffer;
}

std::vector<char> JsonResponsePacketSerializer::serializeResponse(GetQuestionResponse gqr)
{
    nlohmann::json resultsJson;
    if (gqr.status == 1) {
        resultsJson = {
            {"Status",std::to_string(gqr.status)},{"Question",gqr.question}
        };
    }
    else {
        std::string answers;
        for (auto const& it : gqr.answers) {
            answers += it.first;
            answers += ":";
            answers += it.second;
            answers += ",";
        }
        resultsJson = {
            {"Status",std::to_string(gqr.status)},{"Answers",answers}
        };
    }
}

std::vector<char> JsonResponsePacketSerializer::serializeResponse(LeaveGameResponse lgr)
{
    std::vector<char> buffer;
    //create the json object
    nlohmann::json leaveJson = {
        {"Status",std::to_string(lgr.status)}
    };
    std::string jsonAsString = leaveJson.dump(); //convert the json object to string
    for (int i = 0; i < jsonAsString.length(); i++) buffer.push_back(jsonAsString[i]); //push every char into the buffer
    return buffer;
}

std::string JsonResponsePacketSerializer::getPaddedNumber(int num, int digits)
{
    std::ostringstream ostr;
    ostr << std::setw(digits) << std::setfill('0') << num;
    return ostr.str();
}
