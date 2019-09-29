#include <iostream>
using namespace std;
void solve(int n) {
	int data[n];
	for (int i = 0; i < n; i++) data[i] = 0;
	int i = n - 1;
	do {
		if (data[i] == 0) {
			for (int j = 0; j < n; j++) cout << data[j];
			cout << endl;
			data[i] = 1;
			for (int j = i + 1; j < n; j++) data[j] = 0;
			i = n - 1;
		} else {
			i--;
		};
	} while (i >= 0);
	for (int j = 0; j < n; j++) cout << data[j];
	cout << endl;
}
int main() {
	cout << "Input n: ";
	int n;
	cin >> n;
	solve(n);
	return 0;
}
