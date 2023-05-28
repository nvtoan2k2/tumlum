#include<iostream>

using namespace std;

struct node {
	int data;
	node* pNext;
};

void themNODE(node *& head,int value) {
	node* newNode = new node;
	newNode->data = value;
	newNode->pNext = nullptr;
	if (head == nullptr) {
		head = newNode;
		return;
	}
	node* k = head;
	while (k->pNext != NULL) {
		if (k->data == value) {
			cout << "Phan tu da ton tai.\n";
			delete newNode;
			return;
		}
		k = k->pNext;

	}
	if (k->data == value) {
		cout << "Phan tu da ton tai.\n";
		delete newNode;
		return;
	}
	k->pNext = newNode;
}
void Xuat(node* head) {
	node* k = head;
	while (k != nullptr) {

		cout << k->data << " ";
		k = k->pNext;
	}
	cout << endl;
}
int main() {
	int n; 
	cout << "Nhap so luong phan tu: ";
	cin >> n;
	node* head = nullptr;
	for (int i = 0; i < n; i++) {
		int value;
		cout << "Phan tu thu " << i + 1<<": ";
		cin >> value;
		themNODE(head, value);
	}
	cout << "List: ";
	Xuat(head);
	return 0;
}
