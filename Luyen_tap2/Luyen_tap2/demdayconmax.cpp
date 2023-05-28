#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int dodai = 0; //max_length
    vector<int> mang_max;// max_sequence;
    int chieudai_hientai = 0; //current_length
    vector<int> mang_hientai; //current_sequence


    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) {
            chieudai_hientai++;
            mang_hientai.push_back(a[i]);
        }
        else {
            if (chieudai_hientai > dodai) {
                dodai = chieudai_hientai;
                mang_max = mang_hientai;
            }
            chieudai_hientai = 1;
            mang_hientai.clear();
            mang_hientai.push_back(a[i]);
        }
    }
    if (chieudai_hientai > dodai) {
        dodai = chieudai_hientai;
        mang_max = mang_hientai;
    }

    cout << dodai << endl;
    for (int i = 0; i < dodai; i++) {
        cout << mang_max[i] << " ";
    }
    cout << endl;

    return 0;
}
