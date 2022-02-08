#include <iomanip>
#include <iostream>
#include "Functions.h"

using namespace std;

int** createM(int n) {
	int** arr = new int* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
		for (int j = 0; j < n; j++) {
			arr[i][j] = 0;
		}
	}
	return arr;
}

void printM(int** arr, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << setw(3) <<arr[i][j];
		}
		cout << "\n";
	}
}

void fillM(int** arr, int n) {
	int i = n - 1;
	int j = 0;
	int num = n*n;
	int direction = 0;	
	
	while(num>0){
		switch (direction % 4) {
		case(0): //up
			for (; i >= 0 && arr[i][j] == 0 ; i--) {
				arr[i][j] = num--;
			}
			i++;
			j++;
			break;
		case(1): //right
			for (; j < n && arr[i][j] == 0 ; j++){
				arr[i][j] = num--;
			}
			j--;
			i++;
			break;
		case(2): //down
			for (; i < n && arr[i][j] == 0 ; i++){
				arr[i][j] = num--;
			}
			i--;
			j--;
			break;
		case(3): //left
			for (; j >= 0 && arr[i][j] == 0 ; j--){
				arr[i][j] = num--;
			}
			j++;
			i--;
			break;	
		}
		direction++;
	}
}


int m11() {
	int n = 0;
	cout << "Enter size of matrix: ";
	cin >> n;

	int** arr = createM(n);
	fillM(arr, n);
	printM(arr, n);
	
	return 0;
}