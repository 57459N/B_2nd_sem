#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Big256 {
private:
	vector<short> arr;
	const short num_base = 256;

	void toBig(int num) {
		int buff = 0;
		while (num) {
			buff = num % num_base;
			arr.push_back(buff);
			num -= buff;
			num /= num_base;
		}
	}

	void normalize() {
		for (int i = 0; i < arr.size(); i++) {
			if (arr[i] >= num_base) {
				if (i + 1 == arr.size()) {
					arr.push_back(arr[i] / num_base);
					arr[i] = arr[i] % num_base;
				}
				else {
					arr[i + 1] += arr[i] / num_base;
					arr[i] = arr[i] % num_base;
				}
			}
		}
		/*for (auto i = arr.begin(); i != arr.end(); i++) {
			if (*i >= num_base) {
				if (i + 1 == arr.end()) {
					arr.push_back(*i / num_base);
					*i = *i % num_base;
				}
				else{
					*(i + 1) += *i / num_base;
					*i -= *i % num_base;
				}
			}
		}*/
	}

public:
	Big256() = default;

	Big256(int num) {
		toBig(num);
	}

	Big256(const Big256& num) {
		this->arr = num.arr;
	}

	~Big256() {
		arr.clear();
	}

	Big256 operator+ (const Big256& n) {
		Big256 sum(0);
		int mx = max(n.arr.size(), arr.size());
		int mn = min(n.arr.size(), arr.size());
		sum.arr.resize(mx);
		for (int i = 0; i < min(n.arr.size(), arr.size()); i++) {
			sum.arr[i] = arr[i] + n.arr[i];
		}
		if (n.arr.size() > arr.size()) {
			for (int i = mn; i < mx; i++) {
				sum.arr[i] = n.arr[i];
			}
		}
		else {
			for (int i = mn; i < mx; i++) {
				sum.arr[i] = arr[i];
			}
		}

		sum.normalize();
		return sum;
	}

	Big256& operator* (const int n) {
		for (auto i = arr.begin(); i != arr.end(); i++) {
			*i *= n;
		}
		this->normalize();
		return *this;
	}

	Big256 operator* (const Big256& n) {
		Big256 multy(0); 
		for (int i = 0; i < n.arr.size(); i++) {
			multy = multy + *this * n[i] * pow(256,i);
		}
		this->normalize();
		return *this;
	}

	Big256& operator=(const int n) {
		toBig(n);
		return *this;
	}

	Big256& operator=(const Big256 n) {
		this->arr = n.arr;
		return *this;
	}

	short& operator[](const int idx) {
		try {
			return arr[idx];
		}
		catch (int a) {
			throw;
		}
	}

	short operator[](const int idx) const {
		try {
			return arr[idx];
		}
		catch (int a) {
			throw;
		}
	}

	friend std::istream& operator>> (std::istream& str, Big256& o) {
		char* d = new char[100];
		str.getline(d, 100);
		o.toBig(atoi(d));
		return str;
	}

	friend std::ostream& operator<< (std::ostream& str, const Big256& num) {
		bool start = false;
		for (auto i = num.arr.rbegin(); i != num.arr.rend(); i++) {
			if (!start && *i) start = true;
			if (start) {
				str << hex << *i;
			}
		}
		return str;
	}
};


int oop26() {
	
	Big256 num;
	num = 5;
	int power = 100;
	Big256 multiplier(num);
	for (int i = 0; i < power-1; i++) {
		num = num * multiplier;
		cout << num << endl;
	}
	
	cout << num;
	return 0;
}