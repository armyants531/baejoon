#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int n;
	cin >> n;
	string s;
	map<string, int> mp;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 1; j <= s.size(); j++) {
			mp[s.substr(s.size() - j, j)]++;
		}
	}
	int cnt = 0;
	for (auto a : mp) {
		if (a.se % 2 == 1) {
			cnt++;
		}
	}
	cout << cnt << "\n";

	return 0;
}