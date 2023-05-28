#include <iostream>
#include <cmath>

using namespace std;

class mang {
	int n;
	int a[100];
public:
	mang(int _n = 0) {
		n = _n;
	}
	mang(const mang& m) {
		n = m.n;
	}
	~mang() {};
	friend istream& operator >> (istream& is, mang& m) {
		is >> m.n;
		for (int i = 0; i < m.n; i++) {
			is >> m.a[i];
		}
		return is;
	}
	friend ostream& operator << (ostream& os, mang& m) {
		for (int i = 0; i < m.n; i++) {
			os << m.a[i] << " ";
		}
		return os;
	}
	void operator + (mang& m) {
		mang kq;
		kq.n = max(n, m.n);
		for (int i = 0; i < kq.n; i++) {
			if (i >= n) {
				a[i] = 0;
			}
			if (i >= m.n) {
				m.a[i] = 0;
			}
			kq.a[i] = a[i] + m.a[i];
		}
		cout << kq;
	}
	//Toán tử gán mảng bằng mảng
	mang operator = (mang& m) {
		m.n = n;
		for (int i = 0; i < n; i++) {
			m.a[i] = a[i];
		}
		return m;
	}
	//So sánh bằng 
	bool operator == (mang& m) {
		if (n != m.n) {
			return false;
		}
		for (int i = 0; i < n; i++) {
			if (a[i] != m.a[i]) {
				return false;
			}
		}
		return true;
	}
	//So sánh khác
	bool operator != (mang& m) {
		if (n != m.n) {
			return true;
		}
		int dem = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] == m.a[i]) {
				dem++;
			}
		}
		if (dem == n) {
			return false;
		}
		return true;
	}
};

int main() {
	mang m, m1, m2;
	cin >> m1 >> m2;
	m1 + m2;
	return 0;
}