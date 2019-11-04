#include <iostream>
#include <math.h>
using namespace std;
int length(const long &a)
{
    int count = 1;
    int temp = a / 10;
    while (temp != 0)
    {
        count++;
        temp = temp / 10;
    }

    return count;
};
long getLeftRight(const long &a, long &left, long &right)
{
    int n = length(a);
    int m = pow(10, n / 2 + n % 2);
    left = a / m;
    right = a - (left * m);
}
long karatsuba(long &a, long &b)
{

    int n = length(a);
    if (n == 1)
    {
        return a * b;
    }
    else
    {
        long aLeft, aRight, bLeft, bRight;
        getLeftRight(a, aLeft, aRight);
        getLeftRight(b, bLeft, bRight);
        long p = karatsuba(aLeft, bLeft);
        long q = karatsuba(aRight, bRight);
        long A = aLeft + aRight, B = bLeft + bRight;
        long r = karatsuba(A, B);
        return (p * pow(10, n) + (r - p - q) * pow(10, n / 2) + q);
    }
}
int main()
{
    long a = 2222, b = 1111;
    cout << karatsuba(a, b) << endl;
}