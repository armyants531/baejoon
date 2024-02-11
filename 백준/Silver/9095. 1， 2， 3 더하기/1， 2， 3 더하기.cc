#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;

vector<int> dp(12);
int memo(int n) {
	if (n < 0) return 0;
	if (dp[n]) return dp[n];
	else {
		return dp[n] = memo(n-1) + memo(n-2) + memo(n-3); 
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	while (T--) {
		int n;
		cin >> n;
		cout << memo(n) << "\n";
	}
	
	return 0;
}