#include<iostream>

using namespace std;
void Nhap(int *a, int n) {
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
}
//void Xuat(int *a, int n) {
//	for (int i = 1; i < n; i++) {
//		cout << a[i]<< " ";
//	}
//}
int SLN(int *a, int n) {
	int max = a[1];
	for (int i = 2; i <= n; i++) {
		if (max <= a[i]) 
			max = a[i];
	}
	return max;
}
void VITRILN(int *a, int n) {
	for (int i = 1; i <= n; i++) {
		if (a[i] == SLN(a, n)) {
			cout << i<< " ";
		}
	}
}
int SNN(int *a, int n) {
	int min = a[1];
	for (int i = 2; i <= n; i++) {
		if (min >= a[i])
			min = a[i];
	}
	return min;
}
void VITRINN(int *a, int n) {
	for (int i = 1; i <= n; i++) {
		if (a[i] == SNN(a, n)) {
			cout << i<< " ";
		}
	}
}
int main() {
	int n;
	//cout << "Nhap so phan tu mang: ";
	cin >> n;
	int* a;
	a = new int[n];
	Nhap(a, n);
	cout << SLN(a, n)<<"\n";
	VITRILN(a, n);
	cout << endl;
	cout << SNN(a, n) << "\n";
	VITRINN(a, n);
	//delete[] a;
	return 0;
}