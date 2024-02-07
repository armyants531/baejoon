#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;

int p = 10007;

int dp[1010][1010];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	int n = 1;
	// (10 + N - 1)_C_N
	for (int i = 1; i <= 10 + N - 1; i++) {
		dp[i][0] = 1;
		dp[i][1] = i;
	}
	for (int i = 1; i <= 10 + N - 1; i++) {
		for (int j = 2; j <= min(i, N); j++) {
			dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
			dp[i][j] %= p;
		}	
	}
	cout << dp[10 + N - 1][N] << "\n";
	
	return 0;
}