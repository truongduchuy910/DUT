#ifndef TABLE_H
#define TABLE_H
#include <Windows.h>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Menu
{
public:
	char foodName[50];
	int foodId;
	double cost;
	Menu();
	~Menu();
	friend ostream& operator<<(ostream&, Menu&);
	friend istream& operator>>(istream&, Menu&);
};
class Desk
{
public:
    int deskID;
    bool available;
    Desk();
    ~Desk();
    friend ostream &operator<<(ostream &, Desk &);
    friend istream &operator>>(istream &, Desk &);
};
//class Order
//{
//private:
//    
//
//public:
//    int foodId;
//    int deskId;
//    int billId;
//    //==========
//    
//    int quantity; //So luong
//    Order();
//    ~Order();
//    friend ostream &operator<<(ostream &, Order &);
//    friend istream &operator>>(istream &, Order &);
//    friend bool operator==(Order &, Order &);
//};
//class Bill
//{
//
//private:
//    Order *order;
//    int total;
//    
//
//public:
//    string status;
//    int billId;
//    int deskId;
//    Bill();
//    ~Bill();
//    friend ostream &operator<<(ostream &, Bill &);
//
//    friend bool operator==(Bill &, Bill &);
//};
#endif
