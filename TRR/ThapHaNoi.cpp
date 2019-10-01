#include <iostream>
using namespace std;
void move(int n, char A, char B, char C) {
	if (n == 1) {
		cout << A << " to " << C << endl;
	} else {
		move(n - 1, A, C, B);
		move(1, A, B, C);
		move(n -1, B, A, C);
	}
}
int main() {
	char A = 'A';
	char B = 'B';
	char C = 'C';
	cout << "Input number of disks in collum A: ";
	int n;
	cin >> n;
	move(n, A, B, C);
}	
