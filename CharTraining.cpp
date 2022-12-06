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
	������� ������ ���� � �������
*/
void CharTraining::printMenu() {
	cout << "--------------------------------------------------------------------------" << endl;
	cout << "| �������� ���������� ������ ���������� �� �������� ����� 50 �������  |" << endl;
	cout << "| ϳ��� ������� �� ����� ������ ���� ��������� ������ ���, ���� ������- |" << endl;
	cout << "| ����� ��� ������� ���������� ������.                                  |" << endl;
	cout << "|                                                                        |" << endl;
	cout << "| �����! � ����� ����� ���� �������� ������� ������� �� �������       |" << endl;
	cout << "| ��������� Enter ��� ������������ �����                                |" << endl;
	cout << "|                                                                        |" << endl;
	cout << "| ������� ����� ����:                                                   |" << endl;
	cout << "| (1) ����� � ����������                                                 |" << endl;
	cout << "| (2) ������ ����������                                                  |" << endl;
	cout << "| (3) ��������� ��������                                                 |" << endl;
	cout << "--------------------------------------------------------------------------" << endl;
}

/*
	������� ������� ������ � ���� ����������
*/
void CharTraining::openTraining() {
	system("CLS"); // �������� �������
	while (true) {
		printMenu(); // ������� ����-�������
		int input = ConsoleInterface::getIntInput(0, 2);
		switch (input) {
		case 1: // ����������� �� ������������ ����
			system("CLS");
			return;
		case 2: // ������ ����������
			startTraining();
			break;
		case 3: // ��������� ������ ��������
			exit(0);
		}
	}
}

/*
	������� ������� ���������� �� �������� ���������
*/
void CharTraining::startTraining() {
	int inputs = 0; // ������� ������� �������
	int chars_count = 50; // ������� �������
	int matched_chars = 0; // ������� ��������� �������� �������
	char input; // �������� ������ 
	char generated; // ������������ ������
	long long time_to_enter = 5000; // ���������� ��� �� �������� 5 ������
	long long spent_time; // ���������� ��� �� �������� ���������
	long long total_enter_time = 0; // ��������� ��� ����� ��� �������
	bool previous_match = false;
	bool on_time = false;
	do {
		system("CLS"); // �������� �������
		if (on_time) {
			if (inputs != 0) {
				if (previous_match) {
					cout << "�������� ��������: ���������" << endl;
				}
				else {
					cout << "�������� ��������: �����������, ������� '" << input << "', ����������� '" << generated << "'" << endl;
				}
			}
			else {
				cout << endl;
			}
		}
		else {
			cout << "��������� ������ ��� �������� ��������" << endl;
		}
		high_resolution_clock::time_point before = high_resolution_clock::now(); // �����'����� ��� �� ��������
		srand(time(NULL)); // ������� ��� ����������� ����������� �����������
		generated = VOCABULARY[rand() % 72]; // ����� ���� ���� ������ � �������� 
		cout << "������ ������: '" << generated << "'" << endl; // ������� ������� �� ���������
		input = _getch(); // �������� �������
		++inputs; // �������� ������� �������
		high_resolution_clock::time_point after = high_resolution_clock::now(); // �����'����� ��� ���� ��������

		spent_time = floor<milliseconds>(after - before).count(); // ���������� ��� ��������
		total_enter_time += spent_time; // �������� ��������� ��� ��������
		if (time_to_enter > spent_time) {
			on_time = true;
			if (input == generated) { // ���� ������ ������� � ���������, �������� ��������
				// ���������� �������
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
		time_to_enter *= 0.965; // �������� ��� �� �������� �� 3,5%
	} while (inputs < chars_count); // ������ �� ��� ��, ���� ������� ������� �� ������� 50

	Training::printResults(matched_chars, chars_count, total_enter_time); // ������� ����������
}

/*
	������� ��������� ����������
*/
//void CharTraining::printResults(int matched_chars, int total_chars, long long total_enter_time) {
//	system("CLS"); // �������� �������
//	// ������� ������� �� �������� (��������� ��������) / 50 * 100%
//	// ������� ����� �� ��������� ������� ���������� �������: 
//	//         [0,9] - �������, 	
//	//         [10,24] - �����������, 
//	//         [25,40] - ������� ������, 
//	//         [41,50] - ������� ��������
//	cout << "--------------------------------------------------------------------------" << endl;
//	cout << "| ����������:                                                            |" << endl;
//	cout << "|                                                                        |" << endl;
//	cout << "| �������: " << setw(5) << setprecision(5) << 100.0 * matched_chars / total_chars << "%" << setw(56) << "|" << endl;
//	cout << "| г����: ";
//	if (matched_chars < 10) {
//		cout << setw(10) << "������� :(";
//	}
//	else if (matched_chars < 25) {
//		cout << setw(10) << "����������� -_-";
//	}
//	else if (matched_chars < 41) {
//		cout << setw(10) << "������� ������ :)";
//	}
//	else {
//		cout << setw(10) << "������� �������� �_�";
//	}
//	cout << "                                                     |" << endl;
//	cout << "| ������� ��� �������� ����� (��������): " << setw(15) << setprecision(5) << left<< total_enter_time / total_chars << setw(15) << "|" << endl;
//	cout << "--------------------------------------------------------------------------" << endl;
//}

