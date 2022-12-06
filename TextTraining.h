#pragma once
#include "Training.h"

class TextTraining : public Training
{
public:

	static const std::string SENTENCES[25];

	static void printMenu();
	static void openTraining();
	static void startTraining();
	static void startTrainingWithTexts();
	/*static void printResults(int matched_chars, int total_chars, long long total_enter_time);*/
	static std::string getRandText(int used_sentences[]);
};