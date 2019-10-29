#include <fstream>
#include <iostream>
using namespace std;
class Array
{
private:
    Array *next;
    int value;
public:
    int length;
    Array(int);
    ~Array();
    int insertLast(int);
    int &operator[](int);
    friend ostream &operator<<(ostream &, Array &);
    Array Multiply(Array &A, Array &B);
};
Array::Array(int size = 1)
{
    length = 1;
    this->next = NULL;
    this->value = 0;
    while (--size)
    {
        this->insertLast(0);
    }
}

Array::~Array()
{
}

int Array::insertLast(int value)
{
    Array *lastNode = this;
    length++;

    while (lastNode->next != NULL)
    {
        lastNode = lastNode->next;
    }
    Array *newLastNode = new Array;
    newLastNode->value = value;
    newLastNode->next = NULL;
    lastNode->next = newLastNode;
    return value;
}

int &Array::operator[](int i)
{
    Array *node = this;
    int index = 0;
    while (index != i && node != NULL)
    {
        index++;
        node = node->next;
    };
    return node->value;
}
ostream &operator<<(ostream &ostream, Array &A)
{
    for (int i = 0; i < A.length; i++) {
    	ostream << A[i] << " ";
	}
    return ostream;
}
Array Array::Multiply(Array &A, Array &B) {
	Array C(A.length + B.length - 1);
	for (int i = 0; i < A.length; i++) {
		for (int j = 0; j < B.length; j++) {
			int k = i + j;
			C[k] += A[i] * B[j];
		}
	}
	return C;
}
void getData(Array &A, const char *path)
{
    ifstream file;
    int value;
    file.open(path);
    int index = 0;
    while (file >> value)
    {
        if (index < A.length)
        {
            A[index] = value;
        }
        else
        {
            A.insertLast(value);
        }
        index++;
    };
    file.close();
}
void writeData(Array &A, const char *path){
	ofstream file(path);
	for (int i = 0; i < A.length; i++)
    {
        file << A[i] << " " ;
    }
    file.close();
}
int main()
{
    Array A;
    getData(A, "D:/DACS/Code/A.txt");
    Array B;
    getData(B, "D:/DACS/Code/B.txt");
    cout << A << endl << B << endl;
    Array C(A.length + B.length - 1);
	C = C.Multiply(A,B);
	cout << C;
	writeData(C, "D:/DACS/Code/C.txt");
    return 0;
}
