// 파티  // dijkstra(priority queue)
#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> adj[1001];
int INF = 100000;

int dijkstra(int start, int end, int N) {
	vector<int> dist(1001, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 최소힙
	dist[start] = 0;
	pq.push({0, start});
	while (!pq.empty()) {
		int curr_dist = pq.top().first;
		int curr_node = pq.top().second;
		pq.pop();
		for (auto next : adj[curr_node]) {
			int next_dist = next.first + curr_dist;
			int next_node = next.second;
			if (next_dist < dist[next_node]) { // 거리 갱신 되는 경우
				dist[next_node] = next_dist;
				pq.push({ next_dist, next_node });
			}
		}
	}
	return dist[end];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, X;
	cin >> N >> M >> X;
	for (int i = 0; i < M; i++) {
		int s, e, T;
		cin >> s >> e >> T;
		adj[s].push_back({ T, e });
	}
	int max_T = 0;
	// 왕복 시간을 비교하면서 최대 왕복 시간 갱신
	for (int i = 1; i <= N; i++) {
		max_T = max(max_T, dijkstra(i, X, N) + dijkstra(X, i, N));
	}
	cout << max_T << "\n";

	return 0;
}