#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define INF 2000000000000000

using namespace std;

vector<vector<int>> dp(401, vector<int>(201));

// aCb
int memo(int a, int b) {
	if (dp[a][b] > 0) return dp[a][b];
	if (a < b) {
		return 0;
	}
	if (b == 0 || a == b) {
		return 1;
	}
	else {
		return dp[a][b] = (memo(a-1, b) + memo(a-1, b-1)) % 1000000000;
	}
} 

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, K;
	cin >> N >> K;
	cout << memo(K + N - 1, N) << "\n";

	return 0;
}