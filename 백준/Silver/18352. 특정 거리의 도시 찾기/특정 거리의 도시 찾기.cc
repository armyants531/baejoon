#include <bits/stdc++.h>
#define INF 10000001

using namespace std;

vector<vector<pair<int, int>>> adj(300001);

vector<int> dijkstra(int s, int n) {
	vector<int> d(300001, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	d[s] = 0;
	pq.push({0, s});
	while (!pq.empty()) {
		int cur_node = pq.top().second;
		int cur_dist = pq.top().first;
		pq.pop();
		if (cur_dist > d[cur_node]) continue;
		for (auto next : adj[cur_node]) {
			int next_node = next.second;
			int next_dist = cur_dist + next.first;
			if (d[next_node] > next_dist) {
				d[next_node] = next_dist;
				pq.push({next_dist, next_node});
			}
		}
	}
	return d;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, K, X;
	cin >> N >> M >> K >> X;
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		adj[A].push_back({1, B});	
	}
	
	vector<int> d = dijkstra(X, N);
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (d[i] == K) {
			cnt++;
			cout << i << "\n";
		}
	}
	if (cnt == 0) {
		cout << -1 << "\n";
	}
	
	return 0;	
}