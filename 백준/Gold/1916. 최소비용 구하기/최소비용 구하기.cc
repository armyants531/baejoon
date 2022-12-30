// 최소비용 구하기  // dijkstra(priority queue)
#include <bits/stdc++.h>
#define INF 100000001

using namespace std;

vector<pair<int, int>> adj[1000]; // 인접 리스트

// start = 시작 위치, end = 끝 위치, V = 정점의 개수
int dijkstra(int start, int end, int V) {
	vector<int> dist(V, INF); // 거리를 저장할 리스트
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  // priority queue : lower distance has priority
	dist[start] = 0; // start node distance = 0
	pq.push({0, start}); // {distance, node}
	while (!pq.empty()) {
		// current node info 
		int curr_node = pq.top().second;
		int curr_dist = pq.top().first;
		pq.pop(); // pop the current node
		int len = adj[curr_node].size();	
		for (int i = 0; i < len; i++) {
			// next node info
			int next_node = adj[curr_node][i].second;
			int next_dist = adj[curr_node][i].first + curr_dist;
			// update min distance
			if (dist[next_node] > next_dist) {
				dist[next_node] = next_dist;
				// push the updated node
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

	int N, M;
	cin >> N >> M;
	int u, v, w; // u -> v (가중치: w)
	for (int i = 0; i < M; i++) {
		cin >> u >> v >> w;
		// node 번호는 1부터 시작하므로 1을 빼줌
		adj[u-1].push_back({ w, v-1 }); // {weight, node}
  }
  for (int i = 0; i < N; i++) {
    sort(adj[i].begin(), adj[i].end
      ());  // cost에 대해 오름차순 정렬
  }  
  int A, B;
  cin >> A >> B;
  cout << dijkstra(A-1, B-1, N) << "\n";
  
	return 0;
}