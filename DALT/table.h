#ifndef table_h
#define table_h

#include <iostream>
#include <string>
using namespace std;

class Menu;
class Desk;
class Order;
class Bill;
//---------------

class Menu
{
public:
    string name;
    int foodId;
    int cost;
    Menu();
    ~Menu();
    friend ostream &operator<<(ostream &, Menu &);
    friend istream &operator>>(istream &, Menu &);
    friend bool operator==(Menu &, Menu &);
};
class Desk
{
public:
    int deskId;
    string status;
    Desk();
    ~Desk();
    friend ostream &operator<<(ostream &, Desk &);
    friend istream &operator>>(istream &, Desk &);
    friend bool operator==(Desk &, Desk &);
};
class Order
{
private:
    Menu *menu;
    Desk *desk;
    Bill *bill;
    //---------------
    int stt;    //So thu tu
    int number; //So luong

public:
    int billId;
    Order();
    ~Order();
    friend ostream &operator<<(ostream &, Order &);
    friend ostream &operator>>(istream &, Order &);
    friend bool operator==(Order &, Order &);
};
class Bill
{

private:
    Order *order;
    int total;

public:
    Bill();
    ~Bill();
    friend ostream &operator<<(ostream &, Bill &);
    friend bool operator==(Bill &, Bill &);
};
class Table
{
public:
    List<Menu> menu;
    List<Desk> desk;
    List<Order> order;
    List<Bill> bill;
};
#endif
