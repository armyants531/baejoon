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
	int cnt = 0;
	int mi = min(n, m);
	int ma = max(n, m);
	for (int i = 0; i <= n + m; i++) {
		//cout << min(mi, i) - max(i - ma, (int)0) + 1 << "\n";
		cnt += min(mi, i) - max(i - ma, (int)0) + 1;
	}
	cout << cnt << "\n";
	
	return 0;
}