#include "table.h"
#include <iostream>
#include <string>
#include<iomanip>
using namespace std;

Menu::Menu(){};
Menu::~Menu(){};
istream &operator>>(istream &istream, Menu &menu)
{
	cout << "name: ";
	istream.ignore();
	getline(istream, menu.name);
	cout << "foodId: ";
	istream >> menu.foodId;
	cout << "cost: ";
	istream >> menu.cost;
	return istream;
};
ostream &operator<<(ostream &ostream, Menu &menu)
{
	ostream << setw(6) << menu.foodId << " " << setw(12) << menu.name << " " << menu.cost << endl;
	return ostream;
};
bool operator==(Menu &A, Menu &B)
{
	return (A.cost == B.cost && A.foodId == B.foodId && A.name == B.name);
};

Desk::Desk(){};
Desk::~Desk(){};
istream &operator>>(istream &istream, Desk &desk)
{
	cout << "deskId: ";
	istream >> desk.deskId;
	cout << "status: ";
	istream.ignore();
	getline(istream, desk.status);
};
ostream &operator<<(ostream &ostream, Desk &desk)
{
	ostream << setw(6) << desk.deskId << " " << desk.status << endl;
	return ostream;
};
bool operator==(Desk &A, Desk &B)
{
	return (A.deskId == B.deskId && A.status == B.status);
};

Order::Order(){};
Order::~Order(){};
ostream &operator<<(ostream &ostream, Order &order)
{
	return ostream;
};
istream &operator>>(istream &istream, Order &order)
{
	cout<<"billId: ";
	istream >> order.billId;
	cout<<"deskId: ";
	istream >> order.deskId;
	cout<<"foodId: ";
	istream >> order.foodId;
	return istream;
}
bool operator==(Order &A, Order &B)
{
	return 0;//(A.bill == B.bill && A.billId == B.billId && A.desk == B.desk && A.menu == B.menu && A.number == B.number && A.stt == B.stt);
}
Bill::Bill(){};
Bill::~Bill(){};
ostream &operator<<(ostream &ostream, Bill &bill)
{
	ostream << "billId: " << bill.order->billId << endl
			<< "total: " << bill.total << endl;
	return ostream;
};
istream &operator>>(istream &istream, Bill &bill)
{
	cout << "deskId: ";
	istream >> bill.billId;
	// cout << "status: ";
	// istream.ignore();
	getline(istream, bill.status);
};
bool operator==(Bill &A, Bill &B)
{
	return (A.order == B.order && A.total == B.total);
}
