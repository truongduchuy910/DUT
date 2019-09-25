#include <iostream>
using namespace std;
int *nhan_da_thuc (int *P, int *Q);
int main () {
	int P = 3;
	int Q = 4;
	cout << *nhan_da_thuc(&P, &Q);
}
int *nhan_da_thuc (int* P, int* Q) {
	return (P);
}
