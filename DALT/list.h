class List
{
private:
    List *previous;
    List *next;
    int _id;

public:
    List(int);
    ~List();
    List insert(List &);
    List remove(List &);
    List select(List &);
};
