// 최단경로  // dijkstra(priority queue) // 시간 초과
// https://velog.io/@717lumos/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EB%8B%A4%EC%9D%B5%EC%8A%A4%ED%8A%B8%EB%9D%BCDijkstra-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98 참고
#include <bits/stdc++.h>
#define INF 2147483647

using namespace std;

vector<pair<int, int>> adj[20000]; // 인접 리스트

// start = 시작 위치, V = 정점의 개수, return: 최소 거리 행렬
vector<int> dijkstra(int start, int V) {
	vector<int> dist(20000, INF); // 거리를 저장할 리스트
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  // priority queue : lower distance has priority
	dist[start] = 0; // start node distance = 0
	pq.push({0, start}); // {distance, node}
	int current_node, current_dist;
	int next_node, next_dist;
	while (!pq.empty()) {
		// current node info 
		current_node = pq.top().second;
		current_dist = pq.top().first;
		pq.pop(); // pop the current node
		int len = adj[current_node].size();	
		for (int i = 0; i < len; i++) {
			// next node info
			next_node = adj[current_node][i].first;
			next_dist = adj[current_node][i].second + current_dist;
			// update min distance
			if (dist[next_node] > next_dist) {
				dist[next_node] = next_dist;
				// push the updated node
				pq.push({ next_dist, next_node });
			}
		}
	}
	return dist;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V, E, K;
	cin >> V >> E;
	cin >> K;

	int u, v, w; // u -> v (가중치: w)
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		// node 번호는 1부터 시작하므로 1을 빼줌
		adj[u-1].push_back({ v-1, w }); // {node, weight}
	}
	vector<int> dist = dijkstra(K-1, V);
	for (int i = 0; i < V; i++) {
		int val = dist[i];
		if (val == INF) {
			cout << "INF" << "\n";
		}
		else {
			cout << dist[i] << "\n";
		}
	}
	return 0;
}