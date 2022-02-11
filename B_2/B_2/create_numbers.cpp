#include <iostream>
#include <fstream>

using namespace std;

void create_numbers() {
	setlocale(LC_ALL, "Russian");
	
	ofstream out;
	out.open("./numbers.txt");

	if (out.is_open()) {
		for (int i = 0; i <= 1e4; i++) {
			for (int j = 0; j < 1e3; j++) {
				out << i << endl;
			}
			cout << i << endl;
		}

	}
	cout << "Done!";
	}
