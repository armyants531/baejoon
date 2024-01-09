#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] <= 'Z') {
				s[i] += 32;
			}
		}
		cout << s << "\n";
	}
	return 0;
}