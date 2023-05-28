#include<iostream>
using namespace std;

void Nhap(int* a, int n) {
	for (int i = 0; i <= n; i++) {
		cin >> a[i];
	}
}
void MangDoiXung(int* a, int n) {
	bool flag = true;
	for (int i = 0; i < n / 2; i++) {
		if (a[i] != a[n - i - 1])
			flag = false;
	}
	if (flag) cout << "mang doi xung";
	else {
		cout << "mang khong doi xung \n";
		for (int i = 0; i < n / 2; i++) {
			if (a[i] != a[n - i - 1]) {
				cout << a[i] << " " << a[n - i - 1] << endl;
			}
		}
	}
	
}
int main() {
	int n;
	cin >> n;
	int* a = new int[n];
	Nhap(a, n);
	MangDoiXung(a, n);
	return 0;
}