#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct TacGia {
    string ten_tac_gia;
};

struct Sach {
    string ten_sach;
    vector<TacGia> tac_gia;
    string nha_xuat_ban;
    int nam_xuat_ban;
};

void nhap_tac_gia(TacGia& tac_gia) {
    cout << "Nhap ten tac gia: ";
    getline(cin, tac_gia.ten_tac_gia);
}

void nhap_sach(Sach& sach) {
    cout << "Nhap ten sach: ";
    getline(cin, sach.ten_sach);

    int n;
    cout << "Nhap so luong tac gia: ";
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        TacGia tac_gia;
        nhap_tac_gia(tac_gia);
        sach.tac_gia.push_back(tac_gia);
    }

    cout << "Nhap nha xuat ban: ";
    getline(cin, sach.nha_xuat_ban);

    cout << "Nhap nam xuat ban: ";
    cin >> sach.nam_xuat_ban;
    cin.ignore();
}

void xuat_sach(const Sach& sach) {
    cout << sach.ten_sach << " - ";
    cout << sach.tac_gia.size() << " tac gia - ";
    cout << sach.nha_xuat_ban << " - ";
    cout << sach.nam_xuat_ban << endl;
}

int main() {
    int n;
    cout << "Nhap so luong sach: ";
    cin >> n;
    cin.ignore();

    vector<Sach> thu_vien(n);
    for (int i = 0; i < n; i++) {
        Sach sach;
        nhap_sach(sach);
        thu_vien[i] = sach;
    }

    cout << "Danh sach sach trong thu vien:\n";
    for (const auto& sach : thu_vien) {
        xuat_sach(sach);
    }

    return 0;
}
