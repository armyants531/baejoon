// 운전병의 딜레마  // dijkstra  // parametrix search  // binary search
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int N, M;
ll T;

struct node {
	int v;
	ll t;
	int s;
};

vector<vector<node>> adj(50001);
ll MAX = 1000000001;

// feel 만큼의 불편도로 주행할 때 걸리는 시간을 리턴
ll dijkstra(int feel) {
	vector<ll> cost(N + 1, MAX);
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;  // {시간, 노드}
	cost[1] = 0;
	pq.push({0, 1});
	while (!pq.empty()) {
		ll curr_time = pq.top().first;
		ll curr_node = pq.top().second;
		pq.pop();
		if (cost[curr_node] < curr_time) continue;  // 현재 경로보다 더 효율적인 경로 알고 있으면 건너뜀 
		for (auto& next : adj[curr_node]) {
			ll next_time = curr_time + next.t + max(0, next.s - feel); // 불편도 차이 만큼 시간 추가
			ll next_node = next.v;
			if (next_time > T) continue;
			if (next_time < cost[next_node]) { // 시간 갱신이 되는 경우
				cost[next_node] = next_time;
				pq.push({ next_time, next_node });
			}
		}
	}
	return cost[N];
}

int bsearch(int max_s) {
	int low = 0;
	int high = max_s;
	int mid;
	int min_s = 1000000001;
	while (low <= high) {
		mid = (low + high) / 2;
		if (dijkstra(mid) <= T) {
			min_s = min(min_s, mid);
			high = mid - 1;
		}
		else { // bfs(mid) > T
			low = mid + 1;
		}
	}
	return min_s;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> T;
	int max_s = 0;
	for (int i = 0; i < M; i++) {
		int u, v, s;
		ll t;
		cin >> u >> v >> t >> s;
		max_s = max(max_s, s);
		adj[u].push_back({ v, t, s });
		adj[v].push_back({ u, t, s });
	}
	int min_feel = bsearch(max_s);
	if (min_feel > max_s) {
		cout << -1;
	}
	else {
		cout << min_feel;
	}
}