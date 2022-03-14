#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <cstring>
#include <ctime>
#include <stdlib.h>
#include <chrono>

using namespace std;

const double SQR2 = 1.41;

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
			if (!(i++ % 10000)) {
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

	char* more_buff = new char[LEN]{};
	int more_amount = 0;
	char* less_buff = new char[LEN]{};
	int less_amount = 0;

	int i = 0;
	
	if (input.is_open() && more.is_open() && less.is_open()) {
		cout << "new divining..." << endl;
				
		char str[10]{};
		auto prev = chrono::high_resolution_clock::now();
		while (input >> str) {
			double buffer = atof(str);
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

			if (!(i++ % 10000)) {
				cout << i - 1 << endl;
				auto now = chrono::high_resolution_clock::now();
				cout << chrono::duration_cast<chrono::microseconds>(now - prev).count() << endl;
				prev = now;
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

void test_div() {
	ifstream input("numbers_oop_11.txt");
	ofstream more("more_sqr2_new.txt");
	ofstream less("less_sqr2_new.txt");

	
	int i = 0;

	if (input.is_open() && more.is_open() && less.is_open()) {
		cout << "new divining..." << endl;

		char str[10]{};
		
		for (int j = 1; j <= 20; j++) {
			const int row_len = 5;
			const int LEN = row_len * j; // (digit len + 1) * buff size

			char* more_buff = new char[LEN] {};
			int more_amount = 0;
			char* less_buff = new char[LEN] {};
			int less_amount = 0;

			
			auto prev = chrono::high_resolution_clock::now();
			int sum = 0;
			for (long a = 1; a < 1000000; a++, input >> str) {
				double buffer = atof(str);
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

				if (!(i++ % 10000)) {
					auto now = chrono::high_resolution_clock::now();
					int diff = chrono::duration_cast<chrono::microseconds>(now - prev).count();
					sum += diff;
					std::cout << j << " : " << diff << endl;
					prev = now;
				}
			}
			std::cout << " average :        " << sum/100. << endl;
			less_buff = {};
			more_buff = {};
			delete[] more_buff;
			delete[] less_buff;
			more_buff = nullptr;
			less_buff = nullptr;
		}
		cout << "divided" << endl;
		
	}
		
	input.close();
	less.close();
	more.close();
}


void merge() {

	ifstream more("more_sqr2.txt");
	ifstream less("less_sqr2.txt");
	ofstream output("oop_11_out.txt");

	int i = 0;
	if (output.is_open() && more.is_open() && less.is_open()) {
		cout << "merging..." << endl;
		double buffer_more;
		double buffer_less ;
		while (more >> buffer_more && less >> buffer_less) {
			
			output << buffer_more << endl << buffer_less << endl;

			if (!(i++ % 1000000)) {
				cout << i - 1 << endl;
			}
		}
	}
	cout << "merged..." << endl;

	more.close();
	less.close();
	output.close();
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

			if (!(i++ % 1000000)) {
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

			if (!(i++ % 10000)) {
				cout << i - 1 << endl;
			}
		}
	}
	cout << "checked" << endl;
}

int oop11() {
	
	/*int start = time(nullptr);

	new_divide();
	int mid = time(nullptr);
	cout << endl << mid - start << endl;
	new_merge();
	int end = time(nullptr);
	cout << end - mid << endl;
	cout << end - start << endl;*/

	new_divide();

	system("pause");
	return 0;
}