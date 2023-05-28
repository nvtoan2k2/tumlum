#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

bool laSoChinhPhuong(int n) {
    int can = sqrt(n);
    return can * can == n;
}

int main() {
    ifstream fileIn("FSTREAM.inp");
    ofstream fileOut("FSTREAM.out");

    if (!fileIn.is_open() || !fileOut.is_open()) {
        return 0;
    }

    int n;
    fileIn >> n;

    if (laSoChinhPhuong(n)) {
        fileOut << "YES" << endl;
    }
    else {
        fileOut << "NO" << endl;
    }

    fileIn.close();
    fileOut.close();

    return 0;
}
