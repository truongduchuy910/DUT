// File này dùng để định dạng các thuộc tính cho đối tượng
#include <iostream>
struct Revenue
{
    char name[50];
};

struct RevenueEvent
{
    char name[50];
    long price;
};
struct Expenditure
{
    char name[50];
};
struct ExpenditureEvent
{
    char name[50];
    long price;
};
struct Wallet
{
    char name[50];
    long price;
};
struct WalletEvent
{
    char from[50];
    char to[50];
    long price;
};