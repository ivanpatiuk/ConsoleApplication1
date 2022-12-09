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
	cout << "������ ������� ������� ��� ���������� � ����� [5;100]" << endl;
	int chars_count = ConsoleInterface::getIntInput(5, 100); // ������� �������
	int matched_chars = 0; // ������� ��������� �������� �������
	int inputs = 0; // ������� ������� �������
	char input; // �������� ������ 
	char generated; // ������������ ������
	long long time_to_enter = 5000; // ���������� ��� �� �������� 5 ������
	long long spent_time; // ���������� ��� �� �������� ���������
	long long total_allowed_time = 0; // ��������� ���������� ��� ����� ��� �������
	long long total_enter_time = 0; // ��������� ��� ����� ��� �������
	bool previous_match = false;
	bool on_time = false;
	do {
		system("CLS"); // �������� �������
		if (inputs != 0) { // ���� �� ������ ���
			if (on_time) { // ���� ������
				if (previous_match) { // ���� ���������� ���
					cout << "�������� ��������: ���������" << endl;
				}
				else { // ���� ������������ ���
					cout << "�������� ��������: �����������, ������� '" << input << "', ����������� '" << generated << "'" << endl;
				}
			}
			else { // ���� ��������
				cout << "��������� ������ ��� �������� ��������" << endl;
			}
		}
		else { // ���� ������ ���
			cout << endl;
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
		if (time_to_enter > spent_time) { // ���� ������� ���
			on_time = true;
			if (input == generated) { // ���� ���������
				previous_match = true; // ���������� ������, �� ��������� ��� ��� ����������
				matched_chars += 1; // �������� ������� ��������� �������� ���� �� 1
			}
			else { // ���� �� ���������
				previous_match = false; // ���������� ������, �� ��������� ��� ��� ������������
			}
		}
		else { // ���� ��������� ���
			on_time = false; // ���������� ������, �� ��������� ��� ��� ���������
		}
		total_allowed_time += time_to_enter;
		time_to_enter *= 0.965; // �������� ��� �� �������� �� 3,5%
	} while (inputs < chars_count); // ������ �� ��� ��, ���� ������� ������� �� ������� 50

	Training::printResults(matched_chars, chars_count, total_enter_time, total_allowed_time); // ������� ����������
}

