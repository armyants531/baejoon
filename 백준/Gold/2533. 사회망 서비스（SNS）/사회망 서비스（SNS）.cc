// 사회망 서비스(SNS)  // tree DP
// 부모가 얼리 어답터가 아닌 경우 -> 자식이 얼리 어답터이어야 함
// 부모가 얼리 어답터인 경우 -> 자식이 얼리 어답터일 경우와 아닐 경우 중 더 작은 값 선택
// dp[node][0] += dp[child][1]
// dp[node][1] += min(dp[child][1], dp[child][0]);
// https://hqjang.tistory.com/104 참고
#include <bits/stdc++.h>

using namespace std;

vector<int> visited;
vector<vector<int>> adj(1000001);
vector<vector<int>> dp(1000001, vector<int>(2, 0)); // 0: 얼리 어답터 x, 1: 얼리 어답터 O

int cnt = 0;

void dfs(int node) {
	visited[node] = true;
	dp[node][1] = 1;
	for (auto child : adj[node]) {
		if (!visited[child]) {
			dfs(child);
			dp[node][0] += dp[child][1];
			dp[node][1] += min(dp[child][0], dp[child][1]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	visited.resize(n + 1, false);
	for (int i = 1; i <= n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	cout << min(dp[1][1], dp[1][0]) << "\n";
	
	return 0;
}