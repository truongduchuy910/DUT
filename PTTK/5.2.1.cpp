#include <iostream>
using namespace std;
int binary_search(int a[], int n, int from, int to) {
	if (from > to) return false;
	int mid = (from + to) / 2;
	if (n > a[mid]) return binary_search(a, n, mid, to);
	if (n < a[mid]) return binary_search(a, n, from, mid);
	return mid;
}
int main() {
	int a[] = {1, 2, 2, 3, 4, 5, 5, 8, 8, 9, 10};
	cout << binary_search(a, 8, 0, 10);
}
