#include <fstream>
#include <iostream>
using namespace std;
class Array
{
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
    Array Multiply(Array &A, Array &B);
};
Array operator*(Array &A, Array &B)
{
    Array result(A.length + B.length - 1);
    for (int i = 0; i < A.length; i++)
    {
        for (int j = 0; j < B.length; j++)
        {
            int k = i + j;
            result[k] += A[i] * B[j];
        }
    }
    return result;
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

double Array::insertLast(double value)
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

double &Array::operator[](int i)
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
    for (int i = 0; i < A.length; i++)
    {
        ostream << A[i] << " ";
    }
    return ostream;
}
Array Array::Multiply(Array &A, Array &B)
{
    Array C(A.length + B.length - 1);
    for (int i = 0; i < A.length; i++)
    {
        for (int j = 0; j < B.length; j++)
        {
            int k = i + j;
            C[k] += A[i] * B[j];
        }
    }
    return C;
}
void readData(Array &A, const char *path)
{
    ifstream file;
    double value;
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
void writeData(Array &A, const char *path)
{
    ofstream file(path);
    for (int i = 0; i < A.length; i++)
    {
        file << A[i] << " ";
    }
    file.close();
}
int main()
{
    Array A;
    readData(A, "A.txt");
    Array B;
    readData(B, "B.txt");
    cout << A << endl
         << B << endl;
    Array C(A.length + B.length - 1);
    C = A * B;
    cout << C << endl;
    writeData(C, "C.txt");
    return 0;
}
