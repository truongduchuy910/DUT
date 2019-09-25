#include <iostream>
using namespace std;
int main() {
	int a, b, min;
	cout << "Nhap a va b:";
	cin >> a >> b;
	min = a > b ? b : a;
	int i;
	for (i = 2; i < min; i++){
		if ( (a % i ) == 0 && (b % i) == 0)  {
			break;
		}
	}
	if (i == min) {
		cout << "Khong co mau chung nho nhat";
	} else {
		cout << "Mau chung nho nhat la: " << i;
	}
	return 0;
}\
