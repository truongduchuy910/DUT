#ifndef VIEWS_CPP
#define VIEWS_CPP
#include "views.h"
int Views::home()
{

	cout << endl
		<< "=============== HOME CONTROL" << endl;
	int n;
	do
	{
		cout << "0. exit" << endl;
		cout << "1. menu" << endl;
		cout << "2. desk" << endl;
		cout << "3. order" << endl;
		cout << "4. bill" << endl;
		cout << "Choose your option [0-4]: ";
		cin >> n;
	} while (n < 0 || n > 8);

	return n;
}

int Views::menu()
{

	cout << endl
		<< "=============== MENU CONTROL" << endl;
	int n;
	do
	{
		cout << "0. back" << endl;
		cout << "1. show" << endl;
		cout << "2. add" << endl;
		cout << "3. remove" << endl;
		cout << "4. update" << endl;
		cout << "Choose your option [0-4]: ";
		cin >> n;
	} while (n < 0 || n > 4);

	return n;
};
void Views::menuShow(List<Menu>& menus)
{
	cout << endl
		<< "=============== MENU SHOW" << endl
		<< setw(10) << "foodId" << setw(50) << "foodName" << setw(10) << "cost" << endl;
	for (int i = 0; i < menus.length; i++)
	{
		cout << menus[i];
	}
}

Menu Views::menuAdd()
{
	Menu newMenu;
	cin >> newMenu;
	return newMenu;
}
int Views::menuRemove(List<Menu>& menus)
{
	menuShow(menus);
	int foodId;
	cout << endl
		<< "=============== MENU REMOVE" << endl;
	cout << "Input foodId to Remove:" << endl;
	cin >> foodId;
	return foodId;
}
Menu Views::menuUpdate(List<Menu>& menus)
{
	menuShow(menus);
	Menu temp;
	cout << endl
		<< "=============== MENU REMOVE" << endl;
	cout << "Input foodId to Update:" << endl;
	cin >> temp.foodId;
	cin >> temp;
	cout << "Input update:" << endl;
	return temp;
}
/*int Views::desk()
{
	cout << endl
		 << "=============== DESK CONTROL" << endl;
	int n;
	do
	{
		cout << "0. back" << endl;
		cout << "1. show" << endl;
		cout << "2. add" << endl;
		cout << "3. remove" << endl;
		cout << "Choose your option [0-3]: ";
		cin >> n;
	} while (n < 0 || n > 8);

	return n;
};
int Views::deskShow()
{
	cout << endl
		 << "=============== DESK SHOW" << endl
		 << "deskId status" << endl;
	for (int i = 0; i < table.desk.length; i++)
	{
		cout << table.desk[i];
	}
}
Desk Views::deskAdd()
{
	cout << endl
		 << "=============== DESK ADD" << endl;
	Desk newDesk;
	cin >> newDesk;
	return newDesk;
}
Desk Views::deskRemove()
{
	Desk newDesk;
	cin >> newDesk;
	return newDesk;
}
int Views::order()
{
	cout << endl
		 << "=============== ORDER CONTROL" << endl;

	int n;
	do
	{
		cout << "0. back" << endl;
		cout << "1. add" << endl;
		cout << "Choose your option [0 or 1]: ";
		cin >> n;
	} while (n < 0 || n > 1);

	return n;
};
Order Views::orderAdd()
{
	cout << endl
		 << "=============== ORDER ADD" << endl;
	Order newOrder;
	views.deskShow();
	cout<<"deskId: ";
	cin>>newOrder.deskId;
	views.menuShow();
	cout<<"foodId: ";
	cin>>newOrder.foodId;
	return newOrder;
}
int Views::bill()
{

	cout << endl
		 << "=============== BILL CONTROL" << endl;

	int n;
	do
	{
		cout << "0. back" << endl;
		cout << "1. add" << endl;
		cout << "2. order" << endl;
		cout << "3. payment" << endl;
		cout << "Choose your option [0-3]: ";
		cin >> n;
	} while (n < 0 || n > 8);

	return n;
};
Bill Views::billAdd()
{
	cout << endl
		 << "=============== BILL ADD" << endl;
	views.deskShow();
	Bill newBill;
	cout << "billId:" << endl;

	cin >> newBill.billId;
	cout << "deskId:" << endl;

	cin >> newBill.deskId;

	return newBill;
}*/
/*int Views::billShow()
{
	cout << endl
		 << "=============== BILL SHOW" << endl
		 << "deskId status" << endl;
	for (int i = 0; i < table.desk.length; i++)
	{
		cout << table.desk[i];
	}
}*/
#endif // !VIEWS_CPP
