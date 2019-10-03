
class Reviews
{
private:
    Reviews *previous;
    Reviews *next;
    Review data;

public:
    int length;
    Reviews(/* args */);
    Review insertFirst(Review data);
    Review removeFirst();
    Review index(int i);
    Review serch(Review query);
};

Reviews::Reviews(/* args */)
{
    this->next = NULL;
    length = 0;
};
Review Reviews::insertFirst(Review data)
{
    length++;
    Reviews *newNode = new Reviews;
    newNode->data = this->data;
    newNode->next = this->next;
    newNode->previous = this;

    this->previous = NULL;
    this->data = data;
    this->next = newNode;
    return newNode->data;
};
Review Reviews::removeFirst()
{
    //length--;
    Reviews *temp = this->next;

    this->data = this->next->data;
    this->next = this->next->next;

    return this->data;
    delete temp;
};
Review Reviews::index(int i)
{
    Reviews *temp = this;
    while (i != 0)
    {
        i--;
        temp = temp->next;
    }
    return temp->data;
};
Review Reviews::serch(Review query){};