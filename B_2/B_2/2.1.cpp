#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdint>

using namespace std;

void printArrr(int* arr, int size) {
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
}

bool put(int num, int* arr, int& size, bool(*f)(int, int)) { //  1, 3 , 5, 9, 11 
	int left = 0;
	int right = size;

	while (left < right) {
		
		int mid = left + (right - left) / 2;
		if (num == arr[mid]) {
			return 0;
		}
		else if (f(num, arr[mid])) {
			right = mid;
		}
		else {
			left = mid+1;
		}
	}   
	
	//cout << endl << left << " - " << right << endl;
	//cout << size << endl;
	
	for (int i = size; i > left; i--) {
		arr[i] = arr[i-1];
	}
	arr[left] = num;
	size++;

	return 1;
	
}



int m21() {

	
	int* arr = new int[1e4]{};
	ifstream file("./numbers.txt");
	char* line = new char[10]{};
	if (file.is_open()) {
		int size = 0;
		while (file.getline(line, 10)) {
			put(atoi(line), arr, size, [](int a, int b) {return a > b;});
			
		}
	}
	else cout << "Error while opening file!";
	
	printArrr(arr, 1e4+1 );
	return 0;
}