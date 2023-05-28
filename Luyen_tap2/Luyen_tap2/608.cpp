#include<iostream>
#include<string>
using namespace std;

struct hopSua {
	string nhanHieu;
	double trongLuong;
	struct	Ngay {
		int ngay, thang, nam;
	}hanSuDung;
};
istream& operator>>(istream& is, hopSua& hs) {
	getline(is, hs.nhanHieu);
	is >> hs.trongLuong >> hs.hanSuDung.ngay >> hs.hanSuDung.thang >> hs.hanSuDung.nam;
	return is;
}
ostream& operator<<(ostream& os, hopSua hs) {
	os << hs.nhanHieu << endl;
	os << hs.trongLuong << endl;
	os << hs.hanSuDung.ngay << "/" << hs.hanSuDung.thang << "/" << hs.hanSuDung.nam<<endl;
	return os;
}
struct mang {
	int n;
	hopSua a[100];
	hopSua& operator[](int i) {
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
istream& operator>>(istream& is, mang& m) {
	hopSua hs;
	while (is >> hs) m[m.n++];
	return is;
}
ostream& operator<<(ostream& os, mang m) {
	for (int i = 0; i < m.n; i++) {
		os << m[i];
	}
	return os;
}
void kiemTra(mang m, int x) {
	int dem = 0;
	for (int i = 0; i < m.n; i++) {
		if (x > m[i].hanSuDung.ngay) {
			dem++;
		}
	}
	cout << dem;
}
void Max(mang m) {
	
}
int main() {
	hopSua hs;
	cin >> hs;
	cout << hs;
	return 0;
}