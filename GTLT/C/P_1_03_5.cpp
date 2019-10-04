#include <iostream>
using namespace std;
void show(int *chessbroad, int n)
{
    for (int k = 1; k <= n; k++)
    {
        for (int l = 1; l <= n; l++)
        {
            if (l == chessbroad[k])
            {
                cout << "[o]";
            }
            else
            {
                cout << "[ ]";
            }
        }
        cout << endl;
    }
    for (int k = 1; k <= n; k++)
    {
        cout << "---";
    }
    cout << endl;
}
void call(int i, int n, int *chessbroad, int *diaX, int *diaY, int *y)
{
    for (int j = 1; j <= n; j++)
    {
        if (y[j] && diaX[i + j] && diaY[i - j + n])
        {
            chessbroad[i] = j;
            if (i == n)
            {
                show(chessbroad, n);
            }
            if (i < n)
            {
                y[j] = false;
                diaX[i + j] = false;
                diaY[i - j + n] = false;
                call(i + 1, n, chessbroad, diaX, diaY, y);
                y[j] = true;
                diaX[i + j] = true;
                diaY[i - j + n] = true;
            }
        }
    }
}
void solve(int n)
{
    int chessboard[n + 1], y[n + 1];
    int diaX[2 * n + 1], diaY[2 * n + 1];
    for (int i = 0; i <= n + 1; i++)
    {
        chessboard[i] = 0;
        y[i] = true;
    }
    for (int i = 0; i <= n * 2 + 1; i++)
    {
        diaX[i] = true;
        diaY[i] = true;
    }
    call(1, n, chessboard, diaX, diaY, y);
}
int main()
{
    cout << "n: ";
    int n;
    cin >> n;
    solve(n);
}