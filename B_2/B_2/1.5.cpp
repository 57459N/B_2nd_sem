#include <iostream>
#include <cmath>

#define e 2.71828182845904523536

using namespace std;

double f(double x, double s, double t) {
	return t * pow(e, x / 2) / sqrt(x + s);
}

double Yi(double(*f)(double, double, double), double a, double s, double t, double h, int i) {
	return f(a + h * i, s, t);
}
double Integral(double(*f)(double, double, double), double s, double t, double a, double b, double n) {
	int h = (b - a) / 2 / n;
	double I = Yi(f, a, s, t, h, 0) + Yi(f, a, s, t, h, 2 * n);
	
	for (int i = 2; i < 2 * n; i += 2) {
		I += 2 * Yi(f, a, s, t, h, i);
	}
	for (int i = 1; i < 2 * n; i += 2) {
		I += 4 * Yi(f, a, s, t, h, i);
	}
	I *= h / 3;
	return I;
}

double doubleAccuracy(double(*f)(double, double, double), double s, double t, double a, double b, double E) {
	int n = 4;
	int S1 = Integral(f,s,t,a,b,n);
	int S2 = 0;
	do {
		S2 = S1;
		n *= 2;
		S1 = Integral(f, s, t, a, b, n);
		cout << "S1: " << S1 << "  S2: " << S2 << endl;
	} while (abs(S1 - S2) > E);
	
	return S1;
}

int m15() {

	double s = 1;
	double t = 0.5;
	double a = 0;
	double b = 1.047;

	cout << doubleAccuracy(f, s, t, a, b, 1e-6);
	return 0;
}