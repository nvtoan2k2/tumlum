#include <iostream>
using namespace std;

struct phanSo {
	int tu;
	int mau;
};
phanSo nhapPhanSo(){
	phanSo ps;
	cout << "Nhap tu: ";
	cin >> ps.tu;
	cout << "Nhap mau: ";
	cin >> ps.mau;
	return ps;
}
void xuatPhanSo(phanSo ps) {
	cout << ps.tu << "/" << ps.mau << endl;
}
int gcd(int a, int b) {
	if ( b == 0) {
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
phanSo Cong(phanSo ps1, phanSo ps2) {
	phanSo ps3;
	ps3.tu = ps1.tu * ps2.mau + ps1.mau * ps2.tu;
	ps3.mau = ps1.mau * ps2.mau;
	return rutgon(ps3);
}
phanSo Tru(phanSo ps1, phanSo ps2) {
	phanSo ps3;
	ps3.tu = ps1.tu * ps2.mau - ps1.mau * ps2.tu;
	ps3.mau = ps1.mau * ps2.mau;
	return rutgon(ps3);
}
phanSo Nhan(phanSo ps1, phanSo ps2) {
	phanSo ps3;
	ps3.tu = ps1.tu * ps2.tu;
	ps3.mau = ps1.mau * ps2.mau;
	return rutgon(ps3);
}
phanSo Chia(phanSo ps1, phanSo ps2) {
	phanSo ps3;
	ps3.tu = ps1.tu * ps2.mau;
	ps3.mau = ps1.mau * ps2.tu;
	return rutgon(ps3);
}
bool toiGianPhanSo(int tu, int mau) {
	int ucln = gcd(tu, mau);
	return (ucln == 1);
}
phanSo quyDongPhanSo(phanSo ps1, phanSo ps2) {
	phanSo p3, p4;
	p3.tu = ps1.tu * ps2.mau;
	p3.mau = ps1.mau * ps2.mau;
	p4.tu = ps2.tu * ps1.mau;
	p4.mau = ps1.mau * ps2.mau;
	return p3, p4;
}
bool kiemTraAmDuong(int tu, int mau) {
	if (tu < 0 || mau < 0) {
		return false;
	}
	return true;
}
int BCNN(int a, int b) {
	return (a * b) / gcd(a, b);
}
bool soSanhHaiPhanSo(int tu1, int mau1, int tu2, int mau2) {
	toiGianPhanSo(tu1, mau1);
	toiGianPhanSo(tu2, mau2);
	int bcnn = BCNN(mau1, mau2);
	int tu_1 = tu1 * (bcnn / mau1);
	int tu_2 = tu2 * (bcnn / mau2);
	return tu_1 < tu_2;
}
int main() {
	phanSo ps1, ps2;
	cout << "Nhap phan so thu nhat: \n";
	ps1 = nhapPhanSo();
	cout << "Nhap phan so thu hai: \n";
	ps2 = nhapPhanSo();
	//xuatPhanSo(ps);
	cout << "Cong 2 phan so: ";
	xuatPhanSo(Cong(ps1,ps2));
	cout << endl;
	cout << "Tru 2 phan so: ";
	xuatPhanSo(Tru(ps1, ps2));
	cout << endl;
	cout << "Nhan 2 phan so: ";
	xuatPhanSo(Nhan(ps1, ps2));
	cout << endl;
	cout << "Chia 2 phan so: ";
	xuatPhanSo(Chia(ps1, ps2));
	cout << endl;
	cout << "Phan so " << ps1.tu << "/" << ps1.mau;
	if (toiGianPhanSo(ps1.tu, ps1.mau)) {
		cout << " da toi gian";
	}
	else
	{
		cout << " chua toi gian";
	}
	cout << endl;
	cout << "Phan so " << ps2.tu << "/" << ps2.mau;
	if (toiGianPhanSo(ps2.tu, ps2.mau)) {
		cout << " da toi gian";
	}
	else
	{
		cout << " chua toi gian";
	}
	cout << "\nPhan so thu nhat sau khi quy dong: ";
	xuatPhanSo(quyDongPhanSo(ps2, ps1));
	cout << "\nPhan so thu hai sau khi quy dong: ";
	xuatPhanSo(quyDongPhanSo(ps1, ps2));
	cout << "\nPhan so " << ps1.tu << "/" << ps1.mau;
	if (kiemTraAmDuong(ps1.tu, ps1.mau) == true) {
		cout << " la phan so duong";
	}
	else
	{
		cout << " la phan so am";
	}
	cout << endl;
	cout << "Phan so " << ps2.tu << "/" << ps2.mau;
	if (kiemTraAmDuong(ps2.tu, ps2.mau) == true) {
		cout << " la phan so duong";
	}
	else
	{
		cout << " la phan so am";
	}
	cout << "\nPhan so " << ps1.tu << "/" << ps1.mau;
	if (soSanhHaiPhanSo(ps1.tu, ps1.mau, ps2.tu, ps2.mau)) {
		cout << " nho hon ";
	}
	else
	{
		cout << " lon hon hoac bang ";
	}
	cout << "phan so " << ps2.tu << "/" << ps2.mau << endl;
	return 0;
}