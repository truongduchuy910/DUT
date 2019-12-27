#include <iostream>
using namespace std;
#include <fstream>
bool solution(int s[], int f[], int n) {
	for (int i = 0; i < n; i++) 
		for (int j = 0 ; j < n; j++) 
			if (f[i] < f[j]) {
				int temp = s[i];
				s[i] = s[j];
				s[j] = temp;
				temp = f[i];
				f[i] = f[j];
				f[j] = temp;
			}
	int F[n];
	F[0] = 0;
	int m = 1, i = 0;
	for (int j = 1; j < n; j++) {
		if (f[i] <= s[j]) {
			F[m] = j;
			m++; 
			i = j;
		}
	}
	for (int j = 0; j < m;j++) {
		cout << s[F[j]] << " " << f[F[j]] << endl;
	}
}
int main() {
	ifstream inFile("7.2.1.txt");
	int n;
	inFile >> n;
	int s[n], f[n];
	for (int i = 0; i < n; i++) inFile >> s[i] >> f[i];
	for (int i = 0; i < n; i++) cout << s[i] << " " << f[i] << endl;
	cout << "-----" << endl;
	solution(s, f, n);
}
