#include <iostream>
using namespace std;
bool la_hoan_vi(int a[], int k) {
	for (int i = 0; i < k; i++) 
		if (a[k] == a[i]) return false;
	return true;
}
bool hoan_vi(int a[], int n, int k) {
	if (k == n) {
		for(int i = 0; i < n; i++) cout << a[i] + 1;
		cout << endl;
		return false;
	}
	for(int i = 0; i < n; i++) {
		a[k] = i;
		if (la_hoan_vi(a, k)) hoan_vi(a, n, k + 1);
	}
}
int main() {
	cout << "n: ";
	int n;
	cin >> n;
	int a[n];
	hoan_vi(a, n, 0);
}
