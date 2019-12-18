#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
class Matrix
{
public:
    Matrix();
    double data[1000];
    int size = 3;
    double &operator()(int, int);
    friend istream &operator>>(istream &, Matrix &);
    friend ostream &operator<<(ostream &, Matrix &);
};
Matrix::Matrix(){};
istream &operator>>(istream &is, Matrix &A)
{
    for (int i = 0; i < A.size * A.size; i++)
    {
        is >> A.data[i];
    }
    return is;
};
ostream &operator<<(ostream &os, Matrix &A)
{
    for (int i = 0; i < A.size * A.size; i++)
    {
        os << setw(9) << A.data[i];
        if ((i + 1) % A.size == 0)
        {
            os << endl;
        }
    }
    return os;
};
double &Matrix::operator()(int i, int j)
{

    return this->data[i * this->size + j];
}
int jacobi(Matrix &A, Matrix &e, Matrix &E)
{

    int changed, rotations = 0;
    int i;
    for (i = 0; i < A.size; i++)
    {
        e(0, i) = A(i, i);
    }
    Matrix V;
    do
    {
        changed = 0;
        int p, q;
        for (p = 0; p < A.size; p++)
        {
            for (q = p + 1; q < A.size; q++)
            {
                cout << e << endl;

                double app = e(0, p);
                double aqq = e(0, q);
                double apq = A(p, q);
                double phi = 0.5 * atan2(2 * apq, aqq - app);
                double c = cos(phi);
                double s = sin(phi);

                double app1 = c * c * app - 2 * s * c * apq + s * s * aqq;
                double aqq1 = s * s * app + 2 * s * c * apq + c * c * aqq;
                if (app1 != app || aqq1 != aqq)
                {
                    changed = 1;
                    rotations++;
                    e(0, p) = app1;
                    e(0, q) = aqq1;
                    A(p, q) = 0.0;
                    for (i = 0; i < p; i++)
                    {
                        double aip = A(i, p);
                        double aiq = A(i, q);
                        A(i, p) = c * aip - s * aiq;
                        A(i, q) = c * aiq + s * aip;
                    }
                    for (i = p + 1; i < q; i++)
                    {
                        double api = A(p, i);
                        double aiq = A(i, q);
                        A(p, i) = c * api - s * aiq;
                        A(i, q) = c * aiq + s * api;
                    }
                    for (i = q + 1; i < A.size; i++)
                    {
                        double api = A(p, i);
                        double aqi = A(q, i);
                        A(p, i) = c * api - s * aqi;
                        A(q, i) = c * aqi + s * api;
                    }
                    for (i = 0; i < A.size; i++)
                    {
                        double vip = V(i, p);
                        double viq = V(i, q);
                        V(i, p) = c * vip - s * viq;
                        V(i, q) = c * viq + s * vip;
                    }
                }
            }
        }
    } while (changed != 0);
    return rotations;
}

int main()
{
    Matrix A;
    Matrix e;
    Matrix E;
    cin >> A;
    cout << jacobi(A, e, E) << endl;
    cout << e << endl;

    return 0;
}
