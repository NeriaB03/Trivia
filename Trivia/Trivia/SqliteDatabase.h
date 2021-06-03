#pragma once

#include "IDatabase.h"

class SqliteDatabase : public IDatabase {
public:
	SqliteDatabase();
	~SqliteDatabase();
	virtual sqlite3* getDatabase() const;
	virtual bool doesUserExist(std::string& username);
	virtual bool doesPasswordMatch(std::string& username, std::string& password);
	virtual void addNewUser(std::string& username, std::string& password, std::string& email);

	virtual std::list<Question> getQuestions(int numOfQuestions);
	virtual float getPlayerAverageAnswerTime(std::string username);
	virtual int getNumOfCorrectAnswers(std::string username);
	virtual int getNumOfTotalAnswers(std::string username);
	virtual int getNumOfPlayerGames(std::string username);
private:
	virtual bool openTable();
	virtual void addQuestionsToDatabse();
	sqlite3* _db;
	std::string _dbFileName = "DB.sqlite";
};