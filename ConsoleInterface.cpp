#include <Windows.h> 
#include <iostream>
#include <iomanip>
#include "ConsoleInterface.h"
#include "CharTraining.h"
#include "CombinationTraining.h"

using namespace std;

/*
	������� ������� ������ �������� (����������)
*/
void ConsoleInterface::start() {
	SetConsoleCP(1251); // ���������� ��������� ������������� ���������� �����
	SetConsoleOutputCP(1251); // ���������� ��������� ������������� ���������� �����
	int input;
	do {
		printMenu(); // ������� ����-�������
		input = getIntInput(1, 4); // �������� ����� ���� (����� �� 1 �� 4)
		switch (input) {
		case 1: // ������ ���������� � ���������
			CharTraining::openTraining(); 
			break;
		case 2: // ������ ���������� � �����������
			CombinationTraining::openTraining();
			break;
		case 3: // ������ ���������� � �������
			break;
		case 4: // ��������� ������ ��������
			exit(0);
		}
	} while (true);
}

/*
	������� ������ ���� � �������
*/
void ConsoleInterface::printMenu() {
	cout << "--------------------------------------------" << endl;
	cout << "| ������� ������� �����:                  |" << endl;
	cout << "| (1) ��������� ���������� � ���������     |" << endl;
	cout << "| (2) ��������� ���������� � ������������ |" << endl;
	cout << "| (3) ��������� ���������� � �������       |" << endl;
	cout << "| (4) ��������� ��������� ��������         |" << endl;
	cout << "--------------------------------------------" << endl;
}

/*
	������� ��������� ������ �����������. ������ 2 ���������:

	@min - ��������� ���������� ���� �����
	@max - ����������� ���������� ���� �����

	������� ���� ����� � ���������� ����� [min,max]
*/
int ConsoleInterface::getIntInput(int min, int max) {
	int input; // ������� �����
	do {
		cout << "������ �����: "; cin >> input;
		if (min <= input && input <= max) { // ���� � �����, �� ���������
			return input;
		}
		else { // � ������ �������, ������� �����������
			cout << "���� ����� ����, ��������� �� ���" << endl;
		}
	} while (true); // �����������, �� ���� ���������� �� ����� ����� � ����� [min,max]
}