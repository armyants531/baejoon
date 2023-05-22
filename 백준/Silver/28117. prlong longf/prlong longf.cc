// dp[n] = dp[n - 1] + dp[n - 2]
// 처음 한 방법보다 더 쉬운 방법 
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> dp(21);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= 20; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	string s;
	cin >> s;
	int ans = 1;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (s.substr(i, 4) == "long") {
			cnt++;
			i += 3;
		}
		else {
			ans *= dp[cnt];
			cnt = 0;
		}
	}
	if (cnt != 0) {
		ans *= dp[cnt];
	}
	cout << ans << "\n";
}