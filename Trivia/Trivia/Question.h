#pragma once

#include <iostream>
#include <time.h>
#include <vector>

#define NUM_OF_ANSWERS 4

class Question {
public:
	Question(std::string question,std::string correctAnswer,std::vector<std::string> incorrectAnswers);
	std::vector<std::string> getAnswers();
	std::string getCorrectAnswer();
private:
	std::string _question;
	std::string _correctAnswer;
	std::vector<std::string> _answers;
};