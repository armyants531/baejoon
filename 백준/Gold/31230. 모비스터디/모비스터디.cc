#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define INF 2000000000000000

using namespace std;

vector<pair<int, int>> adj[200001];
set<int> city;

vector<int> dijkstra(int start) {
    vector<int> dist(200001, INF);
    // {distance, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min_heap
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        int cur_node = pq.top().se;
        int cur_dist = pq.top().fi;
        pq.pop();
        if (dist[cur_node] < cur_dist) continue;
        for (auto next : adj[cur_node]) { // 인접 노드 탐색
            int next_dist = cur_dist + next.fi; 
            int next_node = next.se;
            if (next_dist < dist[next_node]) { // 거리 갱신
                dist[next_node] = next_dist;
                pq.push({next_dist, next_node});
            }
        }
    }
    return dist;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int N, M, A, B;
	cin >> N >> M >> A >> B;
	for (int i = 0; i < M; i++) {
        int u, v, w;
		cin >> u >> v >> w;
        adj[u].push_back({w, v}); // dist, next_node
        adj[v].push_back({w, u});
	}
    vector<int> dist1 = dijkstra(A);
   	int AB = dist1[B];
   	vector<int> dist2 = dijkstra(B);
   	vector<int> ans;
   	for (int i = 1; i <= N; i++) {
   		// Ai + Bi == AB이면 i는 최단경로에 속함  
   		if (dist1[i] + dist2[i] == AB) {
   			ans.push_back(i);
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
	
	return 0;
}