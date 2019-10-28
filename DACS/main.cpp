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
ostream &operator<<(ostream &ostream, Array &node)
{
    Array *temp = &node;
    if (temp->length > 0)
    {
        ostream << "[" << temp->length << "] : ( ";
        while (temp != NULL)
        {
            ostream << temp->value;
            if (temp->next != NULL)
            {
                ostream << ", ";
            }
            temp = temp->next;
        }
        ostream << ")";
    }
    return ostream;
};
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
int main()
{

    //-----------------------------------------
    Array A;
    getData(A, "A.txt");
    Array B;
    getData(B, "B.txt");
    Array C(A.length + B.length);
    C[0] = A[0] + B[0];

    cout << A << endl
         << B << endl
         << C;
    //-----------------------------------------
    //cout << A << B;
    return 0;
}