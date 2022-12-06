#pragma once

class ConsoleInterface {
public:
	static void start();
	static void printMenu();
	static int getIntInput(int min, int max);
};
