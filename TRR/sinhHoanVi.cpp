#include <iostream>
using namespace std;
bool sinh_thanh_cong(int a[], int n) {
	int i = n - 2;
	while (i >= 0 && a[i] > a[i + 1]) i--;
	if (i < 0) return false;
	int k = n - 1;
	while (a[k] < a[i]) k--;
	int temp = a[i];
	a[i] = a[k];
	a[k] = temp;
	int left = i + 1;
	int right = n - 1;
	while (left < right) {
		temp = a[left];
		a[left] = a[right];
		a[right] = temp;
		left++;
		right--;
	}
	return true;
}
int main() {
	cout << "n: ";
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) a[i] = i;
	do {
		for (int i = 0; i < n; i++) cout << a[i] + 1;
		cout << endl;
	} while (sinh_thanh_cong(a, n)); 
}
