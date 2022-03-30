#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Complex_Matrix {
public:
    class Complex_oop {
    private:
        double re = 0;
        double im = 0;
    public:
        Complex_oop() = default;

        Complex_oop(double a, double b) {
            re = a;
            im = b;
        }
        Complex_oop(const Complex_oop& m) {
            this->re = m.re;
            this->im = m.im;
        }

        Complex_oop operator * (const Complex_oop& num2) {
            return Complex_oop(this->re * num2.re - this->im * num2.im, this->re * num2.im + this->im * num2.re);
        }
        Complex_oop operator + (const Complex_oop& num2) {
            return Complex_oop(this->re + num2.re, this->im + num2.im);
        }

        Complex_oop& operator += (const Complex_oop& num2) {
            re += num2.re;
            im += num2.im;
            return *this;
        }

        friend std::ostream& operator<< (std::ostream& str, const Complex_oop& o) {
            if (o.im >= 0) {
                str << setw(25) << o.re << "+" << o.im << "i";
            }
            else {
                str << setw(25) << o.re << o.im << "i";
            }
            return str;
        }
    };

private:    
    vector<vector<Complex_Matrix::Complex_oop>> arr;
    int w = 3;
    int h = 3;

public:

    Complex_Matrix() = default;
    Complex_Matrix(const int n, const int m) {
        Complex_oop temp_num(0, 0);
        vector<Complex_oop> temp_vec(m);
        for (int i = 0; i < m; i++) {
            temp_vec.push_back(temp_num);
        }
        for (int i = 0; i < n; i++) {
            this->arr.push_back(temp_vec);
        }
        h = n;
        w = m;
    }
    ~Complex_Matrix() {
        h = 0;
        w = 0;
        arr.clear();
    }

    int heigth() const {
        return this->h;
    }

    int width() const {
        return this->w;
    }

    void square() {

        int n = this->h;
        int m = this->w;
        if(n==m){
            Complex_Matrix temp_m(n, m);

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    Complex_oop sum(0, 0);
                    for (int l = 0; l < n; l++)
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

    friend std::ostream& operator<< (std::ostream& str, const Complex_Matrix& o) {
        for (int i = 0; i < o.heigth(); i++) {
            for (int j = 0; j < o.width(); j++) {
                cout << o[i][j] << " ";
            }
            cout << endl;
        }

        return str;
    }

    const vector<Complex_oop>& operator[] (int idx) const { return this->arr[idx]; }

    vector<Complex_oop>& operator[] (int idx) { return this->arr[idx]; }


};


void fillV(vector<int> &v, string path) {
	ifstream input(path);
	int buffer;
	for (int j = 0; j < 10e7 && input >> buffer; j++) {
		v[buffer]++;
		if (j % 10000 == 0) {
			cout << j << endl;
		}
	}
}

void do_21() {
	vector<int> vec(10000);
	for (int i = 0; i < 10000; i++) {
		vec[i] = 0;
	}
	fillV(vec, "numbers.txt");

	int s = vec.size();
	for (int i = s; i < 0; i++) {
		if (vec[i]) {
			cout << i << " ";
		}
	}
}

void do_22() {
    Complex_Matrix Mat(3, 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            Mat[i][j] = Complex_Matrix::Complex_oop(1.2, 1.1);
        }
    }
    Mat.square();
    Mat.square();
    
    cout << Mat << endl;;
}

int oop32() {

    //do_21();
    do_22();

	return 0;
}