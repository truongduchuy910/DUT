#include <iostream>
using namespace std;
struct Data {
	int dms;
	int* drc;
};
class Vector {
	public:
		Data data;
		Vector(int dms = 0);
		~Vector();
		int &operator [] (int i);
		void display(); 
		Vector &operator = (Vector* A);
};
Vector::Vector(int dms) { 
	this->data.dms = dms;
	if (dms) {
		this->data.drc = new int[dms]; 
	} 
}
Vector::~Vector() {
	delete[] this->data.drc; 
}
int &Vector::operator [] (int i) {
	return this->data.drc[i];
}; 
void Vector::display() {
	if (this->data.dms) {
		cout << "vector ";
		for (int i = 0; i < this->data.dms;i++) {
			cout << this->data.drc[i] << " ";
		};
	}; 
	cout << endl; 
};
Vector* operator + (Vector A, Vector B) {
	int dms = A.data.dms;
	Vector* C = new Vector(dms);
	if (A.data.dms == B.data.dms) {
		for (int i = 0; i < dms; i++) {
			C->data.drc[i] = A[i] + B[i];
		};
	} else {
		cout << "Can't solve A + B if A's dimensional different B's dimensional" << endl;
	}; 
	return C;
};
Vector &Vector::operator = (Vector* C) {
	int dms = C->data.dms;
	this->data.dms = dms;
	this->data.drc = new int[dms];
	for (int i = 0; i < dms; i++) {
		this->data.drc[i] = C->data.drc[i];
	}
	return *this;
}
int main() {
	cout << "Input dimensional of vector A (int): ";
	int dms;
	cin >> dms;
	Vector A(dms);
	cout << "Input directions (int int int ...): ";
	for (int i = 0; i < dms; i++) {
		cin >> A[i];
	};
	A.display();
	
	cout << endl;

	cout << "Input dimensional of vector B (int): ";
	cin >> dms;
	Vector B(dms);
	cout << "Input directions (int int int ...): ";
	for (int i = 0; i < dms; i++) {
		cin >> B[i];
	};
	B.display();

	cout << endl;
	
	cout << "A + B = ";
	Vector C;
	C = A + B;
	C.display();
	return 0;
}


