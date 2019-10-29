#include <iostream>
#include <string>
using namespace std;
#include "list.h"
#include "table.h"
#include "views.h"
#include "controller.h"
Views views;
Controllers controllers;

#include "list.cpp"
#include "table.cpp"
#include "views.cpp"
#include "controller.cpp"
#include "test.cpp"

// List list;
// table table;

int main()
{
    controllers.home();
    return 0;
}