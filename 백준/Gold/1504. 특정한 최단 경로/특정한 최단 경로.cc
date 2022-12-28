// 특정한 최단 경로  // dijkstra(priority queue)
#include <bits/stdc++.h>

using namespace std;
int INF = 8000000;

vector<pair<int, int>> adj[800]; // 인접 리스트

// start = 시작 위치, end = 끝나는 위치, N = 정점의 개수
int dijkstra(int start, int end, int N) {
	vector<int> dist(800, INF); // 거리를 저장할 리스트
	// 최소 힙
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 오름차순
	dist[start] = 0; // 0번
	pq.push({0, start}); // {distance, node_num}  // 거리가 우선 순위
	while (!pq.empty()) {
		int curr_dist = pq.top().first;
		int curr_node = pq.top().second;
		pq.pop();
		for (auto next : adj[curr_node]) { // 인접 노드 탐색
			int next_dist = next.first + curr_dist;
			int next_node = next.second;
			if (next_dist < dist[next_node]) {
				// 거리 갱신
				dist[next_node] = next_dist;
				// 갱신되는 노드를 큐에 삽입
				pq.push({next_dist, next_node});
			}
		}
	}

	return dist[end];  // end 까지의 거리 리턴
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, E;
	cin >> N >> E;
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		// 무방향 그래프
		adj[a - 1].push_back({c, b - 1}); // {거리, 노드}
		adj[b - 1].push_back({c, a - 1});
	}
	int v1, v2;
	cin >> v1 >> v2;
	int dist1 = dijkstra(0, v1 - 1, N) + dijkstra(v1 - 1, v2 - 1, N) + dijkstra(v2 - 1, N - 1, N);
	int dist2 = dijkstra(0, v2 - 1, N) + dijkstra(v2 - 1, v1 - 1, N) + dijkstra(v1 - 1, N - 1, N);
	int dist = min(dist1, dist2);
	if (dist >= 8000000) {
		cout << -1 << "\n";
	}
	else {
		cout << dist << "\n";
	}

	return 0; 
}