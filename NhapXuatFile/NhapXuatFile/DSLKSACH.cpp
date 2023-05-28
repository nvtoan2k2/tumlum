#include <iostream>
#include <string>
using namespace std;

struct TacGia {
    int n;
    string danhsach[5];

    void Nhap() {
        cout << "Nhap so luong tac gia: ";
        cin >> n;
        cout << "Nhap danh sach tac gia:\n";
        for (int i = 0; i < n; i++) {
            cout << "Tac gia " << i + 1 << ": ";
            cin >> danhsach[i];
        }
    }
};

struct Sach {
    string tenSach;
    TacGia tacGia;
    string nhaXuatBan;
    int namXuatBan;

    void Nhap() {
        cout << "Nhap ten sach: ";
        cin.ignore();
        getline(cin >> ws, tenSach);
        tacGia.Nhap();
        cout << "Nhap nha xuat ban: ";
        cin.ignore();
        getline(cin >> ws, nhaXuatBan);
        cout << "Nhap nam xuat ban: ";
        cin >> namXuatBan;
    }

    void Xuat() {
        cout << tenSach << "-" << tacGia.n << " tac gia-"
            << nhaXuatBan << "-" << namXuatBan << endl;
    }

};

struct Node {
    Sach data;
    Node* next;
};

void ThemSach(Node*& head, Sach s) {
    Node* p = new Node;
    p->data = s;
    p->next = NULL;
    if (head == NULL) {
        head = p;
        return;
    }
    else {
        Node* k = head;
        while (k->next != NULL) {
            k = k->next;
        }
        k->next = p;
    }
}

void XuatDanhSach(Node* head) {
    while (head != NULL) {
        head->data.Xuat();
        head = head->next;
    }
}
int timSoLuongSachCuaTacGia(Node* head, string tenTacGia) {
    int soLuongSach = 0;
    while (head != NULL) {
        for (int i = 0; i < head->data.tacGia.n; i++) {
            if (head->data.tacGia.danhsach[i] == tenTacGia) {
                soLuongSach++;
            }
        }
        head = head->next;
    }
    return soLuongSach;
}

int main() {
    int nam, soluong;
    string nxb, tacgia;
    int n;
    cout << "Nhap nam can tim kiem: ";
    cin >> nam;
    cout << "Nhap ten nha xuat ban can tim kiem: ";
    cin.ignore();
    getline(cin, nxb);
    cout << "Nhap ten tac gia can tim kiem: ";
    getline(cin, tacgia);
    cout << "Nhap so luong sach trong thu vien: ";
    cin >> n;

    Node* ds_sach = new Node[n];
    for (int i = 0; i < n; i++) {
        Sach s;
        cout << "Nhap thong tin cho quyen sach " << i + 1 << ":\n";
        s.Nhap();
        ThemSach(ds_sach, s);
    }

    cout << "Danh sach cac quyen sach trong thu vien:\n";
    XuatDanhSach(ds_sach);
    
    return 0;
}
