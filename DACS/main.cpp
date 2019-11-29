#include <iostream>
#include <fstream>
using namespace std;
class Array {
private:
    Array *next;
    double value;
public:
    int length;
    Array(int);
    ~Array();
    double insertLast(double);
    double &operator[](int);
    friend Array operator*(Array &, Array &);
    friend ostream &operator<<(ostream &, Array &);
    friend istream &operator>>(istream &, Array &);
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
    Array *lastNode = this;
    length++;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }
    Array *newLastNode = new Array;
    newLastNode->value = value;
    newLastNode->next = NULL;
    lastNode->next = newLastNode;
    return value;
}
double &Array::operator[](int i) {
    Array *node = this;
    int index = 0;
    while (index != i && node != NULL) {
        index++;
        node = node->next;
    };
    return node->value;
}
ostream &operator<<(ostream &ostream, Array &A) {
    for (int i = 0; i < A.length; i++) {
        ostream << A[i] << "   ";
    }
    return ostream;
}
istream &operator>>(istream &istream, Array &A) {
    for (int i = 0; i < A.length; i++) {
        istream >> A[i];
    }
    return istream;
}
Array operator*(Array &A, Array &B) {
    Array result(A.length + B.length - 1);
    for (int i = 0; i < A.length; i++) {
        for (int j = 0; j < B.length; j++) {
            int k = i + j;
            result[k] += A[i] * B[j];
        }
    }
    return result;
}
void readData(Array &A, const char *path) {
    ifstream file;
    double value;
    file.open(path);
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
}
void writeData(Array &A, const char *path) {
    ofstream file(path);
    for (int i = 0; i < A.length; i++) {
        file << A[i] << " ";
    }
    file.close();
}
int main()
{
	cout << endl << " -- CHUONG TRINH TINH TICH 2 DA THUC -- " << endl;
	int option;
	do {
		cout << "Chon phuong thuc nhap: " << endl
			 << "1. Doc du lieu tu file" << endl
		 	 << "2. Nhap du lieu tu ban phim" << endl;
		cin >> option;
	}
	while (option!=1 and option!=2);
	if (option == 1) {
		Array P, Q, R(P.length + Q.length - 1);
		readData(P, "DATA1.txt");
		readData(Q, "DATA2.txt");
		R = P * Q;
		writeData(R, "DATA3.txt");
		cout << "Doc du lieu tu file DATA1.txt va DATA2.txt, ghi vao file DATA3.txt" << endl;
		cout << "He so da thuc P(x): " << P << endl
   			 << "He so da thuc Q(x): " << Q << endl
   			 << "He so da thuc tich R(x) = P(x) * Q(x): " << R << endl;
   	} 
	else {
		cout << "Nhap bac cao nhat cua ham P(x) va Q(x)" << endl	
			 <<	"Nhap he so cua moi ham tu bac 0 den bac cao nhat cua ham do" << endl
			 << "Vi du: P(x) = 2 + 3*x - 5.5*x^3 thi nhap bac la bac 3, he so lan luot la: 2 3 0 -5.5" << endl;
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
		cout << endl << "He so da thuc P(x): " << P << endl
   			 	 	 << "He so da thuc Q(x): " << Q << endl
   			 		 << "He so da thuc tich R(x) = P(x) * Q(x): " << R << endl;
	}
    return 0;
}
