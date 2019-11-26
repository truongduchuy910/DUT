#include <iostream>
using namespace std;
class Label
{
    int _id;
    string name;

    Label &create(int, const string &);
};
Label &Label::create(int _id, const string &name)
{
    this->_id = _id;
    this->name = name;
}
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
    this->length = 0;
}
template <class Data>
List<Data>::~List()
{
    while (this->next != NULL)
    {
        List *temp = this->next->next;
        cout << this->next << endl;
        //delete this->next;
        this->next = temp;
    }
}
template <class Data>
List<Data> &List<Data>::operator=(List<Data> &A){

};
template <class Data>
List<Data> &List<Data>::insertFirst(Data &data)
{
    List *node = new List;
    node->data = this->data;
    node->next = this->next;
    node->length = this->length;
    this->data = data;
    this->next = node;
    this->length++;
};
template <class Data>
List<Data> List<Data>::splice(int index, int number){

};
int main()
{
    Label dut;
    dut.create(1, "truongduchuy");
    List<Label> a;
    a.insertFirst(dut);
    a.insertFirst(dut);
    a.insertFirst(dut);
    for (int i = 0; i < a.length; i++)
    {
        cout << a[i].
    }
}
