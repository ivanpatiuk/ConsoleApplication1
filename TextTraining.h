#pragma once
#include "Training.h"

using namespace std;

class TextTraining : public Training
{
public:
	static void printMenu();
	static void openTraining();
	static void startTraining();
	static void startTrainingWithTexts();
	static void printTrainingWithTextsMenu();
	static string getRandText();
};