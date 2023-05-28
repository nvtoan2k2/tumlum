#include <iostream>
using namespace std;

void Nhap(int* a, int n) {
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
}
void Xuat(int* a, int n) {
	cout << n << "\n";
	for (int i = 1; i <= n; i++) {
		cout << a[i] << " ";
	}
}
void ThemVT(int* a, int& n, int x, int k) {
	for (int i = n; i >= k; i--) {
		a[i + 1] = a[i];

	}
	a[k] = x;
	n++;
}
int main() {
	int n, x, k;
	cin >> n >> x >> k;
	int* a = new int[n + 2];
	Nhap(a, n);
	ThemVT(a, n, x, k);
	Xuat(a, n);
	return 0;
}