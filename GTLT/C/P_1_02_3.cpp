
#include <iostream>
using namespace std;
void show(int data[], int n)
{
    cout << "[" << n << "]: ";
    for (int i = 0; i < n; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}
void solve(int n)
{

    int data[n];
    for (int i = 0; i < n; i++)
    {
        data[i] = i + 1;
    }

    int i = n;
    show(data, n);

    while (i > 0)
    {
        i--;
        if (data[i] > data[i - 1])
        {
            i--;
            int j = n - 1;
            while (j >= 0 && data[j] < data[i])
            {
                j--;
            }

            if (j > 0)
            {
                int temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
            i++;

            int delta = (n - 1 - i) / 2;
            for (int k = 0; k <= delta; k++)
            {
                int temp = data[i + k];
                data[i + k] = data[n - 1 - k];
                data[n - 1 - k] = temp;
            }
            show(data, n);

            i = n;
        }
    }
}
int main()
{
    solve(0);
    solve(1);
    solve(2);
    solve(3);
    solve(4);
}