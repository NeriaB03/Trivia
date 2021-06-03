#include "Question.h"

Question::Question(std::string question, std::string correctAnswer, std::vector<std::string> incorrectAnswers)
{
	this->_question = question;
	this->_correctAnswer = correctAnswer;
	this->_answers = incorrectAnswers;
	srand(time(0));
	int randomNum = rand() % NUM_OF_ANSWERS;
	auto itPos = this->_answers.begin() + randomNum;
	auto newIt = this->_answers.insert(itPos, correctAnswer);
}
