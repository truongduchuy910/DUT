#include <iostream>
using namespace std;
struct Data
{
	int dms;
	int *drc = 0;
};
class Vector
{
public:
	Data data;

	Vector(int dms = 0);
	~Vector();
	int &operator[](int i);
	void display();
	Vector &operator=(Vector *A);
};
Vector::Vector(int dms)
{
	this->data.dms = dms;
	if (dms)
	{
		this->data.drc = new int[dms];
	}
}
Vector::~Vector()
{
	delete[] this->data.drc;
}
int &Vector::operator[](int i)
{
	const Data local = this->data;
	return local.drc[i];
};
void Vector::display()
{
	if (this->data.dms)
	{
		for (int i = 0; i < this->data.dms; i++)
		{
			cout << this->data.drc[i] << " ";
		};
	};
	cout << endl;
};
Vector *operator+(Vector &A, Vector &B)
{
	int dms = A.data.dms;
	Vector *C = new Vector(dms);
	if (A.data.dms == B.data.dms)
	{
		for (int i = 0; i < dms; i++)
		{
			C->data.drc[i] = A[i] + B[i];
		};
	}
	else
	{
		cout << "Can't solve A + B if A's dimensional different B's dimensional" << endl;
	};
	return C;
};
Vector *operator-(Vector &A, Vector &B)
{
	int dms = A.data.dms;
	Vector *C = new Vector(dms);
	if (A.data.dms == B.data.dms)
	{
		for (int i = 0; i < dms; i++)
		{
			C->data.drc[i] = A[i] - B[i];
		};
	}
	else
	{
		cout << "Can't solve A - B if A's dimensional different B's dimensional" << endl;
	};
	return C;
};

int operator*(Vector &A, Vector &B)
{
	int dms = A.data.dms;
	int result = 0;
	if (A.data.dms == B.data.dms)
	{
		for (int i = 0; i < dms; i++)
		{
			result += A[i] + B[i];
		}
	}
	else
	{
		cout << "Can't solve A * B if A's dimensional different B's dimensional" << endl;
	};
	return result;
};

Vector &Vector::operator=(Vector *C)
{
	int dms = C->data.dms;
	this->data.dms = dms;
	if (!this->data.drc)
	{
		this->data.drc = new int[dms];
	}
	for (int i = 0; i < dms; i++)
	{
		this->data.drc[i] = C->data.drc[i];
	}
}
int main()
{
	cout << "Input dimensional of vector A (int): ";
	int dms;
	cin >> dms;
	Vector A(dms);
	cout << "Input directions (int int int ...): ";
	for (int i = 0; i < dms; i++)
	{
		cin >> A[i];
	};
	A.display();

	cout << endl;

	cout << "Input dimensional of vector B (int): ";
	cin >> dms;
	Vector B(dms);
	cout << "Input directions (int int int ...): ";
	for (int i = 0; i < dms; i++)
	{
		cin >> B[i];
	};
	B.display();

	cout << endl;

	cout << endl;

	Vector C;
	cout << "A + B = ";
	C = A + B;
	C.display();

	cout << endl;

	cout << "A - B = ";
	C = A - B;
	C.display();

	cout << endl;

	int delta;
	cout << "A * B = ";
	delta = A * B;
	cout << delta << endl;
	return 0;
}