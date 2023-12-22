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
	vector<int> h(n + 1);
	int s = 0;
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
		s += 2;
		s += 4 * h[i];
		s -= 2 * min(h[i - 1], h[i]);
	}
	cout << s << "\n";

	return 0;
}