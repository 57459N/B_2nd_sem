#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdint>

using namespace std;

void printArrr(int* arr, int size) {
	for (int i = size - 1; i >= 0; i--)
	{
		if (arr[i]) {
			cout << i << " ";
		}
	}
		
}

int m21() {
	int* arr = new int[10001]{};
	ifstream file("./numbers.txt");
	
	if (file.is_open()) {
		int temp = 0;
		while (file >> temp) {
			arr[temp]++;
		}
	}
	printArrr(arr, 10001);

	delete[] arr;
	return 0;
}