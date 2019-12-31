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
	//friend Polynomial operator*(const Polynomial&, double x);
	friend Polynomial operator/(const Polynomial &, const Polynomial &);
	bool empty();

private:
	Term *isExist(const int);
	int size;
	Term *start;
	Term *end;
	bool isEmpty();
	int remove(const int);
};
Polynomial A;
Polynomial B;
Polynomial C;
Polynomial R;
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

Polynomial operator*(const Polynomial &A, const Polynomial &B)
{
	Polynomial result;
	for (int i = 0; i < A.size; i++)
	{
		for (int j = 0; j < B.size; j++)
		{
			int k = i + j;
			result.set(k, result[k] + A[i] * B[j]);
		}
	}
	return result;
}

Polynomial operator/(const Polynomial &A, const Polynomial &B)
{
	int k = B.size - 1;
	Polynomial result;
	Polynomial t;
	t = A;
	for (int i = (A.size - 1); i >= B.size - 1; i--)
	{
		Polynomial tmp;
		Polynomial r;

		result.set(i - k, t[i] / B[k]);
		r.set(i - k, t[i] / B[k]);
		tmp = B * r;
		t = (t - tmp);
		t.size = t.size - 1;
	}
	R = t;
	return result;
}

istream &operator>>(istream &in, Polynomial &m)
{
	m.empty();
	cout << "    Input degree: ";
	int n;
	in >> n;
	for (int i = 0; i <= n; i++)
	{
		cout << "    x^" << i << " = ";
		double coefficicent;
		in >> coefficicent;
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
class
{
public:
	void read()
	{
		cout << "    ------------- Input from keyboard" << endl;
		cout
			<< "    Input A" << endl;
		cin >> A;
		cout << "    Input B" << endl;
		cin >> B;
	}
} consoleInput;
class
{
public:
	void read()
	{
		cout << "    ------------- Input from files" << endl;
		bool noError = true;
		noError *= readData(A, "DATA1.txt");
		noError *= readData(B, "DATA2.txt");
	}
	int readData(Polynomial &A, const char *path)
	{
		ifstream file;
		file.open(path);
		if (file.fail())
		{
			cout << "    Read the " << path
				 << " file failed!" << endl;
			return false;
		}
		double c;
		int i = 0;
		while (file >> c)
		{
			A.set(i, c);
			i++;
		}
		file.close();
		cout << "    Read the " << path << " file successfully!" << endl;
		return true;
	}

	int writeData(Polynomial &A, const char *path)
	{
		ofstream file(path);
		if (file.fail())
		{
			cout << "    Write the " << path << " file failed!";
			return false;
		}
		file << A;
		file.close();
		cout << "    Write the " << path << " file successfully!" << endl;
		return true;
	}
} fileInput;
class
{
public:
	void options()
	{
		int choose;
		do
		{
			cout << "    ------------- Operators" << endl
				 << "    0. Back" << endl
				 << "    1. +" << endl
				 << "    2. -" << endl
				 << "    3. *" << endl
				 << "    4. /" << endl
				 << "    5. Data" << endl
				 << "    Choose your option [0-5]: ";
			cin >> choose;
			switch (choose)
			{
			case 0:
				break;
			case 1:
				cout << "    ------------- A + B" << endl;
				cout << A + B;
				options();
				break;
			case 2:
				cout << "    ------------- A - B" << endl;
				cout << A - B;
				options();
				break;
			case 3:
				cout << "    ------------- A * B" << endl;
				cout << A * B;
				options();
				break;
			case 4:
				cout << "    ------------- A / B" << endl;
				cout << A / B;
				cout << "    DU: " << endl
					 << R;
				options();
				break;
			case 5:
				cout << "    ------------- Data" << endl;
				cout << "    Polynomial A" << endl
					 << A << endl
					 << "    Polynomial B" << endl
					 << B << endl;
				options();

			default:
				cout << "    Invalid option!" << endl;
				break;
			}
		} while (0 < choose && choose > 5);
	}
} solve;
class
{
public:
	void welcome()
	{
		cout << "    +-------------------------------------+" << endl
			 << "    | Chuong Trinh Tinh Tich Da Thuc      |" << endl
			 << "    +-------------------------------------+" << endl
			 << "    | Ma nhom: 18N15 - N6                 |" << endl
			 << "    | Thanh vien trong nhom:              |" << endl
			 << "    | 1. Nguyen Kim Huy - MSSV: 102180207 |" << endl
			 << "    | 2. Tran Ngoc Huy  - MSSV: 102180208 |" << endl
			 << "    +-------------------------------------+" << endl;
	}
	void options()
	{
		int choose;
		do
		{
			cout << "    ------------- Home" << endl
				 << "    0. Exit" << endl
				 << "    1. Input from files" << endl
				 << "    2. Input from keyboard" << endl
				 << "    3. Operators" << endl
				 << "    Choose your option [0-3]: ";
			cin >> choose;
			switch (choose)
			{
			case 0:
				cout << "    Goodbye!" << endl;
				break;
			case 1:
				fileInput.read();
				solve.options();
				this->options();
				break;

			case 2:
				consoleInput.read();
				solve.options();
				this->options();

				break;
			case 3:
				solve.options();
				this->options();
				break;
			default:
				cout << "    Invalid option!" << endl;
				break;
			}
		} while (choose < 0 || choose > 3);
	}
} home;

int main()
{
	home.welcome();
	home.options();

	return 0;
}
