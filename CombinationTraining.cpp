#include "CombinationTraining.h"
#include <iostream>
#include <iomanip>
#include "ConsoleInterface.h"
#include <chrono>
#include <conio.h>

using namespace std;
using namespace chrono;

/*
	������� ������ ���� � �������
*/
void CombinationTraining::printMenu() {
	cout << "--------------------------------------------------------------------------" << endl;
	cout << "| �������� ���������� ������ ���������� �� �������� ��������� �������.|" << endl;
	cout << "| ϳ��� ������� �� ����� ��������� ������� ���� ��������� ������ ���, |" << endl;
	cout << "| ���� ���������� ��� ������� ���������� ������.                       |" << endl;
	cout << "|                                                                        |" << endl;
	cout << "| �����! � ����� ����� ���� �������� ����� ��������� �� �������     |" << endl;
	cout << "| ��������� ��� ������������ ���������. ����� � ������ ����� ������-  |" << endl;
	cout << "| ���� ����� ������� ���������.                                        |" << endl;
	cout << "|                                                                        |" << endl;
	cout << "| ������� ����� ����:                                                   |" << endl;
	cout << "| (1) ����� � ����������                                                 |" << endl;
	cout << "| (2) ������ ����������                                                  |" << endl;
	cout << "| (3) ��������� �������� ��������                                        |" << endl;
	cout << "--------------------------------------------------------------------------" << endl;
}

/*
	������� ������� ������ � ���� ����������
*/
void CombinationTraining::openTraining() {
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
void CombinationTraining::startTraining() {
	cout << "������ ������� ��������� ��� ���������� � ����� [5;100]" << endl;
	int combinations_count = ConsoleInterface::getIntInput(5, 100); // ������� �������
	int inputs = 0; // ������� ������� ���������
	int total_chars = 0;
	int matched_chars = 0; // ������� ��������� �������� ���������
	char input_char;
	string input; // ������� ��������� 
	string generated; // ����������� ���������
	long long time_to_enter = 5000; // ���������� ��� �� �������� 5 ������
	long long spent_time; // ���������� ��� �� �������� ���������
	long long total_allowed_time = 0; // ��������� ���������� ��� ����� ��� �������
	long long total_enter_time = 0; // ��������� ��� ����� ��� ���������
	bool previous_match = false;
	bool on_time = false;
	do {
		system("CLS"); // �������� �������

		high_resolution_clock::time_point before = high_resolution_clock::now(); // �����'����� ��� �� ��������
		generated = generateCombination(); // ����������� ���������
		if (total_chars != 0) { // ���� �� ������ ��� (��� ������� ���� �������� ������� ���� == 0)
			if (on_time) { // ���� ������
				if (previous_match) { // ���� ���������� ���
					cout << "�������� ��������: ���������" << endl;
				}
				else { // ������, ������������ ���
					cout << "�������� ��������: �����������, ������� '" << input << "', ����������� '" << generated << "'" << endl;
				}
			}
			else { // ���� ��������
				cout << "��������� ���� ���� ������� ��������" << endl;
			}
		}
		else { // ���� ������ ��� 
			cout << endl;
		}
		input = "\0"; // ��� ��������� ������������ ��������� �����
		cout << "������ ���������: '" << generated << "'" << endl; // ������� ������� �� ���������
		for (size_t i = 0; i < generated.length(); ++i) { // �������� ���������
			input_char = _getch();
			input += input_char;
			cout << input_char;
		}  
		++inputs; // �������� ������� �������
		high_resolution_clock::time_point after = high_resolution_clock::now(); // �����'����� ��� ���� ��������

		spent_time = floor<milliseconds>(after - before).count(); // ���������� ��� ��������
		total_enter_time += spent_time; // �������� ��������� ��� ��������

		if (time_to_enter > spent_time) { // ���� ������ �������
			on_time = true; // ���������� ��������� �� ������� ��� true
			previous_match = true; // ���������� ��������� �� ���������� ��� true
			for (int i = 0; i < generated.length(); ++i) { // ��������� ��������� ������� �������
				if (input[i] == generated[i]) { // ���� ������� �������
					++matched_chars; // �������� �������� ��������� �������� ���� �� 1
				}
				else { // ���� ������� ���
					previous_match = false; // ���������� ��������� �� ���������� ��� false
				}
			}
		}
		else { // ���������� ��������� �� ������� ��� false
			on_time = false;
		}
		total_allowed_time += time_to_enter;
		total_chars += generated.length();
		time_to_enter *= 0.985; // �������� ��� �� �������� �� 1,5%
	} while (inputs < combinations_count); // ������ �� ��� ��, ���� ������� ������� �� ������� 50

	Training::printResults(matched_chars, total_chars, total_enter_time, total_allowed_time); // ������� ����������
}

/*
	������� ��������� �������� ��������� �� 2 �� 5 �������
*/
string CombinationTraining::generateCombination() {
	srand(time(NULL)); // ������� ��� ����������� ����������� �����������
	string result; // ���������
	for (int i = 0; i < rand() % 4 + 2; ++i) { // �� 2 �� 5 ��������
		result += (VOCABULARY[rand() % 72]); // ������ ��������� ������ � ��������
	}
	return result; // ��������� ���������
}

