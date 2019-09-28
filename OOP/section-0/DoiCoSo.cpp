#include <iostream>
using namespace std;
void doiCoSo(int n, int coSo) {
    if (n == 0) {
        cout << 0;
    } else {
        doiCoSo(n/coSo, coSo);
        cout << n%coSo;
    }
}
int main() {
    doiCoSo(4, 2);
}