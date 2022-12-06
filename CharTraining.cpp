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
	int inputs = 0; // кількість введних символів
	int chars_count = 50; // кількість символів
	int matched_chars = 0; // кількість правильно введених символів
	char input; // введений символ 
	char generated; // згенерований символ
	long long time_to_enter = 5000; // початковий час на введення 5 секунд
	long long spent_time; // витрачений час на введення комбінації
	long long total_enter_time = 0; // загальний час вводу всіх символів
	bool previous_match = false;
	bool on_time = false;
	do {
		system("CLS"); // очистити консоль
		if (on_time) {
			if (inputs != 0) {
				if (previous_match) {
					cout << "Попереднє введення: ПРАВИЛЬНО" << endl;
				}
				else {
					cout << "Попереднє введення: НЕПРАВИЛЬНО, введено '" << input << "', очікувалося '" << generated << "'" << endl;
				}
			}
			else {
				cout << endl;
			}
		}
		else {
			cout << "Попередній символ був введений невчасно" << endl;
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
		if (time_to_enter > spent_time) {
			on_time = true;
			if (input == generated) { // якщо вчасно введено і правильно, збільшити лічильник
				// правильних введень
				previous_match = true;
				matched_chars += 1;
			}
			else {
				previous_match = false;
			}
		}
		else {
			on_time = false;
		}
		time_to_enter *= 0.965; // зменшити час на введення на 3,5%
	} while (inputs < chars_count); // робити до тих пір, поки кількість введень не досягне 50

	Training::printResults(matched_chars, chars_count, total_enter_time); // вивести результати
}

/*
	Функція виведення результатів
*/
//void CharTraining::printResults(int matched_chars, int total_chars, long long total_enter_time) {
//	system("CLS"); // очистити консоль
//	// вивести точність за формулою (правильне введення) / 50 * 100%
//	// вивести рівень за критеріями кількості правильних введень: 
//	//         [0,9] - новачок, 	
//	//         [10,24] - продвинутий, 
//	//         [25,40] - Механічні пальці, 
//	//         [41,50] - Штучний інтелект
//	cout << "--------------------------------------------------------------------------" << endl;
//	cout << "| Результати:                                                            |" << endl;
//	cout << "|                                                                        |" << endl;
//	cout << "| Точність: " << setw(5) << setprecision(5) << 100.0 * matched_chars / total_chars << "%" << setw(56) << "|" << endl;
//	cout << "| Рівень: ";
//	if (matched_chars < 10) {
//		cout << setw(10) << "Новачок :(";
//	}
//	else if (matched_chars < 25) {
//		cout << setw(10) << "Продвинутий -_-";
//	}
//	else if (matched_chars < 41) {
//		cout << setw(10) << "Механічні пальці :)";
//	}
//	else {
//		cout << setw(10) << "Штучний інтелект О_О";
//	}
//	cout << "                                                     |" << endl;
//	cout << "| Середній час введення букви (мілісекунд): " << setw(15) << setprecision(5) << left<< total_enter_time / total_chars << setw(15) << "|" << endl;
//	cout << "--------------------------------------------------------------------------" << endl;
//}

