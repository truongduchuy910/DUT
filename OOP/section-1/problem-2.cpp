#include <iostream>
struct Vector {
	int D;
	int* items;
}; 
void input(Vector& vector) {
	std::cout << "Input dimensional: " << std::endl;
	std::cin >> vector.D;
	std::cout << "Input items with format d1 d2 d3 ... " << std::endl;
	vector.items = new int[vector.D + 1];
	for (int i = 1; i <= vector.D; i++) {
		std::cin >> vector.items[i];
	};
};
void output(const Vector vector) {
	std::cout << "(";
	for (int i = 1;  i <= vector.D; i++) {
		std::cout << vector.items[i];
		if (i != vector.D) std::cout << ", ";
	};
	std::cout << ")" << std::endl;
};
Vector operator + (Vector A, Vector B) {
	static Vector C;
	C.D = A.D;
	C.items = new int[C.D + 1];
	for (int i = 1; i <= C.D; i++) {
		C.items[i] = A.items[i] + B.items[i];
	};
	return C;
};
Vector operator - (Vector A, Vector B) {
	static Vector C;
	C.D = A.D;
	C.items = new int[C.D + 1];
	for (int i = 1; i <= C.D; i++) {
		C.items[i] = A.items[i] - B.items[i];
	};
	return C;
};

int operator * (Vector A, Vector B) {
	static int C;
	for (int i = 1; i <= A.D; i++) {
		C += A.items[i] * B.items[i];
	};
	return C;
};

int main () {
	Vector A;
	Vector B;
	std::cout << "Vector A" << std::endl;
	input(A);
	std::cout << "Vector B" << std::endl;
	input(B);
	Vector C;
	std::cout << "A + B =";
	output(A + B);
	std::cout << "A - B =";
	output(A - B);
	std::cout << "A * B =" << A * B;


}
