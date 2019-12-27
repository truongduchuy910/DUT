#include <iostream>
using namespace std;
void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}
bool quickSort(int a[], int from, int to) {
	if (from > to) return false;
	int m = from;
	for (int i = from + 1; i <= to; i++)
		if (a[i] < a[from]) swap(a[++m], a[i]);
	swap(a[from], a[m]);
	quickSort(a, from, m - 1);
	quickSort(a, m + 1, to);
	return true;
}
int main() {
	int a[] = {9,6,8,7,4,5,3,2,1};
	quickSort(a, 0, 8);
	for (int i = 0; i < 9; i++) {
		cout << a[i] << " ";
	}
}
