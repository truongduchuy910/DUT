#include <iostream>
using namespace std;
#include "controller.h"
Controllers controllers;
int main()
{
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