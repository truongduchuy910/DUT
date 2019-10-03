#include <iostream>
using namespace std;
void call(int i, int data[], int n, int k)
{
    for (int j = data[i - 1] + 1; j <= n - k + i; j++)
    {
        data[i] = j;
        if (i == k)
        {
            for (int j = 1; j <= k; j++)
                cout << data[j] << " ";
            cout << endl;
        }
        else
        {
            call(i + 1, data, n, k);
        }
    }
}
void solve(int n, int k)
{
    int data[k];
    data[0] = 0;
    call(1, data, n, k);
}
int main()
{
    cout << "n: ";
    int n;
    cin >> n;
    cout << "k: ";
    int k;
    cin >> k;
    solve(n, k);
}