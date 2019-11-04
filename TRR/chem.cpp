#include <iostream>
using namespace std;
void kill(int index, int n, int* position,int& count, int& die) {
	if (index == n + 1) {
		index = 1;
	};
	if (position[index] == 1) {
		count++;
	}
	if (count == 3) {
		position[index] = 0;
		die++;
		count = 0;
	};
	if (n - die > 2) {
		kill(index + 1, n, position, count, die);
	} else {
		for (int i = 1; i <= n; i++) {
			if (position[i] == 1) {
				cout << i << endl;
			}
		}
	}
}
void solve(int n) {
	int position[n + 1];
	for (int i = 1; i <= n; i++) {
		position[i] = 1;
	}
	int die = 0, count = 0;
	kill(1, n, position, count, die);
}
int main() {
	int n;
	cout << "n: ";
	cin >> n;
	solve(n);
};
