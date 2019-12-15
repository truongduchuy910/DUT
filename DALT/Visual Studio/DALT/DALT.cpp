#include <iostream>
using namespace std;
#include "list.h"
#include "controllers.h"

Controllers controllers;
int main()
{
	cout << endl
		<< "+-------------------------------+ " << endl
		<< "| Restaurant Management System  |" << endl
		<< "| ============================= |" << endl
		<< "| table, list, models: Ngoc Huy |" << endl
		<< "| controllers: Nguyen Vu        |" << endl
		<< "| database: Tuan Cuong          |" << endl
		<< "+-------------------------------+" << endl;
	controllers.home.render();
	return 0;
}