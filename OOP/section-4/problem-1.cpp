#include <iostream>
#include <math.h>
using namespace std;
class Vector
{
private:
    int n;
    float *data;

public:
    Vector();
    Vector(int);
    Vector(const Vector &);
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
private:
    int col, row;
    float **data;

public:
    Matrix();
    Matrix(int, int);
    Matrix(const Matrix &);
    ~Matrix();
    Matrix &operator=(const Matrix &);
    float &operator()(int, int);
    friend ostream &operator<<(ostream &, const Matrix &);
    friend istream &operator>>(istream &, Matrix &);
    friend Matrix operator+(const Matrix &, const Matrix &);
    friend Matrix operator-(const Matrix &, const Matrix &);
    friend Matrix operator*(const Matrix &, const Matrix &);
    friend float operator^(const Matrix &, const Matrix &);
};

class Polynomial
{
private:
    int n;
    float *data;

public:
    Polynomial();
    Polynomial(int);
    Polynomial(const Polynomial &);
    ~Polynomial();
    Polynomial &operator=(const Polynomial &);
    float &operator()(float);
    friend ostream &operator<<(ostream &, const Polynomial &);
    friend istream &operator>>(istream &, Polynomial &);
    friend Polynomial operator+(const Polynomial &, const Polynomial &);
    friend Polynomial operator-(const Polynomial &, const Polynomial &);
    friend Polynomial operator*(const Polynomial &, const Polynomial &);
};

int main()
{
    Polynomial A(2);
    cin >> A;
    cout << A;

    return 0;
}
Vector::Vector()
{
    this->n = 1;
    this->data = new float[1];
};
Vector::Vector(int n = 1)
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
Vector::Vector(const Vector &A)
{
    this->n = A.n;
    this->data = new float[n];
    for (int i = 0; i < n; i++)
    {
        this->data[i] = A.data[i];
    }
}
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
Matrix::Matrix()
{
    this->row = 1;
    this->col = 1;
    this->data = new float *[1];
    this->data[0] = new float[1];
}
Matrix::Matrix(int row, int col)
{
    if (row > 0 && col > 0)
    {
        this->row = row;
        this->col = col;
        this->data = new float *[row];
        for (int i = 0; i < row; i++)
        {
            this->data[i] = new float[col];
        }
    }
    else
    {
        cout << "please intialize Matrix with both row and col are greater than 0!" << endl;
    }
};
Matrix::Matrix(const Matrix &A)
{

    this->row = A.row;
    this->col = A.col;
    this->data = new float *[A.row];
    for (int i = 0; i < A.row; i++)
    {
        this->data[i] = new float[A.col];
        for (int j = 0; j < A.col; j++)
        {
            this->data[i][j] = A.data[i][j];
        }
    }
};
Matrix::~Matrix()
{
    for (int i = 0; i < this->row; i++)
    {
        delete[] this->data[i];
    }
    delete[] this->data;
};
Matrix &Matrix::operator=(const Matrix &A)
{
    if (this->row == A.row && this->col == A.col)
    {
        for (int i = 0; i < A.row; i++)
        {
            for (int j = 0; j < A.col; j++)
            {
                this->data[i][j] = A.data[i][j];
            }
        }
    }
    else
    {
        cout << "Can't solve operator = in Matrix! " << endl;
    }
};
float &Matrix::operator()(int i, int j)
{
    return this->data[i - 1][j - 1];
};
ostream &operator<<(ostream &stream, const Matrix &A)
{
    for (int i = 0; i < A.row; i++)
    {
        for (int j = 0; j < A.col; j++)
        {
            stream << A.data[i][j] << " ";
        }
        stream << endl;
    }
    return stream;
};
istream &operator>>(istream &stream, Matrix &A)
{
    cout << endl;
    cout << "Matrix " << A.row << "x" << A.col << endl
         << "Input col of row[i]: c1 c2 .. cn | n = " << A.col << endl;
    for (int i = 0; i < A.row; i++)
    {
        cout << "row[" << i + 1 << "]: ";
        for (int j = 0; j < A.col; j++)
        {
            stream >> A.data[i][j];
        }
    }
    return stream;
};
Matrix operator+(const Matrix &A, const Matrix &B)
{
    Matrix result(A.row, A.col);
    if (A.row == B.row && A.col == B.col)
    {
        for (int i = 0; i < A.row; i++)
        {
            for (int j = 0; j < A.col; j++)
            {
                result.data[i][j] = A.data[i][j] + B.data[i][j];
            }
        }
    }
    else
    {
        cout << "Can't solve operator + in Maxtrix" << endl;
    }

    return result;
};
Matrix operator-(const Matrix &A, const Matrix &B)
{
    Matrix result(A.row, A.col);
    if (A.row == B.row && A.col == B.col)
    {
        for (int i = 0; i < A.row; i++)
        {
            for (int j = 0; j < A.col; j++)
            {
                result.data[i][j] = A.data[i][j] - B.data[i][j];
            }
        }
    }
    else
    {
        cout << "Can't solve operator + in Maxtrix" << endl;
    }

    return result;
};
Matrix operator*(const Matrix &A, const Matrix &B)
{
    if (A.col == B.row)
    {
        Matrix result(A.row, B.col);
        for (int i = 0; i < A.row; i++)
        {
            for (int j = 0; j < B.col; j++)
            {
                result.data[i][j] = 0;
                for (int k = 0; k < A.col; k++)
                {
                    result.data[i][j] += A.data[i][k] * B.data[k][j];
                }
            }
        }
        return result;
    }
    else
    {
        cout << "Can't solve operator * in Maxtrix" << endl;
        Matrix result(1, 1);
        return result;
    }
};

Polynomial::Polynomial()
{
    this->n = 1;
    this->data = new float[1];
    this->data[0] = 0;
};
Polynomial::Polynomial(int n)
{
    if (n > 0)
    {
        this->n = n;
        this->data = new float[n];
    }
    else
    {
        cout << "please intialize Polynomial with n greater than 0!";
    }
};
Polynomial::Polynomial(const Polynomial &A)
{
    this->n = A.n;
    this->data = new float[n];
    for (int i = 0; i < A.n; i++)
    {
        this->data[i] = A.data[i];
    }
};
Polynomial::~Polynomial()
{
    delete[] this->data;
};
Polynomial &Polynomial::operator=(const Polynomial &A)
{
    if (A.n == this->n)
    {
        for (int i = 0; i < A.n; i++)
        {
            this->data[i] = A.data[i];
        }
    }
    else
    {
        cout << "Can't solve operator = in Polunimial" << endl;
    }
};
float &Polynomial::operator()(float x)
{
    static float result = 0;
    for (int i = 0; i < this->n; i++)
    {
        result += this->data[i] * pow(x, i);
    }
    return result;
};
ostream &operator<<(ostream &stream, const Polynomial &A)
{
    stream << "f(x): ";
    for (int i = A.n; i >= 0; i--)
    {
        if (A.data[i] > 0 && i != A.n)
        {
            stream << "+";
        }
        if (A.data[i] != 0)
        {
            if (A.data[i] != 1)
            {
                stream << A.data[i];
            }
            if (A.data[i] == 1 && i == 0)
            {
                stream << 1;
            }
            if (i != 0 && i != 1)
            {
                stream << "x^" << i;
            }
            if (i == 1)
            {
                stream << "x";
            }
        }
    }
    stream << endl;
    return stream;
};
istream &operator>>(istream &stream, Polynomial &A)
{
    cout << "Input Polynomial (a0, a1, a2, ... an), n = " << A.n + 1 << ": ";

    for (int i = 0; i <= A.n; i++)
    {
        stream >> A.data[A.n - i];
    };
    return stream;
};
Polynomial operator+(const Polynomial &, const Polynomial &){};
Polynomial operator-(const Polynomial &, const Polynomial &){};
Polynomial operator*(const Polynomial &, const Polynomial &){};