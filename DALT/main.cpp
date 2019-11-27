#include <iomanip>
#include "list.cpp"
#include "table.h"
#include "views.h"
#include "controller.h"
Table table;
Views views;
Controllers controllers;
#include "table.cpp"
#include "views.cpp"
#include "controller.cpp"
int main()
{
    controllers.home();
    return 0;
}