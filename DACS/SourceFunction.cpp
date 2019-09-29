#include <iostream>
using namespace std;

void NhapMang(int phantu, int heso[]) {
	cout << "Nhap cac he so: " << endl;
	for (int i = 0; i <= phantu; i++) {
		cin >> heso[i];
	}
}
void XuatMang(int phantu, int heso[]) {
	for (int i = 0; i <= phantu; i++) {
		cout << heso[i] << " ";
	}
}
void XetMang(int phantu, int heso[]) {
	for (int i = 0; i <= phantu; i++) {
		heso[i] = 0;
	}
}
void NhanDaThuc(int p[], int q[], int r[], int m, int n, int k) {
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			k = i + j;
			r[k] += p[i] * q[j];
		}
	}
}

int main() {
	int p[10], q[10], r[100];
	int n,m,k;
	cout << "Nhap bac: ";
	cin >> n;
	NhapMang(n, p);
	cout << "Nhap bac: ";
	cin >> m;
	NhapMang(m, q);
	XetMang(m+n, r);
	NhanDaThuc(p, q, r, m, n, m+n);
	XuatMang(m+n, r);
	system("pause");
	return 0;
}