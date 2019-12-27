#include <iostream>
using namespace std;
int C(int n, int k) {
	int c[n][n];
	for (int i = 0; i <= n - k; i++) c[i][0] = 1;
	for (int i = 0; i <= k; i++) c[i][i] = 1;
	for (int j = 1; j <= k; j++) 
		for (int i = j + 1; i <= n - k + j; i++)
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
	return c[n][k];
}
int main() {
	cout << C(8, 5);
}
