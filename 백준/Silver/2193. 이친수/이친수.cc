// 이친수  // dp
// dp[n] = 2 * dp[n - 2] + dp[n - 3] (오른쪽에서 두 번째 수가 0일 때 + 1일 때)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<ll> dp(91);

ll tabulation(int n) {
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 2;
	for (int i = 4; i <= n; i++) {
		dp[i] = 2 * dp[i - 2] + dp[i - 3];
	}
	return dp[n];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	cout << tabulation(n);

	return 0;
}