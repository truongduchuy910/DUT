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
    int foodId;
    int cost;

public:
	Menu(string ="", int =0, int =0);
	~Menu();
    friend ostream &operator<<(ostream &, Menu &);
    friend istream &operator>>(istream &, Menu &);
};
class Desk
{
private:
	Desk(int = 0, string ="");
	~Desk();
	int deskId;
    string status;

public:
    Desk();
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
    int stt;              //So thu tu
    int number;           //So luong
    int billId;

public:
	Order(int =0, int =0, int =0);
	~Order();
    friend ostream &operator<<(ostream &, Order &, Menu &, Desk &);
    friend ostream &operator>>(istream &, Order &, Menu &, Desk &);
};
class Bill
{
private:
    int total;
public:
	Bill(int = 0);
	~Bill();
    friend ostream &operator<<(ostream &, Bill &);
};
class Table
{
public:
    Menu *menu;
    Desk *desk;
    Order *order;
    Bill *bill;
};
