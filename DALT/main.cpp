#include <iostream>
#include <iomanip>
#include "list.h"
#include "table.h"
#include "views.h"
#include "controller.h"
Table table;
Views views;
Controllers controllers;
#include "list.cpp"
#include "table.cpp"
#include "views.cpp"
#include "controller.cpp"
int main()
{
    system("clear");
    cout << endl
         << " ------------------------------ " << endl
         << "| WELLCOME TO!                 |" << endl
         << "| Restaurant Management System |" << endl
         << " ------------------------------ " << endl;
    controllers.home();
    return 0;
}