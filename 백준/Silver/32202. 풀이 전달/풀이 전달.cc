#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;
int p = 1000000007;

int dp[1000001][2];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	dp[1][0] = 1;
	dp[1][1] = 2;	
	for (int i = 2; i <= N; i++) {
		dp[i][0] = dp[i-1][1];
		dp[i][1] = 2 * (dp[i-1][0] + dp[i-1][1]) % p;
	}
	cout << (dp[N][0] + dp[N][1]) % p << "\n";
	return 0;
}