#include <iostream>
using namespace std;
void HoanVi(int, int, int *);
bool TrienVong(int, int, int *);
int HoanVi(int k, int n, int *a, int& show)
{
    if (k == n)
    {
	if (show) {
            for (int i = 0; i < n; i++)
            {
                cout << a[i] << " ";
            }
            cout << endl;
	}
	return 1;
    }
    else
    {
	int count = 0;
        for (int i = 1; i <= n; i++)
        {
            if (TrienVong(i, k, a))
            {
                a[k] = i;
                count += HoanVi(k + 1, n, a, show);
            }
        }
	return count;
    }
}
bool TrienVong(int value, int n, int *a)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == value)
            return false;
    }
    return true;
}
int solve(int n, int *a, int& show)
{
    return HoanVi(0, n, a, show);
}
int main()
{
    cout << "Nhap n: ";
    int n;
    cin >> n;
    int a[n];
    cout << "Hien thi ket qua: " << endl
         << "0. No" << endl
	 << "1. Yes" << endl 
	 << "choose your option: " ;

    int show;
    cin >> show;
    cout << solve(n, a, show) << endl;
}
