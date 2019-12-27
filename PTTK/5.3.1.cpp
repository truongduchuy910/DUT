#include <iostream>
using namespace std;
#include <math.h>
int size(double a) {
	int size = 1;
	while (a > 9) {
		size++;
		a /= 10;
	}
	return size;
}
double karatsuba(double a, double b) {
	int size_a = size(a);
	int size_b = size(b);
	int size_N = (size_a > size_b)? size_a: size_b;
	if (size_N == 1) return a * b;
	int n = size_N / 2 + size_N % 2;
	double m = pow(10, n);
	double M = pow(10, 2 * n);

	double left_a  = a / m;
	double right_a = a - (left_a * m);

	double left_b = b / m;
	double right_b = b - (left_b * m);

	double p = karatsuba(left_a, left_b);
	double q = karatsuba(right_a, right_b);
	double r = karatsuba(left_a + right_a, left_b + right_b);

	return p * M + (r - p - q) * m + q;
}
int main() {
	cout << karatsuba(12345 , 6789);
}
