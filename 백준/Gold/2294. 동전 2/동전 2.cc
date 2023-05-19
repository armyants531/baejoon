// 동전 2  // dp
// dp[x] : x원을 만들기 위한 동전의 최소 개수
#include <bits/stdc++.h>

using namespace std;

vector<int> coin;
vector<int> dp(10001, 0);

void tabulation(int n, int k) {
	for (int i = 1; i <= k; i++) {
		int min_cnt = 1000000;
		for (int j = 0; j < n; j++) {
			if (i >= coin[j]) {
				min_cnt = min(min_cnt, dp[i - coin[j]] + 1);
			}
		}
		dp[i] = min_cnt;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	coin.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}
	// dp 초기화
	for (int i = 1; i <= k; i++) {
		dp[i] = 1000000;
	}
	tabulation(n, k);
	if (dp[k] >= 1000000) {
		cout << -1 << "\n";
	}
	else {
		cout << dp[k] << "\n";
	}
	/*
	for (int i = 0; i < k; i++) {
		cout << dp[i] << " ";
	}
	cout << "\n";
	*/
	return 0;
}