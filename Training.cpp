#include "Training.h"
#include <string>
#include <iostream>

using namespace std;

const string Training::VOCABULARY = "�����������媺�����貳�����������������������������������������,+-= ?!.'()";

const void Training::printResults(int matched_chars, int total_chars, long long total_enter_time, long long total_allowed_time) {
	system("CLS");
	double ratio = 1. * matched_chars / total_chars;
	std::cout << "--------------------------------------------------------------------------" << endl;
	cout << "| ����������:                                                            |" << endl;
	cout << "|                                                                        |" << endl;
	cout << "| �������: "  << setw(5) << setprecision(5) << left << 100.0 * ratio << "%" << right << setw(56) << "|" << endl;
	cout << "| г����: ";
	if (ratio < 0.2) {
		cout << setw(30) << left << "������� :(";
	}
	else if (ratio < 0.6) {
		cout << setw(30) << left << "����������� -_-";
	}
	else if (ratio < 0.8) {
		cout << setw(30) << left << "������� ������ :)";
	}
	else {
		cout << setw(30) << left << "������� �������� �_�";
	}
	cout << "                                 |" << endl;
	cout << "| ������� ��� �������� ����� (������): " << setw(15) << right << setprecision(5) << left << total_enter_time / (1000.0 * total_chars) << right << setw(19) << "|" << endl;
	cout << "| ���������� ��� (������): " << setw(15) << right << setprecision(5) << left << total_enter_time / 1000.0 << right << setw(32) << "|" << endl;
	cout << "| ���������� ��� (������): " << setw(15) << right << setprecision(5) << left << total_allowed_time / 1000.0 << right << setw(32) << "|" << endl;
	cout << "--------------------------------------------------------------------------" << endl;
}

