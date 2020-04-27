#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
class Polynomial;
class Term;
class Term
{
public:
    Term(const int, const double);
    friend class Polynomial;

private:
    int degree;
    double coefficicent;
    Term *next;
};

Term::Term(const int degree, const double coefficicent) : degree(degree), coefficicent(coefficicent)
{
    this->next = NULL;
}
class Polynomial
{
public:
    Polynomial();
    ~Polynomial();
    bool set(const int, const double);
    double operator[](int) const;
    int getSize() const;
    Polynomial &operator=(const Polynomial &);

    friend ostream &operator<<(ostream &, const Polynomial &);
    friend istream &operator>>(istream &, Polynomial &);

    friend Polynomial operator+(const Polynomial &, const Polynomial &);
    friend Polynomial operator-(const Polynomial &, const Polynomial &);
    friend Polynomial operator*(const Polynomial &, const Polynomial &);
    friend Polynomial operator/(const Polynomial &, const Polynomial &);
    friend Polynomial operator%(const Polynomial &, const Polynomial &);

private:
    int size;
    Term *position(const int);
    Term *start;
    bool isEmpty();
};
Polynomial::Polynomial()
{
    start = NULL;
    size = 0;
}

Polynomial::~Polynomial()
{
    Term *tmp;
    while (this->start)
    {
        tmp = this->start->next;
        //    cout << "[DEBUG] delete " << this->start << endl;
        delete this->start;
        this->start = tmp;
    }
    size = 0;
}

bool Polynomial::isEmpty()
{
    if (this->start)
        return false;
    return true;
}

bool Polynomial::set(const int degree, const double coefficicent)
{
    Term *tmp = position(degree);
    if (coefficicent == 0 && tmp)
    {
        Term *needDelete = tmp;
        tmp = this->start;
        if (tmp == needDelete)
        {
            this->start = this->start->next;
            delete needDelete;
            return true;
        }
        while (tmp->next != needDelete)
            tmp = tmp->next;
        tmp->next = needDelete->next;
        delete needDelete;
        if (degree == size - 1)
            size--;
        return true;
    }
    if (degree >= size)
        size = degree + 1;
    if (tmp)
    {
        tmp->coefficicent = coefficicent;
        tmp->degree = degree;
        return true;
    }
    Term *needInsert = new Term(degree, coefficicent);
    tmp = this->start;
    if (tmp)
    {
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = needInsert;
        return true;
    }
    this->start = needInsert;

    return true;
}
double Polynomial::operator[](int degree) const
{
    Term *tmp = this->start;
    while (tmp != NULL && tmp->degree != degree)
        tmp = tmp->next;
    if (tmp)
        return tmp->coefficicent;
    return 0;
};
int Polynomial::getSize() const
{
    return this->size;
}

Term *Polynomial::position(const int degree)
{
    Term *tmp = this->start;
    while (tmp != NULL && degree != tmp->degree)
        tmp = tmp->next;

    if (tmp)
        return tmp;

    return NULL;
}

Polynomial operator+(const Polynomial &m, const Polynomial &n)
{
    Polynomial tmp;
    int _length = (m.getSize() >= n.getSize()) ? m.getSize() : n.getSize();
    for (int i = 0; i < _length; i++)
    {
        tmp.set(i, m[i] + n[i]);
    }
    return tmp;
}
Polynomial operator-(const Polynomial &m, const Polynomial &n)
{
    Polynomial tmp;
    int _length = (m.getSize() >= n.getSize()) ? m.getSize() : n.getSize();
    for (int i = 0; i < _length; i++)
    {
        tmp.set(i, m[i] - n[i]);
    }
    return tmp;
}

Polynomial operator*(const Polynomial &a, const Polynomial &b)
{
    Polynomial result;
    for (int i = 0; i < a.getSize(); i++)
    {
        for (int j = 0; j < b.getSize(); j++)
        {
            int k = i + j;
            result.set(k, result[k] + a[i] * b[j]);
        }
    }
    return result;
}

Polynomial operator/(const Polynomial &dividend, const Polynomial &divisor)
{
    int k = divisor.getSize() - 1;
    Polynomial quotient;
    Polynomial remainder;
    Polynomial q;
    Polynomial tmp;
    remainder = dividend;
    for (int i = (dividend.getSize() - 1); i >= divisor.getSize() - 1; i--)
    {
        q.~Polynomial();
        tmp.~Polynomial();
        quotient.set(i - k, remainder[i] / divisor[k]);
        q.set(i - k, remainder[i] / divisor[k]);
        tmp = divisor * q;
        remainder = (remainder - tmp);
    }
    return quotient;
}

Polynomial operator%(const Polynomial &dividend, const Polynomial &divisor)
{
    int k = divisor.getSize() - 1;
    Polynomial remainder;
    Polynomial q;
    Polynomial tmp;
    remainder = dividend;
    for (int i = (dividend.getSize() - 1); i >= divisor.getSize() - 1; i--)
    {
        q.~Polynomial();
        tmp.~Polynomial();
        q.set(i - k, remainder[i] / divisor[k]);
        tmp = divisor * q;
        remainder = (remainder - tmp);
    }
    return remainder;
}
istream &operator>>(istream &in, Polynomial &m)
{
    m.~Polynomial();
    cout << "    Degree: ";
    int n;
    in >> n;
    double coefficicent;

    for (int i = 0; i <= n; i++)
    {
        cout << "    x^" << i << " <- ";
        in >> coefficicent;
        m.set(i, coefficicent);
    }

    return in;
}
ostream &operator<<(ostream &os, const Polynomial &m)
{
    os << "    x^";
    for (int i = 0; i < m.getSize(); i++)
    {
        os << setw(5) << i;
    }
    os << endl;
    os << "     =";

    for (int i = 0; i < m.getSize(); i++)
    {
        os << setw(5) << m[i];
    }
    os << endl;

    return os;
}
Polynomial &Polynomial::operator=(const Polynomial &a)
{
    this->~Polynomial();
    for (int i = 0; i < a.getSize(); i++)
        this->set(i, a[i]);
    return *this;
};