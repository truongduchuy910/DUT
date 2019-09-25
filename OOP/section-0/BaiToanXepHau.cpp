#include <iostream>
using namespace std;

	int collum[8];
	int leftDiagonal[15];
	int rightDiagonal[15];
	int count = 0;
	
void print(int s[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j != s[i]) {
				cout << "[ ]";
			} else {
				cout << "[o]";
			}
		}
		cout << endl;
	}
	cout << endl;
}

void Try(int i, int s[], int n) {
		for (int j = 0; j < n; j++) {
			if (collum[j] == 1 && leftDiagonal[i + j] == 1 && rightDiagonal[i - j + 7] == 1) {
				collum[j] = 0;
				leftDiagonal[i + j] = 0;
				rightDiagonal[i - j + 7] = 0;	
				s[i] = j;		
					
				if (i == n - 1) {
					print(s,n);
					count++;
				};
				
				Try(i + 1, s, n);	
				collum[j] = 1;
				leftDiagonal[i + j] = 1;
				rightDiagonal[i - j + 7] = 1;			
				
			}
		}	
}

int main () {
	int s[8];
	for (int j = 0; j < 8; j++) {
		collum[j] = 1;
	}
	
	for (int j = 0; j < 15; j++) {
		leftDiagonal[j] = 1;
		rightDiagonal[j] = 1;
	}
	
	Try(0, s, 6);
	cout << count;
}
