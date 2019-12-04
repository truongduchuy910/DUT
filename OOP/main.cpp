#include <iostream>
#include <math.h>
using namespace std;
class Polynomial
{
private:
    int n;
    float data[100];

public:
    Polynomial();
    Polynomial(int);
    Polynomial(const Polynomial &);
    ~Polynomial();
    Polynomial &operator=(const Polynomial &);
    float &operator()(float);
    float &operator[](int);
    friend ostream &operator<<(ostream &, const Polynomial &);
    friend istream &operator>>(istream &, Polynomial &);
    friend Polynomial operator+(const Polynomial &, const Polynomial &);
    friend Polynomial operator-(const Polynomial &, const Polynomial &);
    friend Polynomial operator*(const Polynomial &, const Polynomial &);
};
Polynomial det(int n, Polynomial mat[10][10]);
int main(int argc, char **argv)
{
    cout << "Enter the dimension of the matrix:\n";
    int n;
    cin >> n;
    Polynomial mat[10][10];
    cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[j][i][0];
            if (i == j)
            {
                mat[i][j][1] = -1;
            }
        }
    }
    cout << "The determinant of the given matrix is: " << det(n, mat) << endl;
    return 0;
}
Polynomial::Polynomial()
{
    this->n = 1;
    this->data[0] = 0;
    this->data[1] = 0;
};
Polynomial::Polynomial(int n)
{
    this->n = n;

    for (int i = 0; i <= n; i++)
    {
        this->data[i] = 0;
    }
};
Polynomial::Polynomial(const Polynomial &A)
{
    this->n = A.n;

    for (int i = 0; i <= A.n; i++)
    {
        this->data[i] = A.data[i];
    }
};
Polynomial::~Polynomial(){

};
Polynomial &Polynomial::operator=(const Polynomial &A)
{
    this->n = A.n;
    for (int i = 0; i <= A.n; i++)
    {
        this->data[i] = A.data[i];
    }
    return *this;
};
float &Polynomial::operator()(float x)
{
    static float result = 0;
    for (int i = 0; i <= this->n; i++)
    {
        result += this->data[i] * pow(x, i);
    }
    return result;
};
float &Polynomial::operator[](int i)
{
    return this->data[i];
};
ostream &operator<<(ostream &stream, const Polynomial &A)
{
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
Polynomial operator+(const Polynomial &A, const Polynomial &B)
{
    int n = 1;
    n = A.n > B.n ? A.n : B.n;
    Polynomial result(n);
    for (int i = 0; i <= n; i++)
    {
        if (i <= A.n)
        {
            result.data[i] += A.data[i];
        }
        if (i <= B.n)
        {
            result.data[i] += B.data[i];
        }
    }
    return result;
};
Polynomial operator-(const Polynomial &A, const Polynomial &B)
{
    int n = 1;
    n = A.n > B.n ? A.n : B.n;
    Polynomial result(n);
    for (int i = 0; i <= n; i++)
    {
        if (i <= A.n)
        {
            result.data[i] += A.data[i];
        }
        if (i <= B.n)
        {
            result.data[i] -= B.data[i];
        }
    }
    return result;
};
Polynomial operator*(const Polynomial &A, const Polynomial &B)
{
    Polynomial result(A.n + B.n);
    for (int i = 0; i <= A.n; i++)
    {
        for (int j = 0; j <= B.n; j++)
        {
            result.data[i + j] += A.data[i] * B.data[j];
        }
    }
    return result;
};

Polynomial det(int n, Polynomial mat[10][10])
{
    Polynomial d = 0;
    Polynomial submat[10][10];
    if (n == 2)
    {
        return (mat[0][0] * mat[1][1]) - (mat[1][0] * mat[0][1]);
    }
    else
    {
        for (int c = 0; c < n; c++)
        {
            int subi = 0;
            for (int i = 1; i < n; i++)
            {
                int subj = 0;
                for (int j = 0; j < n; j++)
                {
                    if (j == c)
                        continue;
                    submat[subi][subj] = mat[i][j];
                    subj++;
                }
                subi++;
            }
            Polynomial alpha;
            alpha[0] = pow(-1, c);
            d = d + (alpha * mat[0][c] * det(n - 1, submat));
        }
    }
    return d;
}