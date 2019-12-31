#include <iostream>
using namespace std;
bool sinh_thanh_cong(int n, int a[]) {
	int i = n - 1;
	while (i >= 0 && a[i] != 0) a[i--] = 0;
	if (i >= 0) a[i] = 1;
	else return false;
	return true;	
}
int main() {
	cout << "n: ";
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) a[i] = 0;
	do {
		for (int i = 0; i < n; i++) cout << a[i];
		cout << endl;
	} while (sinh_thanh_cong(n, a));
}
