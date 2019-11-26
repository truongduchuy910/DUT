template <typename Data>
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
template <typename Data>
List<Data>::List(){

};
template <typename Data>
List<Data>::~List(){

};
template <typename Data>
unsigned int List<Data>::create()
{
}
