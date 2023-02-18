// 운동  // Floyd-Warshall
// 기존 플로이드-워셜 알고리즘에서 자기 자신으로 가는 경로의 값을 INF로 초기화하면 된다
#include <bits/stdc++.h>

using namespace std;

int INF = 1000000000;
vector<vector<int>> adj(401, vector<int>(401, INF));

void floyd(int V) {
	// k: 거쳐가는 노드, i: 시작 노드, j: 도착 노드
	for (int k = 1; k <= V; k++) {
		for (int i = 1; i <= V; i++) {
			if (adj[i][k] == INF) { // i에서 k로 가는 경로가 없으면 넘어감
				continue;
			}
			for (int j = 1; j <= V; j++) {
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int V, E;
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a][b] = c;
	}
	floyd(V);
	int min_cycle = INF;
	for (int i = 1; i <= V; i++) {
		min_cycle = min(min_cycle, adj[i][i]);
	}
	if (min_cycle == INF) cout << -1 << "\n";
	else cout << min_cycle << "\n";

	return 0;
}