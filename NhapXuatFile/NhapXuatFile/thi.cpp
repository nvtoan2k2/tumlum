#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<char> s;
    string input;
    cin >> input;

    for (char c : input) {
        if (c == '*') {
            if (!s.empty()) {
                cout << s.top() << endl;
                s.pop();
            }
        }
        else {
            s.push(c);
        }
    }

    return 0;
}
