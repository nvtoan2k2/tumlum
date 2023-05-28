 //BAI LAM CHUA HOAN THIEN 
#include<iostream>

using namespace std;

void Nhap(int* a, int n) {
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
}
void Xuat(int* a, int n) {
    for (int i = 1; i <= n; i++) {
        if (a[i] + a[i + 1] == a[i + 2]) {

            cout << "YES";
            break;
        }
        else {
            cout << "NO";
            break;
        }
    }
    
}
int main() {
    int n;
    cin >> n;
    int* a = new int[n];
    Nhap(a, n);
    Xuat(a, n);
    return 0;
}