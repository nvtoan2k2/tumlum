#include<iostream>
#include<string>
using namespace std;


struct Sach {
	string ten, tacGia;
	int nam;	
	Sach* pNext;
};

class danhSach {
private:
	Sach* pHead;
public:
	danhSach() {
		pHead = NULL;
	}
	void themSach(string ten, string tacGia, int nam) {
		Sach* newSach = new Sach;
		newSach->ten = ten;
		newSach->tacGia = tacGia;
		newSach->nam = nam;
		newSach->pNext = NULL;
		if (pHead == NULL) {
			pHead = newSach;
		}
		else
		{
			Sach* k = pHead;
			while (k->pNext != NULL) {
				k = k->pNext;
			}
			k->pNext = newSach;
		}
	}
		void xuatSach() {
			Sach* k = pHead;
			while (k != NULL) {
				cout << k->ten << endl;
				cout << k->tacGia << endl;
				cout << k->nam<<endl;
				k = k->pNext;
			}
		}
		Sach* sachCu() {
			Sach* k = pHead;
			Sach* s = pHead;
			while (s != NULL) {
				if (s->nam < k->nam) {
					k = s;
				}
				s = s->pNext;
			}
			return k;
		}
		void sachXuatBanMax() {
			int maxCount = 0;
			int maxYear = 0;
			Sach* k = pHead;
			while (k != NULL) {


			}
		}
};
int main() {
	danhSach ds;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string ten, tacGia;
		int nam;
		cin.ignore();
		getline(cin, ten);
		getline(cin, tacGia);
		cin >> nam;
		ds.themSach(ten, tacGia, nam);
	}
	ds.xuatSach();
	Sach* sach = ds.sachCu();
	cout << sach->ten << endl;
	cout << sach->tacGia << endl;
	cout << sach->nam << endl;

	return 0;
}