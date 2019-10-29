class Menu;
class Desk;
class Order;
class Bill;
//----------
class Menu : public List
{
private:
    string name;
    int cost;

public:
    friend ostream &operator<<(ostream &, Menu &);
};
class Desk : List
{
private:
    string status;

public:
    friend ostream &operator<<(ostream &, Desk &);
};
class Order
{
private:
    Menu *menu;
    Order *order;
    Bill *bill;
    //----------
    int menuId;
    int orderId;
    int billId;
    int count;

public:
    friend ostream &operator<<(ostream &, Order &);
};
class Bill : List
{
private:
    int total;

public:
    friend ostream &operator<<(ostream &, Bill &);
};