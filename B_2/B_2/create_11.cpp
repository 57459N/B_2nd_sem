#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>

using namespace std;


void create_for_oop_11() {
	srand(time(nullptr));
	ofstream out("numbers_oop_11.txt");
	
	if (out.is_open()) {
		for (int i = 0; i < 10000000 / 2; i++) {
			out << ((rand() % 141) + 142) / 100. << endl;
			if (!(i % 10000)) {
				cout << i << endl;
			}
		}
		for (int i = 0; i < 10000000 / 2; i++) {
			out << (rand() % 142) / 100. << endl;
			if (!(i % 10000)) {
				cout << i << endl;
			}
		}
	}
}

void create_for_oop_11_new() {
	srand(time(nullptr));
	ofstream out("numbers_oop_11_new.txt");

	const int precision = 1000000;

	char buffer[5 * 1]{};
	char num[100]{};

	const long amount_of_numbers = 1000000000;

	if (out.is_open()) {
		int start = time(nullptr);
		for (long i = 0; i < amount_of_numbers / 2; i++) {
			float n = ((rand() % 141) + 142) / 100.;
			snprintf(num, 5, "%f", n);
			
			strcat(num, "\n");
			out << num;

			if (!(i % precision)) {
				cout << i << endl;
			}
		}

		for (long i = 0; i < amount_of_numbers / 2; i++) {
			float n = (rand() % 142) / 100.;
			snprintf(num, 5, "%f", n);
			strcat(num, "\n");

			out << num;
		
			if (!(i % precision)) {
				cout << i << endl;
			}
		}
		cout << endl << time(nullptr) - start;
		system("pause");
	}
}
}
