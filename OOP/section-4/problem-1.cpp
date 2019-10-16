#include <iostream>
#include <math.h>
using namespace std;
class Vector
{
private:
    int n;
    float *data;

public:
    Vector(int);
    ~Vector();
    Vector &operator=(const Vector &);
    float &operator[](int);
    friend ostream &operator<<(ostream &, const Vector &);
    friend istream &operator>>(istream &, Vector &);
    friend Vector operator+(const Vector &, const Vector &);
    friend Vector operator-(const Vector &, const Vector &);
    friend Vector operator*(const Vector &, const Vector &);
    friend float operator^(const Vector &, const Vector &);
};

class Matrix
{
};

class Polynomial
{
};

int main()
{
    Vector A(3);
    cin >> A;
    cout << A;

    Vector B(3);

    Vector C(3);
    cin >> C;
    cout << C;

    float multiple = A ^ C;
    cout << multiple << endl;
    cout << "----------" << endl;
    B = C = A;
    cout << B << C;
    cout << "----------" << endl;
    C = A + B;
    cout << A + B << A + B + C;
    cout << "----------" << endl;
    cout << A;
    A[0] = 0;
    cout << A;

    return 0;
}

Vector::Vector(int n)
{
    if (n > 0)
    {
        this->n = n;
        this->data = new float[n];
    }
    else
    {
        cout << "Please initialize vector with dimensional greater than 0!" << endl;
    }
};
Vector::~Vector()
{
    delete[] this->data;
};
Vector &Vector::operator=(const Vector &A)
{
    this->n = A.n;
    for (int i = 0; i < A.n; i++)
    {
        this->data[i] = A.data[i];
    }
    return *this;
};
float &Vector::operator[](int i)
{
    return this->data[i];
};
ostream &operator<<(ostream &stream, const Vector &A)
{
    for (int i = 0; i < A.n; i++)
    {
        cout << A.data[i] << " ";
    }
    cout << endl;
    return stream;
};
istream &operator>>(istream &stream, Vector &A)
{
    cout << "Input direction of vector (d1 d2 ... dn), n = " << A.n << ": ";
    for (int i = 0; i < A.n; i++)
    {
        cin >> A.data[i];
    }
    return stream;
};
Vector operator+(const Vector &A, const Vector &B)
{
    Vector result(A.n);
    if (A.n == B.n)
    {
        for (int i = 0; i <= A.n; i++)
        {
            result.data[i] = A.data[i] + B.data[i];
        }
    }
    else
    {
        cout << "can't solve operator +! " << endl;
    }
    return result;
};
Vector operator-(const Vector &A, const Vector &B)
{
    Vector result(A.n);
    if (A.n == B.n)
    {
        for (int i = 0; i <= A.n; i++)
        {
            result.data[i] = A.data[i] - B.data[i];
        }
    }
    else
    {
        cout << "can't solve operator -! " << endl;
    }
    return result;
};
Vector operator*(const Vector &A, const Vector &B)
{
    Vector result(A.n);
    if (A.n == B.n)
    {
        for (int i = 0; i <= A.n; i++)
        {
            result.data[i] = A.data[i] * B.data[i];
        }
    }
    else
    {
        cout << "can't solve operator *! " << endl;
    }
    return result;
};
float operator^(const Vector &A, const Vector &B)
{
    float result = 0;
    if (A.n == B.n)
    {
        for (int i = 0; i <= A.n; i++)
        {
            result += pow(B.data[i] - A.data[i], 2);
        }
        result = sqrt(result);
    }
    else
    {
        cout << "can't solve operator ^! " << endl;
    }
    return result;
};