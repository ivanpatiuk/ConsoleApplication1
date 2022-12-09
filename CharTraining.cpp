#include "CharTraining.h"
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <chrono>
#include <conio.h>
#include "ConsoleInterface.h"

using namespace std;
using namespace chrono;

/*
	Функція виводу меню в консоль
*/
void CharTraining::printMenu() {
	cout << "--------------------------------------------------------------------------" << endl;
	cout << "| Наступне тренування включає тренування на введення підряд 50 символів  |" << endl;
	cout << "| Після початку на кожен символ буде відведений певний час, який зменшу- |" << endl;
	cout << "| ється при кожному наступному введені.                                  |" << endl;
	cout << "|                                                                        |" << endl;
	cout << "| УВАГА! В цьому режимі після введення кожного символу не потрібно       |" << endl;
	cout << "| натискати Enter для підтвердження вводу                                |" << endl;
	cout << "|                                                                        |" << endl;
	cout << "| Виберіть опцію меню:                                                   |" << endl;
	cout << "| (1) Вийти з тренування                                                 |" << endl;
	cout << "| (2) Почати тренування                                                  |" << endl;
	cout << "| (3) Завершити виконаня                                                 |" << endl;
	cout << "--------------------------------------------------------------------------" << endl;
}

/*
	Функція початку роботи з меню тренування
*/
void CharTraining::openTraining() {
	system("CLS"); // очистити консоль
	while (true) {
		printMenu(); // вивести меню-підказку
		int input = ConsoleInterface::getIntInput(0, 2);
		switch (input) {
		case 1: // повернутися до попереднього меню
			system("CLS");
			return;
		case 2: // почати тренування
			startTraining();
			break;
		case 3: // завершити роботу програми
			exit(0);
		}
	}
}

/*
	Функція запуску тренування на введення комбінацій
*/
void CharTraining::startTraining() {
	cout << "Введіть кількість символів для тренування в межах [5;100]" << endl;
	int chars_count = ConsoleInterface::getIntInput(5, 100); // кількість символів
	int matched_chars = 0; // кількість правильно введених символів
	int inputs = 0; // кількість введних символів
	char input; // введений символ 
	char generated; // згенерований символ
	long long time_to_enter = 5000; // початковий час на введення 5 секунд
	long long spent_time; // витрачений час на введення комбінації
	long long total_allowed_time = 0; // загальний лозволений час вводу всіх символів
	long long total_enter_time = 0; // загальний час вводу всіх символів
	bool previous_match = false;
	bool on_time = false;
	do {
		system("CLS"); // очистити консоль
		if (inputs != 0) { // якщо не перший ввід
			if (on_time) { // якщо вчасно
				if (previous_match) { // якщо правильний ввід
					cout << "Попереднє введення: ПРАВИЛЬНО" << endl;
				}
				else { // якщо неправильний ввід
					cout << "Попереднє введення: НЕПРАВИЛЬНО, введено '" << input << "', очікувалося '" << generated << "'" << endl;
				}
			}
			else { // якщо невчасно
				cout << "Попередній символ був введений невчасно" << endl;
			}
		}
		else { // якщо перший ввід
			cout << endl;
		}

		high_resolution_clock::time_point before = high_resolution_clock::now(); // запам'ятати час до введення
		srand(time(NULL)); // потрібно для правильного випадкового генерування
		generated = VOCABULARY[rand() % 72]; // взяти будь який символ з словника 
		cout << "Введіть символ: '" << generated << "'" << endl; // вивести підказку та комбінацію
		input = _getch(); // введення символу
		++inputs; // збільшити кількість введень
		high_resolution_clock::time_point after = high_resolution_clock::now(); // запам'ятати час після введення

		spent_time = floor<milliseconds>(after - before).count(); // порахувати час введення
		total_enter_time += spent_time; // збільшити загальний час введення
		if (time_to_enter > spent_time) { // якщо вчасний ввід
			on_time = true;
			if (input == generated) { // якщо правильно
				previous_match = true; // встановити маркер, що попередній ввід був правильний
				matched_chars += 1; // збільшити кількість правильно введених букв на 1
			}
			else { // якщо не правильно
				previous_match = false; // встановити маркер, що попередній ввід був неправильний
			}
		}
		else { // якщо невчасний ввід
			on_time = false; // встановити маркер, що попередній ввід був невчасний
		}
		total_allowed_time += time_to_enter;
		time_to_enter *= 0.965; // зменшити час на введення на 3,5%
	} while (inputs < chars_count); // робити до тих пір, поки кількість введень не досягне 50

	Training::printResults(matched_chars, chars_count, total_enter_time, total_allowed_time); // вивести результати
}

