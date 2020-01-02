#include <iostream>
#include <fstream>
#include <iomanip>
#include "newList.h"
using namespace std;
DaThuc A;
DaThuc B;
DaThuc C;
int main()
{
    cin >> A;
    cout << A;
    for (int i = 0; i < A.layKichThuoc(); i++)
    {
        A.ghi(i, 0);
        cout << A;
    }
    cout << A;
}