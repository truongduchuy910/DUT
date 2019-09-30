#include <iostream>
using namespace std;
struct Data
{
    //non-pointer please
};
class List
{
private:
    Data data;

public:
    append(Data data);
    push(Data data);
    pop();
    extend(List list);
    insert(int index, Data data);
    remove(int index);
    index(int i);
    int cout();
    sort();
    reverse();
    List copy(int from, int to);
}

int
main()
{
    return 0;
}
