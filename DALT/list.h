class Data
{
public:
    unsigned int _id;
};
class List
{
private:
    List *previous;
    List *next;
    Data *data;

public:
    List();
    ~List();
    unsigned int create();
};
