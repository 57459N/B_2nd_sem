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

public:
	Branch* _head = new Branch(0);
	void go_down(Branch* parent, int iter, int depth) {
		parent->child1 = new Branch(INT32_MIN);
		parent->child2 = new Branch(INT32_MIN);
		if (iter < depth) {			
			go_down(parent->child1, iter + 1, depth);
			go_down(parent->child2, iter + 1, depth);
		}
	}

	BTree(int pairs) {
		int depth = ceil(log2(pairs));
		int iter = 0;
		_head->data = iter;
		go_down(_head, iter, depth);
	}

	void show(Branch* parent) {
		if (parent->child1 == nullptr && parent->child2 == nullptr) {
			cout << parent->data;
			return;
		}
		else {
			show(parent->child1);
			cout << parent->data;
			show(parent->child2);
		}\


};

int m26() {

	BTree tree = BTree(2);
	tree.show();

	return 0;
}