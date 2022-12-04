// 앱  // dp  // tabulation
#include <bits/stdc++.h>

using namespace std;

int N, M;
// 앱-비용 테이블(테이블에는 메모리 크기 저장)
vector<vector<int>> table(101, vector<int>(10001, 0));

int knapSack(vector<pair<int, int>> apps, int tot_cost) {
	int min_cost = tot_cost;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= tot_cost; j++) {
			if (j >= apps[i].second) { // 앱 apps[i]를 비활성할 수 있으면
				table[i][j] = max(table[i - 1][j], table[i - 1][j - apps[i].second] + apps[i].first);
			}
			else {
				table[i][j] = table[i - 1][j];
			}

			if (table[i][j] >= M) { // 필요한 메모리를 충족하면
				min_cost = min(min_cost, j);
			}
		}
	}
	return min_cost;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);
	cin >> N >> M;
	vector<pair<int, int>> apps(N + 1);
	apps.push_back({ 0, 0 });
	for (int i = 1; i <= N; i++) {
		int mem;
		cin >> mem;
		apps[i].first = mem;
	}
	int tot_cost = 0;
	for (int i = 1; i <= N; i++) {
		int cost;
		cin >> cost;
		tot_cost += cost;
		apps[i].second = cost;
	}
	cout << knapSack(apps, tot_cost) << "\n";

	return 0;
}