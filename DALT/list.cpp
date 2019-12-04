template <class Data>
List<Data>::List()
{
    this->next = NULL;
    this->length = 0;
    this->data = NULL;
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
    cout << "[insert] success" << endl
         << data;
    List<Data> *node = new List<Data>;
    node->next = NULL;
    node->data = data;
    if (this->next == NULL)
    {
        this->next = node;
    }
    this->length++;
};
template <class Data>
List<Data> &List<Data>::findOneAndRemove(Data &data)
{
    List<Data> *temp = this;

    if (temp->next == NULL)
    {
        this->data = NULL;
        return *this;
    }

    while (temp != NULL && temp->next && !(temp->next->data == data))
    {
        temp = temp->next;
    }
    if (temp->next)
    {
        cout << "[remove] success" << endl
             << temp->next->data;
        List<Data> *deleteNode = temp->next;
        temp->next = temp->next->next;
        this->length--;
        delete deleteNode;
    }
    else
    {
        cout << "[remove] couldn't find" << endl
             << data;
    }

    return *this;
};
