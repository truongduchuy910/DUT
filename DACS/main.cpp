#include <fstream>
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
    void show();
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
    this->length++;
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

Data &List::operator[](int i)
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
void List::show()
{
    List *List = this;
    std::cout << "[" << length << "]=>( ";
    while (List->next != NULL)
    {
        std::cout << List->data.value;
        List = List->next;
        if (List->next != NULL)
            std::cout << ", ";
    }
    std::cout << " )" << std::endl;
}
struct Data
{
    /* data */
    int value;
};
int main()
{
    List A;
    List B;
    List C;

    std::ifstream dataInput;

    dataInput.open("A.txt");
    int data;
    Data newNode;

    while (dataInput >> data)
    {
        newNode.value = data;
        A.insertLast(newNode);
    };
    dataInput.close();

    dataInput.open("B.txt");
    while (dataInput >> data)
    {
        newNode.value = data;
        B.insertFirst(newNode);
    };
    dataInput.close();

    A.show();
    B.show();
    return 0;
}
