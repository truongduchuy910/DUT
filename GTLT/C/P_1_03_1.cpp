#include <iostream>
using namespace std;

void call(int i, int data[], int n)
{
    if (i > n)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
    else
    {
        data[i] = 0;
        call(i + 1, data, n);
        data[i] = 1;
        call(i + 1, data, n);
    }
};
void solve(int n)
{
    int data[n];
    call(1, data, n);
}

int main()
{
    cout << "n: ";
    int n;
    cin >> n;
    solve(n);
}