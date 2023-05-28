#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Khai báo cấu trúc dữ liệu của một nhân viên
struct NHANVIEN {
    string maNV;
    string tenNV;
    float luongNV;
};

// Hàm nhập thông tin của một nhân viên
void nhapNhanVien(NHANVIEN& nv) {
   
    cin >> nv.maNV;
    cin.ignore(); // Đọc bỏ dấu enter sau khi nhập maNV
    
    getline(cin, nv.tenNV);
    
    cin >> nv.luongNV;
}

// Hàm xuất thông tin của một nhân viên
void xuatNhanVien( NHANVIEN& nv) {
    cout <<  nv.maNV << endl;
    cout << nv.tenNV << endl;
    cout <<  fixed << setprecision(2) << nv.luongNV << endl;
}

// Hàm nhập danh sách nhân viên
void nhapDanhSach(vector<NHANVIEN>& danhSachNV) {
    int n;
    cin >> n;

    danhSachNV.resize(n); // Thay đổi kích thước danh sách thành n

   
    for (int i = 0; i < n; i++) {
        nhapNhanVien(danhSachNV[i]);
    }
}

// Hàm xuất danh sách nhân viên
void xuatDanhSach( vector<NHANVIEN>& danhSachNV) {
    for (int i = 0; i < danhSachNV.size(); i++) {
        xuatNhanVien(danhSachNV[i]);
    }
}

// Hàm tìm nhân viên có lương cao nhất
NHANVIEN timNhanVienLuongCaoNhat( vector<NHANVIEN>& danhSachNV) {
    NHANVIEN nvMaxLuong = danhSachNV[0];
    for (int i = 0; i < danhSachNV.size(); i++) {
        if (danhSachNV[i].luongNV > nvMaxLuong.luongNV) {
            nvMaxLuong = danhSachNV[i];
        }
    }
    return nvMaxLuong;
}

// Hàm tính tổng lương của các nhân viên
float tinhTongLuong( vector<NHANVIEN>& danhSachNV) {
    float tongLuong = 0.0;
    for (int i = 0; i < danhSachNV.size(); i++) {
        tongLuong += danhSachNV[i].luongNV;
    }
    return tongLuong;
}

// Hàm so sánh lương của hai nhân viên
// Hàm so sánh lương của hai nhân viên
bool soSanhLuong( NHANVIEN& nv1,  NHANVIEN& nv2) {
    return nv1.luongNV < nv2.luongNV;
}

// Hàm sắp xếp danh sách tăng dần theo lương nhân viên
void sapXepDanhSach(vector<NHANVIEN>& danhSachNV) {
    sort(danhSachNV.begin(), danhSachNV.end(), soSanhLuong);
}

int main() {
    vector<NHANVIEN> danhSachNV;
    nhapDanhSach(danhSachNV);
    xuatDanhSach(danhSachNV);
    NHANVIEN nvMaxLuong = timNhanVienLuongCaoNhat(danhSachNV);
    xuatNhanVien(nvMaxLuong);

    float tongLuong = tinhTongLuong(danhSachNV);
    cout <<fixed << setprecision(2) << tongLuong << endl;

  
    sapXepDanhSach(danhSachNV);
    xuatDanhSach(danhSachNV);

    return 0;
}

