#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class Array;
class Node;

class Node
{
	friend class Array;

public:
	Node(double);
	double &getData();

private:
	double data;
	Node *next;
};

Node::Node(double dataIn)
{
	data = dataIn;
	next = NULL;
}

double &Node::getData()
{
	return data;
}

class Array
{
public:
	int length;
	Array();
	Array(int);
	~Array();
	int insertLast(const double &);
	double &operator[](int);
	friend Array operator*(Array &, Array &);
	friend ostream &operator<<(ostream &, Array &);
	friend istream &operator>>(istream &, Array &);

private:
	Node *start;
	Node *end;
	bool isEmpty();
};
Array::Array()
{
	start = NULL;
	end = NULL;
	length = 0;
}
Array::Array(int size)
{
	length = 0;
	start = NULL;
	end = NULL;
	while (size)
	{
		this->insertLast(0);
		size--;
	}
}

Array::~Array()
{
	if (!isEmpty())
	{
		Node *currentNode = start;
		Node *temp;
		while (currentNode != NULL)
		{
			temp = currentNode;
			currentNode = currentNode->next;
		}
	}
}

bool Array::isEmpty()
{
	if (start == NULL)
		return 1;
	else
		return 0;
}

int Array::insertLast(const double &dataIn)
{
	Node *newNode = new Node(dataIn);

	if (isEmpty())
	{
		start = newNode;
		end = newNode;
		this->length++;
		return true;
	}
	else
	{
		end->next = newNode;
		end = newNode;
		this->length++;
		return true;
	}
	return false;
}

double &Array::operator[](int i)
{
	Node *temp = this->start;
	while (i && temp != NULL)
	{
		temp = temp->next;
		i--;
	};
	return temp->getData();
};

Array operator*(Array &A, Array &B)
{
	Array result(A.length + B.length - 1);
	for (int i = 0; i < A.length; i++)
	{
		for (int j = 0; j < B.length; j++)
		{
			int k = i + j;
			result[k] += A[i] * B[j];
		}
	}
	return result;
}
ostream &operator<<(ostream &ostream, Array &A)
{
	for (int i = 0; i < A.length; i++)
	{
		ostream << setw(8) << A[i];
	}
	return ostream;
}

istream &operator>>(istream &istream, Array &A)
{
	for (int i = 0; i < A.length; i++)
	{
		cout << "He so cua x^" << i << ": ";
		istream >> A[i];
	}
	return istream;
}

int readData(Array &A, const char *path)
{
	ifstream file;
	file.open(path);
	if (file.fail())
	{
		cout << "Doc file " << path
			 << " that bai!" << endl;
		return 0; //fail
	}
	double value;
	int index = 0;
	while (file >> value)
	{
		if (index < A.length - 1)
		{
			A[index] = value;
		}
		else
		{
			A.insertLast(value);
		}
		index++;
	};
	file.close();
	cout << "Doc file " << path << " thanh cong!" << endl;
	return 1; //success
}

int writeData(Array &A, const char *path)
{
	ofstream file(path);
	if (file.fail())
	{
		cout << "ghi file " << path << " that bai!";
		return 0; //fail
	}
	for (int i = 0; i < A.length; i++)
	{
		file << setw(8) << A[i];
	}
	file.close();
	cout << "Ghi file " << path << " thanh cong!" << endl;
	return 1; //success
}

int controller()
{
	int option;
	do
	{
		cout << endl
			 << "------ MENU DIEU KHIEN ----- " << endl
			 << "0. Thoat chuong trinh" << endl
			 << "1. Doc du lieu tu file" << endl
			 << "2. Nhap du lieu tu ban phim" << endl
			 << "Nhap lua chon: ";
		cin >> option;
	} while (option < 0 || option > 2);
	return option;
}

int exit()
{
	int option;
	do
	{
		cout << endl
			 << "Thoat chuong trinh? " << endl
			 << "1. Tiep tuc chuong trinh" << endl
			 << "0. Thoat chuong trinh" << endl
			 << "Nhap lua chon: ";
		cin >> option;
	} while (option < 0 || option > 1);
	return option;
}
class
{
public:
	void wellcome()
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
	void home()
	{
		int option;
		do
		{
			cout << "0. Thoat chuong trinh" << endl
				 << "1. Doc du lieu tu file" << endl
				 << "2. Nhap du lieu tu ban phim" << endl
				 << "Nhap lua chon: ";

			cin >> option;
		} while (option < 0 || option > 2);
		cout << "---------------------------------------" << endl;

		switch (option)
		{
		case 1:
		{
			fileInput();
			home();
			break;
		}
		case 2:
		{
			consoleInput();
			home();
			break;
		}
		}
	}
	void fileInput()
	{
		cout << "He so cua duoc nhap theo so mu tu 0 den n" << endl;
		Array P, Q, R;
		bool noError = true;
		noError *= readData(P, "DATA1.txt");
		noError *= readData(Q, "DATA2.txt");
		R = P * Q;
		noError *= writeData(R, "DATA3.txt");
		if (noError)
			cout << "He so P(x): " << endl
				 << P << endl
				 << "He so Q(x): " << endl
				 << Q << endl
				 << "He so tich R(x) = P(x) * Q(x): " << endl
				 << R << endl
				 << "---------------------------------------" << endl;
	}
	void consoleInput()
	{
		cout << "Nhap bac P(x) va Q(x)" << endl
			 << "Nhap he so theo so mu tu 0 den n " << endl
			 << "Vi du: P(x) = 2 + 3*x - 5.5*x^3 | bac: 3, he so: 2 3 0 -5.5" << endl;
		int bac;
		cout << "Nhap bac P(x): " << endl;
		cin >> bac;
		Array P(bac + 1);
		cout << "Nhap cac he so: " << endl;
		cin >> P;
		cout << "Nhap bac Q(x): " << endl;
		cin >> bac;
		Array Q(bac + 1);
		cout << "Nhap cac he so: " << endl;
		cin >> Q;
		Array R(P.length + Q.length - 1);
		R = P * Q;
		cout << endl
			 << "Ket qua: " << endl
			 << "He so P(x): " << endl
			 << P << endl
			 << "He so Q(x): " << endl
			 << Q << endl
			 << "He so tich R(x) = P(x) * Q(x):" << endl
			 << R << endl
			 << "---------------------------------------" << endl;
		;
	}
} controllers;
int main()
{

	controllers.wellcome();
	controllers.home();
	return 0;
}
