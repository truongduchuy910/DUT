#include "list.h"
#include "list.cpp"
class Menu;
class Desk;
class Order;
class Bill;
//----------
class Menu : public List
{
private:
    string name;
    int foodId;
    int cost;

public:
<<<<<<< HEAD
	Menu(string ="", int =0, int =0);
	~Menu();
=======
    Menu();
    ~Menu();
>>>>>>> 673639a5f5099ed126b4eb0eb4295094e10dc80b
    friend ostream &operator<<(ostream &, Menu &);
    friend istream &operator>>(istream &, Menu &);
};
class Desk: public List
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
class Order: public List
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
<<<<<<< HEAD
	Order(int =0, int =0, int =0);
	~Order();
    friend ostream &operator<<(ostream &, Order &, Menu &, Desk &);
    friend ostream &operator>>(istream &, Order &, Menu &, Desk &);
=======
    Order();
    ~Order();
    friend ostream &operator<<(ostream &, Order &);
    friend ostream &operator>>(ostream &, Order &);
>>>>>>> 673639a5f5099ed126b4eb0eb4295094e10dc80b
};
class Bill: public List
{
private:
    int total;
public:
<<<<<<< HEAD
	Bill(int = 0);
	~Bill();
=======
    Bill();
    ~Bill();
>>>>>>> 673639a5f5099ed126b4eb0eb4295094e10dc80b
    friend ostream &operator<<(ostream &, Bill &);
};
class Table
{
public:
<<<<<<< HEAD
    Menu *menu;
    Desk *desk;
    Order *order;
    Bill *bill;
};
=======
    Menu menu;
    Desk desk;
    Order order;
    Bill bill;
};
>>>>>>> 673639a5f5099ed126b4eb0eb4295094e10dc80b
