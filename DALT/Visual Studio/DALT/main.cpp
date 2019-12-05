#include <iostream>
#include "list.h"
#include "table.h"
#include "views.h"
#include "controller.h"
#include <iomanip>
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
         << "+-------------------------------+ " << endl
         << "| Restaurant Management System  |" << endl
         << "| ============================= |" << endl
         << "| table, list: Ngoc Huy         |" << endl
         << "| views, controllers: Nguyen Vu |" << endl
         << "| database: Tuan Cuong          |" << endl
         << "+-------------------------------+" << endl;
    controllers.home();
    return 0;
}