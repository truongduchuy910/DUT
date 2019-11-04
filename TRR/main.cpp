#include <iostream>
using namespace std;
int solve(int *pos, int i, int n, int &count, int &die)
{
    if (i == n)
    {
        i = 1;
    }
    if (pos[i] == 1)
    {

        count++;
        if (count == 3)
        {
            pos[i] = 0;
            die++;
            count = 0;
        }
    }
    if (die < n - 3)
    {
        solve(pos, i + 1, n, count, die);
    }
    else
    {
        for (int i = 1; i < n; i++)
        {
            if (pos[i] == 1)
            {
                cout << i << endl;
            }
        }
    }
}
int main()
{
    int n = 100;
    int pos[n + 1];
    for (int i = 1; i <= 100; i++)
    {
        pos[i] = 1;
    }
    int count = 0;
    int die = 0;
    solve(pos, 1, n + 1, count, die);
}