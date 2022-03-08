#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>


using namespace std;

const double SQR2 = 1.41;

void divide() {
	ifstream input("numbers_oop_11.txt");
	ofstream more("more_sqr2.txt");
	ofstream less("less_sqr2.txt");

	
	int i = 0;
	if (input.is_open() && more.is_open() && less.is_open()) {
		cout << "divining..." << endl;

		double buffer;
		while (input >> buffer) {
			if (buffer > SQR2) {
				more << buffer << endl;
			}
			else {
				less << buffer << endl;
			}
			if (!(i++ % 10000)) {
				cout << i - 1 << endl;
			}
		}
	}
	cout << "divining ended" << endl;
}

void new_divide() {
	ifstream input("numbers_oop_11.txt");
	ofstream more("more_sqr2_new.txt");
	ofstream less("less_sqr2_new.txt");

	const int LEN = 9 * 1000; // (float len + 1) * buff size

	char* more_buff = new char[LEN]{};
	int more_amount = 0;
	char* less_buff = new char[LEN]{};
	int less_amount = 0;

	int i = 0;

	if (input.is_open() && more.is_open() && less.is_open()) {
		cout << "new divining..." << endl;

		double buffer = 0;
		char* str = new char[6]{};
		while (input >> buffer) {
			
			sprintf(str, "%f", buffer);
			str[4] = '\n';  // doesn't currupt number
			str[5] = '\0';  // strip zeros
			if (buffer > SQR2) {
				strcat(more_buff, str);
				more_amount++;
			}
			else {
				strcat(less_buff, str);
				less_amount++;
			}

			if (more_amount >= LEN / 9) {
				more << more_buff;
				more_buff[0] = '\0';
				more_amount = 0;
			}
			if (less_amount >= LEN / 9) {
				less << less_buff;
				less_buff[0] = '\0';
				less_amount = 0;
			}

			if (!(i++ % 10000)) {
				cout << i - 1 << endl;
			}
		}
		str = nullptr;
		delete[] str;
	}
	more_buff = nullptr;
	less_buff = nullptr;
	delete[] more_buff;
	delete[] less_buff;
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

			if (!(i++ % 10000)) {
				cout << i - 1 << endl;
			}
		}
	}
	cout << "merged..." << endl;

}

void new_merge() {

	ifstream more("more_sqr2_new.txt");
	ifstream less("less_sqr2_new.txt");
	ofstream output("oop_11_out_new.txt");

	int i = 0;
	if (output.is_open() && more.is_open() && less.is_open()) {
		cout << "merging..." << endl;
		char buffer_more[5]{};
		char buffer_less[5]{};
		
		while (more >> buffer_more && less >> buffer_less) {

			output << buffer_more << endl << buffer_less << endl;

			if (!(i++ % 10000)) {
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
	
	setlocale(LC_ALL, "ru");

	new_divide();
	new_merge();
	system("pause");
	return 0;
}