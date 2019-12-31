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
    Polynomial(Polynomial &);
    ~Polynomial();
    int set(const int, const double);
    double operator[](int) const;
    friend ostream &operator<<(ostream &, const Polynomial &);
    friend istream &operator>>(istream &, const Polynomial &);
    Polynomial &operator=(const Polynomial &);
    friend Polynomial operator+(const Polynomial &, const Polynomial &);
    friend Polynomial operator-(const Polynomial &, const Polynomial &);
    friend Polynomial operator*(const Polynomial &, const Polynomial &);
    friend Polynomial operator/(const Polynomial &, const Polynomial &);
    friend Polynomial operator%(const Polynomial &, const Polynomial &);
    bool empty();
    int size;

private:
    Term *isExist(const int);
    Term *start;
    Term *end;
    bool isEmpty();
    int remove(const int);
};
Polynomial::Polynomial()
{
    start = NULL;
    end = NULL;
    size = 0;
}
Polynomial::Polynomial(Polynomial &a)
{
    this->size = 0;
    for (int i = 0; i < a.size; i++)
    {
        this->set(i, a[i]);
    }
};

Polynomial::~Polynomial()
{
    if (!this->isEmpty())
    {
        Term *currentTerm = this->start;
        Term *temp;
        while (currentTerm != NULL)
        {
            temp = currentTerm;
            currentTerm = currentTerm->next;
            delete temp;
        }
    }
    this->size = 0;
    this->start = NULL;
    this->end = NULL;
}

bool Polynomial::isEmpty()
{
    if (this->start == NULL)
        return true;
    return false;
}
bool Polynomial::empty()
{
    this->~Polynomial();

    return true;
}
int Polynomial::remove(const int degree)
{
    if (this->isEmpty())
        return false;
    Term *current = this->start;
    Term *previous = NULL;
    while (current != NULL && current->degree != degree)
    {
        previous = current;
        current = current->next;
    }
    if (current == NULL)
        return false;
    if (previous)
        previous->next = current->next;
    else
        this->start = current->next;
    if (current->next == NULL)
        this->end = previous;
    delete current;
    return true;
};
int Polynomial::set(const int degree, const double coefficicent)
{
    if (coefficicent == 0)
    {
        this->remove(degree);
        return false;
    }
    if (this->size < degree + 1)
        this->size = degree + 1;
    Term *newTerm = this->isExist(degree);
    if (newTerm)
    {
        newTerm->coefficicent = coefficicent;
    }
    else
    {
        newTerm = new Term(degree, coefficicent);
        if (isEmpty())
        {
            start = newTerm;
            end = newTerm;
        }
        else
        {
            end->next = newTerm;
            end = newTerm;
        }
    }

    return true;
}
double Polynomial::operator[](int degree) const
{

    Term *temp = this->start;
    while (temp != NULL && temp->degree != degree)
    {
        temp = temp->next;
    }
    if (temp)
        return temp->coefficicent;
    return 0;
};

Term *Polynomial::isExist(const int degree)
{
    Term *temp = this->start;
    while (temp != NULL && degree != temp->degree)
        temp = temp->next;

    if (temp)
        return temp;

    return NULL;
}

Polynomial operator+(const Polynomial &m, const Polynomial &n)
{
    Polynomial temp;
    int _length = (m.size >= n.size) ? m.size : n.size;
    for (int i = 0; i < _length; i++)
    {
        temp.set(i, m[i] + n[i]);
    }
    return temp;
}
Polynomial operator-(const Polynomial &m, const Polynomial &n)
{
    Polynomial temp;
    int _length = (m.size >= n.size) ? m.size : n.size;
    for (int i = 0; i < _length; i++)
    {
        temp.set(i, m[i] - n[i]);
    }
    return temp;
}

Polynomial operator*(const Polynomial &a, const Polynomial &b)
{
    Polynomial result;
    for (int i = 0; i < a.size; i++)
    {
        for (int j = 0; j < b.size; j++)
        {
            int k = i + j;
            result.set(k, result[k] + a[i] * b[j]);
        }
    }
    return result;
}

Polynomial operator/(const Polynomial &a, const Polynomial &b)
{
    int k = b.size - 1;
    Polynomial result;
    Polynomial t;
    t = a;
    for (int i = (a.size - 1); i >= b.size - 1; i--)
    {
        Polynomial tmp;
        Polynomial r;

        result.set(i - k, t[i] / b[k]);
        r.set(i - k, t[i] / b[k]);
        tmp = b * r;
        t = (t - tmp);
        t.size = t.size - 1;
    }
    return result;
}

Polynomial operator%(const Polynomial &a, const Polynomial &b)
{
    int k = b.size - 1;
    Polynomial result;
    Polynomial t;
    t = a;
    for (int i = (a.size - 1); i >= b.size - 1; i--)
    {
        Polynomial tmp;
        Polynomial r;

        result.set(i - k, t[i] / b[k]);
        r.set(i - k, t[i] / b[k]);
        tmp = b * r;
        t = (t - tmp);
        t.size = t.size - 1;
    }
    return t;
}
istream &operator>>(istream &in, Polynomial &m)
{
    m.empty();
    int n;
    do
    {
        in.clear();
        in.ignore();
        cout << "    Input degree: ";
        in >> n;

    } while (in.fail());

    for (int i = 0; i <= n; i++)
    {

        double coefficicent;
        do
        {
            in.clear();
            in.ignore();
            cout << "    x^" << i << " = ";
            in >> coefficicent;
        } while (in.fail());
        m.set(i, coefficicent);
    }
    return in;
}
ostream &operator<<(ostream &os, const Polynomial &m)
{
    cout << "    degree:       ";
    for (int i = 0; i < m.size; i++)
    {
        os << setw(5) << i;
    }
    cout << endl
         << setw(10) << "    coefficicent: ";

    for (int i = 0; i < m.size; i++)
    {
        os << setw(5) << m[i];
    }
    cout << endl;
    return os;
}
Polynomial &Polynomial::operator=(const Polynomial &a)
{
    this->empty();
    if (a.size == 0)
    {
        this->size = 0;
        this->start = NULL;
        return *this;
    }
    for (int i = 0; i < a.size; i++)
        this->set(i, a[i]);
    return *this;
};