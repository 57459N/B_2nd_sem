#include <cmath>
#include <iostream>

using namespace std;

void print_arr(int* arr, int len) {
	for (size_t i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void sum_and_ins(int* arr, int& len) {

	int res_len = 2 * len - 1;
	int* res_arr = new int[res_len];

	for (int i = 0; i < len; i++) {
		res_arr[i * 2] = arr[i];
	}
	for (int i = 1; i < res_len-1 ; i += 2) {
		res_arr[i] = res_arr[i - 1] + res_arr[i + 1];
	}
	
	delete[] arr;
	len = res_len;
	arr = res_arr;
}

uint64_t sum_of_circle(int* arr, int len) {
	uint64_t sum = 0;
	for (int i = 0; i < len; i++) {
		sum += arr[i];
	}
	sum *= 2;
	sum -= arr[0] + arr[len - 1];
	return sum;
}


int alg_lab() {

	int* arr = new int[2]{ 1,4 };
	uint64_t len = 2;
	int begin = 1+4;
	int repeat = 40;

	//sum_and_ins(arr, len);

	

	//for (int i = 0; i < repeat; i++) {

	//	uint64_t res_len = 2 * len - 1;
	//	int* res_arr = new int[res_len];

	//	for (uint64_t i = 0; i < len; i++) {
	//		res_arr[i * 2] = arr[i];
	//	}
	//	for (uint64_t i = 1; i < res_len - 1; i += 2) {
	//		res_arr[i] = res_arr[i - 1] + res_arr[i + 1];
	//	}
	//	delete[] arr;
	//	len = res_len;
	//	arr = res_arr;
	//	cout << i << endl;
	//	//print_arr(arr, len);
	//} 
	// cout << endl << "Cicle: " <<sum_of_circle(arr, len);
	// либо утечка, либо слишком много чисел
	
	cout << endl << "Math: " << uint64_t(begin * pow(3, repeat));



	return 0;
}