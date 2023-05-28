#include <iostream>
#include <algorithm>

using namespace std;

struct PhanSo {
    int tu, mau;
};

int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a % b);
}

PhanSo rutgon(PhanSo ps) {
    int ucln = gcd(ps.tu, ps.mau);
    ps.tu /= ucln;
    ps.mau /= ucln;
    if (ps.mau < 0) {
        ps.tu = -ps.tu;
        ps.mau = -ps.mau;
    }
    if (ps.tu == 0) ps.mau = 1;
    return ps;
}
ostream& operator << (ostream& os, PhanSo ps) {
    rutgon(ps);
    if (ps.tu == 0) os << 0;
    else if (ps.mau == 1) os << ps.tu;
    else {
        os << ps.tu << "/" << ps.mau;
    }
    return os;
}
PhanSo cong(PhanSo ps1, PhanSo ps2) {
    PhanSo ketqua;
    ketqua.tu = ps1.tu * ps2.mau + ps2.tu * ps1.mau;
    ketqua.mau = ps1.mau * ps2.mau;
    return rutgon(ketqua);
}

PhanSo tru(PhanSo ps1, PhanSo ps2) {
    PhanSo ketqua;
    ketqua.tu = ps1.tu * ps2.mau - ps2.tu * ps1.mau;
    ketqua.mau = ps1.mau * ps2.mau;
    return rutgon(ketqua);
}

PhanSo nhan(PhanSo ps1, PhanSo ps2) {
    PhanSo ketqua;
    ketqua.tu = ps1.tu * ps2.tu;
    ketqua.mau = ps1.mau * ps2.mau;
    return rutgon(ketqua);
}

PhanSo chia(PhanSo ps1, PhanSo ps2) {
    PhanSo ketqua;
    ketqua.tu = ps1.tu * ps2.mau;
    ketqua.mau = ps1.mau * ps2.tu;
    return rutgon(ketqua);
}

int main() {
    PhanSo ps1, ps2;
    cin >> ps1.tu >> ps1.mau >> ps2.tu >> ps2.mau;
    PhanSo kq;
    if (ps1.mau == 0 || ps2.mau == 0) cout << -1;

    else if (ps1.mau != 0 && ps2.mau != 0) { 
        kq = cong(ps1, ps2);
        cout << kq << "\n";
        kq = tru(ps1, ps2);
        cout << kq << "\n";
        kq = nhan(ps1, ps2);
        cout << kq << "\n";
        if (ps2.tu != 0) {
            kq = chia(ps1, ps2);
            cout << kq;
        }
        else {
            return 0;
        }
    }
}