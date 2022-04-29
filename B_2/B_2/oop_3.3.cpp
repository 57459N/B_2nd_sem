#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

template <typename T>
void print_l(list<T> l) {
	for (auto i = l.begin(); i != l.end(); i++) {
		cout << *i << " ";
	}
}

void execute_24() {
	list<int> a{ 1,2,3,0,2,3 };
	list<int> b{ 3,0,2 };
	list<int> c{ 4,4,4 };


	auto b_el = b.begin();
	int len = 0;
	bool found_start = false;
	int start_i = 0;
	auto start = a.begin();
	auto end = a.begin();
	int off = 0;

	auto result = std::find_end(a.begin(), a.end(), b.begin(), b.end());
	if(result == a.end()){
		return;
	}

	auto result_end = result;
	advance(result_end, b.size());

	for (auto i = c.rbegin(); i != c.rend(); i++) {
		a.insert(result, *i);
	}

	print_l(a);
}

void execute_26() {

	list<int> a{1,2,3,4,9,6,7,8,5,10};

	auto start = a.begin();
	auto end = a.rbegin();
	
	int res = INT32_MAX;
	for (int i = 0; i < a.size() / 2; i++) {
		res = min(res, max(*start, *end));
		++start;
		++end;
	}
	
	cout << res;
}

int oop33() {

	//execute_24();
	//execute_26();

	return 0;
}