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
	
	for (int i = size; i > left; i--) {
		arr[i] = arr[i-1];
	}
	arr[left] = num;
	size++;

	return 1;
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