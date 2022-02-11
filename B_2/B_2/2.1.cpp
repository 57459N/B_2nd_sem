#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdint>

using namespace std;

int m21() {

	ifstream file("./numbers.txt");
	char* line = '\0';

	if (file.is_open()) {
		while(getline(file, line)) {
			cout << atoi(line) << endl;
		}

	}
	else cout << "Error while opening file!";

	return 0;
}