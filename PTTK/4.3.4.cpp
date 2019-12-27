#include <iostream>
using namespace std;
bool move(int disk, int i, int j) {
	if (disk <= 0) return false;
        move(disk - 1, i, 6 - i - j);
        cout << i << " to " << j << endl;
        move(disk - 1, 6 - i - j, j);
}
int main() {
	cout << "n: ";
	int n;
	cin >> n;
	move(n, 1, 3);
}
