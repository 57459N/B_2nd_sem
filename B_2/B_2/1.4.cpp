#include <iostream>
#include <cmath>

#define PI 3.14159265358979323846
#define e 2.71828182845904523536

using namespace std;

double f1(double x, double s = 0) {
	return (x + 1) * (x + 1) - 9;
}

double f2(double x, double s) {
	return pow(cos(PI * x), 2) - pow(e, pow(x, s)) + 1;
}

void get_solution(double(*f)(double, double), double a, double b, double E, double s1 = 0, double s2 = 1, double ds = 2) {

	
	for (s1; s1 <= s2; s1 += ds) {
		double temp_x = a;
		double x1 = a;
		double x2 = b;
		int k_iter = 0;

		while (abs(x1 - x2) > E) {
			temp_x = x1;
			x1 = x2;
			x2 = temp_x - ((x2 - temp_x) * f(temp_x, s1) / (f(x2, s1) - f(temp_x, s1)));
			k_iter++;
		}
		
		cout << "S: " << s1 << "  X: " << x1 << "  F(x): " << f(x1, s1) << "  K_iter: " << k_iter << "\n";

	}

}



int m14() {

	double E = 1e-6;
	double a = 0;
	double b = 5;
			
	get_solution(f2, a, b, E);
	
	return 0;
}