#include <Windows.h> 
#include <iostream>
#include <iomanip>
#include "ConsoleInterface.h"
#include "CharTraining.h"
#include "CombinationTraining.h"
#include "TextTraining.h"

using namespace std;

/*
	Функція початку роботи програму (тренування)
*/
void ConsoleInterface::start() {
	SetConsoleCP(1251); // встановити можливість користуватися українською мовою
	SetConsoleOutputCP(1251); // встановити можливість користуватися українською мовою
	int input;
	do {
		printMenu(); // вивести меню-підказку
		input = getIntInput(0, 3); // отримати опцію меню (число від 1 до 4)
		switch (input) {
		case 1: // почати тренування з символами
			CharTraining::openTraining(); 
			break;
		case 2: // почати тренування з комбінаціями
			CombinationTraining::openTraining();
			break;
		case 3: // почати тренування з текстом
			TextTraining::openTraining();
			break;
		case 0: // завершити роботу програми
			exit(0);
		}
	} while (true);
}

/*
	Функція виводу меню в консоль
*/
void ConsoleInterface::printMenu() {
	cout << "--------------------------------------------" << endl;
	cout << "| Виберіть наступу опцію:                  |" << endl;
	cout << "| (1) Розпочати тренування з символами     |" << endl;
	cout << "| (2) Розпочати тренування з комбінаціямии |" << endl;
	cout << "| (3) Розпочати тренування з творами       |" << endl;
	cout << "| (0) Завершити виконання програми         |" << endl;
	cout << "--------------------------------------------" << endl;
}

/*
	Функція отримання вибору користувача. Приймає 2 аргументи:

	@min - мінімально допустимий вибір вводу
	@max - максимально допустимий вибір вводу

	Повертає ціле число в допустимхи межах [min,max]
*/
int ConsoleInterface::getIntInput(int min, int max) {
	int input; // введене число
	do {
		cout << "Введіть опцію: "; cin >> input;
		if (min <= input && input <= max) { // якщо в межах, то повернути
			return input;
		}
		else { // в іншому випадку, вивести повідомлення
			cout << "Такої опції нема, спробуйте ще раз" << endl;
		}
	} while (true); // повторювати, до поки користувач не введе число в межах [min,max]
}