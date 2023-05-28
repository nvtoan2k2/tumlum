#include <iostream>
using namespace std;


void Nhap(int* a, int n = 0) {
	for (int i = 0; i < n; i++) {
			 cin >> a[i];
	}
}
void Xuat(int* a, int n) {
	cout << n << endl;
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}

void XoaPT(int* a, int&n, int x) {
	for (int i = 0; i < n; i++) {
		if (a[i] == x) {
			for (int j = i; j < n; j++) {
				a[j] = a[j + 1];
			}
			--i;
			n = n - 1;
		}
	
	}
}
int main() {
	int n ,x;
	cin >> n;
	cin >> x;
	int* a = new int[n];
	Nhap(a, n);
	XoaPT(a, n, x);
	Xuat(a, n);
	return 0;
}