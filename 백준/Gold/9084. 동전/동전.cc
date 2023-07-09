// 동전  // dp
// 돈을 사용하는 순서는 구분하지 않음 -> 금액이 작은 돈부터 큰 돈 순으로 경우의 수 누적
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int tabulation(int N, int M, vector<int> coin) {
	vector<ll> dp(M + 1);
	for (int i = 0; i < N; i++) {
		if (coin[i] > M) break;
		dp[coin[i]]++;
		for (int j = coin[i] + 1; j <= M; j++) {
			if (j - coin[i] >= 0) {
				dp[j] += dp[j - coin[i]];
			}
		}
	}
	return dp[M];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N;
		vector<int> coin(N);
		for (int i = 0; i < N; i++) {
			cin >> coin[i];
		}
		sort(coin.begin(), coin.end());
		cin >> M;
		cout << tabulation(N, M, coin) << "\n";
	}

	return 0;
}