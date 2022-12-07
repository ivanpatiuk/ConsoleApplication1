#pragma once

#include <string>
#include <iomanip>

using namespace std;

class Training {
public:
	static const string VOCABULARY;

	virtual	void printMenu() = 0;
	virtual void openTraining() = 0;
	virtual void startTraining() = 0;
	static const void printResults(int matched_chars, int total_chars, long long total_enter_time);
};