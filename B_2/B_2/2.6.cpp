#include <cmath>
#include <iostream>

using namespace std;


struct Node {

	int data = 0;
	Node* next = nullptr;
	Node* prev = nullptr;

	Node(int data, Node* prev = nullptr, Node* next = nullptr) {

		this->data = data;
		this->next = next;
		this->prev = prev;
	}
};

class TwoList {

private:
	Node* _head = nullptr;
	Node* _tail = nullptr;

public:
	TwoList() = default;

	void pushback(const int& num) {
		Node* newNode = new Node(num);

		if (_head == nullptr) {
			_head = newNode;
			_tail = newNode;
		}
		else{
			Node* it = _head;
			while (it->next != nullptr) {
				it = it->next;
			}
			newNode->prev = it;
			it->next = newNode;
			_tail = newNode;
		}
	}

	void show_result() {
		Node* first = _head;
		Node* last = _tail;
		int result = INT32_MAX;

		do {
			result = min(result, max(first->data, last->data));
			cout << first->data << " " << last->data << endl;
			first = first->next;
			last = last->prev;
		} while (first->next != last);
		cout << first->data << " " << last->data << endl;

		result = min(result, max(first->data, last->data));
		cout << endl << "> " << result;
	}

};

int m26() {

	TwoList list;

	for (int i = 0; i < 10; i++) {
		list.pushback(i);
	}

	list.show_result();
	return 0;
}