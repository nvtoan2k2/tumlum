#include <iostream>
using namespace std;

struct phanSo {
	int tu, mau;
};

istream& operator>>(istream &is, phanSo& p) {
	is >> p.tu >> p.mau;
	return is;
}
ostream& operator<<(ostream &os, phanSo p) {
	os << p.tu << "/" << p.mau;
	return os;
}
int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}

	return gcd(b, a % b);
}
phanSo rutgon(phanSo ps) {
	int x = gcd(ps.tu, ps.mau);
	ps.tu = ps.tu / x;
	ps.mau = ps.mau / x;
	return ps;
}
phanSo operator+(phanSo p1, phanSo p2) {
	phanSo p3;
	p3.tu = p1.tu * p2.mau + p2.tu * p1.mau;
	p3.mau = p1.mau * p2.mau;
	return rutgon(p3);
}
bool operator ==(phanSo a, phanSo b) {
	return a.tu * b.mau == a.mau * b.tu;
}
bool operator !=(phanSo a, phanSo b) {
	return a.tu * b.mau != a.mau * b.tu;
}

int main() {
	phanSo ps1, ps2, ps3;
	cin >> ps1 >> ps2;
	ps3 = ps1 + ps2;
	cout << ps3;
	return 0;
}