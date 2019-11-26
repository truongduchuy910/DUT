#include <iostream>
using namespace std;
template <class Data, int max>
class Array
{
private:
    Array *next;
    Data data;
    int length;

public:
    Array() { this->length = 0; };
    Array(const Array &);
    ~Array(){};
    Array &operator=(Array);
    Array &operator+=(Array &);
    Array &operator-=(Array &);
    Data &operator[](int);
    //Đoạn này khó giải thích vl
    template <class DataOperater, int maxOperater>
    friend Array<DataOperater, maxOperater> operator+(Array<DataOperater, maxOperater> &, Array<DataOperater, maxOperater> &);
    template <class DataOperater, int maxOperater>
    friend Array<DataOperater, maxOperater> operator-(Array<DataOperater, maxOperater> &, Array<DataOperater, maxOperater> &);
    template <class DataOperater, int maxOperater>
    friend ostream &operator<<(ostream &, Array<DataOperater, maxOperater> &);
    template <class DataOperater, int maxOperater>
    friend istream &operator>>(istream &, Array<DataOperater, maxOperater> &);
};
template <class Data, int max>
Data &Array::operator[](int i){};

template <class Data, int max>
Array<Data, max>::Array(const Array<Data, max> &A)
{
    this->length = A.length;
    for (int i = 0; i < A.length; i++)
    {
        this->data[i] = A.data[i];
    }
};
template <class Data, int max>
Array<Data, max> &Array<Data, max>::operator=(Array<Data, max> A)
{
    this->length = A.length;
    for (int i = 0; i < A.length; i++)
    {
        this->data[i] = A.data[i];
    }

    return *this;
};
template <class Data, int max>
Array<Data, max> &Array<Data, max>::operator+=(Array<Data, max> &A)
{
    Array<Data, max> temp;

    for (int i = 0; i < A.length; i++)
    {
        bool check = true;
        for (int j = 0; j < temp.length; j++)
        {
            if (A.data[i] == temp.data[j])
            {
                check = false;
            }
        }
        if (check)
        {
            temp.data[temp.length] = A.data[i];
            temp.length++;
        }
    }

    *this = temp;
    return *this;
};
template <class Data, int max>
Array<Data, max> &Array<Data, max>::operator-=(Array<Data, max> &A)
{
    Array<Data, max> temp;
    for (int i = 0; i < this->length; i++)
    {
        bool check = true;
        for (int j = 0; j < A.length; j++)
        {
            if (this->data[i] == A.data[j])
            {
                check = false;
            }
        }
        if (check)
        {
            temp.data[temp.length] = this->data[i];
            temp.length++;
        }
    }
    *this = temp;
    return *this;
};
template <class Data, int max>
Array<Data, max> operator-(Array<Data, max> &A, Array<Data, max> &B)
{
    Array<Data, max> temp;
    for (int i = 0; i < A.length; i++)
    {
        bool check = true;
        for (int j = 0; j < B.length; j++)
        {
            if (A.data[i] == B.data[j])
            {
                check = false;
            }
        }
        if (check)
        {
            temp.data[temp.length] = A.data[i];
            temp.length++;
        }
    }
    return temp;
};
template <class Data, int max>
Array<Data, max> operator+(Array<Data, max> &A, Array<Data, max> &B)
{
    Array<Data, max> temp;

    for (int i = 0; i < A.length; i++)
    {
        bool check = true;
        for (int j = 0; j < temp.length; j++)
        {
            if (A.data[i] == temp.data[j])
            {
                check = false;
            }
        }
        if (check)
        {
            temp.data[temp.length] = A.data[i];
            temp.length++;
        }
    }
    for (int i = 0; i < B.length; i++)
    {
        bool check = true;
        for (int j = 0; j < temp.length; j++)
        {
            if (B.data[i] == temp.data[j])
            {
                check = false;
            }
        }
        if (check)
        {
            temp.data[temp.length] = B.data[i];
            temp.length++;
        }
    }
    return temp;
};
template <class Data, int max>
ostream &operator<<(ostream &os, Array<Data, max> &A)
{
    for (int i = 0; i < A.length; i++)
    {
        os << A.data[i] << " ";
    }
    os << " co " << A.length << " phan tu";
    return os;
};
template <class Data, int max>
istream &operator>>(istream &is, Array<Data, max> &A)
{
    is >> A.data[A.length];
    A.length++;
    return is;
};
int main()
{
    Array<int, 50> a;
    cout << "Nhap so phan tu: ";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "]= ";
        cin >> a;
    }
    cout << "a: " << a << endl;
    Array<int, 50> b(a);
    cout << "b: " << b << endl;

    Array<int, 50> c;
    c = a;
    c[1] = 9;
    cout << "c: " << c << endl;

    a += b;
    cout << "a+=b: " << a << endl;
    a -= c;
    cout << "a-=c: " << a << endl;
    a = b - c;
    cout << "a = b - c: " << a << endl;
    a = b + c;
    cout << "a = b + c: " << a << endl;
}
