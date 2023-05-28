#include <iostream>
#include <cmath>
using namespace std;

bool SNT(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int tachSo(int n) {
    int s = 0;
    while (n > 0) {
        int digit = n % 10;
        if (digit != 2 && digit != 3 && digit != 5 && digit != 7) {
            s += digit;
        }
        n /= 10;
    }
    return s;
}

int main() {
    int n;
    cin >> n;
    int numbers[n];
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    for (int i = 0; i < n; i++) {
        if (SNT(numbers[i])) {
            cout << tachSo(numbers[i]) << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
    return 0;
}
