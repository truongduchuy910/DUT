#include <iostream>
struct Array {
	int* data;
	int length;
};
void input(Array& A) {
	std::cout << "Input lenght: ";
	std::cin >> A.length;
	std::cout <<  "Input data with format d1 d2 d3  ... ";
	A.data = new int[A.length];
	for (int i = 0; i < A.length; i++) {
		std::cin >> A.data[i];
	};
};
void output(const Array A) { 
	for (int i = 0; i < A.length; i++) {
		std::cout << A.data[i] << " ";
	};
	std::cout << std::endl;
};
void sort(Array& A) {
	for (int i = 0; i < A.length; i++) {
		for (int j = A.length - 1; j > i; j--) {
			if (A.data[j] < A.data[j - 1]) {
				int cache = A.data[j];
				A.data[j] = A.data[j - 1];
				A.data[j - 1] = cache;
			};
		};
	};
};
int search (Array &A, const int keyword) {
	for (int i = 0; i < A.length; i++) {
		if (A.data[i] == keyword) {
			return i;
		};
	};
	return -1;
};
int main() {
	Array A;
	input(A);
	std::cout << "Your data : ";
	output(A);
	sort(A);
	std::cout << "After sort: ";
	output(A);
	int keyword;
	std::cout << "Input value to search (int): ";
	std::cin >> keyword;
	std::cout << "Position of " << keyword << " is " << search(A, keyword) << std::endl;
};
