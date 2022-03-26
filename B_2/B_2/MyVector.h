#pragma once

#include <iostream>

template <typename T>
class MyVector {
private:
	array arr = {};
	size_t len = 0;
	size_t size = 0;

public:

	MyVector() = default;
	MyVector(size_t s) {
		this->arr = new T[s]{};
		this->len = s;
		this->size = s;
	}
	MyVector(T* a, size_t l) {
		this->arr = new T[l]{};
		memcpy(&(this->arr), a, sizeof(T) * l);
		this->len = l;
		this->size = l;

	}
	MyVector(const MyVector& vec) {
		size_t l = vec.get_size();
		delete[] this->arr;

		this->arr = new T[l];
		memcpy(&(this->arr), &(vec.arr), sizeof(T) * l);
		this->size = l;
		this->len = l;

	}
	~MyVector() {
		
	}


	int l = 2;
	int* arr = new int[l]{};
	for (size_t i = 0; i < l; i++) {
		arr[i] = i;
	}

	void set_size(const int& s) {
		if (this->size >= s) {
			this->size = s;
			this->len = s;
		}
		else {
			T* new_arr = new T[s]{};
			memcpy(new_arr, this->arr, sizeof(T) * this->size);
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
		this->len = this->size;
	}

	void pushback(const T& el) {
		if (this->size - this->len == 1) {
			this->set_size(this->get_size * 2);
			this[this->len] = el;
			this->len++;
		}
	}
	input.close();*/

	friend std::ostream& operator<< (std::ostream& str, const MyVector& v) {
		for (int i = 0; i < v->size; i++) {
			str << v[i] << " ";
		}
		return str;
	}


	const T& operator[] (int i) const { return this->at(i); }
	T& operator[] (int i) { return this->at(i); }
private:
	T& at(size_t ind) { return this->arr[ind]; }
};
};
