#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

struct sinhVien {
	int ma;
	string ten;
	float diemTB;
};
void Nhap(sinhVien& sv) {
	cin >> sv.ma;
	cin.ignore();
	getline(cin, sv.ten);
	
	cin >> sv.diemTB;
}
void Xuat(sinhVien& sv) {
	cout << sv.ma << endl;
	cout << sv.ten<<endl;
	cout << setprecision(1) << fixed << sv.diemTB<<endl;
}
struct mang {
	int n;
	sinhVien a[100];
	sinhVien& operator[](int i) {
		return a[i];
	}
	void operator=(mang m) {
		n = m.n;
		for (int i = 0; i < m.n; i++)
			a[i] = m[i];
	}
	mang() {
		n = 0;
	}
};
void nhapMang(mang& m) {
	cin >> m.n;
	for (int i = 0; i < m.n; i++) {
		Nhap(m[i]);
	}
}
void xuatMang(mang& m) {
	for (int i = 0; i < m.n; i++) {
		Xuat(m[i]);
		
	}
}
void kiemTra(mang m) {
	//mang t;
	
	for (int i = 0; i < m.n; i++) {
		if (m[i].diemTB >= 7) {
			Xuat(m[i]);
		}
	}
}
int main() {
	/*sinhVien sv;
	Nhap(sv);
	Xuat(sv);*/
	mang m;
	nhapMang(m);
	kiemTra(m);
	return 0;
}