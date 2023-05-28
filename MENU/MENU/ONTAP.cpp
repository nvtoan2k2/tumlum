#include<iostream>
#include<math.h>

#include <cstring> 
using namespace std;


//khai bao bien trong dslk
struct node {
	int data;
	node* pNext;
};
//them node vao dau danh sach
void themNodeVaoDau(node*& head, int value) {
	node* newNode = new node;
	newNode->data = value;
	newNode->pNext = head;
	head = newNode;
}
//them node vao cuoi danh sach
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
bool KT_SNT(int n) {
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
void themNodeVaoViTriBatKi(node*& head, int val, int position) {
	// Tạo một node mới
	node* newNode = new node;
	newNode->data = val;
	newNode->pNext = NULL;

	// Nếu danh sách rỗng hoặc muốn chèn vào đầu danh sách
	if (head == NULL || position == 0) {
		newNode->pNext = head;
		head = newNode;
		return;
	}

	// Đi đến node trước node cần chèn
	node* prevNode = head;
	for (int i = 0; i < position - 1; i++) {
		if (prevNode->pNext == NULL) {
			break;
		}
		prevNode = prevNode->pNext;
	}

	// Thêm node mới vào danh sách
	newNode->pNext = prevNode->pNext;
	prevNode->pNext = newNode;
}
//void xoaNode(node* head, int vt) {
//
//		for (int i = 0; i < vt - 1; i++) {
//			head[i].pNext = head[i].pNext->pNext;
//		}
//		node* next = temp->next->next;
//		delete temp->next;
//		temp->next = next;
//}
void xuatDanhSachLienKet(node* head) {
	node* current_node = head;
	while (current_node != nullptr) {
		cout << current_node->data << " ";
		current_node = current_node->pNext;
	}
	cout << endl;
	cout << sizeof(head);
	cout << endl;
	system("pause");
}
void dem_SNT(node* head) {
	int dem = 0;
	node* k = head;
	while (k != nullptr) {
		if (KT_SNT(k->data)) {
			cout << k->data<<" \n";
			dem++;
		}
		k = k-> pNext;
	}
	cout << dem;
	cout << endl;
	system("pause");
}

int main() {
	node* head = nullptr;
	
	int choice;
	while (true) {
		system("cls");
		cout << ("\n\n\t\t======== MENU ==========");
		cout << ("\n\t1. Them node vao danh sach lien ket.");
		cout << ("\n\t2. Xuat danh dach lien ket.");
		cout << ("\n\t3. Them mot node vao dau danh sach lien ket.");
		cout << ("\n\t4. Xoa node trong danh sach lien ket.");
		cout << ("\n\t5. Dem so nguyen to trong danh sach lien ket.");
		cout << ("\n\t0. Thoat chuong trinh.");
		cout << ("\n\t Ban co muon tiep tuc (co/khong).\n");
		string a;
		cin >> a;
		cout << a;
		if (a == "co") {
			cout << ("\nNhap lua chon cua ban: ");
			cin >> choice;
			switch (choice)
			{
			case 1: {
				int data;
				cout << "Nhap gia tri: ";
				cin >> data;
				themNODE(head, data);
				break;
			}
			case 2: {
				cout << "Danh sach lien ket la: ";
				xuatDanhSachLienKet(head);
				break;
			}
			case 3: {
				int data;
				cout << "Them node: ";
				cin >> data;
				int x;
				cout << "Vi tri can them: ";
				cin >> x;
				themNodeVaoViTriBatKi(head, data, x);
				xuatDanhSachLienKet(head);
				break;
			}
		/*	case 4: {
				int vt;
				cin >> vt;
				xoaNode(head, vt);
				xuatDanhSachLienKet(head);
				break;
			}*/
			case 5: {
				cout << "So luong so nguyen to trong danh sach lien ket: ";
				dem_SNT(head);
				break;
			}
			case 0: {
				cout << "Tam biet hen gap lai.";
				return 0;
			}
			}
		}
		else {
			return 0;
		}
	}
	
	return 0;
}