#include <iostream>
using namespace std;
void call(int *data, bool *allow, int n, int *result, int k, int i)
{
    if (i > k)
    {
        for (int j = 1; j <= k; j++)
        {
            cout << result[j] << " ";
        }
        cout << endl;
    }
    else
    {

        for (int j = 1; j <= n; j++)
        {
            if (allow[j])
            {
                result[i] = data[j];
                allow[j] = false;
                call(data, allow, n, result, k, i + 1);
                allow[j] = true;
            }
        }
    }
}
void solve(int n, int k)
{
    int data[n];
    bool allow[n];
    for (int i = 1; i <= n; i++)
    {
        data[i] = i;
        allow[i] = true;
    }
    int result[k];
    call(data, allow, n, result, k, 1);
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