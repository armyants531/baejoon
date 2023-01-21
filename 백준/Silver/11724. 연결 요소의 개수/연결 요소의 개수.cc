// 연결 요소의 개수  // bfs
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj(1001);
vector<int> visited(1001);

void bfs(int start) {
	queue<int> que;
	visited[start] = true;
	que.push(start);
	while (!que.empty()) {
		int node = que.front();
		que.pop();
		for (auto next : adj[node]) {
			if (!visited[next]) {
				visited[next] = start;
				que.push(next);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			bfs(i);
			cnt++;
		}
	}
	cout << cnt << "\n";

	return 0;
}