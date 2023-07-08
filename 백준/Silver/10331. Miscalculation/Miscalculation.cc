#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int order(char c) {
	if (c == '*') {
		return 2;
	}
	else {
		return 1;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >> s;
	int result;
	cin >> result;
	stack<char> st;
	string str = ""; // 후위 표기식
	for (int i = 0; i < s.size(); i++) {
		if (s[i] - '0' >= 0 && s[i] - '0' <= '9') {
			str += s[i];
		}
		else {
			if (st.empty()) {
				st.push(s[i]);
			}
			else if (order(s[i]) > order(st.top())) {
				st.push(s[i]);
			}
			else {
				str += st.top();
				st.pop();
				st.push(s[i]);
			}
		}
	}
	while (!st.empty()) {
		str += st.top();
		st.pop();
	}
	//cout << str << "\n";
	// 후위 표기식 계산
	stack<int> Stack;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] - '0' >= 0 && str[i] - '0' <= '9') {
			Stack.push(str[i] - '0');
		}
		else {
			int b = Stack.top();
			Stack.pop();
			int a = Stack.top();
			Stack.pop();
			if (str[i] == '*') {
				Stack.push(a * b);
			}
			else {
				Stack.push(a + b);
			}
		}
	}

	int A = Stack.top();
	int B = s[0] - '0';
	for (int i = 1; i < s.size(); i += 2) {
		if (s[i] == '*') {
			B *= s[i + 1] - '0';
		}
		else {
			B += s[i + 1] - '0';
		}
	}
	if (A == B && A == result) {
		cout << 'U' << "\n";
	}
	else if (A == result) {
		cout << 'M' << "\n";
	}
	else if (B == result) {
		cout << 'L' << "\n";
	}
	else {
		cout << 'I' << "\n";
	}

	return 0;
}