#include <iostream>
class Data
{
public:
    int value;
};
class List
{
private:
    List *previous;
    List *next;
    Data data;

public:
    List();
    List(int);
    Data insert(Data &);
    Data remove(Data &);
    Data select(Data &);
    ~List();
};
int main()
{
}