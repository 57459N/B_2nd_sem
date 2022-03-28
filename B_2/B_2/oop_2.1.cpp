//#include "MyVector.h"
//#include <iomanip>
//#include <iostream>
//#include <fstream>
//
//using namespace std;
//
//void create_21_num() {
//	ofstream file("numbers.txt", ios::_Noreplace);
//
//	if (file.is_open()) {
//		char num[100]{};
//		for (size_t i = 0; i < 1e4; i++) {
//			for (int j = 0; j < 10e3; j++) {
//				snprintf(num, 6, "%i", j);
//				file << num << "\n";
//			}
//		}
//		file.close();
//	}
//}
//
//
//int oop21() {
//
//	int l = 2;
//	int* arr = new int[l]{};
//	for (int i = 0; i < l; i++) {
//		arr[i] = i;
//	}
//
//	MyVector<int> vec = MyVector<int>(arr, l);
//
//
//	vec.set_size(10000);
//	cout << "reading..." << endl;
//	ifstream input("numbers.txt");
//	
//	if (input.is_open()) {
//		int num = 0;
//		int c = 0;
//		while (input >> num) {
//			vec[num]++;
//			if (num == 1) cout << c++ << endl;
//		}
//	}
//	input.close();
//
//	cout << "print..." << endl;
//	for (int i = 0; i < vec.get_len(); i++) {
//		if (vec[i]) {
//			cout << i << " ";
//		}
//	}
//	system("pause");
//	return 0;
//}