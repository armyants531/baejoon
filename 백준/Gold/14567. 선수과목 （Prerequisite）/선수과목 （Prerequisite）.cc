// 선수과목 (Prerequisite)  // dp
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	vector<pair<int, int>> arr;
	cin >> N >> M;
	vector<int> dp(N + 1, 1); // 최소 1학기에 이수
	int A, B;
	for (int i = 0; i < M; i++) {
		cin >> A >> B; // A < B
		arr.push_back({B, A}); // A는 B의 선수과목
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < M; i++) {
		int A = arr[i].second;
		int B = arr[i].first;
		dp[B] = max(dp[A] + 1, dp[B]);
	}
	for (int i = 1; i <= N; i++) {
		cout << dp[i] << " ";
	}
	return 0;
}