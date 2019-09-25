#include <iostream>
using namespace std;
int main() {
	//input
	long n;
	long a[200000];
	cin >> n;
	cin >> a[1];
	cin >> a[2];
	long second_positive_value = a[1];
	long second_negative_value = a[2];
	long fist_positive_value = a[1];
	long fist_negative_value = a[2];
	// continue input and find min, max.
	for (long i = 3; i <= n; i++) {
		cin >> a[i];
		if (a[i] > fist_positive_value) {
			fist_positive_value = a[i];
		}
		if (a[i] < fist_negative_value) {
			fist_negative_value = a[i];
		}
	}
	for (long i = 1; i <= n; i++) {
		if (a[i] > second_positive_value && a[i] < fist_positive_value) {
			second_positive_value = a[i];
		}
		if (a[i] < second_negative_value && a[i] > fist_negative_value) {
			second_negative_value = a[i];
		}
	}
	if (fist_positive_value + second_positive_value > -(fist_negative_value + second_negative_value)) {
		cout << fist_positive_value + second_positive_value;
	}
	else {
		cout << -(fist_negative_value + second_negative_value);
	}
	
}
