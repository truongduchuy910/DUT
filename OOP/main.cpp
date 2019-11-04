#include <iostream>
using namespace std;
class Base
{
protected:
    int x;

private:
    int y;

public:
    int z;
    Base()
    {
        cout << "Base construct" << endl;
    };
    ~Base()
    {
        cout << "Base destruct" << endl;
    };
};
class PublicDerived : public Base
{
protected:
    int d;

private:
    int e;

public:
    int f;

public:
    PublicDerived()
    {
        cout << "PublicDerived construct" << endl;
    };
    ~PublicDerived()
    {
        cout << "PublicDerived destruct" << endl;
    };
};
int main()
{
    PublicDerived publicDerived;
    publicDerived.f = 1;
}