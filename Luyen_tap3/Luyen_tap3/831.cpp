#include<iostream>
#include<string>
using namespace std;

struct dienThoai {
	string ten;
	int donGia, soLuongTon;

};
void Nhap(dienThoai& dt) {
	cin.ignore();
	getline(cin, dt.ten);
	cin >> dt.donGia >> dt.soLuongTon;
	
}
void Xuat(dienThoai& dt) {
	cout << dt.ten<<", "<< dt.donGia<<", "<< dt.soLuongTon << endl;
}
struct mang {
	int n;
	dienThoai a[100];
	dienThoai& operator[](int i) {
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
void XuatMang(mang& m) {
	for (int i = 0; i < m.n; i++) {
		if (m.n == 0) {
			cout << "-1";
		}

		Xuat(m[i]);
	}
}
void tonKhoMax(mang m) {
	int max = m[0].soLuongTon;
	dienThoai x = m[0];
	for (int i = 0; i < m.n; i++) {
		if (max < m[i].soLuongTon) {
			max = m[i].soLuongTon;
			x = m[i];
		}
	}
	int tong = max * x.donGia;
	cout << x.ten << ", " << tong<<endl;
}
void demSoLuongTonKho(mang m) {
	int dem = 0;
	for (int i = 0; i < m.n; i++) {
		if (m[i].soLuongTon > 1000) {
			dem++;
		}
	}
	cout << dem << endl;
}
int main() {
	mang m;
	nhapMang(m);
	XuatMang(m);
	tonKhoMax(m);
	demSoLuongTonKho(m);
	return 0;
}