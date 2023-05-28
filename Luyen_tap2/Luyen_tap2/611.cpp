#include <iostream>
#include <string>
using namespace std;

struct chuyenBay {
	string ma;
	int ngay, thang, nam;
	int gio, phut;
	string noiDi, noiDen;
};

istream& operator>>(istream& is, chuyenBay& cb) {
	getline(is >> ws, cb.ma);
	is >> cb.ngay >> cb.thang >> cb.nam >> cb.gio >> cb.phut;
	cin.ignore(); // Add this line to clear the newline character
	getline(is >> ws, cb.noiDi);
	getline(is >> ws, cb.noiDen);
	return is;
}

ostream& operator<<(ostream& os, chuyenBay cb) {
	os << "ma chuyen bay: " << cb.ma << endl;
	os << "ngay bay: " << cb.ngay ;
	if (cb.thang > 9) {
		os << "/" << cb.thang << "/" << cb.nam << endl;
	}
	else {
		os << "/0" << cb.thang << "/" << cb.nam << endl;
	}
	os << "gio bay: " << cb.gio;
	if (cb.phut > 9) {
		os << ":0" << cb.phut << endl;
	}
	else {
		os << ":" << cb.phut << endl;
	}
	os << "noi di: " << cb.noiDi << endl;
	os << "noi den: " << cb.noiDen;
	return os;
}

int main() {
	chuyenBay cb;
	cin >> cb;
	cout << cb;
	return 0;
}
