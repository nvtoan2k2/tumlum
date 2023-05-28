#include <iostream>
#include <unordered_set>

using namespace std;

// Khai báo cấu trúc của một nút trong DSLK đơn
struct Node {
    char info; // giá trị của nút
    Node* next; // con trỏ liên kết đến nút kế tiếp
};

// Hàm tạo nút mới với giá trị cho trước
Node* createNode(char value) {
    Node* newNode = new Node;
    newNode->info = value;
    newNode->next = nullptr;
    return newNode;
}

// Hàm chèn một nút vào cuối DSLK đơn
void append(Node*& head, Node*& tail, char value) {
    Node* newNode = createNode(value);
    if (head == nullptr) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

// Hàm xuất DSLK đơn
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->info << " ";
        head = head->next;
    }
    cout << endl;
}

// Hàm loại bỏ các phần tử vi phạm điều kiện tăng dần của DSLK đơn
void removeInvalidElements(Node*& head) {
    unordered_set<char> s; // tập hợp lưu các phần tử đã xuất hiện
    Node* current = head;
    Node* prev = nullptr;
    while (current != nullptr) {
        if (s.find(current->info) != s.end()) {
            // nếu phần tử đã xuất hiện trước đó, xoá nút này
            Node* temp = current;
            current = current->next;
            if (prev == nullptr) {
                head = current;
            }
            else {
                prev->next = current;
            }
            delete temp;
        }
        else if (prev != nullptr && current->info < prev->info) {
            // nếu phần tử hiện tại nhỏ hơn phần tử trước đó, xoá nút trước đó
            Node* temp = prev;
            prev = prev->next;
            if (prev == nullptr) {
                head = current;
            }
            else {
                prev->next = current;
            }
            delete temp;
        }
        else {
            // nếu phần tử thỏa điều kiện, thêm vào tập hợp và tiếp tục duyệt
            s.insert(current->info);
            prev = current;
            current = current->next;
        }
    }
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;
    char value;
    while (cin >> value) {
        append(head, tail, value);
    }
    removeInvalidElements(head);
    printList(head);
    return 0;
}
