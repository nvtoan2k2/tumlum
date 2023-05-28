#include<iostream>
using namespace std;

struct phanSo {
	int tu, mau;
};
istream& operator >> (istream& is, phanSo& p) {
	is >> p.tu >> p.mau;
	return is;
}
ostream& operator<<(ostream& os, phanSo p) {
	os << p.tu << "/" << p.mau;
	return  os;
}

int main() {
	phanSo p;
	cin >> p;
	string x;
	cin >> x;
	cout << p;
	cout << endl;
	if (x == "++") {
		p.tu += 1;
	}
	else {
		p.tu -= 1;
	}
	cout << p;
	return 0;
}