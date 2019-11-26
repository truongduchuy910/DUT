#include "list.h"
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
Data &List<Data>::operator[](int i)
{
    List *temp = this;
    while (i && temp->next != NULL)
    {
        temp = temp->next;
        i--;
    }
    return temp->data;
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
List<Data> &List<Data>::findOneAndRemove(Data &data)
{
    return *this;
};
