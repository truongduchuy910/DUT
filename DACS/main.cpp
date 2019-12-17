#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class Array {
private:
	Array* next;
	double value;
public:
	int length;
	Array(int);
	~Array();
	double insertLast(double);
	double& operator[](int);
	friend Array operator*(Array&, Array&);
	friend ostream& operator<<(ostream&, Array&);
	friend istream& operator>>(istream&, Array&);
};

Array::Array(int size = 1) {
	length = 1;
	this->next = NULL;
	this->value = 0;
	while (--size) {
		this->insertLast(0);
	}
}

Array::~Array() {}

double Array::insertLast(double value) {
	Array* lastNode = this;
	length++;
	while (lastNode->next != NULL) {
		lastNode = lastNode->next;
	}
	Array* newLastNode = new Array;
	newLastNode->value = value;
	newLastNode->next = NULL;
	lastNode->next = newLastNode;
	return value;
}

double& Array::operator[](int i) {
	Array* node = this;
	int index = 0;
	while (index != i && node != NULL) {
		index++;
		node = node->next;
	};
	return node->value;
}

ostream& operator<<(ostream& ostream, Array& A) {
	for (int i = 0; i < A.length; i++) {
		ostream << setw(8) << A[i];
	}
	return ostream;
}

istream& operator>>(istream& istream, Array& A) {
	for (int i = 0; i < A.length; i++) {
		istream >> A[i];
	}
	return istream;
}

Array operator*(Array& A, Array& B) {
	Array result(A.length + B.length - 1);
	for (int i = 0; i < A.length; i++) {
		for (int j = 0; j < B.length; j++) {
			int k = i + j;
			result[k] += A[i] * B[j];
		}
	}
	return result;
}

int readData(Array& A, const char* path) {
	ifstream file;
	file.open(path);
	if (file.fail())
	{
		cout << "Khong the doc file!" << endl;
		return 0;
	}
	double value;
	int index = 0;
	while (file >> value) {
		if (index < A.length) {
			A[index] = value;
		}
		else {
			A.insertLast(value);
		}
		index++;
	};
	file.close();
	return 1;
}

int writeData(Array& A, const char* path) {
	ofstream file(path);
	if (file.fail())
	{
		cout << "Khong the ghi file!" << endl;
		return 0;
	}
	for (int i = 0; i < A.length; i++) {
		file << setw(8) << A[i];
	}
	file.close();
	return 1;
}

int controller() {
	int option;
	do {
		cout << endl;
		cout << "Chon phuong thuc nhap: " << endl;
		cout << "1. Doc du lieu tu file" << endl;
		cout << "2. Nhap du lieu tu ban phim" << endl;
		cin >> option;
	} while (option < 0 || option > 2);
	return option;
}

int continueprogram() {
	int option;
	do {
		cout << endl;
		cout << "Tiep tuc? " << endl;
		cout << "1. Co" << endl;
		cout << "0. Thoat" << endl;
		cin >> option;
	} while (option < 0 || option > 1);
	return option;
}

int main()
{
	cout << endl << " -- CHUONG TRINH TINH TICH 2 DA THUC -- " << endl << endl;
	cout << "Thanh vien trong nhom: " << endl;
	cout << "1. Nguyen Kim Huy - MSSV: 102180207" << endl;
	cout << "2. Tran Ngoc Huy  - MSSV: 102180208" << endl << endl;
	do {
		switch (controller()) {
		case 1:
		{
			Array P, Q, R;
			if (readData(P, "DATA1.txt") && readData(Q, "DATA2.txt")) {
				cout << "Doc du lieu tu file DATA1.txt va DATA2.txt thanh cong" << endl;
				R = P * Q;
				if (writeData(R, "DATA3.txt")) {
					cout << "Ghi du lieu ra file DATA3.txt thanh cong" << endl;
				}
				cout << "Ket qua:" << endl;
				cout << "He so da thuc P(x) (file DATA1.txt): " << P << endl;
				cout << "He so da thuc Q(x) (file DATA2.txt): " << Q << endl;
				cout << "He so da thuc tich R(x) = P(x) * Q(x) (file DATA3.txt): " << endl << R << endl;
			}
			break;
		}
		case 2:
		{
			cout << "Nhap bac cao nhat cua ham P(x) va Q(x)" << endl;
			cout << "Nhap he so cua moi ham tu bac 0 den bac cao nhat cua ham do" << endl;
			cout << "Vi du: P(x) = 2 + 3*x - 5.5*x^3 thi nhap bac la bac 3, he so lan luot la: 2 3 0 -5.5" << endl;
			int bacP, bacQ, bacR;
			cout << endl << "Nhap bac da thuc P(x): ";
			cin >> bacP;
			Array P(bacP + 1);
			cout << "Nhap cac he so: " << endl;
			cin >> P;
			cout << endl << "Nhap bac da thuc Q(x): ";
			cin >> bacQ;
			Array Q(bacQ + 1);
			cout << "Nhap cac he so: " << endl;
			cin >> Q;
			Array R(P.length + Q.length - 1);
			R = P * Q;
			cout << endl;
			cout << "He so da thuc P(x): " << P << endl;
			cout << "He so da thuc Q(x): " << Q << endl;
			cout << "He so da thuc tich R(x) = P(x) * Q(x): " << endl << R << endl;
			break;
		}
		}
	} while (continueprogram() == 1);
	return 0;
}
