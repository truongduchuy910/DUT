#include <iostream>
using namespace std;
bool la_uoc_so(int a, int b) {
	if (a > b) return false;
	if (a == b) return true;
	return la_uoc_so(a, b - a);
}
int main() {
	cout << "a: ";
	int a;
	cin >> a;
	cout << "b: ";
	int b;
	cin >> b;
	cout << la_uoc_so(a, b);
}	
