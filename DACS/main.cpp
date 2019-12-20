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
	friend istream &operator>>(istream &, const Term &);
	friend ostream &operator<<(ostream &, const Term &);
	friend class Polynomial;

private:
	int degree;
	double coefficicent;
	Term *next;
};

Term::Term(const int degree = 0, const double coefficicent = 0) : degree(degree), coefficicent(coefficicent)
{
	this->next = NULL;
}
istream &operator>>(istream &is, const Term &term){};
ostream &operator<<(ostream &os, const Term &term)
{
	os << "x[" << term.degree << "]= " << term.coefficicent;
	return os;
};

class Polynomial
{
public:
	int length;
	Polynomial();
	~Polynomial();
	int set(const int, const double);
	Term *isExist(const int);
	Polynomial &operator=(const Polynomial &);
	Term operator[](int) const;

private:
	Term *start;
	Term *end;
	bool isEmpty();
};
Polynomial::Polynomial()
{
	start = NULL;
	end = NULL;
	length = 0;
}

Polynomial::~Polynomial()
{
	if (!isEmpty())
	{
		Term *currentTerm = start;
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
	if (start == NULL)
		return 1;
	else
		return 0;
}

int Polynomial::set(const int degree, const double x)
{
	if (x == 0)
	{
		return false;
	}
	Term *newTerm = this->isExist(degree);
	if (newTerm)
	{
		newTerm->coefficicent = x;
	}
	else
	{
		newTerm = new Term(degree, x);
		if (isEmpty())
		{
			start = newTerm;
			end = newTerm;
			this->length++;
			return true;
		}
		else
		{
			end->next = newTerm;
			end = newTerm;
			this->length++;
			return true;
		}
	}

	return false;
}
Term *Polynomial::isExist(const int degree)
{
	Term *temp = this->start;
	while (temp != NULL && degree != temp->degree)
	{
		temp = temp->next;
	}
	if (temp)
	{
		return temp;
	}
	else
	{
		return NULL;
	}
}

Polynomial &Polynomial::operator=(const Polynomial &A)
{
	for (int i = 0; i < A.length; i++)
	{
		this->set(A[i].degree, A[i].coefficicent);
	}
	return *this;
}

Term Polynomial::operator[](int i) const
{
	Term *temp = this->start;
	while (temp->degree != i && temp->next != NULL)
	{
		temp = temp->next;
	};
	return *temp;
};

Polynomial operator*(const Polynomial &A, const Polynomial &B)
{
	Polynomial result;
	// for (int i = 0; i < A.length; i++)
	// {
	// 	for (int j = 0; j < B.length; j++)
	// 	{
	// 		int k = i + j;
	// 		result[k] += A[i] * B[j];
	// 	}
	// }
	return result;
}

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
// 		cout << "Nhap bac P(x) va Q(x)" << endl
// 			 << "Nhap he so theo so mu tu 0 den n " << endl
// 			 << "Vi du: P(x) = 2 + 3*x - 5.5*x^3 | bac: 3, he so: 2 3 0 -5.5" << endl;
// 		int bac;
// 		cout << "Nhap bac P(x): " << endl;
// 		cin >> bac;
// 		Polynomial P(bac + 1);
// 		cout << "Nhap cac he so: " << endl;
// 		cin >> P;
// 		cout << "Nhap bac Q(x): " << endl;
// 		cin >> bac;
// 		Polynomial Q(bac + 1);
// 		cout << "Nhap cac he so: " << endl;
// 		cin >> Q;
// 		Polynomial R(P.length + Q.length - 1);
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
	A.set(1, 1);
	A.set(1, 2);
	for (int i = 0; i < A.length; i++)
	{
		cout << A[i];
	}
	// controllers.welcome();
	// controllers.home();
	return 0;
}
