#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>

using namespace std;

class Complex {
private:
    double re = 0;
    double im = 0;
public:
    Complex() = default;

    Complex(double a, double b) {
        re = a;
        im = b;
    }
   
   
    Complex operator * (const Complex& num2) {
        return Complex(this->re * num2.re - this->im*num2.im, this->re*num2.im + this->im*num2.re);
    }
    Complex operator + (const Complex& num2) {
        return Complex(this->re+num2.re, this->im+num2.im);
    }

    Complex& operator += (const Complex& num2) {
        re += num2.re;
        im += num2.im;
        return *this;
    }

    friend std::ostream& operator<< (std::ostream& str, const Complex& o);
};

std::ostream& operator<< (std::ostream& str, const Complex& o) {
    if (o.im >= 0) {
        str << setw(25) << o.re << "+" << o.im << "i";
    }
    else {
        str << setw(25) << o.re << o.im << "i";
    }
    return str;
}

void print_matrix_2d(int** arr, int res) {
    for (int i = 0; i < res; i++) {
        for (int j = 0; j < res; j++) {
            cout << setw(6) << arr[i][j] << "  ";
        }
        cout << endl;
    }
}

int m_2d_to_line(int i, int j, int res) {
    return res * j + i;
}

void m_multy( Complex* arrA, Complex* arrB, Complex* arrC, int res) {
    for (int i = 0; i < res; i++)
    {
        for (int j = 0; j < res; j++)
        {
            Complex sum = Complex(0,0);

            for (int l = 0; l < res; l++)
            {
                int addA = m_2d_to_line(i, l, res);
                int addB = m_2d_to_line(l, j, res);
                sum += arrA[addA] * arrB[addB];
            }

            int addIJ = m_2d_to_line(i, j, res);
            arrC[addIJ] = sum;
        }
    }
}

void m_multy(Complex** arrA, Complex** arrB, Complex** arrC, int res) {
    for (int i = 0; i < res; i++)
    {
        for (int j = 0; j < res; j++)
        {
            Complex sum = Complex(0, 0);
            for (int l = 0; l < res; l++)
            {
                sum += arrA[i][l] * arrB[l][j];
            }
            arrC[i][j] = sum;
        }
    }
}

void printM(Complex* arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[m_2d_to_line(i, j, n)] << "   ";
        }
        cout << "\n\n\n";
    }
}

void printM(Complex** arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << "   ";
        }
        cout << "\n\n\n";
    }
}

int m22()
{
    int res = 0;
    cout << "Enter resolution of matrix NxN: ";
    cin >> res;

    srand(time(nullptr));

    int len = res*res;

    Complex* arrA_line = new Complex[len];
    Complex* arrB_line = new Complex[len] {};

    Complex** arrA_2d = new Complex*[res];
    Complex** arrB_2d = new Complex*[res];

    for (int i = 0; i < len; i++) {
        arrA_line[i] = Complex((rand() % 15)/10.0, (rand() % 15) / 10.0);
        arrB_line[i] = Complex(1,1);
    }
    for (int i = 0; i < res; i++) {
        arrA_2d[i] = new Complex[res];
        arrB_2d[i] = new Complex[res];
        for (int j = 0; j < res; j++) {
            arrA_2d[i][j] = arrA_line[m_2d_to_line(i, j, res)];
            arrB_2d[i][j] = Complex(1,1);
        }
    }

    cout << "1. Input:" << endl;

    cout << "A LINE:" << endl;
    printM(arrA_line, res);
    cout << "A 2D:" << endl;
    printM(arrA_2d, res);

    cout << endl << "B LINE:" << endl;
    printM(arrB_line, res);
    cout << endl << "B 2D:" << endl;
    printM(arrB_2d, res);

    //
    // 2. Multiplication
    //

    for (int i = 0; i < 3; i++) {
        m_multy(arrA_line, arrA_line, arrB_line, res);
        arrA_line = arrB_line;
        m_multy(arrA_2d, arrA_2d, arrB_2d, res);
        arrA_2d = arrB_2d;
    }

    cout << "2. A in 8th grade:" << endl;
    cout << "C LINE:" << endl;
    printM(arrA_line, res);

    cout << "C 2D:" << endl;
    printM(arrA_2d, res);

    //
    // 4. Cleanup
    //

    arrA_line, arrB_line = nullptr;
    arrA_2d, arrB_2d = nullptr;

    delete[] arrA_line;
    delete[] arrB_line;
    delete[] arrA_2d;
    delete[] arrB_2d;

    return 0;
}
