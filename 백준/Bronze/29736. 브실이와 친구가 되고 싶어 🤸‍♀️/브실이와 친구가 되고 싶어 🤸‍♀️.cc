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
	int A, B, K, X;
	cin >> A >> B >> K >> X;
	int a = max(K - X, A);
	int b = min(K + X, B);
	int ans = b - a + 1;
	if (ans > 0) {
		cout << ans;
	}
	else {
		cout << "IMPOSSIBLE";
	}
	
	return 0;
}