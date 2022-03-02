#include <iostream>
#include <fstream>

using namespace std;

void create_for_oop_11() {
	srand(time(nullptr));
	ofstream out("numbers_oop_11.txt");
	
	if (out.is_open()) {

		for (int i = 0; i < 10000000; i++) {
			out << (rand() % 283) / 100. << endl;
			if (!(i % 100)) {
				cout << i << endl;
			}
		}
	}
}