#include "table.h"
Menu::Menu(string name, int foodId, int cost): name(name), foodId(foodId), cost(cost){};
Menu::~Menu(){};
istream &operator>>(istream &istream, Menu &menu)
{
	cout <<"Nhap ten mon: ";
	istream >> menu.name;
	cout <<"Ma mon: ";
	istream >> menu.foodId; 
	cout <<endl <<"Cost: ";
	istream >> menu.cost;
};
ostream &operator<<(ostream &ostream, Menu &menu)
{
	ostream <<menu.name <<" : " <<menu.cost;
    return ostream;
};
Desk::Desk(int deskId, string status): deskId(deskId), status(status){};
Desk::~Desk(){};
istream &operator>>(istream &istream, Desk &desk)
{
	cout <<"DeskID: ";
	istream >>desk.deskId;
	cout <<endl <<"desk status: ";
	istream >> desk.status;
};
ostream &operator<<(ostream &ostream, Desk &desk)
{
	ostream<<desk.deskId <<": "<<desk.status;
    return ostream;
};
Order::Order(int stt, int number, int billId): stt(stt), number(number), billId(billId){};
Order::~Order(){};
ostream &operator<<(ostream &ostream, Order &order)
{
    ostream <<order.stt <<" || "<<order.menu->foodId <<" || " << order.number << "||" <<order.desk->deskId <<"||"<<order.billId;
    return ostream;
};
Bill::Bill(int total): total(total){};
Bill::~Bill(){};
ostream &operator<<(ostream &ostream, Bill &bill)
{
	ostream <<"BillId: "<< bill.order->billId << "||" <<"Cost Total: " <<bill.total<<endl;
    return ostream;
};
