#include <iostream>

using namespace std;

template <typename T>
class MyList {
private:
	T data[255]{};
	int index[255];

	int first = 0;
	int free_to_use = -1;
	int end_of_list = -2

	int find_empty() {
		for (int i = 0; i < 255; i++) {
			if (this->index[i] == free_to_use) {
				return i;
			}
		}
		return end_of_list;
	}

public:
	MyList() {
		for (int i = 0; i < 255; i++) {
			this->index[i] = free_to_use;
		}
	}
	MyList(T* arr, int size) {
		for (int i = 0; i < size; i++) {
			int empty = find_empty();
			this->index[cur] = empty;

			if (empty != end_of_list) {
				this->data[empty] = c;
				this->index[empty] = address;
			}
			else {
				cout << "Error: List overflow";
				throw free_to_use;
			}
		}
	}

	MyList(const MyList& list) {
		for (int i = 0; i < 255; i++) {
			this->index[i] = list.get_index[i];
			this->data[i] = list.get_data[i];
		}
	}

	int& get_index(int idx) {
		return this->index[idx];
	}

	int& get_data(int idx) {
		return this->data[idx];
	}

	void head_init(const int& c) {
		this->data[this->first] = c;
		this->index[this->first] = end_of_list;		
	}

	T& pop(int idx) {
		int cur = this->first;
		if (idx == 0) {
			this->first = this->index[cur];
			this->index[cur] = free_to_use;
			return data[0];
		}

		for (int i = 0; i < idx-1; i++) {
			if (this->index[cur] == end_of_list) {
				cout << "List is not big enought" << endl;
				break;
			}
			cur = this->index[cur];
		}
		int idx_to_del = this->index[cur];
		this->index[cur] = this->index[this->index[cur]];
		index[idx_to_del] = free_to_use;
		
		return this->data[idx_to_del];
	}

	void pushback(const T& c, const T& address = end_of_list) {
		int cur = this->first;

		if (this->index[cur] == free_to_use) {
			head_init(c);
			return;
		}

		while (this->index[cur] != end_of_list) {
			cur = this->index[cur];
		}

		int empty = find_empty();
		this->index[cur] = empty;

		if (empty != end_of_list) {
			this->data[empty] = c;
			this->index[empty] = address;
		}
		else {
			cout << "Error: List overflow";
			throw free_to_use;
		}
	}

	int find(const T& key) {
		int cur = first;
		while (index[cur] != end_of_list) {
			if (data[cur] == key) {
				return cur;
			}
		}
		cout << "No such element in this list" << endl;
		return end_of_list; 
	}

	void paste(const MyList& from, MyList& to) {
		bool found = false;
		int start = 0;
		int end = 0;

		int cur = first;
		while (this->index[cur] != end_of_list) {
			int cur_from = from.first;
			while (from.data[cur_from] == this->data[this->index[cur]]) {
				if (cur_from == from.first) {
					start = cur;
				}

				if (from.index[cur_from] == end_of_list) {
					found = true;
					end = this->index[this->index[cur]];
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
			this->index[cur] = free_to_use;
			cur = next;
		}
		this->index[cur] = free_to_use;

		this->index[start] = end_of_list;
		int cur_to = to.first;
		while (to.index[cur_to] != end_of_list) {
			this->pushback(to.data[cur_to]);
			cur_to = to.index[cur_to];
		}
		this->pushback(to.data[cur_to], end);
	}

	void show() {
		int cur = first;
		while (this->index[cur] != end_of_list) {
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

	void wipe() {
		for (int i = 0; i < 255; i++) {
			this->index[i] = free_to_use;
		}
	}
};



int oop22() {

	return 0;
}