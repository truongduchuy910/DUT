#include <iostream>
using namespace std;
bool sinh_thanh_cong(int a[], int n, int k) {
	int i = k - 1;
	while (i >= 0 && a[i] == n - k + i) i--;
	if (i < 0) return false;
	a[i]++;
	for (int j = i + 1; j < k; j++) a[j] = a[i] + j - i;
	return true;
}
int main() {
	cout << "n: ";
	int n;
	cin >> n;
	cout << "k: ";
	int k;
	cin >> k;
	int a[k];
	for (int i = 0; i < k; i++) a[i] = i;
	do {
		for (int i = 0; i < k; i++) cout << a[i];
		cout << endl;
	} while (sinh_thanh_cong(a, n, k));
}
