// 조교의 맹연습  // dp  // knapsack
// dp[i] : i 에너지를 소모하게되는 제식 수행 최소 횟수의 수
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int dp[1000001];

int knapsack(vector<int> arr, vector<int> cnt, int K) {
	dp[0] = 0;
	for (int i = 1; i <= K; i++) {
    for (int j = 0; j < 6; j++) {
      if (i >= arr[j]) {
         dp[i] = min(dp[i], dp[i - arr[j]] + cnt[j]);
      }
    }
	}
	return dp[K];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int A, B, C, K;
	cin >> A >> B >> C >> K;
	vector<int> arr = {A * 4 , B * 4, A + B, A * 2 + C, B * 2 + C, C * 2};
	vector<int> cnt = {4, 4, 2, 3, 3, 2 };
	fill(&dp[0], &dp[K + 1], 1000001);

	int ans = knapsack(arr, cnt, K);
	if (ans == 1000001) {
		cout << -1 << "\n";
	}
	else {
		cout << knapsack(arr, cnt, K) << "\n";
	}

	return 0;
}