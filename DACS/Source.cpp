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
	//friend Polynomial operator*(const Polynomial&, double x);
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
	Polynomial r;
	Polynomial result;
	Polynomial tmp;
	Polynomial t;
	t = A;
	for (int i = (A.size - 1); i >= B.size - 1; i--)
	{
		result.set(i - k, t[i] / B[k]);
		r.set(i - k, t[i] / B[k]);
		tmp = B * r;
		t = (t - tmp);
		t.size = t.size - 1;
		r.size = r.size - 1;
	}
	return result;
}
istream &operator>>(istream &in, Polynomial &m)
{
	cout << "Nhap bac: ";
	int n;
	in >> n;
	cout << "Nhap da thuc voi dang x0, x1, x2,.. xn: ";
	for (int i = 0; i <= n; i++)
	{
		double coefficicent;
		in >> coefficicent;
		m.set(i, coefficicent);
	}
	return in;
}
ostream &operator<<(ostream &os, const Polynomial &m)
{
	cout << setw(7) << "so mu: ";
	for (int i = 0; i < m.size; i++)
	{
		os << setw(5) << i;
	}
	cout << endl
		 << setw(7) << "he so: ";

	for (int i = 0; i < m.size; i++)
	{
		os << setw(5) << m[i];
	}
	cout << endl;
	return os;
}
Polynomial &Polynomial::operator=(const Polynomial &a)
{
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

Polynomial A;
Polynomial B;
Polynomial C;
class
{
public:
	void views()
	{
		cout << "Nhap da thuc A" << endl;
		cin >> A;
		cout << "Nhap da thuc B" << endl;
		cin >> B;
	}
} consoleInput;
class
{
public:
	void options()
	{
		cout << "Chon toan tu" << endl
			 << "0. tro ve" << endl
			 << "1. +" << endl
			 << "2. -" << endl
			 << "3. *" << endl
			 << "4. /" << endl
			 << "5. data" << endl
			 << "Chon so ban muon [1-4]: ";
		int choose;
		cin >> choose;
		cout << "ket qua: " << endl;
		switch (choose)
		{
		case 0:
			break;
		case 1:
			cout << A + B;
			options();
			break;
		case 2:
			cout << A - B;
			options();
			break;
		case 3:
			cout << A * B;
			options();
			break;
		case 4:
			cout << A / B;
			options();
			break;
		case 5:
			cout << A << endl
				 << B << endl;
			options();

		default:
			break;
		}
	}
} solve;
class
{
public:
	void views()
	{
		cout << "+-------------------------------------+" << endl
			 << "| Chuong Trinh Tinh Tich Da Thuc      |" << endl
			 << "+-------------------------------------+" << endl
			 << "| Ma nhom: 18N15 - N6                 |" << endl
			 << "| Thanh vien trong nhom:              |" << endl
			 << "| 1. Nguyen Kim Huy - MSSV: 102180207 |" << endl
			 << "| 2. Tran Ngoc Huy  - MSSV: 102180208 |" << endl
			 << "+-------------------------------------+" << endl;
	}
	void options()
	{
		int choose;
		do
		{
			cout << "0. Thoat chuong trinh" << endl
				 << "1. Doc du lieu tu file" << endl
				 << "2. Nhap du lieu tu ban phim" << endl
				 << "3. Thuc hien toan tu" << endl
				 << "Nhap lua chon: ";

			cin >> choose;
		} while (choose < 0 || choose > 3);
		cout << "---------------------------------------" << endl;

		switch (choose)
		{
		case 1:
			break;

		case 2:
			consoleInput.views();
			solve.options();
			this->options();
			break;
		case 3:
			solve.options();
			break;
		}
	}
	// void fileInput()
	// {
	// 	cout << "He so cua duoc nhap theo so mu tu 0 den n" << endl;
	// 	Polynomial P, Q, R;
	// 	bool noError = true;
	// 	noError *= readData(P, "DATA1.txt");
	// 	noError *= readData(Q, "DATA2.txt");
	// 	R = P * Q;
	// 	noError *= writeData(R, "DATA3.txt");
	// 	if (noError)
	// 		cout << "He so P(x): " << endl
	// 			 << P << endl
	// 			 << "He so Q(x): " << endl
	// 			 << Q << endl
	// 			 << "He so tich R(x) = P(x) * Q(x): " << endl
	// 			 << R << endl
	// 			 << "---------------------------------------" << endl;
	// }
	// void consoleInput()
	// {
	// 	cout << "Nhap size P(x) va Q(x)" << endl
	// 		 << "Nhap he so theo so mu tu 0 den n " << endl
	// 		 << "Vi du: P(x) = 2 + 3*x - 5.5*x^3 | size: 3, he so: 2 3 0 -5.5" << endl;
	// 	int size;
	// 	cout << "Nhap size P(x): " << endl;
	// 	cin >> size;
	// 	Polynomial P(size + 1);
	// 	cout << "Nhap cac he so: " << endl;
	// 	cin >> P;
	// 	cout << "Nhap size Q(x): " << endl;
	// 	cin >> size;
	// 	Polynomial Q(size + 1);
	// 	cout << "Nhap cac he so: " << endl;
	// 	cin >> Q;
	// 	Polynomial R(P.size + Q.size - 1);
	// 	R = P * Q;
	// 	cout << endl
	// 		 << "Ket qua: " << endl
	// 		 << "He so P(x): " << endl
	// 		 << P << endl
	// 		 << "He so Q(x): " << endl
	// 		 << Q << endl
	// 		 << "He so tich R(x) = P(x) * Q(x):" << endl
	// 		 << R << endl
	// 		 << "---------------------------------------" << endl;
	// }
} home;
int main()
{
	home.views();
	home.options();
	return 0;
}
