#include "list.h"
#include "list.cpp"
class Menu;
class Desk;
class Order;
class Bill;
//----------

class Menu
{
private:
    string name;
    int cost;

public:
    Menu();
    ~Menu();
    friend ostream &operator<<(ostream &, Menu &);
    friend ostream &operator>>(ostream &, Menu &);
};
class Desk
{
private:
    string status;

public:
    Desk();
    ~Desk();
    friend ostream &operator<<(ostream &, Desk &);
    friend ostream &operator>>(ostream &, Desk &);
};
class Order
{
private:
    Menu *menu;
    Desk *desk;
    Bill *bill;
    //----------
    int menuId;
    int orderId;
    int billId;
    int count;

public:
    Order();
    ~Order();
    friend ostream &operator<<(ostream &, Order &);
    friend ostream &operator>>(ostream &, Order &);
};
class Bill
{
private:
    int total;

public:
    Bill();
    ~Bill();
    friend ostream &operator<<(ostream &, Bill &);
    friend ostream &operator>>(ostream &, Bill &);
};
class Table
{
public:
    Menu menu;
    Desk desk;
    Order order;
    Bill bill;
};