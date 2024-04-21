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
	int N, M;
	cin >> N >> M;
	if (N >= M) {
		cout << 0 << "\n";
	}
	else {
		int rem = 1;
		for (int i = 1; i <= N; i++) {
			rem *= i;
			rem %= M;
			if (rem==0) break;
		}
		cout << rem << "\n";
	}
	
	return 0;
}