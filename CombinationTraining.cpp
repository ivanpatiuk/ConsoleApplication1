#include "CombinationTraining.h"
#include <iostream>
#include <iomanip>
#include "ConsoleInterface.h"
#include <chrono>
#include <conio.h>

using namespace std;
using namespace chrono;

/*
	Функція виводу меню в консоль
*/
void CombinationTraining::printMenu() {
	cout << "--------------------------------------------------------------------------" << endl;
	cout << "| Наступне тренування включає тренування на введення комбінації символів.|" << endl;
	cout << "| Після початку на кожну комбінацію символів буде відведений певний час, |" << endl;
	cout << "| який зменшується при кожному наступному введені.                       |" << endl;
	cout << "|                                                                        |" << endl;
	cout << "| УВАГА! В цьому режимі після введення кожної комбінації не потрібно     |" << endl;
	cout << "| натискати для підтвердження комбінації. Також в даному режимі виводи-  |" << endl;
	cout << "| ться текст набраної комбінації.                                        |" << endl;
	cout << "|                                                                        |" << endl;
	cout << "| Виберіть опцію меню:                                                   |" << endl;
	cout << "| (1) Вийти з тренування                                                 |" << endl;
	cout << "| (2) Почати тренування                                                  |" << endl;
	cout << "| (3) Завершити виконаня програми                                        |" << endl;
	cout << "--------------------------------------------------------------------------" << endl;
}

/*
	Функція початку роботи з меню тренування
*/
void CombinationTraining::openTraining() {
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
void CombinationTraining::startTraining() {
	cout << "Введіть кількість комбінацій для тренування в межах [5;100]" << endl;
	int combinations_count = ConsoleInterface::getIntInput(5, 100); // кількість символів
	int inputs = 0; // кількість введних комбінацій
	int total_chars = 0;
	int matched_chars = 0; // кількість правильно введених комбінацій
	char input_char;
	string input; // введена комбінація 
	string generated; // згенерована комбінація
	long long time_to_enter = 5000; // початковий час на введення 5 секунд
	long long spent_time; // витрачений час на введення комбінації
	long long total_allowed_time = 0; // загальний лозволений час вводу всіх символів
	long long total_enter_time = 0; // загальний час вводу всіх комбінацій
	bool previous_match = false;
	bool on_time = false;
	do {
		system("CLS"); // очистити консоль

		high_resolution_clock::time_point before = high_resolution_clock::now(); // запам'ятати час до введення
		generated = generateCombination(); // згенерувати комбінацію
		if (total_chars != 0) { // якщо не перший ввід (при першому вводі загальна кількість букв == 0)
			if (on_time) { // якщо вчасно
				if (previous_match) { // якщо правильний ввід
					cout << "Попереднє введення: ПРАВИЛЬНО" << endl;
				}
				else { // вчасно, неправильний ввід
					cout << "Попереднє введення: НЕПРАВИЛЬНО, введено '" << input << "', очікувалося '" << generated << "'" << endl;
				}
			}
			else { // якщо невчасно
				cout << "Попередній блок було введено невчасно" << endl;
			}
		}
		else { // якщо перший ввід 
			cout << endl;
		}
		input = "\0"; // для занулення попереднього введеного блоку
		cout << "Введіть комбінацію: '" << generated << "'" << endl; // вивести підказку та комбінацію
		for (size_t i = 0; i < generated.length(); ++i) { // введення комбінації
			input_char = _getch();
			input += input_char;
			cout << input_char;
		}  
		++inputs; // збільшити кількість введень
		high_resolution_clock::time_point after = high_resolution_clock::now(); // запам'ятати час після введення

		spent_time = floor<milliseconds>(after - before).count(); // порахувати час введення
		total_enter_time += spent_time; // збільшити загальний час введення

		if (time_to_enter > spent_time) { // якщо вчасно введено
			on_time = true; // встановити прапорець чи вчасний ввід true
			previous_match = true; // встановити прапорець чи правильний ввід true
			for (int i = 0; i < generated.length(); ++i) { // перевірити співпадіння кожного символу
				if (input[i] == generated[i]) { // якщо символи однакові
					++matched_chars; // збільшити лічильник правильно введених букв на 1
				}
				else { // якщо символи різні
					previous_match = false; // встановити прапорець чи правильний ввід false
				}
			}
		}
		else { // встановити прапорець чи вчасний ввід false
			on_time = false;
		}
		total_allowed_time += time_to_enter;
		total_chars += generated.length();
		time_to_enter *= 0.985; // зменшити час на введення на 1,5%
	} while (inputs < combinations_count); // робити до тих пір, поки кількість введень не досягне 50

	Training::printResults(matched_chars, total_chars, total_enter_time, total_allowed_time); // вивести результати
}

/*
	Функція генерації рандомної комбінації від 2 до 5 символів
*/
string CombinationTraining::generateCombination() {
	srand(time(NULL)); // потрібно для правильного випадкового генерування
	string result; // комбінація
	for (int i = 0; i < rand() % 4 + 2; ++i) { // від 2 до 5 ітерацій
		result += (VOCABULARY[rand() % 72]); // додати рандомний символ з словника
	}
	return result; // повернути комбінацію
}

