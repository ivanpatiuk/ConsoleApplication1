#include "TextTraining.h"
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <chrono>
#include <conio.h>
#include "ConsoleInterface.h"
#include "TextLoader.h"
#include <string>

using namespace std;
using namespace chrono;

/*
	??????? ?????? ???? ? ???????
*/
const static string SENTENCES[] = { "?? ????, ?? ????????? ???? ?? ?????? ????? ????? ???????? ?? ??????? ?????, ??? ???? ??????????, ? ??????, ? ????? ???? ?????, ???? ????, ?? ???? ???????.",
									"?? ???? ???????? ??? ????? ????? ?? ?????? ????, ? ???? ??? ???????? ??????? ???? ? ????? ????????? ???? ??????.",
									"???? ? ???, ????! ??????? ? ??? ?????????, ??????? ????? ?????????, ????? ??????????, ??????'? ?????????, ???? ????? ????? ??????????!",
									"????? ??? ? ????????, ??????, ???? ??????????? ? ????, ??? ? ????? ??? ??????? ????? ?? ????? ???????.",
									"???? ????? ????????????, ????? ?????, ? ??? ?? ????? ????????. ??????????? ??? ???? ?? ??????????, ??? ??????? ???? ?????????????, ?????????????.",
									"???? ????? ?????? ? ???????? ????? ?????? ????, ??? ??????? ??????? ???, ? ???? ????? ? ????. ???? ????? ?????? ???????, ??? ?????? ????, ????????? ??? ????? ? ????? ?? ??????????.",
									"?? ???? ????, ?? ? ???? ?????, ?? ? ??? ?????? ????? ??????????. ͳ, ?? ????, ?? ????????? ??????! ?? ?????????, ??? ?????, ? ?? ????.",
									"????????????? ? ?? ?? ???????? ? ?????? ?? ???????, ???? ?????? ???????? ? ???????? ???????????.",
									"??????? ? ?? ? ?? ?????? ??????????? ??????????? ???????. ?? ???? ? ?? ???????? ???? ?? ??????????? ?????????????, ???? ?? ????????????? ???? ? ????? ?? ?? ?????? ??????????????? ????????.",
									"???? ?? ??????. ????????, ?? ??????????? ????????????? ?????????? ???????, ?? ??????????? ???? ????????? ????????? ????? ????????.",
									"???? ???, ???? ???, ???? ???? ? ????! ???? ????? ?? ?????? ??????? ???????",
									"? ????? ?????? ???. ????? ?????? ???? ????i???, ?? ?????, i ???? ??????? I ?, ?????????? ?????? ???i????, ???? ?i? ?????????? ????i???? ??????, ? ???i ?????i ????? ?????, ?? ?.",
									"??????, ????, ??, ????? ??????! ?? ? ?????? ????? ??????! ?? ?? ??? ? ????, ? ????????? ????????? ????䳿 ?????",
									"???? ?????? ?????, ?? ?? ????? ?? ???????? ? ????????? ?????? ?? ??????, ?? ????볿 ????? ???? ϒ???-??????? ??? ???????? ??????.",
									"??-???? ?? ????? ? ????? ????? ??????, ??-???? ??? ? ??? ??????! ?? ?? ? ????? ??-???? ?????? ?????????? ?? ? ?? ????????? ???????",
									"I?? ? i ?? ?? ???????, ?? ?? ???????? ????-?????? ?i?? i ???????, ?? ?????? ???? i? ?? ?i?'? ??? i ?????i?, ?? ???i??? ??? ?????i???i ????????? ?? ???? ??i?? ? ???????? ?????i?. ?i, ?? ??? ???!",
									"? ???? ?????, ?? ? ??????????! ?????????. ?????????? ?? ???????????. ?? ????????????, ???????? ?????? ???????? ??????? - ?? ???????? ????.",
									"?? ???? ????? ?????; ???????: ?????? - ?????... ??, ????-????! ???? ?? ?????, ??-?? ???????? ?????? ??? ???????? ??????, ??? ?? ?? ???????? ???? ???.",
									"? ?????? ????? ???????? ????? ??? ????, ??? ????? ????? ??? ????? ??? ???????. ? ? ?? ????? ????????? ?????? ?? ???.",
									"??? ???, ??? ??? ???? ?????? ??????? ????? ???, ????? ??? ???? ???? ?쳺???? ??? ???, ??? ??? ???? ?? ??????? ?????, ? ??? ???? ???? ?????.",
									"??, ?? ????? ?? ???? ? ?? ?????? ????? ??? ? ?? ?????? ???????, ??? ? ?????? ???????? ? ????? ?? ?????? ??? ???? ???: ?? ? ????, ?? ? ????? ????, ???? ???? ??????, ?????? ???? ???? ?????.",
									"?? ??? ????? ??? ????? ????????, ?? ????? ? ???????? ??? ?????, ? ?? ???? ???????, ??? ????, ? ???? ? ????? ???? ???????? ???!",
									"? ?? ? ????????? ?? ? ?? ? ????? ????, ?? ?????? ????? ? ??? ?? ???????? ??????? ??????, ?? ????? ??????, ? ???? ?? ???? ???????? ????.",
									"??? ??, ?? ???? ???????? ?????, ?? ???? ? ???? ?????? ? ?????. ?? ????????? ?????? ?????? ???????.",
									"????? ?????????? ?? ???????. ?? ????? ?? ?????? ???? ???????! ?? ? ???? ??? ?? ??????? ???????, ? ?????? ????????!" };


/*
	??????? ?????? ?????? ? ???? ??????????
*/
void TextTraining::printMenu() {
	cout << "--------------------------------------------------------------------------" << endl;
	cout << "| ???????? ?????????? ??????? ?????????? ?? ???????? ??????. ϳ??? ????- |" << endl;
	cout << "| ??? ?? ????? ??????? ???? ?????????? ?????? ???, ???? ??????????? ???  |" << endl;
	cout << "| ??? ??????? ?????????? ???????.                                        |" << endl;
	cout << "|                                                                        |" << endl;
	cout << "| ?????! ? ????? ?????? ????? ???????? ??????? ??????? ?? ???????? ????- |" << endl;
	cout << "| ????? Enter??? ????????????? ????? ???????. ????? ? ?????? ?????? ????-|" << endl;
	cout << "| ?????? ????? ????????? ???????. ?? ??????????? ????????? ????????????  |" << endl;
	cout << "| ?????, ???????? ?? ???? ?????????? ?? ???????? ???????, ???? ????????- |" << endl;
	cout << "| ??? ??????? ???????? ??????.                                           |" << endl;
	cout << "|                                                                        |" << endl;
	cout << "| ???????? ????? ????:                                                   |" << endl;
	cout << "| (1) ?????? ?????????? ? ???????? ????????                              |" << endl;
	cout << "| (2) ??????? ????? ??? ?????????? ? ?????                               |" << endl;
	cout << "| (3) ????? ? ??????????                                                 |" << endl;
	cout << "| (0) ????????? ????????? ????????                                       |" << endl;
	cout << "--------------------------------------------------------------------------" << endl;
}

/*
	??????? ?????? ???? ??? ?????????? ? ???????
*/
void TextTraining::printTrainingWithTextsMenu() {
	cout << "--------------------------------------------------------------------------" << endl;
	cout << "| ???????? ????? ????:                                                   |" << endl;
	cout << "| (1) ?????????? ? ?????? '???????????', ?. ??????                       |" << endl;
	cout << "| (2) ?????????? ? ?????? '??????? ??? ???? ???????', ?. ??????          |" << endl;
	cout << "| (3) ?????????? ? ?????? 'Contra spem spero', ???? ????????             |" << endl;
	cout << "| (4) ?????????? ? ?????? '???????? ??????????', ?. ?????                |" << endl;
	cout << "| (5) ?????????? ? ?????? '???? ?? ?????? ????? ???????', ?.????????     |" << endl;
	cout << "| (6) ?????????? ? ?????? '???????', ?.????????                          |" << endl;
	cout << "| (7) ?????????? ? ?????? '?????', ?.???????????                         |" << endl;
	cout << "| (8) ?????????? ? ?????? '? ????? ?? ?????', ?.????                     |" << endl;
	cout << "| (9) ????? ? ??????????                                                 |" << endl;
	cout << "| (0) ????????? ????????? ????????                                       |" << endl;
	cout << "--------------------------------------------------------------------------" << endl;
}

/*
	??????? ??????? ?????? ? ???? ??????????
*/
void TextTraining::openTraining() {
	system("CLS"); // ???????? ???????
	while (true) {
		printMenu(); // ??????? ????-????????
		int input = ConsoleInterface::getIntInput(0, 3);
		switch (input) {
		case 1: // ?????? ?????????? ? ???????? ????????
			startTraining();
			break;
		case 2: // ?????? ?????????? ? ???????
			startTrainingWithTexts();
			break;
		case 3: // ??????????? ?? ???????????? ???? 
			system("CLS");
			return;
		case 0: // ????????? ?????? ????????
			exit(0);
		}
	}
}

/*
	??????? ??????? ?????????? ? ?????????
*/
void TextTraining::startTraining() {
	cout << "??????? ????????? ?????????? ??? ?????????? ? ????? [1;25] (????????????? ?? ?????? 10)" << endl;
	int sentence_count = ConsoleInterface::getIntInput(1, 25); // ????????? ??????????
	int inputs = 0; // ????????? ??????? ??????
	int matched_chars = 0; // ????????? ????????? ???????? ??????
	int total_chars = 0; // ???????? ????????? ????????
	char input_char; // ???????? ??????
	string input; // ??????? ?????????? 
	string generated; // ??????????? ???????
	long long time_to_enter = 20000; // ?????????? ??? ?? ???????? 20 ??????
	long long spent_time; // ?????????? ??? ?? ???????? ???????
	long long total_allowed_time = 0; // ????????? ?????????? ??? ????? ???? ????????
	long long total_enter_time = 0; // ????????? ??? ????? ???? ??????
	long long additional_time;
	bool previous_match = false; // ??? ????????? ?? ?????????? ???? ??? ??????????
	bool on_time = false; // ??? ????????? ?? ?????????? ???? ??? ???????
	do {
		system("CLS"); // ???????? ???????
		srand(time(NULL));
		if (total_chars != 0) { // ???? ?? ?????? ???? (??? ??????? ????? ???????? ????????? ???? == 0)
			if (on_time) { // ???? ??????
				if (previous_match) { // ???? ?????????? ????
					cout << "????????? ????????: ?????????" << endl;
				}
				else { // ??????, ???????????? ????
					cout << "????????? ????????: ???????????" << endl << "???????:" << input << endl << "???????????: " << generated << "'" << endl;
				}
			}
			else { // ???? ????????
				cout << "????????? ??????? ???? ??????? ????????, ????????? " << spent_time << ", ????????? " << time_to_enter / 0.95 << endl;
			}
		}
		else { // ???? ?????? ???? 
			cout << endl;
		}
		generated = getRandText(); // ???????? ?????
		input = "\0"; // ??? ????????? ???????????? ????????? ??????
		cout << "??????? ???????: '" << endl << generated << "'" << endl; // ??????? ???????? ?? ??????????

		high_resolution_clock::time_point before = high_resolution_clock::now(); // ?????'????? ??? ?? ????????
		for (size_t i = 0; i < generated.length(); ++i) { // ???????? ??????????
			input_char = _getch(); // ???????? ????????? ?????? ? ???????
			input += input_char; // ?????? ?? ????????? ??????? ?????????? ???????? ??????
			cout << input_char; // ??????? ???????? ??????
		}
		++inputs; // ????????? ????????? ???????
		high_resolution_clock::time_point after = high_resolution_clock::now(); // ?????'????? ??? ????? ????????

		spent_time = floor<milliseconds>(after - before).count(); // ?????????? ??? ????????
		total_enter_time += spent_time; // ????????? ????????? ??? ????????

		if (generated.length() > 170) { // ???? ? ??????? ?-??? ???????? ?????? 170, ????????? ?????????? ??? ?? 15 ???.
			additional_time = 15000;
		}
		else if (generated.length() > 135) { // ???? ? ??????? ?-??? ???????? ?????? 135, ????????? ?????????? ??? ?? 10 ???.
			additional_time = 10000;
		}
		else if (generated.length() > 100) { // ???? ? ??????? ?-??? ???????? ?????? 100, ????????? ?????????? ??? ?? 5 ???.
			additional_time = 5000;
		}
		else { // ? ?????? ???????, ?????????? ?????????? ??? 0 ???.
			additional_time = 0;
		}
		if (time_to_enter + additional_time > spent_time) { // ???? ?????? ???????
			on_time = true; // ?????????? ????????? ?? ??????? ???? true
			previous_match = true; // ?????????? ????????? ?? ?????????? ???? true
			for (int i = 0; i < generated.length(); ++i) { // ?????????? ??????????? ??????? ???????
				if (input[i] == generated[i]) { // ???? ??????? ????????
					++matched_chars; // ????????? ????????? ????????? ???????? ???? ?? 1
				}
				else { // ???? ??????? ?????
					previous_match = false; // ?????????? ????????? ?? ?????????? ???? false
				}
			}
		}
		else { // ?????????? ????????? ?? ??????? ???? false
			on_time = false;
		}
		total_allowed_time += time_to_enter;
		total_chars += generated.length(); // ????????? ???????? ????????? ???????? ????????
		time_to_enter *= 0.95; // ???????? ??? ?? ???????? ?? 5%
	} while (inputs < sentence_count); // ?????? ?? ??? ???, ???? ????????? ??????? ?? ??????? 15

	Training::printResults(matched_chars, total_chars, total_enter_time, total_allowed_time); // ??????? ??????????
}

/*
	??????? ??????? ?????????? ? ???????
*/
void TextTraining::startTrainingWithTexts() {
	printTrainingWithTextsMenu(); // ??????? ????-???????? ?? ?????
	int choice = ConsoleInterface::getIntInput(0, 9); // ?????? ?????
	if (choice == 0) { // ???? 0, ??????????? ?? ???????????? ????
		return;
	}
	else if (choice == 9) { // ???? 9, ????? ? ????????
		exit(0);
	}
	ifstream text_file = TextLoader::openText(choice); // ???????? ?? ???????? ???? ?????
	int matched_chars = 0; // ????????? ????????? ???????? ??????
	int total_chars = 0; // ???????? ????????? ????????
	char input_char; // ???????? ??????
	string input; // ??????? ??????? 
	string next_sentence; // ???????? ??????? ? ?????
	long long time_to_enter; // ?????????? ??? ?? ???????? (???????? ??? ??????? ???????)
	long long spent_time; // ?????????? ??? ?? ???????? ???????
	long long total_allowed_time = 0; // ????????? ?????????? ??? ????? ???? ????????
	long long total_enter_time = 0; // ????????? ??? ????? ???? ????
	bool previous_match = false; // ??? ????????? ?? ?????????? ???? ??? ??????????
	bool on_time = false; // ??? ????????? ?? ?????????? ???? ??? ???????

	while(getline(text_file, next_sentence)){ // ???????? ?? ???? ???????? ?????
		system("CLS"); // ???????? ???????
		srand(time(NULL));
		if (total_chars != 0) { // ???? ?? ?????? ???? (??? ??????? ????? ???????? ????????? ???? == 0)
			if (on_time) { // ???? ??????
				if (previous_match) { // ???? ?????????? ????
					cout << "????????? ????????: ?????????" << endl;
				}
				else { // ??????, ???????????? ????
					cout << "????????? ????????: ???????????" << endl << "???????:" << input << endl << "???????????: " << next_sentence << "'" << endl;
				}
			}
			else { // ???? ????????
				cout << "????????? ??????? ???? ??????? ????????, ????????? " << spent_time << ", ????????? " << time_to_enter / 0.95 << endl;
			}
		}
		else { // ???? ?????? ???? 
			cout << endl;
		}
		input = "\0"; // ??? ????????? ???????????? ????????? ??????
		cout << "??????? ???????: '" << endl << next_sentence << "'" << endl; // ??????? ???????? ?? ??????????

		high_resolution_clock::time_point before = high_resolution_clock::now(); // ?????'????? ??? ?? ????????
		for (size_t i = 0; i < next_sentence.length(); ++i) { // ???????? ??????????
			input_char = _getch(); // ???????? ????????? ?????? ? ???????
			input += input_char; // ?????? ?? ????????? ??????? ?????????? ???????? ??????
			cout << input_char; // ??????? ???????? ??????
		}
		high_resolution_clock::time_point after = high_resolution_clock::now(); // ?????'????? ??? ????? ????????

		spent_time = floor<milliseconds>(after - before).count(); // ?????????? ??? ????????
		total_enter_time += spent_time; // ????????? ????????? ??? ????????
		
		time_to_enter = next_sentence.length() * 400; // ?? ????? ?????? ??????????? 400 ??????????
		if (time_to_enter > spent_time) { // ???? ?????? ???????
			on_time = true; // ?????????? ????????? ?? ??????? ???? true
			previous_match = true; // ?????????? ????????? ?? ?????????? ???? true
			for (int i = 0; i < next_sentence.length(); ++i) { // ?????????? ??????????? ??????? ???????
				if (input[i] == next_sentence[i]) { // ???? ??????? ????????
					++matched_chars; // ????????? ????????? ????????? ???????? ???? ?? 1
				}
				else { // ???? ??????? ?????
					previous_match = false; // ?????????? ????????? ?? ?????????? ???? false
				}
			}
		}
		else { // ?????????? ????????? ?? ??????? ???? false
			on_time = false;
		}
		total_allowed_time += time_to_enter;
		total_chars += next_sentence.length(); // ????????? ???????? ????????? ???????? ????????
	} 

	Training::printResults(matched_chars, total_chars, total_enter_time, total_allowed_time); // ??????? ??????????
	text_file.close(); // ???????? ????? ?????
}

/*
	??????? ????????? ? ?????? ?????? ???? ???????. ???????? ??????? ???????????? ?????????, ?? ??????? ?
	??????? ????????? ???? ??????????? ?????? ?????? ???? (??????????? ???????? ??????? ??? ???? ?????? 0.16%)
*/
string TextTraining::getRandText() {
	return SENTENCES[rand() % 25];
}
