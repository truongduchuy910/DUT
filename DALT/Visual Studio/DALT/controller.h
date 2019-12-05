#ifndef CONTROLLERS_H
#define CONTROLLERS_H
#include <iostream>
using namespace std;
//#include "list.h"
//#include "table.h"
#include "views.h"
#include "models.h"
class Controllers
{
public:
	Views views;
	Models models;
	void home();
	void menu();
	void menuShow();
	void menuAdd();
	void menuRemove();
	void menuUpdate();
	//void deskShow();
	//void deskAdd();
	//void deskRemove();
	//void desk();
	//void order();
	//void orderAdd();
	//void bill();
	//void billShow();
	//void billAdd();
	//void billOrder();
   // void billPayment();
};
#endif

