#pragma once

#include "Training.h"
class CombinationTraining: public Training
{
public:
	static void printMenu();
	static void openTraining();
	static void startTraining();
	//static void printResults(int matched_chars, int total_chars, long long total_enter_time);
	static std::string generateCombination();
};

