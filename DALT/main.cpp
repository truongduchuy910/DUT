#include <iostream>
#include <string>
using namespace std;
#include "table.h"
Table table;
#include "views.h"
Views views;
#include "controller.h"
Controllers controllers;
#include "table.cpp"
#include "views.cpp"
#include "controller.cpp"
#include "testTable.cpp"

int main()
{
    testTable();
    controllers.home();
    return 0;
}