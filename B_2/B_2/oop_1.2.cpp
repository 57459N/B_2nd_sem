#define _CRT_SECURE_NO_WARNINGS
#include <chrono>
#include <cstring>
#include <iostream>
#include <fstream>

using namespace std;

#define SQR2 1.41

const char file_in[]   = "numbers_oop_12.bin";
const char file_out[]  = "numbers_oop_12_out.bin";

void create_oop_12() {
	srand(time(nullptr));
	ofstream out(file_in, ios::binary);

	const int precision = 1000000;

	char buffer[5 * 1]{};
	char num[100]{};

	const long amount_of_numbers = 10000000;

	if (out.is_open()) {
		time_t start = time(nullptr);

		for (long i = 0; i < amount_of_numbers / 2; i++) {
			float n = ((rand() % 141) + 142) / 100.;
			snprintf(num, 5, "%f", n);
			strcat(num, "\n");

			out.write(num, 5);

			if (!(i % precision)) {
				cout << i << endl;
			}
		}

		for (long i = 0; i < amount_of_numbers / 2; i++) {
			float n = (rand() % 142) / 100.;
			snprintf(num, 5, "%f", n);
			strcat(num, "\n");

			out.write(num, 5);

			if (!(i % precision)) {
				cout << i << endl;
			}
		}
		cout << endl << "Created : " << time(nullptr) - start;
	}
	system("pause");
}

void merge_bin() {
	int precision = 1000000;
	ifstream more(file_in, ios::binary);
	ifstream less(file_in, ios::binary);
	ofstream output(file_out, ios::binary);

	int i = 0;

	if (output.is_open() && more.is_open() && less.is_open()) {
		cout << "merging..." << endl;

		float less_number = 0.0f;
		float more_number = 0.0f;

		auto start = chrono::high_resolution_clock::now();
		auto prev = start;
		while (more || less)
		{
			while (more) {
				more.read(reinterpret_cast<char*>( & more_number), sizeof(more_number));

				if (more_number > SQR2) {
					output.write(reinterpret_cast<char*>(&more_number), sizeof(more_number));
					i++;
					break;

				}
			}

			while (less) {
				less.read(reinterpret_cast<char*>(&less_number), sizeof(less_number));

				if (less_number < SQR2) {
					output.write(reinterpret_cast<char*>(&less_number), sizeof(less_number));
					i++;
					break;
				}

			}

			if (!(i % precision)) {
				cout << i << endl;
				auto now = chrono::high_resolution_clock::now();
				cout << chrono::duration_cast<chrono::milliseconds>(now - prev).count() << endl;
				prev = now;
			}
		}
		cout << endl << "Merged : " << chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now()-start).count();
	}
}


int oop12() {

	create_oop_12();
	merge_bin();

	return 0;
}