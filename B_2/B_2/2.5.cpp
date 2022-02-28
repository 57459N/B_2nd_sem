#include <iostream>

using namespace std;

class List_c25{

private:
	int data[255]{};
	int index[255];
	
	int first = 0;

	// DATA:  1 2 3 4 5
	// indEX: 1 2 3 4 0
	//

public:
	List_c25() {
		for (int i = 0; i < 255; i++) {
			this->index[i] = -1;
		}
	}

	int find_empty() {
		for (int i = 0; i < 255; i++) {
			if (this->index[i] == -1){ 
				return i;
			}
		}
	}

	void pushback(const int& c) {
		int cur = first;
		while (this->index[cur] != -2) {
			cur = this->index[cur];
		}

	}

};

//void fill_chars(List_c25& c) {
//	char a = 0;
//	cin >> a;
//	while (a != '0') {
//		c.push_back(a);
//		cin >> a;
//	}
//}


int m25() {

	List_c25 chars;

	return 0;
}