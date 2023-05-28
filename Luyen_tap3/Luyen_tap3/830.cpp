#include<iostream>
#include<string>
#include<iomanip>
#include<algorithm>
#include<vector>
using namespace std;

struct Time {
	int gio, phut;
};
istream& operator>>(istream& is, Time& t) {
	char x;
	is >> t.gio >> x >> t.phut >> x;
	return is;
}
ostream& operator<<(ostream& os, Time t) {
	os << t.gio << ":" << setfill('0') << setw(2) << t.phut << "h";
	return os;
}
bool operator<(Time m1, Time m2) {
	return m1.gio <= m2.gio && m1.phut <= m2.phut;
}
struct Date {
	int ngay, thang, nam;
};
istream& operator>>(istream& is, Date& d) {
	char x;
	is >> d.ngay >> x >> d.thang >> x >> d.nam;
	return is;
}
ostream& operator<<(ostream& os, Date d) {
	os << d.ngay <<"/" << d.thang <<"/" << d.nam;

	return os;
}
bool operator<(Date d1, Date d2) {
	return d1.ngay <= d2.ngay&& d1.thang <= d2.thang&& d1.nam <= d2.nam;
}
bool operator==(Date d1, Date d2) {
	return d1.ngay == d2.ngay&& d1.thang== d2.thang&& d1.nam == d2.nam;
}
struct vePhim {
	string Ten;
	int Gia;
	Time thoiGian;
	Date Ngay;
};
istream& operator>>(istream& is, vePhim& vp) {
	//is.ignore();
	getline(is, vp.Ten);
	is >> vp.Gia;
	is >> vp.thoiGian;
	is >> vp.Ngay;
	return is;
}
ostream& operator<<(ostream& os, vePhim vp) {
	os << vp.Ten << endl;
	os << vp.Gia << endl;
	os << vp.thoiGian << endl;
	os << vp.Ngay << endl;
	return os;
}
bool tangDan(vePhim vp1, vePhim vp2) {
	return vp1.Ngay < vp2.Ngay || vp1.Ngay == vp2.Ngay && vp1.thoiGian < vp2.thoiGian;
}
struct mang {
	int n;
	vePhim a[100];
	vePhim& operator[](int i) {
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
vector<vePhim> nhapMang() {
	vector<vePhim> myVector;
	vePhim vp;
	while (true) {
		cin >> vp;
		myVector.push_back(vp);
	}

	return myVector;
}
void xuatMang(vector<vePhim>& myVector) {
	for (int i = 0; i < myVector.size(); i++) {
		cout << myVector[i];
	}
	cout << endl;
}
istream& operator>>(istream& is, mang& m) {
	vePhim vp;
	while (is >> vp) m[m.n++] = vp;
	return is;
}
ostream& operator<<(ostream& os, mang m) {
	for (int i = 0; i < m.n; i++) {
		os << m[i];
	}
	return os;
}
int tinhTong(vector<vePhim>& myvector) {
	int tong = 0;
	for (int i = 0; i < myvector.size(); i++) {
		tong = tong + myvector[i].Gia;
	}
	return tong;
}
void sapXep(vector<vePhim>& myvector) {
	sort(myvector.begin(), myvector.end(), tangDan);
	
}
int main() {
	vector<vePhim> myvector;
	nhapMang();	
	xuatMang(myvector);
	cout<<tinhTong(myvector);
	sapXep(myvector);
	xuatMang(myvector);
	return 0;
}