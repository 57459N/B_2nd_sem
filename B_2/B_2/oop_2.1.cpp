#include <iostream>
#include <iomanip>


using namespace std;

template <typename T>
class Vector {
private:
	T* arr = nullptr;
	size_t len = 0;
	size_t size = 0;

public:

	Vector() = default;
	Vector(size_t s) {
		this->arr = new T[s]{};
		this->len = s;
		this->size = s;
	}
	Vector(double a[]) {
		size_t l = sizeof(a) / sizeof(a[0])
		this->arr = new T[l]{};
		arr = a;
		this->len = l;
		this->size = l;

	}
	Vector(const Vector& vec) {
		size_t new_size = vec.get_size();
		
		delete[] this->arr;
		this->arr = new T[new_size];
		this->size = new_size;
		this->len = new_size;

		memcpy(this->arr, vec.arr, vec[0] * new_size);
	}

	size_t get_size() const {
		return this->size;
	}
	size_t get_len() const {
		return this->len;
	}

	void set_size(const int& s) {
		if (this->size <= s) {
			this->size = s;
		}
		else {
			T* new_arr = new T[s];
			memcpy(new_arr, this->arr, sizeof(this[0]) * this->size);
			delete[] this->arr;
			this->arr = new_arr;
			this->size = s;
		}
	}

	void fill_rand() {
		srand(time(nullptr));
		for (int i = 0; i < this->size; i++) {
			this[i] = (rand() % 10000) / 100.;
		}
	}

	void pushback(cosnt T& el) {
		if (this->size - this->len == 1) {
			this->set_size(this->get_size * 2);
			this[this->len] = el;
			this->len++;
		}
	}

	friend std::ostream& operator<< (std::ostream& str, const Vector& v) {
		for (int i = 0; i < v->size; i++) {
			str << v[i] << " ";
		}
		return str;
	}


	const T& operator[] (int i) const { return this->at(i); }
	T& operator[] (int i) { return this->at(i); }
private:
	T& at(size_t ind) { return this->arr[i]; }
};


int oop21() {



	return 0;
}