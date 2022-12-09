#include "Training.h"
#include <string>
#include <iostream>

using namespace std;

const string Training::VOCABULARY = "јаЅб¬в√гƒд≈е™Ї∆ж«з»и≤≥ѓњ…й кЋлћмЌнќоѕп–р—с“т”у‘ф’х÷ц„чЎшўщьёюя€,+-= ?!.'()";

const void Training::printResults(int matched_chars, int total_chars, long long total_enter_time, long long total_allowed_time) {
	system("CLS");
	double ratio = 1. * matched_chars / total_chars;
	std::cout << "--------------------------------------------------------------------------" << endl;
	cout << "| –езультати:                                                            |" << endl;
	cout << "|                                                                        |" << endl;
	cout << "| “очн≥сть: "  << setw(5) << setprecision(5) << left << 100.0 * ratio << "%" << right << setw(56) << "|" << endl;
	cout << "| –≥вень: ";
	if (ratio < 0.2) {
		cout << setw(30) << left << "Ќовачок :(";
	}
	else if (ratio < 0.6) {
		cout << setw(30) << left << "ѕродвинутий -_-";
	}
	else if (ratio < 0.8) {
		cout << setw(30) << left << "ћехан≥чн≥ пальц≥ :)";
	}
	else {
		cout << setw(30) << left << "Ўтучний ≥нтелект ќ_ќ";
	}
	cout << "                                 |" << endl;
	cout << "| —ередн≥й час введенн€ букви (секунд): " << setw(15) << right << setprecision(5) << left << total_enter_time / (1000.0 * total_chars) << right << setw(19) << "|" << endl;
	cout << "| ¬итрачений час (секунд): " << setw(15) << right << setprecision(5) << left << total_enter_time / 1000.0 << right << setw(32) << "|" << endl;
	cout << "| ƒозволений час (секунд): " << setw(15) << right << setprecision(5) << left << total_allowed_time / 1000.0 << right << setw(32) << "|" << endl;
	cout << "--------------------------------------------------------------------------" << endl;
}

