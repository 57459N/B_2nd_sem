#include <cmath>
#include <iostream>

using namespace std;


struct Branch {

	int data;
	Branch* child1 = nullptr;
	Branch* child2 = nullptr;

	Branch(int data, Branch* child1 = nullptr, Branch* child2 = nullptr) {

		this->data = data;
		this->child1 = child1;
		this->child2 = child2;
	}
};

class BTree {
private:
	Branch* _head = nullptr;

	Branch* find(Branch* top, const int& num) {
		if (top == nullptr) {
			return nullptr;
		}

		Branch* p;
		if (num < top->data) {
			p = find(top->child1, num);
		}
		else {
			p = find(top->child2, num);
		}

		if (p != nullptr) {
			return p;
		}
		return top;
	}

public:

	BTree() = default;

	void pushback(const int& num) {

		Branch* newEl = new Branch(num);
		if (_head == nullptr) {
			_head = newEl;
		}
		else {
			Branch* to_ins = find(_head, num);

			if (num < to_ins->data) {
				to_ins->child1 = newEl;
			}
			else {
				to_ins->child2 = newEl;
			}
		}
	}

	void complete(Branch* top) {
		if (top->child1 == nullptr && top->child2 == nullptr) {
			return;
		}
		if (top->child1 == nullptr) {
			top->child1 = new Branch(top->data);
		}
		if (top->child2 == nullptr) {
			top->child2 = new Branch(top->data);
		}

		complete(top->child1);
		complete(top->child2);
	}

	void complete() {
		complete(_head);
	}

	void show(Branch* parent) {

		if (parent == nullptr) {
			return;
		}

		if (parent->child1 == nullptr && parent->child2 == nullptr) {
			cout << parent->data;
			return;
		}
		else {
			show(parent->child1);
			cout << parent->data;
			show(parent->child2);
		}
	}

	void show() {
		show(_head);
	}
};


int m27() {

	BTree tree;
	tree.pushback(2);
	for (int i = 0; i < 5; i++) {
		if (i == 2) continue;
		tree.pushback(i);
	}
	tree.complete();
	tree.show();

	return 0;
}