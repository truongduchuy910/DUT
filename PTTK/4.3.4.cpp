#include <iostream>
using namespace std;
bool move(int disk, int i, int j) {
	if (disk <= 0) return false;
        move(disk - 1, i, 6 - i - j);
        cout << i << " to " << j << endl;
        move(disk - 1, 6 - i - j, j);
	r
}
bool moveOrther(int disk, int a, int b, int c) {
	if (disk == 1) {
		cout << a << " to " << c << endl;
		return false;
	}
	moveOrther(disk - 1, a, c, b);
	moveOrther(1, a, b, c);
	moveOrther(disk - 1, b, a, c);
	return true;
}
int main() {
	cout << "n: ";
	int n;
	cin >> n;
	cout << "solve with move" << endl;
	move(n, 1, 3);
	cout << "solve with moveOrther" << endl;
	moveOrther(n, 1, 2, 3);
}
