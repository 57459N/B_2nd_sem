#define _CRT_SECURE_NO_WARNINGS
#include <chrono>
#include <fstream>
#include <iostream>
#include <cstring>
#include <ctime>
#include <stdlib.h>
#include <chrono>

using namespace std;

const double SQR2 = 1.41;
const int precision = 1000000;

void create_for_oop_11_new() {
	srand(time(nullptr));
	ofstream out("numbers_oop_11.txt");

	const int precision = 1000000;

	char buffer[5 * 1]{};
	char num[100]{};

	const long amount_of_numbers = 1000000000;

	if (out.is_open()) {
		time_t start = time(nullptr);
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
		cout << endl << "Creating : " << time(nullptr) - start;
	}
}

void divide() {
	ifstream input("numbers_oop_11.txt");
	ofstream more("more_sqr2.txt");
	ofstream less("less_sqr2.txt");

	
	int i = 0;
	if (input.is_open() && more.is_open() && less.is_open()) {
		cout << "divining..." << endl;

		char str[10]{};
		auto prev = chrono::high_resolution_clock::now();
		while (input >> str) {
			double buffer = atof(str);
			strcat(str, "\n");
			if (buffer > SQR2) {
				more << str;
			}
			else {
				less << str;
			}
			if (!(i++ % precision)) {
				cout << i - 1 << endl;
				auto now = chrono::high_resolution_clock::now();
				cout << chrono::duration_cast<chrono::microseconds>(now - prev).count() << endl;
				prev = now;
			}
		}
	}
	cout << "divining ended" << endl;
}

void new_divide() {
	ifstream input("numbers_oop_11.txt");
	ofstream more("more_sqr2_new.txt");
	ofstream less("less_sqr2_new.txt");

	const int row_len = 5;
	const int LEN = row_len * 6; // (digit len + 1) * buff size

	char* more_buff = new char[LEN] {};
	int more_amount = 0;
	char* less_buff = new char[LEN] {};
	int less_amount = 0;

	int i = 0;
	
	if (input.is_open() && more.is_open() && less.is_open()) {
		cout << "new divining..." << endl;
				
		char str[10]{};
		auto prev = chrono::high_resolution_clock::now();
		while (input >> str) {
			double buffer = atof(str);
			strcat(str, "\n");

		char str[10]{};
		auto prev = chrono::high_resolution_clock::now();
		while (input >> str) {
			float buffer = atof(str);
			strcat(str, "\n");

			if (buffer > SQR2) {
				strcat(more_buff, str);
				more_amount++;
			}
			else {
				strcat(less_buff, str);
				less_amount++;
			}

			if (more_amount >= LEN / row_len) {
				more << more_buff;
				more_buff[0] = '\0';
				more_amount = 0;
			}
			if (less_amount >= LEN / row_len) {
				less << less_buff;
				less_buff[0] = '\0';
				less_amount = 0;
			}

			if (!(i++ % precision)) {
				cout << i - 1 << endl;
				/*auto now = chrono::high_resolution_clock::now();
				cout << chrono::duration_cast<chrono::microseconds>(now - prev).count() << endl;
				prev = now;*/
			}
		}
	}
	cout << "divided" << endl;

	less_buff = {};
	more_buff = {};
	delete[] more_buff;
	delete[] less_buff;
	more_buff = nullptr;
	less_buff = nullptr;

	input.close();
	less.close();
	more.close();
}


void merge() {

	ifstream more("numbers_oop_11.txt");
	ifstream less("numbers_oop_11.txt");
	ofstream output("oop_11_out.txt");

	int i = 0;
	if (output.is_open() && more.is_open() && less.is_open()) {
		cout << "merging..." << endl;
		char more_buf[6]{};
		float more_number = 0.0f;

		char less_buf[6]{};
		float less_number = 0.0f;
		auto prev = chrono::high_resolution_clock::now();
		while (more || less)
		{
			while (more) {
				more.read(more_buf, sizeof(more_buf));
				more_number = atof(more_buf);

				if (more_number > SQR2) {
					output.write(more_buf, sizeof(more_buf));
					i++;
					break;
					
				}
			}

			while (less) {
				less.read(more_buf, sizeof(more_buf));
				less_number = atof(less_buf);

				if (less_number < SQR2) {
					output.write(less_buf, sizeof(less_buf));
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

	
	}
	cout << "merged..." << endl;
}

void new_merge() {

	ifstream more("more_sqr2_new.txt");
	ifstream less("less_sqr2_new.txt");
	ofstream output("oop_11_out_new.txt");

	const int LEN = 10 * 3;
	char* buff = new char[LEN] {};
	int buff_amount = 0;


	int i = 0;
	if (output.is_open() && more.is_open() && less.is_open()) {
		cout << "merging..." << endl;
		char buffer_more[5]{};
		char buffer_less[5]{};

		while (more >> buffer_more && less >> buffer_less) {

			strcat(buff, buffer_more);
			strcat(buff, "\n");
			strcat(buff, buffer_less);
			strcat(buff, "\n");

			buff_amount++;

			if (buff_amount >= LEN / 10) {
				output << buff;
				buff[0] = '\0';
				buff_amount = 0;
			}

			if (!(i++ % precision)) {
				cout << i - 1 << endl;
			}
		}
	}
	cout << "merged..." << endl;

}



void check() {
	ifstream input("oop_11_out.txt");

	int i = 0;
	if (input.is_open()) {
		cout << "checking..." << endl;
		double buffer;
		bool prev_more = false;
		while (input >> buffer) {

			if (buffer > SQR2 && prev_more) {
				cout << "Trouble - " << i << endl;
			}

			prev_more = (buffer > SQR2);

			if (!(i++ % precision)) {
				cout << i - 1 << endl;
			}
		}
	}
	cout << "checked" << endl;
}

int oop11() {
	
	time_t start = time(nullptr);
	//create_for_oop_11_new();
	merge();
	cout << "Merging : " << time(nullptr) - start << endl;
	return 0;
}
// dounlouded from rfe.homework.by
