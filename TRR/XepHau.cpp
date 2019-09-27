#include <iostream>
using namespace std;
void tryCol(int i, int n, bool* col, bool*diaX, bool* diaY) { 
};
int main() {
	cout << "Input size of chessboard (int): ";
	int n;
	cin >> n;
	bool col[n];
	bool diaX[2*n], diaY[2*n]; 
	for (int i = 0; i < n; i++) {
		col[i] = true;
	};
	for (int i = 0; i < 2*n; i++) {
		diaX[i] = true;
		diaY[i] = true;
	}; 
	tryCol(1, n, col, diaX, diaY);
}
