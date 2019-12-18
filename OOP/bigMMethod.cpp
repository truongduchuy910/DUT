#include <iostream>
#include <iomanip>
#include <fstream>
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
        for (int i = 0; i < 200; i++)
        {
            data[i] = 0;
        }
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
        os << setw(10) << matrix.data[i];
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
void nhanHang(Matrix &matrix, const int row, const double c)
{
    for (int j = 0; j < matrix.col; j++)
    {
        matrix(row, j) *= c;
    }
}
void chiaHang(Matrix &matrix, const int row, const double c)
{
    for (int j = 0; j < matrix.col; j++)
    {
        matrix(row, j) /= c;
    }
}
void chiaCot(Matrix &matrix, const int col, const double c)
{
    for (int i = 0; i < matrix.row; i++)
    {
        matrix(i, col) /= c;
    }
}
void print(Matrix &matrix)
{
    for (int i = 0; i < matrix.row; i++)
    {
        for (int j = 0; j < matrix.col; j++)
        {
            cout << setw(10) << matrix(i, j);
        }
        cout << endl;
    }
}
int minRow(Matrix &matrix, const int row)
{
    double min = matrix(row, 0);
    int pivot = 0;
    for (int j = 0; j < matrix.col; j++)
    {
        if (matrix(row, j) < min)
        {
            min = matrix(row, j);
            pivot = j;
        }
    }
    return pivot;
}
int minCol(Matrix &matrix, const int col)
{
    double min = matrix(0, col);
    int pivot = 0;
    for (int i = 0; i < matrix.row; i++)
    {
        if (matrix(i, col) < min)
        {
            min = matrix(i, col);
            pivot = i;
        }
    }
    return pivot;
}
bool luonDuong(Matrix &matrix)
{
    for (int i = 0; i < matrix.row; i++)
    {
        for (int j = 0; j < matrix.col; j++)
        {
            if (matrix(i, j) < 0)
            {
                return false;
            }
        }
    }
    return true;
}
double M = 9999;
int main()

{
    ifstream file;
    file.open("input.txt");
    //------------------------------
    int n;
    file >> n;
    //------------------------------
    Matrix cj(1, n);
    for (int j = 0; j < n; j++)
    {
        file >> cj(0, j);
    }
    //------------------------------
    int m;
    file >> m;
    //------------------------------
    Matrix f(m, n + m * 2);
    Matrix cb(n, 1);
    Matrix bv(n, 1);
    Matrix solution(m, 1);
    Matrix lambda(m, 1);
    Matrix sign(n, 1);

    Matrix delta(1, n + m * 2);

    //------------------------------
    for (int i = 0; i < m; i++)
    {
        file >> sign(i, 0);
        file >> solution(i, 0);

        // NHAP
        for (int j = 0; j < n; j++)
        {
            file >> f(i, j);
        }

        //CHUAN HOA
        if (solution(i, 0) < 0)
        {
            nhanHang(f, i, -1);
            if (sign(i, 0) == 1)
            {
                sign(i, 0) = -1;
            }
            else
            {
                sign(i, 0) = 1;
            }
        }

        //THEM BIEN
        switch ((int)sign(i, 0))
        {
        case 1:
            //S
            f(i, n + i) = -1;
            //A
            f(i, n + m + i) = 1;
            cj(0, n + m + i) = M;
            cb(i, 0) = M;
            break;
        case -1:
            //S
            f(i, n + i) = 1;
            //A
            f(i, n + m + i) = 0;
            cj(0, n + i) = 0;
            cb(i, 0) = 0;
            break;
        case 0:
            //S
            f(i, n + i) = 0;
            //A
            f(i, n + m + i) = 1;
            cj(0, n + i) = M;
            cb(i, 0) = M;
            break;
        }
    }
    int count = 0;
    do
    {

        //delta
        for (int j = 0; j < n + 2 * m; j++)
        {
            delta(0, j) = 0;
            for (int i = 0; i < m; i++)
            {
                delta(0, j) += cb(i, 0) * f(i, j);
            }
            delta(0, j) = cj(0, j) - delta(0, j);
        }
        count++;
        if (luonDuong(delta))
        {
            break;
        }

        //minDelta
        int pivotY = minRow(delta, 0);

        //lambda
        for (int i = 0; i < m; i++)
        {
            lambda(i, 0) = solution(i, 0) / f(i, pivotY);
        }

        //min lambda
        int pivotX = minCol(lambda, 0);

        //remove AM
        f(pivotX, n + m + pivotX) = 0;

        //pivot
        double pivot = f(pivotX, pivotY);

        //solution of row pivot
        solution(pivotX, 0) = solution(pivotX, 0) / pivot;

        cb(pivotX, 0) = cj(0, pivotY);
        bv(pivotX, 0) = pivotY;
        chiaHang(f, pivotX, pivot);

        for (int i = 0; i < m; i++)
        {
            if (i != pivotX)
            {
                double key = f(i, pivotY);

                solution(i, 0) = solution(i, 0) - key * solution(pivotX, 0);
                for (int j = 0; j < n + m * 2; j++)
                {
                    f(i, j) = f(i, j) - key * f(pivotX, j);
                }
            }
        }

        //delta
        for (int j = 0; j < n + 2 * m; j++)
        {
            delta(0, j) = 0;
            for (int i = 0; i < m; i++)
            {
                delta(0, j) += cb(i, 0) * f(i, j);
            }
            delta(0, j) = cj(0, j) - delta(0, j);
        }

    } while (count < 10);
    double minz = 0;
    for (int i = 0; i < n; i++)
    {
        cout << "x[" << bv(i, 0) << "]= " << solution(i, 0) << endl;
        minz += cb(i, 0) * solution(i, 0);
    }
    cout << "min(z) = " << minz << endl;

    file.close();

    return 0;
}