#include <iostream>

using namespace std;

class diem {
	int x, y;//x là hoành độ, y là tung độ
public:
	diem(int _x = 0, int _y = 0) {
		x = _x;
		y = _y;
	}
	diem(const diem& d) {
		x = d.x;
		y = d.y;
	}
	~diem() {};
	friend istream& operator >> (istream& is, diem& d) {
		is >> d.x >> d.y;
		return is;
	}
	friend ostream& operator << (ostream& os, diem& d) {
		os << "(" << d.x << "," << d.y << ")" << endl;
		return os;
	}
	bool operator == (diem& d) {
		if (x == d.x && y == d.y) {
			return true;
		}
		return false;
	}
	bool operator > (diem& d) {
		if (x > d.x) {
			return true;
		}
		if (x == d.x) {
			if (y > d.y) {
				return true;
			}
			else {
				return false;
			}
		}
		return false;
	}
	diem operator + (diem& d) {
		diem kq;
		kq.x = x + d.x;
		kq.y = y + d.y;
		return kq;
	}
};
class mang {
	int n;
	diem d[100];
public:
	mang(int _n = 0) {
		n = _n;
	}
	mang(const mang& m) {
		n = m.n;
	}
	~mang() {};
	friend istream& operator >> (istream& is, mang& m) {
		while (is >> m.d[m.n]) {
			m.n++;
		}
		return is;
	}
	friend ostream& operator << (ostream& os, mang& m) {
		diem max = m.d[0];
		for (int i = 1; i < m.n; i++) {
			if (m.d[i] > max) {
				max = m.d[i];
			}
		}
		cout << max;
		diem tong;
		for (int i = 0; i < m.n; i++) {
			tong = tong + m.d[i];
		}
		cout << tong;
		return os;
	}
};
int main() {
	mang d;
	cin >> d;
	cout << d;
	return 0;
}