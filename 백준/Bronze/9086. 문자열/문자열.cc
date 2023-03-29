#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	string s;
	for (int t = 0; t < T; t++) {
		cin >> s;
		cout << s[0] << s[s.size() - 1] << "\n";
	}
}