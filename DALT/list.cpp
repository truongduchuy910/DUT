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
    List *temp = this->next;
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

    node->next = this->next;
    node->data = data;
    this->next = node;
    this->length++;
    cout << "[insert] success" << endl
         << this->next->data;
};
template <class Data>
List<Data> &List<Data>::findOneAndRemove(Data &data)
{
    List<Data> *temp = this;
    do
    {
        if (temp->next->data == data)
        {
            temp->next = temp->next->next;
        }
        if (temp->next)
        {
            temp = temp->next;
        }
    } while (temp->next);
    this->length--;
    return *this;
};
