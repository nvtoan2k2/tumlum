#include<iostream>
#include<string>
using namespace std;

bool kiemTra(string s, string t) {
	int a = s.length();
	int b = t.length();
	int i = 0, j = 0;
	while (i < a && j < b) {
		if (s[i] == t[j]) {
			i++;
		}
		j++;
	}
	//	cout<<i;
	return i == a;
}
int main() {
	string s, t;

	getline(cin, s);
	getline(cin, t);
	//	cout << s<<endl<<t<<endl;
	bool result = kiemTra(s, t);
	if (result) {
		cout << "True";
	}
	else {
		cout << "False";
	}
	return 0;
}