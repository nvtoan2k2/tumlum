#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class Diem {
public:
    int x, y;
};
float khoangcach(Diem A, Diem B) {
    return sqrt(pow(B.x - A.x, 2) + pow(B.y - A.y, 2));
}
float tinhDienTich(float AB, float AC, float BC) {
    float p = (AB + AC + BC) / 2;
    return sqrt(p * (p - AB) * (p - AC) * (p - BC));
}

float tinhChuVi(float AB, float AC, float BC) {
    return AB + AC + BC;
}
int main() {
    Diem A, B, C;

    
    cin >> A.x >> A.y;
    
    cin >> B.x >> B.y;
    
    cin >> C.x >> C.y;

    cout << "(" << A.x << "," << A.y << ") ";
    cout << "(" << B.x << "," << B.y << ") ";
    cout << "(" << C.x << "," << C.y << ")\n";
    float AB = khoangcach(A, B);
    float AC = khoangcach(A, C);
    float BC = khoangcach(B, C);
    cout << fixed << setprecision(3);
    cout << AB << endl;
    cout << AC << endl;
    cout << BC << endl;
    if ((B.y - A.y) * (C.x - A.x) == (C.y - A.y) * (B.x - A.x)) {
        cout << "-1" << endl;
    }
    else {
        float DT = tinhDienTich(AB, AC, BC);
        float CV = tinhChuVi(AB, AC, BC);

        cout << fixed << setprecision(3);
        cout << DT <<" ";
        cout << CV;
    }
    return 0;
}
