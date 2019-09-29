#include <iostream>
using namespace std;
void solve(int n, int k) {
	int data[n];
	for (int i = 0; i < n; i++) data[i] = i + 1;

	int i = k - 1;
	while (i >= 0) {
		int gioi_han_tren = n - k + i + 1;
		if (data[i] < gioi_han_tren) {
			for (int j = 0; j < k; j++) cout << data[j];
			cout << endl;
			
			data[i]++;
			for (int j  = i + 1; j < k; j++) data[j] = data[j - 1] + 1;
			
			i = k - 1;

		} else {
			i--;
		}
	}
	for (int j = 0; j < k; j++) cout << data[j];
	cout << endl;
}
int main() {
	cout << "Input n, k (int int)";
	int n,k;
	cin >> n >> k;
	solve(n, k);
	return 0;
}

