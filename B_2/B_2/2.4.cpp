#include <ctime>
#include <iostream>

using namespace std;

struct Node {
	char data = 0;
	Node* next = nullptr;

	Node(char data, Node* next = nullptr) {
		this->data = data;
		this->next = next;
	}
};


class List_c {

private:

	Node* _head = nullptr;
	Node* _tail = nullptr;

public:
	List_c() = default;

	void push_back(const char& c) {
		Node* newNode = new Node(c);

		if (_head == nullptr) {
			_head = newNode;
			_tail = newNode;
		}
		else {
			Node* it = _head;
			while (it->next != nullptr) {
				it = it->next;
			}
			it->next = newNode;
			_tail = newNode;
		}
	}

	void paste(const List_c& from, List_c& to) {
		bool found = false;
		Node* start = nullptr;
		Node* end = nullptr;

		Node* it = _head;
		while (it->next != nullptr) {
			Node* it_from = from._head;
			while (it_from->data == it->next->data) {
				if (it_from == from._head) {
					start = it;
				}

				if (it_from->next == nullptr) {
					found = true;
					end = it->next->next;
					break;
				}

				it_from = it_from->next;
				it = it->next;
			}

			it = it->next;
		}

		if (!found) {
			return;
		}

		if (start)
			start->next = to._head;
		else
			_head = to._head;

		to._tail->next = end;
	}

	void show() {
		Node* it = _head;

		while (it->next != nullptr) {
			cout << it->data;
			it = it->next;
		}
		cout << it->data;

	}
};

void fill_chars(List_c& c) {
	char a = 0;
	cin >> a;
	while (a != '0') {
		c.push_back(a);
		cin >> a;
	}
}

int m24() {

	srand(time(nullptr));

	List_c chars;
	fill_chars(chars);
	cout << "start list : ";
	chars.show();
	cout << endl;

	List_c replace;
	fill_chars(replace);
	cout << "replace this : ";
	replace.show();
	cout << endl;

	List_c ins;
	fill_chars(ins);
	cout << "to this : ";
	ins.show();
	cout << endl;

	cout << "final list : ";
	chars.paste(replace, ins);
	chars.show();

	return 0;
}