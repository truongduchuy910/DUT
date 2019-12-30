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
	Polynomial &operator=(const Polynomial &);
	friend Polynomial operator+(const Polynomial &, const Polynomial &);
	friend Polynomial operator-(const Polynomial &, const Polynomial &);
	friend Polynomial operator*(const Polynomial &, const Polynomial &);
	friend Polynomial operator/(const Polynomial &, const Polynomial &);

private:
	Term *isExist(const int);
	int size;
	Term *start;
	Term *end;
	bool isEmpty();
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
}

bool Polynomial::isEmpty()
{
	if (this->start == NULL)
		return true;
	return false;
}

int Polynomial::set(const int degree, const double coefficicent)
{
	if (coefficicent == 0)
		return false;
	if (this->size <= degree + 1)
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
double Polynomial::operator[](int i) const
{

	Term *temp = this->start;
	while (temp != NULL && temp->degree != i)
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

// Polynomial &Polynomial::operator=(const Polynomial A)
// {
// 	return *this;
// }

// double Polynomial::operator[](int i) const
// {

// 	Term *temp = this->start;
// 	while (temp->degree != i && temp != NULL)
// 	{
// 		temp = temp->next;
// 	};
// 	if (temp == NULL)
// 		return 0;

// 	return temp->coefficicent;
// };
Polynomial operator+(const Polynomial &m, const Polynomial &n)
{
	Polynomial temp;
	int _length = (m.size > n.size) ? m.size : n.size;
	cout << "size cua da thuc tao thanh " << _length << endl;
	for (int i = 0; i < _length; i++)
	{
		temp.set(i, m[i] + n[i]);
	}
	return temp;
}
Polynomial operator-(const Polynomial &m, const Polynomial &n)
{
	Polynomial temp;
	int _length = (m.size > n.size) ? m.size : n.size;
	cout << "size cua da thuc tao thanh " << _length << endl;
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
Polynomial operator/(const Polynomial &m, const Polynomial &n)
{
	int k = n.size;
	Polynomial r;
	Polynomial result;
	Polynomial tmp;
	Polynomial t;
	t = m;

	for (int i = m.size - 1; i >= n.size - 1; i--)
	{
		result.set(i - k, t[i] / n[k]);
		r.set(i - k, result[i - k]);
		tmp = n * r;
		t = (m - tmp);
		t.size = t.size - 1;
	}
	//In ra da thuc du
	cout << "Du: " << endl;
	for (int i = 0; i < n.size - 1; i++)
	{
		cout << setw(5) << t[i];
	}
	cout << endl;
	return result;
}
istream &operator>>(istream &in, Polynomial &m)
{
	cout << "Nhap size: ";
	int n;
	in >> n;
	cout << "Nhap da thuc voi dang x1, x2, x3,.. xn: ";
	for (int i = 0; i < n; i++)
	{
		double coefficicent;
		in >> coefficicent;
		m.set(i, coefficicent);
	}
	return in;
}
ostream &operator<<(ostream &os, const Polynomial &m)
{

	cout << "xuat bac: " << m.size << endl;
	for (int i = 0; i < m.size; i++)
	{
		os << setw(5) << m[i];
	}
	return os;
}
Polynomial &Polynomial::operator=(const Polynomial &a)
{
	for (int i = 0; i < a.size; i++)

		this->set(i, a[i]);
};
// int readData(Polynomial &A, const char *path)
// {
// 	ifstream file;
// 	file.open(path);
// 	if (file.fail())
// 	{
// 		cout << "Doc file " << path
// 			 << " that bai!" << endl;
// 		return 0; //fail
// 	}
// 	file >> A;
// 	file.close();
// 	cout << "Doc file " << path << " thanh cong!" << endl;
// 	return 1; //success
// }

// int writeData(Polynomial &A, const char *path)
// {
// 	ofstream file(path);
// 	if (file.fail())
// 	{
// 		cout << "ghi file " << path << " that bai!";
// 		return 0; //fail
// 	}
// 	file << A;
// 	file.close();
// 	cout << "Ghi file " << path << " thanh cong!" << endl;
// 	return 1; //success
// }

// class
// {
// public:
// 	void welcome()
// 	{
// 		cout << "+-------------------------------------+" << endl
// 			 << "| Chuong Trinh Tinh Tich Da Thuc      |" << endl
// 			 << "+-------------------------------------+" << endl
// 			 << "| Ma nhom: 18N15 - N6                 |" << endl
// 			 << "| Thanh vien trong nhom:              |" << endl
// 			 << "| 1. Nguyen Kim Huy - MSSV: 102180207 |" << endl
// 			 << "| 2. Tran Ngoc Huy  - MSSV: 102180208 |" << endl
// 			 << "+-------------------------------------+" << endl;
// 	}
// 	void home()
// 	{
// 		int option;
// 		do
// 		{
// 			cout << "0. Thoat chuong trinh" << endl
// 				 << "1. Doc du lieu tu file" << endl
// 				 << "2. Nhap du lieu tu ban phim" << endl
// 				 << "Nhap lua chon: ";

// 			cin >> option;
// 		} while (option < 0 || option > 2);
// 		cout << "---------------------------------------" << endl;

// 		switch (option)
// 		{
// 		case 1:
// 		{
// 			fileInput();
// 			home();
// 			break;
// 		}
// 		case 2:
// 		{
// 			consoleInput();
// 			home();
// 			break;
// 		}
// 		}
// 	}
// 	void fileInput()
// 	{
// 		cout << "He so cua duoc nhap theo so mu tu 0 den n" << endl;
// 		Polynomial P, Q, R;
// 		bool noError = true;
// 		noError *= readData(P, "DATA1.txt");
// 		noError *= readData(Q, "DATA2.txt");
// 		R = P * Q;
// 		noError *= writeData(R, "DATA3.txt");
// 		if (noError)
// 			cout << "He so P(x): " << endl
// 				 << P << endl
// 				 << "He so Q(x): " << endl
// 				 << Q << endl
// 				 << "He so tich R(x) = P(x) * Q(x): " << endl
// 				 << R << endl
// 				 << "---------------------------------------" << endl;
// 	}
// 	void consoleInput()
// 	{
// 		cout << "Nhap size P(x) va Q(x)" << endl
// 			 << "Nhap he so theo so mu tu 0 den n " << endl
// 			 << "Vi du: P(x) = 2 + 3*x - 5.5*x^3 | size: 3, he so: 2 3 0 -5.5" << endl;
// 		int size;
// 		cout << "Nhap size P(x): " << endl;
// 		cin >> size;
// 		Polynomial P(size + 1);
// 		cout << "Nhap cac he so: " << endl;
// 		cin >> P;
// 		cout << "Nhap size Q(x): " << endl;
// 		cin >> size;
// 		Polynomial Q(size + 1);
// 		cout << "Nhap cac he so: " << endl;
// 		cin >> Q;
// 		Polynomial R(P.size + Q.size - 1);
// 		R = P * Q;
// 		cout << endl
// 			 << "Ket qua: " << endl
// 			 << "He so P(x): " << endl
// 			 << P << endl
// 			 << "He so Q(x): " << endl
// 			 << Q << endl
// 			 << "He so tich R(x) = P(x) * Q(x):" << endl
// 			 << R << endl
// 			 << "---------------------------------------" << endl;
// 	}
// } controllers;
int main()
{
	Polynomial A;
	Polynomial B;
	Polynomial C;
	cin >> A >> B;
	cout << A << endl;
	cout << B << endl;
	C = A + B;
	cout << C << endl;
	C = A - B;
	cout << C << endl;
	C = A * B;
	cout << C << endl;
	C = A / B;
	cout << C << endl;
	return 0;
}
