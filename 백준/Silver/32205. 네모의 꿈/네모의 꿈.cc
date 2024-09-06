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
	int N;
	cin >> N;
	vector<bool> mp(1000001);
	bool can = false;
	for (int i = 0; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (mp[a] || mp[b] || mp[c]) {
			can = true;
		}
		mp[a] = true;
		mp[b] = true;
		mp[c] = true;
	}
	if (can) cout << 1 << "\n";
	else cout << 0 << "\n";
	return 0;
}