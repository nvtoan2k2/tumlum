#include <iostream>
using namespace std;


struct HCN {
    float chieu_dai, chieu_rong;
    

    float chu_vi() {
        return 2 * (chieu_dai + chieu_rong);
    }

  
    bool operator<(HCN hcn) {
        return chu_vi() < hcn.chu_vi();
    }

    float operator+(float so_thuc) {
        return chu_vi() + so_thuc;
    }
    friend istream& operator>>(istream& is, HCN& h) {
        is >> h.chieu_dai >> h.chieu_rong;
        return is;
    }


    friend ostream& operator<<(ostream& os, HCN &h) {
        os << "[HCN] " << h.chieu_dai << "," << h.chieu_rong << endl;
        return os;
    }   
};

int main() {
    HCN hcn1, hcn2;
    cin >> hcn1 >> hcn2;
    cout << hcn1 << hcn2;

    // So sánh 2 HCN và xuất kết quả
    if (hcn1 < hcn2) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

    return 0;
}