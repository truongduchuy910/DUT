#include <iostream>
#include <string>
using namespace std;
template <class Data>
class List
{
private:
    List *next;
    Data data;

public:
    int length;
    List();
    ~List();
    Data &operator[](int);
    List &insertFirst(Data &);
    List &findOneAndRemove(Data &);
    List &findOneAndModify(Data &);
};