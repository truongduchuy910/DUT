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
<<<<<<< HEAD
         << " ------------------------------ " << endl
         << "| WELLCOME TO RMS!             |" << endl
         << "| Restaurant Management System |" << endl
         << " ------------------------------ " << endl
         << "Luu y: Nghiem cam moi hanh vi sao chep"<< endl;
=======
         << "+-------------------------------+ " << endl
         << "| Restaurant Management System  |" << endl
         << "| ============================= |" << endl
         << "| table, list: Ngoc Huy         |" << endl
         << "| views, controllers: Nguyen Vu |" << endl
         << "| database: Tan Cuong           |" << endl
         << "+-------------------------------+" << endl;
>>>>>>> e722c93bff45e0f14c0bf797451acd52ca6c9d29
    controllers.home();
    return 0;
}