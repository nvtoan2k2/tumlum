#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct NHANVIEN {
    string maNV;
    string tenNV;
    float luongNV;
};

void nhapNhanVien(NHANVIEN& nv) {
    cin >> nv.maNV;
    cin.ignore();
    getline(cin, nv.tenNV);
    cin >> nv.luongNV;
}

void xuatNhanVien(NHANVIEN& nv) {
    cout << nv.maNV << endl;
    cout << nv.tenNV << endl;
    cout << fixed << setprecision(2) << nv.luongNV << endl;
}

void nhapDanhSach(vector<NHANVIEN>& danhSachNV) {
    int n;
    cin >> n;
    danhSachNV.resize(n);
    for (int i = 0; i < n; i++) {
        nhapNhanVien(danhSachNV[i]);
    }
}

void xuatDanhSach(vector<NHANVIEN>& danhSachNV) {
    for (int i = 0; i < danhSachNV.size(); i++) {
        xuatNhanVien(danhSachNV[i]);
    }
}

NHANVIEN timNhanVienLuongCaoNhat(vector<NHANVIEN>& danhSachNV) {
    NHANVIEN nvMaxLuong = danhSachNV[0];
    for (int i = 0; i < danhSachNV.size(); i++) {
        if (danhSachNV[i].luongNV > nvMaxLuong.luongNV) {
            nvMaxLuong = danhSachNV[i];
        }
    }
    return nvMaxLuong;
}

float tinhTongLuong(vector<NHANVIEN>& danhSachNV) {
    float tongLuong = 0.0;
    for (int i = 0; i < danhSachNV.size(); i++) {
        tongLuong += danhSachNV[i].luongNV;
    }
    return tongLuong;
}

void countingSort(vector<NHANVIEN>& danhSachNV, int exp) {
    const int RADIX = 10;
    vector<int> count(RADIX, 0);
    vector<NHANVIEN> output(danhSachNV.size());

    for (int i = 0; i < danhSachNV.size(); i++) {
        int digit = int(danhSachNV[i].luongNV / exp) % RADIX;
        count[digit]++;
    }

    for (int i = 1; i < RADIX; i++) {
        count[i] += count[i - 1];
    }

    for (int i = danhSachNV.size() - 1; i >= 0; i--) {
        int digit = int(danhSachNV[i].luongNV / exp) % RADIX;
        output[count[digit] - 1] = danhSachNV[i];
        count[digit]--;
    }

    for (int i = 0; i < danhSachNV.size(); i++) {
        danhSachNV[i] = output[i];
    }
}
void radixSort(vector<NHANVIEN>& danhSachNV) {
    // Tìm phần tử có lương cao nhất để xác định số chữ số cần sắp xếp
    NHANVIEN nvMaxLuong = timNhanVienLuongCaoNhat(danhSachNV);
    int maxLuong = int(nvMaxLuong.luongNV);

    // Áp dụng counting sort cho mỗi chữ số từ phải sang trái
    for (int exp = 1; maxLuong / exp > 0; exp *= 10) {
        countingSort(danhSachNV, exp);
    }
}

int main() {
    vector<NHANVIEN> danhSachNV;
    nhapDanhSach(danhSachNV);
    xuatDanhSach(danhSachNV);
    NHANVIEN nvMaxLuong = timNhanVienLuongCaoNhat(danhSachNV);
    xuatNhanVien(nvMaxLuong);

    float tongLuong = tinhTongLuong(danhSachNV);
    cout << fixed << setprecision(2) << tongLuong << endl;

    radixSort(danhSachNV);
    xuatDanhSach(danhSachNV);

    return 0;
}
