#include <iomanip>
#include <iostream>
#include <string>
#include "MyVector.h"

using namespace std;

class NewComplex {
private:
	double re = 0;
	double im = 0;
public:
	NewComplex() = default;

	NewComplex(double a, double b) {
		re = a;
		im = b;
	}

	NewComplex(double arr[2]) {
		re = arr[0];
		im = arr[1];
	}

	NewComplex& operator=(double arr[2]) {
		re = arr[0];
		im = arr[1];
		return *this;
	}

	NewComplex operator * (const NewComplex& num2) {
		return NewComplex(this->re * num2.re - this->im * num2.im, this->re * num2.im + this->im * num2.re);
	}
	NewComplex operator + (const NewComplex& num2) {
		return NewComplex(this->re + num2.re, this->im + num2.im);
	}

	NewComplex& operator += (const NewComplex& num2) {
		re += num2.re;
		im += num2.im;
		return *this;
	}

	friend std::ostream& operator<< (std::ostream& str, const NewComplex& o) {
		if (o.im >= 0) {
			str << setw(25) << o.re << "+" << o.im << "i";
		}
		else {
			str << setw(25) << o.re << o.im << "i";
		}
		return str;
	};
};


class MyMatrix {
private:
	MyVector<MyVector<NewComplex>> arr;
	int rows = 0;
	int cols = 0;
	
	static int obj_count;
	string name;

public:

	MyMatrix(const int r, const int c) {
		rows = r;
		cols = c;
		arr.set_size(r);
		for (int i = 0; i < r; i++) {
			arr[i].set_size(c);
			for (int j = 0; j < c; j++) {
				arr[i][j] = {(rand() % 15) / 10.0, (rand() % 15) / 10.0};
			}
		}
		++obj_count;
		name = "matrix " + to_string(obj_count);
	}

	~MyMatrix() {
		--obj_count;
	}

	void get_name() {
		cout << name << endl;
	}

	void print() {
		get_name();
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				cout << arr[i][j] << "   ";
			}
			cout << "\n";
		}
	}

	void square() {

		if (rows == cols) {
			MyMatrix temp_m(rows, cols);

			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
				{
					NewComplex sum(0, 0);
					for (int l = 0; l < rows; l++)
					{
						sum += this->arr[i][l] * this->arr[l][j];
					}
					temp_m.arr[i][j] = sum;
				}
			}
			*this = temp_m;
		}
		else {
			cout << "Can't square not square matrix" << endl;
		}
	}

	MyVector<NewComplex>& operator[](int idx) {
		if (idx >= rows) throw;
		return arr[idx];
	}

	const MyVector<NewComplex>& operator[](int idx) const {
		if (rows < idx) throw;
		return arr[idx];
	}

};

int MyMatrix::obj_count = 0;

int oop27() {

	MyMatrix b(3,3);
	b[0][0] = { 1,1 };
	b.print();

	b.square();
	b.square();


	return 0;
}
