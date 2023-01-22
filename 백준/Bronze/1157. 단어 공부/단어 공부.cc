// 단어 공부  // string
#include <bits/stdc++.h>

using namespace std;

vector<int> L(26, 0);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] <= 'Z') { // A <= char <= Z
			L[s[i] - 'A']++;
		}
		else { // a <= char <= z
			L[s[i] - 'a']++;
		}
	}
	stack<char> st;
	int max = 0;
	for (int i = 0; i < L.size(); i++) {
		if (L[i] > max) {
			while (!st.empty()) {
				st.pop();
			}
			st.push('A' + i);
			max = L[i];
		}
		else if (L[i] == max) {
			st.push('A' + i);
		}
	}
	if (st.size() == 1) {
		cout << st.top();
	}
	else {
		cout << '?';
	}
	return 0;
}