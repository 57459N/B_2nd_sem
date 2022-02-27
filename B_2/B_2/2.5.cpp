#include <iostream>

using namespace std;

struct Node {

	char c = 0;
	int next = 0;

	Node() {
		this->c = 0;
		this->next = 0;
	}
};

class List_c25{

private:

	Node* _list;

public:
	//List_c25() {
	//	_list = new Node[1000];
	//}

	//~List_c25() {
	//	delete[] _list;
	//	_list = nullptr;
	//}

	void pushback(const char& c) {

	}

	void show() {
		Node el = _list[0];
		while (el.next != 0) {
			cout << el.c << " ";
		}
		cout << el.c << endl;
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
	chars.show();

	return 0;
}