#include <iostream>
using namespace std;

struct SoDao {
    int so; // số ban đầu
    int dao; // số đảo ngược
};

istream& operator>>(istream& is, SoDao& sd) {
    is >> sd.so;
    sd.dao = (sd.so % 10) * 100 + ((sd.so / 10) % 10) * 10 + (sd.so / 100);
    return is;
}
ostream& operator<<(ostream& os, SoDao& sd) {
    os << "[SoDao] " << sd.so << endl;
    return os;
}
int daoNguoc(SoDao sd) {
    return sd.dao;
}

bool operator > (SoDao sd1, SoDao sd2) {
    return sd1.dao > sd2.dao;
}
int operator + (SoDao sd, int x) {
    return sd.dao + x;
}

int main() {
    SoDao sd1, sd2;
    cin >> sd1 >> sd2;
    cout << sd1 << sd2;

    // So sánh hai SoDao
    if (sd1 > sd2) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    int tong = daoNguoc(sd1) + 0 + daoNguoc(sd2);
    cout << tong << endl;

    return 0;
}
