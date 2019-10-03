#include <iostream>
using namespace std;
void call(int i, int data[], int n)
{

    int sum = 0;
    for (int j = 1; j < i; j++)
    {
        sum += data[j];
    }
    if (sum == n)
    {
        for (int j = 1; j < i; j++)
        {
            cout << data[j] << " ";
        }
        cout << endl;
    }
    else if (sum < n)
    {
        for (int j = data[i - 1]; j <= n; j++)
        {
            data[i] = j;
            call(i + 1, data, n);
        }
    }
}
void solve(int n)
{
    int data[n];
    for (int i = 0; i <= n; i++)
    {
        data[i] = 1;
    }
    call(1, data, n);
}
int main()
{
    cout << "n: ";
    int n;
    cin >> n;
    solve(n);
    return 0;
}