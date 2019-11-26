#include <iostream>
using namespace std;
template <class Data>
class List
{
private:
    List *next;
    List *previous;
    Data data;
    int length;

public:
    List(const Data &data)
    {
        //First item have previous is NULL
        //Last item have next is NULL
        this->next = NULL;
        this->previous = NULL;
        this->data = data;
        this->length = 1;
    };
    ~List(){};

    friend ostream &operator<<(ostream &, List &);

    //Add to the end of a List
    void push(const Data &data)
    {
        List *temp = this;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        List *node = new List(data);
        node->next = NULL;
        node->previous = temp;

        temp->next = node;

        this->length++;
    };
    //Remove from the end of a List
    void pop(){};
    //Remove from the front of a List
    void shift();
    //Add to the front of a List
    void unshift(const Data &);
    Data &index(int i)
    {
        List *temp = this;
        int count = 0;

        while (temp->next != NULL && count != i)
        {
            temp = temp->next;
            count++;
        }
        return temp->data;
    }
};
int main()
{
    List<int> digital(2);
    digital.push(3);
    digital.index(1) = 10;
    cout << digital.index(0)
         << digital.index(1)
         << endl;
}