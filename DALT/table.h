#ifndef table_h
#define table_h

#include <iostream>
#include <string>
using namespace std;

class Menu;
class Desk;
class Order;
class Bill;
//----------

class Menu
{
public:
    string name;
    int foodId;
    int cost;
    Menu(string = "", int = 0, int = 0);
    ~Menu();
    friend ostream &operator<<(ostream &, Menu &);
    friend istream &operator>>(istream &, Menu &);
};
class Desk
{
public:
    int deskId;
    string status;
    Desk(int = 0, string = "");
    ~Desk();
    friend ostream &operator<<(ostream &, Desk &);
    friend istream &operator>>(istream &, Desk &);
};
class Order
{
private:
    Menu *menu;
    Desk *desk;
    Bill *bill;
    //----------
    int stt;    //So thu tu
    int number; //So luong

public:
    int billId;
    Order(int = 0, int = 0, int = 0);
    ~Order();
    friend ostream &operator<<(ostream &, Order &);
    friend ostream &operator>>(istream &, Order &);
};
class Bill
{

private:
    Order *order;
    int total;

public:
    Bill(int = 0);
    ~Bill();
    friend ostream &operator<<(ostream &, Bill &);
};
class Table
{
public:
    Menu menu;
    Desk desk;
    Order order;
    Bill bill;
};
#endif
