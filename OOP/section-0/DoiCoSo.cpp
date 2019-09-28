#include <iostream>
using namespace std;
char format[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
void doiCoSo(int n, int coSo)
{
    if (n == 0)
    {
    }
    else
    {
        doiCoSo(n / coSo, coSo);
        cout << format[n % coSo];
    }
}
int main()
{
    doiCoSo(13233, 16);
    cout << endl;
}