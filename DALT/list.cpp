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
    List<Data> *node = new List<Data>;
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
    List<Data> *temp = this;
    while (temp != NULL && temp->next && !(temp->next->data == data))
    {
        temp = temp->next;
    }
    if (temp->next)
    {
        List<Data> *deleteNode = temp->next;
        temp->next = temp->next->next;
        this->length--;
        delete deleteNode;
    }

    return *this;
};
