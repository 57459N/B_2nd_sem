#include <iostream>
#include <fstream>

using namespace std;

int oop11() {

	ifstream input("numbers_oop_11.txt");
	ofstream output("oop_11_out.txt");

	const double SQR2 = 1.41;
	int i = 0;
	if (input.is_open() && output.is_open()) {
		double buffer;
		bool prev_more = false;
		while (input >> buffer) {

			if (buffer > SQR2 && prev_more) {
				continue;
			}
			output << buffer << endl;
			prev_more = (buffer > SQR2);
			if (!(i++ % 100)) {
				cout << i-1 << endl;
			}
		}
		
	}

	return 0;
}