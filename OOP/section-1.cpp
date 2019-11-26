#include <iostream>
using namespace std;

class Person
{
public:
    int age;
};
class Car
{
public:
    long price;
};

template <typename Data>
class List
{
private:
    List *previous;
    List *next;
    Data data;

public:
    List(Data &A){};
    Data insert(Data &A){};
    Data remove(Data &A){};
    Data select(Data &A){};
};
int main()
{
    Person robert;
    Car BMW;
    robert.age = 12;
    BMW.price = 7000000000;
    List listPerson(robert);
    List listCar(BMW);
    return 0;
}