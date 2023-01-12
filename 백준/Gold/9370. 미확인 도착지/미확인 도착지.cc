// 미확인 도착지  // dijkstra(priority queue)
#include <bits/stdc++.h>

using namespace std;
int INF = 2000000;

// start = 시작 위치, N = 정점의 개수
vector<int> dijkstra(int start, int N, vector<pair<int, int>> adj[2001]) {
	vector<int> dist(2001, INF); // 거리를 저장할 리스트
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 오름차순(최소힙)
	dist[start] = 0; // 0번
	pq.push({ 0, start });
	while (!pq.empty()) {
		int curr_dist = pq.top().first;
		int curr_node = pq.top().second;
		pq.pop();
		for (auto next : adj[curr_node]) {
			int next_dist = next.first + curr_dist;
			int next_node = next.second;
			if (next_dist < dist[next_node]) { // 거리가 갱신되는 경우
				dist[next_node] = next_dist; // 거리 갱신
				pq.push({ next_dist, next_node }); // 갱신되는 노드를 큐에 삽입
			}
		}
	}
	return dist;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while (T) {
		T--;
		int n, m, t;
		cin >> n >> m >> t;
		int s, g, h;
		cin >> s >> g >> h;
		vector<pair<int, int>> adj[2001]; // 인접 리스트
		for (int i = 0; i < m; i++) {
			int a, b, d;
			cin >> a >> b >> d;
			// 무방향 그래프
			adj[a].push_back({d, b}); // {거리, 노드}
			adj[b].push_back({d, a});
		}
		vector<int> arr;
		for (int i = 0; i < t; i++) {
			int x;
			cin >> x;
			vector<int> dist1 = dijkstra(s, n, adj);
			int dist_s_x = dist1[x];
			int dist_s_g = dist1[g];
			int dist_s_h = dist1[h];
			vector<int> dist2 = dijkstra(g, n, adj);
			int dist_g_h = dist2[h];
			int dist_g_x = dist2[x];
			vector<int> dist3 = dijkstra(h, n, adj);
			int dist_h_x = dist3[x];
			if (dist_s_x == min(dist_s_g + dist_g_h + dist_h_x, dist_s_h + dist_g_h + dist_g_x)) {
				arr.push_back(x);
			}
		}
		sort(arr.begin(), arr.end());
		for (int i = 0; i < arr.size(); i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
	}

	return 0;
}