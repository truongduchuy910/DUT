#include <iostream>
using namespace std;
long giai_thua(int n) {
	if (n <= 0) return 1;
	return n * giai_thua(n - 1);
}
int main() {
	cout << "n: ";
	int n;
	cin >> n;
	cout << giai_thua(n);
}
