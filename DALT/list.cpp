#include <iostream>
using namespace std;
class Label
{
private:
    int _id;
    string name;

public:
    Label &create(int, string &);
};
Label &Label::create(int _id, string &name)
{
    this->_id = _id;
    this->name = name;
}
template <class Data>
class List
{
private:
    List *next;
    List *previous;
    Data data;
    int length;

public:
    List();
    ~List();
    List &operator=(List &);
    List &insertFirst(Data &);
    List &findOneAndRemove(Data &);
    List &findOneAndModify(Data &);
    List splice(int, int);
};
template <class Data>
List<Data>::List()
{
    this->next = NULL;
    this->previous = NULL;
    this->data = NULL;
    this->length = 0;
}
template <class Data>
List<Data>::~List()
{
}
template <class Data>
List<Data> &List<Data>::operator=(List<Data> &A){

};
template <class Data>
List<Data> &List<Data>::insertFirst(Data &data)
{
    List *emptyNode = this;
    while (emptyNode->data != NULL)
    {
        emptyNode = emptyNode->next;
    }
    List node;
    node.data = data;
    node.next = emptyNode;
    node.previous = emptyNode->previous;
    this->length++;
};
template <class Data>
List<Data> List<Data>::splice(int index, int number){

};
int main()
{
    Label dut;
    dut.create(1, 'truongduchuy');
    List<Label> a;
    a.insertFirst(dut);
}
