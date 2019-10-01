#include <iostream>
using namespace std;
class Dathuc {
private:
	int bac;
	int* heso;
public:
	Dathuc(int bac);
	~Dathuc();
	void Nhap();
	void Xuat();
	void Nhan(Dathuc& dt1, Dathuc& dt2);
};
Dathuc::Dathuc(int max) {
	bac = max;
	heso = new int[bac + 1];
	for (int i = 0; i <= bac; i++) {
		heso[i] = 0;
	}
}
Dathuc::~Dathuc() {
	delete[]heso;
}
void Dathuc::Nhap() {
	cout << "Nhap cac he so: " << endl;
	for (int i = 0; i <= bac; i++) {
		cin >> heso[i];
	}
}
void Dathuc::Xuat() {
	for (int i = 0; i <= bac; i++) {
		cout << heso[i] << " ";
	}
	cout << endl;
}
void Dathuc::Nhan(Dathuc& dt1, Dathuc& dt2) {
	for (int i = 0; i <= dt1.bac; i++) {
		for (int j = 0; j <= dt2.bac; j++) {
			bac = i + j;
			heso[bac] += dt1.heso[i] * dt2.heso[j];
		}
	}
}
int main() {
	int bacdt1, bacdt2;
	cout << "Nhap bac da thuc 1: "; cin >> bacdt1;
	Dathuc dt1(bacdt1);
	dt1.Nhap();
	dt1.Xuat();
	cout << "Nhap bac da thuc 2: "; cin >> bacdt2;
	Dathuc dt2(bacdt2);
	dt2.Nhap();
	dt2.Xuat();
	int bacdt3 = bacdt1 + bacdt2;
	Dathuc dt3(bacdt3);
	cout << "Tich 2 da thuc: ";
	dt3.Nhan(dt1, dt2);
	dt3.Xuat();
	system("pause");
	return 0;
}
