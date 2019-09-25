#include <iostream>
using namespace std;
void print(int s[], int k) {
	for (int i = 1; i <= k; k++) {
		cout<< s[i];
	}
	cout << endl;
}
void combination(int i, int s[],int k, int n) {
	for (int j = 1; j <= n; j++) {
		if (
			j <= n - k + i &&
			j >= s[i - 1] + 1
		) {
			s[i] = j;
			if (i == n) {
				print(s,n);
			} else {
				combination(i + 1, s,k, n);
			}
		}
	}
}

int main() {
	int s[] = {0,1,2,3,4,5,6};
	combination(1,s,3,6);
	return 0;
}
