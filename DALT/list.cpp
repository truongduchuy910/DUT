
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

template <typename Data>
class List;
template <typename Data>
class Node;
class Menu;

template <typename Data>
class Node
{
    friend class List<Data>;

public:
    Node(Data);
    Data getData();

private:
    Data data;
    Node *next;
};

template <typename Data>
Node<Data>::Node(Data dataIn)
{
    data = dataIn;
    next = NULL;
}

template <typename Data>
Data Node<Data>::getData()
{
    return data;
}

template <typename Data>
class List
{
public:
    List();
    ~List();
    void insert(const Data &);
    void findAndRemove(const Data &);
    void print();

private:
    Node<Data> *start;
    bool isEmpty();
};

template <typename Data>
List<Data>::List()
{
    start = NULL;
}

template <typename Data>
List<Data>::~List()
{
    if (!isEmpty())
    {
        Node<Data> *currentNode = start;
        Node<Data> *temp;

        while (currentNode != 0)
        {
            temp = currentNode;
            currentNode = currentNode->next;
            delete temp;
        }
    }
}

template <typename Data>
bool List<Data>::isEmpty()
{
    if (start == NULL)
        return 1;
    else
        return 0;
}

template <typename Data>
void List<Data>::insert(const Data &dataIn)
{
    if (isEmpty())
    {
        Node<Data> *newNode = new Node<Data>(dataIn);
        start = newNode;
    }
    else
    {

        Node<Data> *newNode = new Node<Data>(dataIn);
        newNode->next = start;
        start = newNode;
    }
}

template <typename Data>
void List<Data>::findAndRemove(const Data &dataIn)
{
    Node<Data> *temp = this->start;
    while (temp != NULL && !(temp->data == dataIn))
    {
        temp = temp->next;
    }
    if (temp != NULL)
    {
        delete temp;
        start = start->next;
    }
}

template <typename Data>
void List<Data>::print()
{
    if (isEmpty())
    {
        cout << "The list is empty" << endl;
    }
    else
    {
        Node<Data> *currentNode = start;
        while (currentNode != NULL) //prints until the end of the list is reached
        {
            cout << currentNode->data << endl;
            currentNode = currentNode->next; //moves to next node in list
        }
    }
}

class Menu
{
public:
    Menu()
    {
        this->foodId = 0;
        this->cost = 0.0;
    }
    static void head()
    {
        cout << setw(6) << "foodId" << setw(6) << "name" << setw(6) << "cost" << endl;
    }
    const bool operator==(const Menu &);
    friend ostream &operator<<(ostream &, const Menu &);
    friend istream &operator>>(istream &, Menu &);

protected:
    int foodId;
    string name;
    double cost;
};
const bool Menu::operator==(const Menu &menu)
{
    if (this->foodId == menu.foodId)
    {
        return true;
    }
    else
    {
        return false;
    }
};

ostream &operator<<(ostream &os, const Menu &menu)
{
    os << setw(6) << menu.foodId << setw(6) << menu.name << setw(6) << menu.cost;
    return os;
}
istream &operator>>(istream &is, Menu &menu)
{
    cout << "name: ";
    is.ignore();
    getline(is, menu.name);
    cout << "cost: ";
    is >> menu.cost;
    return is;
}
class
{
public:
    List<Menu> menus;
} db;
class
{
public:
    class
    {
    public:
        void render()
        {
            cout << "HOME CONTROLL" << endl
                 << "0. Exit" << endl
                 << "1. Menu" << endl;
            int n;
            cin >> n;
            switch (n)
            {
            case 1:
                menus.render();
                break;
            }
        };
        class
        {
        public:
            class
            {
            public:
                void render()
                {
                    cout << "MENU ADD" << endl;
                    Menu menu;
                    cin >> menu;
                    db.menus.insert(menu);
                }
            } add;
            class
            {

            public:
                void render()
                {
                    cout << "MENU SHOW" << endl;
                    Menu::head();
                    db.menus.print();
                }
            } show;
            void render()
            {
                cout << "MENU CONTROLL" << endl
                     << "0. Back" << endl
                     << "1. Add" << endl
                     << "2. Show" << endl;
                int n;
                cin >> n;
                switch (n)
                {
                case 1:
                    add.render();
                    render();
                    break;
                case 2:
                    show.render();
                    render();

                    break;
                }
            };

        } menus;
    } home;

} controllers;
int main()
{

    controllers.home.render();
}