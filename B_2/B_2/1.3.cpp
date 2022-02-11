#include <iostream>

using namespace std;

void printA(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}


int& max_amount(int* arr, int n, int max_el) {
	int& link = *arr;
	int amount_len = max_el;
	int* amount = new int[amount_len]{};
	for (int i = 0; i < n; i++) {
		amount[arr[i]]++;
	}
	int max_amount_pos = 0;
	for (int i = 0; i < amount_len; i++) {
		if (amount[i] > amount[max_amount_pos])
			max_amount_pos = i;
	}
	for (int i = 0; i < n; i++) {
		if (arr[i] == max_amount_pos)
			return arr[i];
	}
}


int m13() {
	srand(time(nullptr));
	
	int n = 0;
	cout << "Enter amount of numbers: ";
	cin >> n;

	int k = 0;
	cout << "Numbet to replace: ";
	cin >> k;

	int* arr = new int[n] {};
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 99 + 1;
	}

	printA(arr, n);
	cout << endl;
	
	max_amount(arr, n, 99) = k;
	
	printA(arr, n);
	return 0;
}