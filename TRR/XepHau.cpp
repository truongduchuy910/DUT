#include <iostream>
using namespace std;
int col[30], row[30], diaX[30], diaY[30];
int n;
void displayChessboard()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (row[i] == j)
			{
				cout << " [o] ";
			}
			else
			{
				cout << " [ ] ";
			}
		}
		cout << endl;
	}
	cout << "--------------------" << endl;
};
void putQueen(int i, int j)
{
	row[i] = j;
	col[j] = false;
	diaX[i + j] = false;
	diaY[i - j + n - 1] = false;
}
void removeQueen(int i, int j)
{
	col[j] = true;
	diaY[i - j + n - 1] = true;
	diaX[i + j] = true;
}
int validPostion(int i, int j)
{
	return (col[j] && diaX[i + j] && diaY[i - j + n - 1]);
}
void tryRow(int i)
{
	for (int j = 0; j < n; j++)
		if (validPostion(i, j))
		{
			putQueen(i, j);

			if (i == n - 1)
			{
				displayChessboard();
			}
			else
			{
				tryRow(i + 1);
			}

			removeQueen(i, j);
		}
};

int main()
{
	cout << "Input size of chessboard (int): ";
	cin >> n;

	for (int i = 0; i < 30; i++)
	{
		col[i] = true;
		diaX[i] = true;
		diaY[i] = true;
	}
	tryRow(0);
}
