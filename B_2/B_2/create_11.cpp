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



