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
	int T;
	cin >> T;
	while (T--) {
		int x, y;
		cin >> x >> y;
		int c = y-x;
		int n = sqrt(c);
		if (c == n * n) {
			cout << 2 * n - 1 << "\n";	
		}
		else {
			if (c <= n * (n + 1)) {
				cout << 2 * n << "\n";
			}
			else {
				cout << 2 * n + 1 << "\n";
			}
		}
	}

	return 0;
}