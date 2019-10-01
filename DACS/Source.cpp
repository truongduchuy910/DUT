#include <iostream>
using namespace std;

int main() {
	int n, m, k, i, j;
	int p[10], q[10], r[100];
	cout << "Nhap bac cua P(x): ";
	cin >> n;
	cout << "Nhap cac he so cua P(x): ";
	for (i = 0; i <= n; i++) {
		cin >> p[i];
	}
	cout << "Nhap bac cua Q(x): ";
	cin >> m;
	cout << "Nhap cac he so cua Q(x): ";
	for (j = 0; j <= m; j++) {
		cin >> q[j];
	}
	for (k = 0; k <= m + n; k++) r[k] = 0;
	for (i = 0; i <= n; i++) {
		for (j = 0; j <= m; j++) {
			k = i + j;
			r[k] += p[i] * q[j];
		}
	}
	for (k = 0; k <= m + n; k++) cout << r[k] << " ";
	system("pause");
	return 0;
}