#include <iostream>

using namespace std;

class List_c25{

private:
	int data[255]{};
	int index[255];
	
	int first = 0;

	// DATA:  1 2 3 4 5
	// indEX: 1 2 3 4 0
	
	int find_empty() {
		for (int i = 0; i < 255; i++) {
			if (this->index[i] == -1) {
				return i;
			}
		}
		return -2;
	}

public:
	List_c25() {
		for (int i = 0; i < 255; i++) {
			this->index[i] = -1;
		}
	}

	void pushback(const int& c, const int& addres = -2) {
		int cur = first;
		if (this->index[cur] == -1) {
			this->data[cur] = c;
			this->index[cur] = addres;
			return;
		}

		while (this->index[cur] != -2) {
			cur = this->index[cur];
		}

		int empty = find_empty();
		this->index[cur] = empty;

		if (empty != -2) {
			this->data[empty] = c;
			this->index[empty] = addres;
		}
		else {
			cout << "Error: List overflow";
			throw -1;
		}
	}

	void paste(const List_c25& from, List_c25& to) {
		bool found = false;
		int start = 0;
		int end = 0;

		int cur = first;
		while (this->index[cur] != -2) {
			int cur_from = from.first;
			while (from.data[cur_from] == this->data[this->index[cur]]) {
				if (cur_from == from.first) {
					start = cur;
				}

				if (from.index[cur_from] == -2) {
					found = true;
					end = this->index[this-> index[cur]];
					break;
				}

				cur_from = from.index[cur_from];
				cur = this->index[cur];
			}
			cur = this->index[cur];
		}

		if (!found) {
			return;
		}

		cur = start;

		while (this->index[cur] != end) {
			int next = this->index[cur];
			this->index[cur] = -1;
			cur = next;
		}
		this->index[cur] = -1;

		this->index[start] = -2;
		int cur_to = to.first;
		while (to.index[cur_to] != -2) {
			this->pushback(to.data[cur_to]);
			cur_to = to.index[cur_to];
		}
		this->pushback(to.data[cur_to], end);
	}

	void show() {
		int cur = first;
		while (this->index[cur] != -2) {
			cout << char(this->data[cur]);
			cur = this->index[cur];
		}
		cout << char(this->data[cur]);
	}

	void showall() {
		for (int i = 0; i < 255; i++) {
			cout << char(this->data[i]) << " ";
		}
		cout << endl;
		for (int i = 0; i < 255; i++) {
			cout << this->index[i] << " ";
		}
	}
};

int m25() {

	List_c25 chars;
	for (int i = 0; i < 10; i++) {
		chars.pushback('A' +  i);
	}

	List_c25 from;
	from.pushback('B');

	List_c25 to;
	to.pushback('Q');
	to.pushback('Q');
	to.pushback('Q');

	chars.paste(from, to);

	chars.show();
	

	return 0;
}