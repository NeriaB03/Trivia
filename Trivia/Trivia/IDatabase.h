#pragma once

#include <io.h>
#include <list>
#include <string>
#include <fstream>
#include <vector>
#include "HelperFunctions.h"
#include "Question.h"
#include "JsonRequestPacketDeserializer.h"

#define QUESTION_FILE_NAME "questions.txt"
#define NUMBER_OF_QUESTIONS 10

class IDatabase {
public:
	virtual sqlite3* getDatabase() const = 0;
	virtual bool doesUserExist(std::string& username) = 0;
	virtual bool doesPasswordMatch(std::string& username,std::string& password) = 0;
	virtual void addNewUser(std::string& username,std::string& password,std::string& email) = 0;

	virtual std::list<Question> getQuestions(int numOfQuestions) = 0;
	virtual float getPlayerAverageAnswerTime(std::string username) = 0;
	virtual int getNumOfCorrectAnswers(std::string username) = 0;
	virtual int getNumOfTotalAnswers(std::string username) = 0;
	virtual int getNumOfPlayerGames(std::string username) = 0;
};