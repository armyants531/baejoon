#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;

int p = 9901;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vector<int> dp(N + 1);
	vector<int> pre(N + 1);
	dp[0] = 1;
	dp[1] = 3;
	dp[2] = 7;
	pre[0] = 1;
	pre[1] = 4;
	pre[2] = 11;
	for (int i = 3; i <= N; i++) {
		dp[i] = dp[i-1];
		int tmp = 1 + pre[i-2];
		dp[i] += 2 * tmp;
		dp[i] %= p;
		pre[i] = dp[i] + pre[i - 1];
		pre[i] %= p;
	}
	cout << dp[N] << "\n";
	
	return 0;
}