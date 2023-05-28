#include<iostream>

using namespace std;

struct node {
	int data;
	node* pNext;
};
//them node vao cuối
void themNODE(node*& head, int value) {
	node* newNode = new node;
	newNode->data = value;
	newNode->pNext = nullptr;
	if (head == nullptr) {
		head = newNode;
		return;
	}
	else {
		node* k = head;
		while (k->pNext != nullptr) {
			k = k->pNext;
		}
		k->pNext = newNode;
	}
}
//them node vao dau
//void themNODE(node*& head, int value) {
//	node* newNode = new node;
//	newNode->data = value;
//	newNode->pNext = head;
//	head = newNode;
//	
//}
void Xuat(node* head, int x) {
	int dem = 0;
	node* k = head;
	while (k != nullptr) {
		if (k->data == x) {
			dem++;
		}
		k = k->pNext;
	}
	cout << "So luong phan tu trung voi phan tu x la: "<<dem;
}
int main() {
	int n;
	cout << "Nhap so luong phan tu: ";
	cin >> n;
	node* head = nullptr;
	for (int i = 0; i < n; i++) {
		int value;
		cout << "Phan tu thu " << i + 1 << ": ";
		cin >> value;
		themNODE(head, value);
	}
	int x;
	cout << "Nhap phan tu x: ";
	cin >> x;
	
	Xuat(head, x);
	return 0;
}
