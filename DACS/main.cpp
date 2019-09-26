#include <fstream>
#include <iostream>
struct Data
{
    int value;
};

class List
{
private:
    List *next;
    List *previous;
    Data data;

public:
    int length;
    List(int size = 0);
    ~List();
    Data insertFirst(Data data);
    Data removeFirst();
    Data insertLast(Data data);
    Data &operator[](int i);
    void display();
};

List::List(int size)
{
    this->length = 0;

    if (size)
    {
        while (size--)
        {
            Data emptyNode;
            emptyNode.value = 0;
            this->insertFirst(emptyNode);
        }
    }
    else
    {
        this->next = NULL;
    }
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

void List::display()
{
    List *List = this;
    std::cout << "[" << length << "] : ( ";
    while (List->next != NULL)
    {
        std::cout << List->data.value;
        List = List->next;
        if (List->next != NULL)
            std::cout << ", ";
    }
    std::cout << " )" << std::endl;
}

int main()
{
    //-----------------------------------------
    std::ifstream dataInput;
    int data;
    //-----------------------------------------
    List A;
    dataInput.open("A.txt");
    Data newNode;
    while (dataInput >> data)
    {
        newNode.value = data;
        A.insertLast(newNode);
    };
    dataInput.close();
    //-----------------------------------------
    List B;
    dataInput.open("B.txt");
    while (dataInput >> data)
    {
        newNode.value = data;
        B.insertLast(newNode);
    };
    dataInput.close();
    //-----------------------------------------
    List C(A.length + B.length);
    A.display();
    B.display();
    C.display();
	std::cout << "Huy";
    A[0] = B[0];
    A.display();
    return 0;
}
