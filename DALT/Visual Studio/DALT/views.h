#ifndef VIEWS_H
#define VIEWS_H
#include <iostream>
#include <iomanip>
using namespace std;

#include "list.h"
#include "table.h"
//#include "models.h"
class Views
{
public:
	int home();
	int menu();
	void menuShow(List<Menu>&);
	Menu menuAdd();
	int menuRemove(List<Menu>&);
	Menu menuUpdate(List <Menu>&);
	/*int desk();
	Desk deskAdd();
	Desk deskRemove();
	int deskShow();
	int order();
	Order orderAdd();
	int bill();
	Bill billAdd();*/
	//int billShow();
};
#endif
