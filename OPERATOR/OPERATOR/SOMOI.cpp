#include <iostream>

using namespace std;

class somoi {
	int n;
public:
	somoi(int _n = 0) {
		n = _n;
	}
	somoi(const somoi& s) {
		n = s.n;
	}
	~somoi() {};
	friend istream& operator >> (istream& is, somoi& s) {
		is >> s.n;
		return is;
	}
	friend ostream& operator << (ostream& os, somoi& s) {
		os << "[SoMoi] " << s.n << endl;
		return os;
	}
	int tong() {
		int x = n;
		int tong = 0;
		while (x > 0) {
			tong += x % 10;
			x = x / 10;
		}
		return tong;
	}
	bool operator > (somoi& s) {
		if (tong() > s.tong()) {
			return true;
		}
		return false;
	}
	somoi operator + (somoi& s) {
		int x = tong() + s.tong();
		return x;
	}
};

int main() {
	somoi s1, s2;
	cin >> s1 >> s2;
	cout << s1 << s2;
	if (s1 > s2) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}
	somoi s3 = s1 + s2;
	cout << s3;
	return 0;
}
