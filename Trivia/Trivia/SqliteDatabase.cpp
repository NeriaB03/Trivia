#include "SqliteDatabase.h"

SqliteDatabase::SqliteDatabase()
{
	if(!openTable()) throw std::exception(__FUNCTION__ " - Failed while open database!");
}

SqliteDatabase::~SqliteDatabase()
{
	sqlite3_close(this->_db);
	this->_db = nullptr;
	delete this->_db;
}

sqlite3* SqliteDatabase::getDatabase() const
{
	return this->_db;
}

bool SqliteDatabase::doesUserExist(std::string& username)
{
	std::string sqlStatement = "SELECT * FROM USERS WHERE NAME LIKE '" + username + "';";
	std::vector<std::pair<std::string, std::string>> usersVector = HelperFunctions::runSql(sqlStatement, this->_db);
	if (usersVector.size() == 0) return false;
	return true;
}

bool SqliteDatabase::doesPasswordMatch(std::string& username, std::string& password)
{
	std::string sqlStatement = "SELECT * FROM USERS WHERE NAME LIKE '" + username + "' AND PASSWORD LIKE '" + password + "';";
	std::vector<std::pair<std::string, std::string>> usersVector = HelperFunctions::runSql(sqlStatement, this->_db);
	if (usersVector.size() == 0) return false;
	return true;
}

void SqliteDatabase::addNewUser(std::string& username, std::string& password, std::string& email)
{
	std::string sqlStatement = "INSERT INTO USERS('NAME','PASSWORD','EMAIL')VALUES('" + username + "','" + password + "','" + email + "');";
	HelperFunctions::runSqlWithoutCallback(sqlStatement, this->_db);
}

std::list<Question> SqliteDatabase::getQuestions(int numOfQuestions)
{
	std::list<Question> listOfQuestions;
	std::string sqlStatement = "SELECT * FROM QUESTIONS;";
	std::vector<std::pair<std::string, std::string>> questions = HelperFunctions::runSql(sqlStatement, this->_db);
	if (questions.size() == 0) return listOfQuestions;
	int index = 0;
	std::string question = "";
	std::string correctAnswer = "";
	std::string firstIncorrectAnswer = "";
	std::string secondIncorrectAnswer = "";
	std::string thirdIncorrectAnswer = "";
	for (auto const& it : questions) {
		switch (index) {
		case 0:
			question = it.second;
			index++;
			break;
		case 1:
			correctAnswer = it.second;
			index++;
			break;
		case 2:
			firstIncorrectAnswer = it.second;
			index++;
			break;
		case 3:
			secondIncorrectAnswer = it.second;
			index++;
			break;
		case 4:
			thirdIncorrectAnswer = it.second;
			index = 0;
			listOfQuestions.push_back(Question(question, correctAnswer, std::vector<std::string>{firstIncorrectAnswer, secondIncorrectAnswer, thirdIncorrectAnswer}));
			break;
		}
	}
	return listOfQuestions;
}

float SqliteDatabase::getPlayerAverageAnswerTime(std::string username)
{
	std::string sqlStatement = "SELECT AVERAGE_TIME FROM STATISTICS WHERE NAME LIKE " + username + ";";
	std::vector<std::pair<std::string, std::string>> averageTime = HelperFunctions::runSql(sqlStatement, this->_db);
	return std::stof(averageTime.front().second);
}

int SqliteDatabase::getNumOfCorrectAnswers(std::string username)
{
	std::string sqlStatement = "SELECT CORRECT_ANSWERS FROM STATISTICS WHERE NAME LIKE " + username + ";";
	std::vector<std::pair<std::string, std::string>> correctAnswers = HelperFunctions::runSql(sqlStatement, this->_db);
	return std::stoi(correctAnswers.front().second);
}

int SqliteDatabase::getNumOfTotalAnswers(std::string username)
{
	std::string sqlStatement = "SELECT TOTAL_ANSWERS FROM STATISTICS WHERE NAME LIKE " + username + ";";
	std::vector<std::pair<std::string, std::string>> totalAnswers = HelperFunctions::runSql(sqlStatement, this->_db);
	return std::stoi(totalAnswers.front().second);
}

int SqliteDatabase::getNumOfPlayerGames(std::string username)
{
	std::string sqlStatement = "SELECT TOTAL_GAMES FROM STATISTICS WHERE NAME LIKE " + username + ";";
	std::vector<std::pair<std::string, std::string>> totalGames = HelperFunctions::runSql(sqlStatement, this->_db);
	return std::stoi(totalGames.front().second);
}

bool SqliteDatabase::openTable()
{
	int doesFileExist = _access(this->_dbFileName.c_str(), 0);
	int res = sqlite3_open(this->_dbFileName.c_str(), &this->_db);
	std::string sqlStatement = "";
	if (res != SQLITE_OK) {
		this->_db = nullptr;
		return false;
	}
	if (doesFileExist != 0) {
		sqlStatement = "CREATE TABLE USERS (NAME TEXT PRIMARY KEY NOT NULL, PASSWORD TEXT NOT NULL, EMAIL TEXT NOT NULL);";
		if (!HelperFunctions::runSqlWithoutCallback(sqlStatement, this->_db)) return false;
		sqlStatement = "CREATE TABLE QUESTIONS (QUESTION TEXT PRIMARY KEY NOT NULL, CORRECT_ANSWER TEXT NOT NULL, FIRST_INCORRECT_ANSWER TEXT NOT NULL, SECOND_INCORRECT_ANSWER TEXT NOT NULL, THIRD_INCORRECT_ANSWER TEXT NOT NULL);";
		if (!HelperFunctions::runSqlWithoutCallback(sqlStatement, this->_db)) return false;
		this->addQuestionsToDatabse(); //add questions to the db
		sqlStatement = "CREATE TABLE STATISTICS (NAME TEXT PRIMARY KEY NOT NULL, TOTAL_ANSWERS INTEGER NOT NULL, CORRECT_ANSWERS INTEGER NOT NULL, TOTAL_GAMES INTEGER NOT NULL, AVERAGE_TIME FLOAT NOT NULL, HIGHEST_SCORE INTEGER NOT NULL);";
		if(!HelperFunctions::runSqlWithoutCallback(sqlStatement, this->_db)) return false;
	}
	return true;
}

void SqliteDatabase::addQuestionsToDatabse()
{
	system("python C:\\Magshimim\\CPP\\Trivia\\trivia\\getQuestionsJSONFormat.py"); //run python code that gets 10 random questions using GET request
	std::fstream questionsFile;
	std::string fileContent = "";
	std::string line = "";
	questionsFile.open(QUESTION_FILE_NAME);
	if (questionsFile.is_open()) {
		while (getline(questionsFile, line)) {
			fileContent += line;
		}
		std::vector<char> buffer;
		nlohmann::json questionsJson = nlohmann::json::parse(fileContent);
		for (int i = 0; i < NUMBER_OF_QUESTIONS; i++) {
			std::string sqlStatement = "INSERT INTO QUESTIONS('QUESTION','CORRECT_ANSWER','FIRST_INCORRECT_ANSWER','SECOND_INCORRECT_ANSWER','THIRD_INCORRECT_ANSWER')VALUES('" + questionsJson["results"][i]["question"].dump() + "','" + questionsJson["results"][i]["correct_answer"].dump() + "','" + questionsJson["results"][i]["incorrect_answers"][0].dump() + "','" + questionsJson["results"][i]["incorrect_answers"][1].dump() + "','" + questionsJson["results"][i]["incorrect_answers"][2].dump() + "');";
			HelperFunctions::runSqlWithoutCallback(sqlStatement, this->_db);
		}
	}
	else throw std::exception(__FUNCTION__ " - Failed while getting questions");
}