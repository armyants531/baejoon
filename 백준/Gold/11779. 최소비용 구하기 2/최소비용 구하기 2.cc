#include <bits/stdc++.h>
#define fi first
#define se second
#define INF 2000000000

using namespace std;

using pii = pair<int, int>;
vector<pii> adj[1001];
vector<bool> visited(1001); // 방문 여부 확인
vector<int> route(1001);

vector<int> dijkstra(int s, int n) {
	vector<int> d(1001, INF);
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	d[s] = 0;
	pq.push({ 0, s });
	while (!pq.empty()) {
		int cur = pq.top().se;
		int dist = pq.top().fi;
		pq.pop();
		if (dist > d[cur]) continue;
		for (auto e : adj[cur]) {
			int next = e.se;
			int next_dist = e.fi + dist;
			if (d[next] > next_dist) {
				d[next] = next_dist;
				route[next] = cur;
				pq.push({ next_dist, next });
			}
		}
	}
	return d;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		// 편도
		adj[a].push_back({ c, b }); // cost, node
	}
	int s, e;
	cin >> s >> e;
	vector<int> dist = dijkstra(s, n);
	cout << dist[e] << "\n";
	int pre = e;
	stack<int> st;
	st.push(pre);
	while (pre != s) {
		st.push(route[pre]);
		pre = route[pre];
	}
	cout << st.size() << "\n";
	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}
	cout << "\n";

	return 0;
}