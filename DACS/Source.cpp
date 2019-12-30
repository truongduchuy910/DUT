#include <iostream>
#include <iomanip>
using namespace std;

class Poly {
private:
	double* data;
	int size;
public:
	Poly(int n);
	~Poly();
	Poly(const Poly& m);
	friend istream& operator >> (istream& in, const Poly& m);
	friend ostream& operator << (ostream& out, const Poly& m);
	const Poly& operator = (const Poly& b);
	friend Poly operator+(const Poly& m, const Poly& n);
	friend Poly operator-(const Poly& m, const Poly& n);
	friend Poly operator*(const Poly& m, const Poly& n);
	friend Poly operator*(const Poly& m, double x);
	friend Poly operator/(const Poly& m, const Poly& n);
	double& operator[] (int i);
};
Poly::Poly(int n) {
	size = n;
	data = new double[size + 1];
	for (int i = 0; i <= size; i++) {
		data[i] = 0;
	}
}
Poly::~Poly() {
	delete[]data;
}
Poly::Poly(const Poly& m) {
	size = m.size;
	data = new double[size + 1];
	for (int i = 0; i <= size; i++) {
		data[i] = m.data[i];
	}
}
istream& operator >> (istream& in, const Poly& m) {
	for (int i = 0; i <= m.size; i++) {
		cout << "x^" << i << " = ";
		cin >> m.data[i];
	}
	return in;
}
ostream& operator << (ostream& out, const Poly& m) {
	for (int i = 0; i <= m.size; i++) {
		cout << setw(5) << m.data[i] ;
	}
	return out;
}
const Poly& Poly::operator = (const Poly& m) {
	if (this != &m) {
		size = m.size;
		delete[] data;
		data = new double[size + 1];
		for (int i = 0; i <= size; i++) {
			data[i] = m.data[i];
		}
	}
	return *this;
}

Poly operator+(const Poly& m, const Poly& n) {
	int _size = (m.size >= n.size) ? m.size : n.size;
	Poly tmp(_size);
	if (m.size > n.size) {
		for (int i = 0; i <= n.size; i++) {
			tmp[i] = m.data[i] + n.data[i];
		}
		for (int i = n.size + 1; i <= m.size; i++) {
			tmp[i] = m.data[i];
		}
	}
	else if (m.size < n.size) {
		for (int i = 0; i <= m.size; i++) {
			tmp[i] = m.data[i] + n.data[i];
		}
		for (int i = m.size + 1; i <= n.size; i++) {
			tmp[i] = n.data[i];
		}
	}
	else {
		for (int i = 0; i <= tmp.size; i++) {
			tmp[i] = m.data[i] + n.data[i];
		}
	}
	return tmp;
}

Poly operator-(const Poly& m, const Poly& n) {
	int _size = (m.size >= n.size) ? m.size : n.size;
	Poly tmp(_size);
	if (m.size > n.size) {
		for (int i = 0; i <= n.size; i++) {
			tmp[i] = m.data[i] - n.data[i];
		}
		for (int i = n.size + 1; i <= m.size; i++) {
			tmp[i] = -m.data[i];
		}
	}
	else if (m.size < n.size) {
		for (int i = 0; i <= m.size; i++) {
			tmp[i] = m.data[i] - n.data[i];
		}
		for (int i = m.size + 1; i <= n.size; i++) {
			tmp[i] = -n.data[i];
		}
	}
	else {
		for (int i = 0; i <= tmp.size; i++) {
			tmp[i] = m.data[i] - n.data[i];
		}
	}
	return tmp;
}

Poly operator*(const Poly& m, const Poly& n) {
	Poly tmp(m.size + n.size);
	for (int i = 0; i <= m.size; i++) {
		for (int j = 0; j <= n.size; j++) {
			int k = i + j;
			tmp[k] += m.data[i] * n.data[j];
		}
	}
	return tmp;
}

Poly operator*(const Poly& m, double x) {
	Poly tmp(m.size);
	for (int i = 0; i <= m.size; i++) {
		tmp[i] = m.data[i] * x;
	}
	return tmp;
}

Poly operator/(const Poly& m, const Poly& n) {
	int k = n.size;
	Poly r(m.size - n.size);
	Poly result(m.size - n.size);
	Poly tmp(m.size);
	Poly t(m.size);
	//Poly du(m.size);
	t = m;
	/*r (int i = 0; i <= m.size; i++) {
		cout << setw(5) << t[i];
	}
	cout << endl;*/
	for (int i = m.size; i >= n.size; i--) {
		result[i - k] = t.data[i] / n.data[k];
		r[i - k] = result[i - k];
		tmp = n * r;
		t = (m - tmp);
		t.size = t.size - 1;
	}
	//In ra da thuc du
	cout << "Du: " << endl;
	for (int i = 0; i <= n.size - 1; i++) {
		cout << setw(5) << t[i];
	}
	cout << endl;
	/*for (int i = 0; i <= m.size; i++) {
		cout << setw(5) << m.data[i];
	}
	cout << endl;*/
	/*tmp = result * n;
	du = m - tmp;
	for (int i = 0; i <= n.size - 1; i++) {
		cout << setw(5) << du[i];
	}
	cout << endl;*/
	return result;
}

double& Poly::operator [] (int i) {
	return data[i];
}
int main() {
	int n, m;
	cout << "Nhap bac P(x): ";
	cin >> m;
	cout << "Nhap bac Q(x): ";
	cin >> n;
	int k = (m >= n) ? m : n;
	Poly a(m), b(n), c(k), d(k), e(m+n-1), f(k);
	cin >> a;
	cin >> b;
	c = a + b;
	cout << c << endl;
	d = a - b;
	cout << d << endl;
	e = a * b;
	cout << e << endl;
	f = a / b;
	cout << f << endl;
	system("pause");
	return 0;
}