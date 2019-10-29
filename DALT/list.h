class Data
{
public:
    unsigned int _id;
};
class List : public Data
{
private:
    List *previous;
    List *next;
public:
    List();
    ~List();
    Data insert(Data &);
    Data removeById(int);
    Data findById(int);
};
