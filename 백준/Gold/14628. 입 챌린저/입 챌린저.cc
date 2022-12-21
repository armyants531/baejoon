// 입 챌린저  // DP  // 배낭 문제
// DP[i][j] = i번 째 스킬까지 사용하여 피를 j만큼 깎았을 때 소모한 최소 마나량
// DP[i][j] = min_k(DP[i - 1][j - k * Y_i] + k * X_i + ((k - 1) * k / 2) * K); (k = 사용한 i번 째 스킬 갯수)
#include <bits/stdc++.h>

using namespace std;

// 스킬 - 깎인 체력 테이블(테이블에는 소모된 마나 표시)
vector<vector<int>> DP(101, vector<int>(101, 1000000));

int knapsack(vector<pair<int, int>> skill, int N, int M, int K) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			int k = 0;
			while (j - k * skill[i].second >= 0) {
				DP[i][j] = min(DP[i][j], DP[i - 1][j - k * skill[i].second] + k * skill[i].first + ((k - 1) * k / 2) * K);
				k++;
			}
		}
	}
	return DP[N][M];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);
	int N, M, K;
	cin >> N >> M >> K;
	vector<pair<int, int>> skill; // {X, Y}
	skill.push_back({ 0, 0 });
	for (int i = 0; i < N; i++) {
		int X, Y;
		cin >> X >> Y;
		skill.push_back({X, Y});
	}
	for (int i = 0; i <= M; i++) { // 0열 초기화(피가 0일 때 소모 마나 0)
		DP[i][0] = 0;
	}
	cout << knapsack(skill, N, M, K) << "\n";

	return 0;
}