#include <iostream>
struct Data;
class List
{
private:
    List *next;
    List *previous;
    Data data;

public:
    int length;
    List(/* args */);
    ~List();
    Data insertFirst(Data data);
    Data removeFirst();
    Data insertLast(Data data);
    Data &operator[](int i);
};

List::List(/* args */)
{
    this->next = NULL;
    length = 0;
}

List::~List()
{
}

Data List::insertFirst(Data data)
{
    length++;
    List *newNode = new List;
    newNode->data = this->data;
    newNode->next = this->next;
    newNode->previous = this;

    this->previous = NULL;
    this->data = data;
    this->next = newNode;
    return newNode->data;
}

Data List::insertLast(Data data)
{
    length++;
    List *lastNode = this;
    while (lastNode->next != NULL)
    {
        lastNode = lastNode->next;
    }

    lastNode->data = data;
    lastNode->next = new List;

    return lastNode->data;
}

Data List::removeFirst()
{
}

Data &List::operator[](int i) const
{
    List *List = this;
    int index = 0;
    while (index != i && List->next != NULL)
    {
        index++;
        List = List->next;
    };

    if (List->next == NULL)
    {
        std::cout << "Warning: You access to undifine item" << std::endl;
    }
    return List->data;
}
// ----------------------------------------------------------------
struct Data
{
    int value;
};
int main()
{
}
