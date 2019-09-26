#include <iostream>
using namespace std;
void tower(int n, char a[], char b[], char c[]) {
	if (n == 1) {
		cout << a << "->" << c << endl;
	} else {
		tower(n - 1, a, c, b);
		tower(1, a, b, c);
		tower(n - 1, b, a, c);
	}
}
int main() {
	char a[] = "A";
	char b[] = "B";
	char c[] = "C";
	tower(3, a, b, c);
	return 0;
}
