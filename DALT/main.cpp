#include <iostream>
#include <iomanip>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>
#include "list.h"
#include "table.h"
#include "views.h"
#include "controller.h"
//#include "models.h"
Table table;
Views views;
Controllers controllers;
#include "list.cpp"
#include "table.cpp"
#include "views.cpp"
#include "controller.cpp"
//#include "models.cpp"
int main()
{
    system("clear");
    cout << endl
         << "+-------------------------------+ " << endl
         << "| Restaurant Management System  |" << endl
         << "| ============================= |" << endl
         << "| table, list: Ngoc Huy         |" << endl
         << "| views, controllers: Nguyen Vu |" << endl
         << "| database: Tuan Cuong           |" << endl
         << "+-------------------------------+" << endl
         << "Luu y: Moi hanh vi sao chep la pham phap :)" << endl;
    controllers.home();
    return 0;
}