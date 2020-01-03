#include <iostream>
#include <fstream>
#include <iomanip>
#include "Polynomial.h"
using namespace std;
Polynomial A;
Polynomial B;
Polynomial C;
class
{
public:
	void read()
	{
		cout << endl
			 << "    ------------- Input from keyboard" << endl;
		cout << "    Input A" << endl;
		cin >> A;
		cout << "    Input B" << endl;
		cin >> B;
	}
} console;
class
{
public:
	void read()
	{
		cout << endl
			 << "    ------------- Input from files" << endl;
		cout << "    Input A from DATA1.txt - ";
		A.~Polynomial();
		readData(A, "DATA1.txt");
		B.~Polynomial();
		cout << "    Input B from DATA2.txt - ";
		readData(B, "DATA2.txt");
	}
	void write()
	{
		cout << endl
			 << "    ------------- Export to files" << endl;
		cout << "    Export Result to DATA3.txt - ";
		writeData(C, "DATA3.txt");
	}
	int readData(Polynomial &A, const char *path)
	{
		ifstream file;
		file.open(path);
		if (file.fail())
		{
			cout << "failure!";
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
		cout << "success!" << endl;
		return true;
	}

	int writeData(Polynomial &A, const char *path)
	{
		ofstream file(path);
		if (file.fail())
		{
			cout << "failure!";
			return false;
		}
		for (int i = 0; i < A.getSize(); i++)
		{
			file << A[i] << " ";
		}
		file.close();
		cout << "success!" << endl;
		return true;
	}
} file;
class
{
public:
	void options()
	{
		char choose;

		do
		{
			cout << endl
				 << "    ------------- Operators" << endl
				 << "    0. Back" << endl
				 << "    1. +" << endl
				 << "    2. -" << endl
				 << "    3. *" << endl
				 << "    4. /" << endl
				 << "    5. %" << endl
				 << "    6. Data" << endl
				 << "    Choose your option [0-5]: ";
			cin >> choose;
			cout << "    you have chosen: " << choose << endl;
			switch (choose)
			{
			case '0':
				break;
			case '1':
				cout << endl
					 << "    ------------- A + B" << endl;
				C = A + B;
				cout << C;
				file.write();
				options();
				break;
			case '2':
				cout << endl
					 << "    ------------- A - B" << endl;
				C = A - B;
				cout << C;
				file.write();
				options();
				break;
			case '3':
				cout << endl
					 << "    ------------- A * B" << endl;
				C = A * B;
				cout << C;
				file.write();
				options();
				break;
			case '4':
				cout << endl
					 << "    ------------- A / B" << endl;
				C = A / B;
				cout << C;
				file.write();
				options();
				break;
			case '5':
				cout << endl
					 << "    ------------- A % B" << endl;
				C = A % B;
				cout << C;
				file.write();
				options();
				break;
			case '6':
				cout << endl
					 << "    ------------- Data" << endl;
				cout << "    Polynomial A" << endl
					 << A << endl
					 << "    Polynomial B" << endl
					 << B << endl;
				options();
				break;
			default:
				cout << "    Invalid option!" << endl;
				break;
			}
		} while ('0' > choose || choose > '6');
	}
} solve;
class
{
public:
	void welcome()
	{
		cout << endl
			 << "    Chuong Trinh Tinh Tich Da Thuc     " << endl
			 << "    -----------------------------------" << endl
			 << "    Ma nhom: 18N15 - N6                " << endl
			 << "    Thanh vien trong nhom:             " << endl
			 << "    1. Nguyen Kim Huy - MSSV: 102180207" << endl
			 << "    2. Tran Ngoc Huy  - MSSV: 102180208" << endl;
	}
	void options()
	{
		char choose;

		do
		{
			cout << endl
				 << "    ------------- Home" << endl
				 << "    0. Exit" << endl
				 << "    1. Input from files" << endl
				 << "    2. Input from keyboard" << endl
				 << "    3. Operators" << endl
				 << "    Choose your option [0-3]: ";
			cin >> choose;
			cout << "    you have chosen: " << choose << endl;
			switch (choose)
			{
			case '0':
				cout << "    Goodbye!" << endl;
				break;
			case '1':
				file.read();
				solve.options();

				this->options();
				break;

			case '2':
				console.read();
				solve.options();

				this->options();

				break;
			case '3':
				solve.options();

				this->options();
				break;
			default:
				cout << "    Invalid option!" << endl;
				break;
			}
		} while ('0' > choose || choose > '3');
	}
} home;

int main()
{
	home.welcome();
	home.options();
	return 0;
}
