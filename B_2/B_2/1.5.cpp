#include <cmath>
#include <iomanip>
#include <iostream>


using namespace std;

int Integral_counter= 0;

double f(double x, double s, double t) {
	return t * exp( x / 2) / sqrt(x + s);
}

double Yi(double(*f)(double, double, double), double a, double s, double t, double h, int i) {
	return f(a + h * i, s, t);
}
double Integral(double(*f)(double, double, double), double s, double t, double a, double b, double n) {
	double h = (b - a) / 2 / n;
	double I = Yi(f, a, s, t, h, 0) + Yi(f, a, s, t, h, 2 * n);
	
	for (int i = 2; i < 2 * n; i += 2) {
		I += 2 * Yi(f, a, s, t, h, i);
	}
	for (int i = 1; i < 2 * n; i += 2) {
		I += 4 * Yi(f, a, s, t, h, i);
	}
	I *= h / 3;
	Integral_counter++;
	return I;
}

double doubleAccuracy(double(*f)(double, double, double), double s, double t, double a, double b, double E) {
	int n = 4;
	double S1 = Integral(f,s,t,a,b,n);
	double S2 = 0;
	do {
		S2 = S1;
		n *= 2;
		S1 = Integral(f, s, t, a, b, n);
		//cout << "S1: " << S1 << "  S2: " << S2 << endl;
	} while (abs(S1 - S2) > E);
	
	return S1;
}

int m15() {

	double a = 0;
	double b = 1.047;
	cout << setw(2) << "S" << setw(6) << "T" << setw(9) << "Int" << setw(7) <<  "K" << endl;
	for (double s = 0.5; s <= 2; s += 0.5) {
		for (double t = 0.5; t <= 4; t += 0.5) {
			cout << setw(3) << s << "  " << setw(4) << t << "  " << setw(8) << doubleAccuracy(f, s, t, a, b, 1e-6) << setw(5) << Integral_counter << endl;
		}
	}
	
	return 0;
}