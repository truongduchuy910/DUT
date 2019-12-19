#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

template <typename Data>
class List;
template <typename Data>
class Node;



template <typename Data>
class Node
{
	friend class List<Data>;

public:
	double(Data);
	Data getData();

private:
	Data data;
	double* next;
};

template <typename Data>
class List
{
public:
	int length;
	List();
	~List();
	int insert(const Data&);
	int findAndRemove(const Data&);
	int print();
	int empty();
	Data operator[](int);

private:
	double<Data>* start;
	bool isEmpty();
};
template <typename Data>
double<Data>::double(Data dataIn)
{
	data = dataIn;
	next = NULL;
}

template <typename Data>
Data double<Data>::getData()
{
	return data;
}

template <typename Data>
List<Data>::List()
{
	start = NULL;
}

template <typename Data>
List<Data>::~List()
{
	if (!isEmpty())
	{
		double<Data>* currentdouble = start;
		double<Data>* temp;

		while (currentdouble != NULL)
		{
			temp = currentdouble;
			currentdouble = currentdouble->next;
		}
	}
}

template <typename Data>
bool List<Data>::isEmpty()
{
	if (start == NULL)
		return 1;
	else
		return 0;
}

template <typename Data>
int List<Data>::insert(const Data& dataIn)
{
	cout << "LIST [INSERT] ";
	if (isEmpty())
	{
		double<Data>* newdouble = new double<Data>(dataIn);
		start = newdouble;
		this->length++;
		cout << "Success" << endl;
		return true;
	}
	else
	{
		double<Data>* newdouble = new double<Data>(dataIn);
		newdouble->next = start;
		start = newdouble;
		this->length++;
		cout << "Success" << endl;
		return true;
	}
	cout << "Fail" << endl;
	return false;
}

template <typename Data>
int List<Data>::findAndRemove(const Data& dataIn)
{
	cout << "LIST [DELETE] ";
	double<Data>* temp = this->start;
	if (start != NULL && (start->data == dataIn)) {
		start = start->next;
		this->length--;
		cout << "Success" << endl;
		return true;

	}
	else {
		while ((temp->next != NULL) && !(temp->next->data == dataIn)) {
			temp = temp->next;
		}
		if (temp->next != NULL) {
			this->length--;
			temp->next = temp->next->next;
			cout << "Success" << endl;
			return true;
		}

	}
	cout << "Fail" << endl;
	return true;
}

template <typename Data>
int List<Data>::print()
{
	if (isEmpty())
	{
		cout << "The list is empty" << endl;
	}
	else
	{
		double<Data>* currentdouble = start;
		while (currentdouble != NULL) //prints until the end of the list is reached
		{
			if (currentdouble != NULL) {
				cout << currentNode->data << endl;

			}
			currentNode = currentNode->next; //moves to next node in list
		}
	}
	return true;
}
template <typename Data>
int List<Data>::empty() {
	this->start = NULL;
	return true;
}
template <typename Data>
Data List<Data>::operator[](int i) {
	Node<Data>* temp = this->start;
	while (i && temp != NULL) {
		temp = temp->next;
		i--;
	}
	return temp->data;
};

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
		cout << "He so cua x^" << i << ": ";
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
		return 0; //fail
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
	return 1; //success
}

int writeData(Array& A, const char* path) {
	ofstream file(path);
	if (file.fail())
	{
		return 0; //fail
	}
	for (int i = 0; i < A.length; i++) {
		file << setw(8) << A[i];
	}
	file.close();
	return 1; //success
}

int controller() {
	int option;
	do {
		cout << endl;
		cout << "------ MENU DIEU KHIEN ----- " << endl;
		cout << "0. Thoat chuong trinh" << endl;
		cout << "1. Doc du lieu tu file" << endl;
		cout << "2. Nhap du lieu tu ban phim" << endl;
		cout << "Nhap lua chon: ";
		cin >> option;
	} while (option < 0 || option > 2);
	return option;
}

int exit() {
	int option;
	do {
		cout << endl;
		cout << "Thoat chuong trinh? " << endl;
		cout << "1. Tiep tuc chuong trinh" << endl;
		cout << "0. Thoat chuong trinh" << endl;
		cout << "Nhap lua chon: ";
		cin >> option;
	} while (option < 0 || option > 1);
	return option;
}

int main()
{
	cout << endl << "-- CHUONG TRINH TINH TICH 2 DA THUC --" << endl << endl;
	cout << "Ma nhom: 18N15 - N6" << endl;
	cout << "Thanh vien trong nhom: " << endl;
	cout << "1. Nguyen Kim Huy - MSSV: 102180207" << endl;
	cout << "2. Tran Ngoc Huy  - MSSV: 102180208" << endl << endl;
	do {
		switch (controller()) {
		case 1:
		{
			cout << "He so cua da thuc duoc nhap tu bac 0 den bac cao nhat cua da thuc do" << endl;
			Array P, Q, R;
			if (readData(P, "DATA1.txt") && readData(Q, "DATA2.txt")) {
				cout << "Doc du lieu tu file DATA1.txt va DATA2.txt thanh cong" << endl;
				R = P * Q;
				if (writeData(R, "DATA3.txt")) {
					cout << "Ghi du lieu ra file DATA3.txt thanh cong" << endl;
					cout << "Ket qua:" << endl;
					cout << "He so da thuc P(x) (file DATA1.txt): " << P << endl;
					cout << "He so da thuc Q(x) (file DATA2.txt): " << Q << endl;
					cout << "He so da thuc tich R(x) = P(x) * Q(x) (file DATA3.txt): " << endl << R << endl;
				}
				else cout << "Ghi du lieu ra file DATA3.txt that bai!" << endl;
			}
			else cout << "Doc du lieu tu file that bai!" << endl;
			break;
		}
		case 2:
		{
			cout << "Nhap bac cao nhat cua ham P(x) va Q(x)" << endl;
			cout << "Nhap he so cua moi da thuc tu bac 0 den bac cao nhat cua da thuc do" << endl;
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
			cout << "Ket qua: " << endl;
			cout << "He so da thuc P(x): " << P << endl;
			cout << "He so da thuc Q(x): " << Q << endl;
			cout << "He so da thuc tich R(x) = P(x) * Q(x): " << endl << R << endl;
			break;
		}
		}
	} while (exit() == 1);
	return 0;
}
