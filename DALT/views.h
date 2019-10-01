#include <iostream>
using namespace std;
#include "objects.h"
int home()
{
    system("clear");
    int n;
    do
    {
        cout << "1. option 1" << endl;
        cout << "2. option 2" << endl;
        cout << "3." << endl;
        cout << "4." << endl;
        cout << "5." << endl;
        cout << "6." << endl;
        cout << "7." << endl;
        cout << "8." << endl;
        cout << "Choose your option [1-8]: ";
        cin >> n;
    } while (n < 1 || n > 8);

    return n;
}

int option_1()
{
    return 0;
}
int option_2()
{
    return 0;
}
//...