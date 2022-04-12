#include <iostream>

using namespace std;

template <typename T>
class TwoList_oop {
private:

	struct Node {
		T data = 0;
		Node* next = nullptr;
		Node* prev = nullptr;

		Node(T data, Node* prev = nullptr, Node* next = nullptr) {
			this->data = data;
			this->next = next;
			this->prev = prev;
		}
	};

	Node* _head = nullptr;
	Node* _tail = nullptr;

public:
	TwoList_oop() = default;

	void head_init(const T& num) {
		Node* newNode = new Node(num);
		this->_head = newNode;
		this->_tail = newNode;
	}

	void pushback(const T& num) {

		if (_head == nullptr) {
			head_init(num);
		}
		else {
			_tail->next = new Node(num, _tail);
			_tail = _tail->next;
		}
	}

	void remove(const int idx) {
		Node* it = _head;

		if (idx == 0) {
			if (it->next == nullptr) {
				_head = nullptr;
				_tail = nullptr;
			}
			else {
				_head = it->next;
			}
		} 
		else {
			int cur_i = 0;
			while (cur_i++ < idx && it->next != nullptr) {
				it = it->next;
			}
			if (it->next == nullptr) {
				_tail = it->prev;
			}
			else {
				it->next->prev = it->prev;
			}
			it->prev->next = it->next;
			delete it;
		}
	}

	friend std::ostream& operator<< (std::ostream& str, const TwoList_oop& o) {
		Node* it = o._head;
		while (it != nullptr) {
			str << it->data << " ";
			it = it->next;
		}
		str << endl;
		return str;
	}

	void clear() {
		while (_head) {
			auto* todelete = _head;
			_head = _head->next;
			delete todelete;
		}
		_tail = nullptr;
	}

	Node* find(const T& num) {
		Node* it = _head;
		while ( it->next != nullptr) {
			if (it->data == num) {
				return it;
			}
			it = it->next;
		}
		return nullptr;
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

int oop23() {

	TwoList_oop<int> list;

	for (int i = 0; i < 10; i++) {
		list.pushback(i);
	}
	cout << list;
	list.show_result();
	list.clear();
	cout << list;
	return 0;
}