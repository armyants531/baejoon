// 평범한 배낭  // dp  // tabulation
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> table(101, vector<int>(100001, 0));

int knapSack(vector<pair<int, int>> objects, int N, int K) {
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < K + 1; j++) {
			if (j >= objects[i].first) { // 새로운 물건을 넣을 수 있으면
				table[i][j] = max(table[i - 1][j], table[i - 1][j - objects[i].first] + objects[i].second); // 새로운 물건을 넣지 않는 경우와 넣는 경우 비교
			}
			else { // 새로운 물건을 넣을 수 없으면
				table[i][j] = table[i - 1][j];
			}
		}
	}

	return table[N][K];
}
	
int main() {
	int N, K;
	cin >> N >> K;
	vector<pair<int, int>> objects;
	objects.push_back({ 0, 0 });
	for (int i = 0; i < N; i++) {
		int W, V;
		cin >> W >> V; // 무게, 가치
		objects.push_back({W, V});
	}
	sort(objects.begin(), objects.end());
	cout << knapSack(objects, N, K) << "\n";

	return 0;
}