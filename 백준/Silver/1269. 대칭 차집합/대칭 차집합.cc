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
	int n, m;
	cin >> n >> m;
	unordered_map<int, bool> mp;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		mp[a] = true;
	}
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		int b;
		cin >> b;
		if (mp[b]) {
			cnt++;
		}
	}
	cout << n + m - 2 * cnt << "\n";
	return 0;
}