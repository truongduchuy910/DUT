#include <iostream>
#include <fstream>
using namespace std;
const int lock = -1;
struct Citis
{
    bool allow = true;
    int *price;
};
void travel(int ps, int ct, Citis *citis, int &c, int *pass, int &p, int cost, int &cheapest, int *trip)
{
    if (ps > 1)
        cost += citis[ct].price[pass[ps - 1]];
    if (cost < cheapest)
    {
        if (ps == p - 1)
        {
            pass[ps] = ct;
            if (citis[ct].price[1] != lock)
            {
                cost += citis[ct].price[1];
                cheapest = cost;
                for (int i = 1; i <= p; i++)
                    trip[i] = pass[i];
            }
        }
        else
        {
            for (int nxt = 2; nxt <= c; nxt++)
            {
                if (citis[nxt].allow == true && citis[ct].price[nxt] != lock)
                {
                    pass[ps] = ct;
                    citis[ct].allow = false;
                    travel(ps + 1, nxt, citis, c, pass, p, cost, cheapest, trip);
                    citis[ct].allow = true;
                }
            }
        }
    }
}
int main()
{
    ifstream infile;
    infile.open("input.txt");
    int c, w;
    infile >> c >> w;
    Citis citis[c];
    for (int i = 1; i <= c; i++)
    {
        citis[i].price = new int[c];
        for (int j = 1; j <= c; j++)
            citis[i].price[j] = lock;
    }
    int p = c + 1, pass[p], trip[p];
    for (int i = 1; i <= p; i++)
        pass[i] = lock;
    citis[1].allow = false;
    pass[1] = 1;
    pass[p] = 1;
    for (int i = 1; i <= w; i++)
    {
        int from, j, price;
        infile >> from, j, price;
        citis[from].price[j] = price;
        citis[j].price[from] = price;
    }
    infile.close();
    int cheapest = __INT_MAX__;
    travel(1, 1, citis, c, pass, p, 0, cheapest, trip);
    for (int j = 1; j <= p; j++)
        cout << trip[j] << " ";
    cout << endl
         << cheapest << endl;
    return 0;
}