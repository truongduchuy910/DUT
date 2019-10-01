#include <iostream>

#include "database.h"
Collections wallet;

#include "controlles.h"

int main()
{
    //initialize();
    Wallet main;
    int address = (int)&main;
    std::cout << address;
    return 0;
}