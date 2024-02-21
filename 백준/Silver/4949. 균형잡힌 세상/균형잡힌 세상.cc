#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while (true) {
		string s;
		getline(cin, s);
		if (s == ".") break;
		stack<char> st;
		bool can = true;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(') {
				st.push('(');
			}
			else if (s[i] == '[') {
				st.push('[');
			}
			else if (s[i] == ')') {
				if (!st.empty() && st.top() == '(') {
					st.pop();
				}
				else {
					can = false;
					break;
				}
			}
			else if (s[i] == ']') {
				if (!st.empty() && st.top() == '[') {
					st.pop();
				}
				else {
					can = false;
					break;
				}
			}
		}
		if (!st.empty()) can = false;
		if (can) cout << "yes" << "\n";
		else cout << "no" << "\n";
	}
}