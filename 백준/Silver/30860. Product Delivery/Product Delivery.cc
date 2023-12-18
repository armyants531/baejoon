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
	vector<int> l(n);
	vector<int> m(n);
	for (int i = 0; i < n; i++) {
		cin >> l[i] >> m[i];
	}
	int cnt = 1;
	int pre = l[0];
	for (int i = 1; i < n; i++) {
		if (pre > m[i]) {
			cnt++;
			pre = l[i];
		}
		else {
			pre = max(pre, l[i]);
		}
	}
	cout << cnt << "\n";

	return 0;
}