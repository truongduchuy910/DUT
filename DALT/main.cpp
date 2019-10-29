#include <iostream>
#include <string>
using namespace std;
#include "list.h"
#include "table.h"
#include "views.h"
Views views;
#include "controller.h"
Controllers controllers;
#include "list.cpp"
#include "table.cpp"
#include "views.cpp"
#include "controller.cpp"
#include "test.cpp"

// table table;

int main()
{
    controllers.home();
    return 0;
}