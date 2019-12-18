#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
using namespace std;

class Matrix;
class Matrix
{
private:
public:
    double data[500];

    int row, col;
    double max;
    Matrix(int row, int col)
    {
        this->row = row;
        this->col = col;
    };
    ~Matrix(){};
    double &operator()(int, int);
    double operator()(int, int) const;

    Matrix &operator=(const Matrix);
    double findMax();
    friend ostream &operator<<(ostream &, const Matrix &);
    friend Matrix operator*(const Matrix &, const Matrix &);
    friend Matrix operator-(const Matrix &, const Matrix &);
    friend Matrix operator/(Matrix &, double);
    friend Matrix operator*(const double, const Matrix &);
    Matrix &transition();
};
double &Matrix::operator()(int i, int j)
{
    return (this->data[i * this->col + j]);
}
double Matrix::operator()(int i, int j) const
{
    return (this->data[i * this->col + j]);
}
Matrix &Matrix::operator=(const Matrix A)
{
    this->row = A.row;
    this->col = A.col;
    for (int i = 0; i < A.row * A.row; i++)
    {
        this->data[i] = roundf(A.data[i] * 10000) / 10000;
    }
    return *this;
};
double Matrix::findMax()
{
    this->max = this->data[0];
    for (int i = 0; i < this->row * this->col; i++)
    {
        if (this->max < abs(this->data[i]))
        {
            this->max = this->data[i];
        }
    }
    return this->max;
}
ostream &operator<<(ostream &os, const Matrix &matrix)
{
    for (int i = 0; i < matrix.row * matrix.col; i++)

    {
        os << setw(6) << matrix.data[i];
        if ((i + 1) % matrix.col == 0)
        {
            os << endl;
        }
    }
    return os;
};
Matrix operator*(const Matrix &A, const Matrix &B)
{
    Matrix result(A.row, B.col);

    if (A.col == B.row)
    {
        for (int i = 0; i < A.row; i++)
        {
            for (int j = 0; j < B.col; j++)
            {
                result(i, j) = 0;
                for (int k = 0; k < A.col; k++)
                {
                    result(i, j) += A(i, k) * B(k, j);
                }
            }
        }
    }
    return result;
}
Matrix operator-(const Matrix &A, const Matrix &B)
{
    Matrix result(A.row, B.col);

    for (int i = 0; i < A.row; i++)
    {
        for (int j = 0; j < B.col; j++)
        {
            result(i, j) = A(i, j) - B(i, j);
        }
    }
    return result;
}
Matrix operator/(Matrix &matrix, double c)
{
    Matrix result(matrix.row, matrix.col);
    if (c != 0)
        for (int i = 0; i < matrix.row * matrix.col; i++)
        {
            result.data[i] = matrix.data[i] / c;
        }
    return result;
}
Matrix operator*(const double c, const Matrix &matrix)
{
    Matrix result(matrix.row, matrix.col);
    for (int i = 0; i < matrix.row * matrix.col; i++)
    {
        result.data[i] = matrix.data[i] * c;
    }
    return result;
}
Matrix &Matrix::transition()
{
    Matrix temp(this->row, this->col);
    temp = *this;
    int col = this->col;
    this->col = this->row;
    this->row = col;
    for (int i = 0; i < this->row; i++)
    {
        for (int j = 0; j < this->col; j++)
        {
            (*this)(i, j) = temp(i, j);
        }
    }
    return *this;
}
int main()
{
    ifstream file;

    Matrix A(1, 1);
    file.open("matrix.txt");
    file >> A.row >> A.col;
    for (int i = 0; i < A.row * A.col; i++)
    {
        file >> A.data[i];
    }
    file.close();
    cout << "A: " << endl
         << A;

    Matrix v(A.row, 1);
    for (int i = 0; i < A.row; i++)
    {
        v(i, 0) = 1;
    }
    cout << "v: " << endl
         << v;
    Matrix e(A.row, A.row);
    for (int i = 0; i < A.row; i++)
    {
        e(i, i) = 1;
    }
    cout << "e: " << endl
         << e;
    Matrix c(A.row, 1);
    double oldMax = 0;
    long count = 0;
    do
    {
        oldMax = c.findMax();
        c = A * v;
        v = c / c.findMax();
        count++;
    } while (oldMax != c.max && count < 1000);
    cout << "Tri rieng: " << endl
         << setw(6) << c.max << endl;
    cout << "Vecto rieng: " << endl
         << v << endl;
    cout << A.transition() - (c.max * e) << endl;
    return 0;
}