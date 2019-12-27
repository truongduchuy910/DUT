#include <iostream>
using namespace std;
long uoc_chung(long a, long b) {
	if (b == 0) return a;
	return uoc_chung(b, a % b);
}
int main() {
	cout << "a, b: ";
	long a, b;
	cin >> a >> b;
	cout << uoc_chung(a, b);
}
