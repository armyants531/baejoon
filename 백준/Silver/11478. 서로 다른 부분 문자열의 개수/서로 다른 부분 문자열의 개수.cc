#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >> s;
	unordered_map<string, bool> mp;
	for (int l = 1; l <= s.size(); l++) {
		for (int i = 0; i + l <= s.size(); i++) {
			string str = s.substr(i, l);
			mp[str] = true;
		}
	}
	cout << mp.size() << "\n";

	return 0;
}