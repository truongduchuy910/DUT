#ifndef TABLE_CPP
#define TABLE_CPP
#include "table.h"

Menu::Menu() {};
Menu::~Menu() {};
istream& operator>>(istream& istream, Menu& menu)
{
	cout << "foodName: ";
	istream.ignore();
	istream.get(menu.foodName, 50);
	cout << "cost: ";
	istream >> menu.cost;
	return istream;
};
ostream& operator<<(ostream& ostream, Menu& menu)
{
	ostream << setw(10) << menu.foodId << setw(50) << menu.foodName << setw(10) << menu.cost << " USD" << endl;
	return ostream;
};
Desk::Desk() {};
Desk::~Desk() {};
istream& operator>>(istream& istream, Desk& desk)
{
	cout << "Input status [0-1]: " << endl
		<< "0. Fill" << endl
		<< "1. Empty" << endl;
	cin >> desk.available;
	return istream;
};
ostream& operator<<(ostream& ostream, Desk& desk)
{
	string status = "Fill";
	if (desk.available) {
		status = "Empty";
	}
	ostream << setw(10) << desk.deskID << " " << setw(10) << status << endl;
	return ostream;
};
//Order::Order() {};
//Order::~Order() {};
//ostream& operator<<(ostream& ostream, Order& order)
//{
//	return ostream;
//};
//istream& operator>>(istream& istream, Order& order)
//{
//	cout << "billId: ";
//	istream >> order.billId;
//	cout << "deskId: ";
//	istream >> order.deskId;
//	cout << "foodId: ";
//	istream >> order.foodId;
//	return istream;
//}
//bool operator==(Order& A, Order& B)
//{
//	return 0;//(A.bill == B.bill && A.billId == B.billId && A.desk == B.desk && A.menu == B.menu && A.number == B.number && A.stt == B.stt);
//}
//Bill::Bill() {};
//Bill::~Bill() {};
//ostream& operator<<(ostream& ostream, Bill& bill)
//{
//	ostream << "billId: " << bill.order->billId << endl
//		<< "total: " << bill.total << endl;
//	return ostream;
//};
//istream& operator>>(istream& istream, Bill& bill)
//{
//	cout << "deskId: ";
//	istream >> bill.billId;
//	// cout << "status: ";
//	// istream.ignore();
//	getline(istream, bill.status);
//};
//bool operator==(Bill& A, Bill& B)
//{
//	return (A.order == B.order && A.total == B.total);
//}
#endif