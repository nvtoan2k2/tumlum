#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

void push(Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data;
        node = node->next;
    }
}

void moveLeft(Node** head_ref) {
    Node* last = *head_ref;
    while (last->next != *head_ref) {
        last = last->next;
    }
    last->next = (*head_ref)->next;
    *head_ref = (*head_ref)->next;
}

void moveRight(Node** head_ref) {
    *head_ref = (*head_ref)->next;
}

int main() {
    Node* head = new Node(0); // node đầu tiên là 0
    Node* current = head;
    for (int i = 1; i <= 9; i++) {
        push(&current->next, i);
        current = current->next;
    }
    current->next = head; // nối lại với node đầu tiên để tạo vòng tròn

    string input;
    cin >> input;

    for (int i = 0; i < input.length(); i++) {
        if (input[i] < '0' || input[i] > '9') {
            cout << "Invalid input" << endl;
            return 0;
        }
        int digit = input[i] - '0';
        if (digit < 0 || digit > 9) {
            cout << "Invalid input" << endl;
            return 0;
        }
        if (digit < 5) {
            moveLeft(&head);
        }
        else {
            moveRight(&head);
        }
    }

    printList(head->next->next); // bỏ qua node đầu tiên và node thứ hai để bắt đầu từ số 0
    return 0;
}
