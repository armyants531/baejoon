// 횡단보도  // dijkstra
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<pair<ll, ll>> adj[100000];
ll INF = 70000000000;

ll dijkstra(ll start, ll end, ll M) { // 시작, 끝, 주기
	vector<ll> cost(100000, INF);
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
	cost[start] = 0;
	pq.push({0, start});
	while (!pq.empty()) {
		ll curr_cost = pq.top().first;
		ll curr_node = pq.top().second;
		pq.pop();
		for (auto next : adj[curr_node]) { // 인접 노드 탐색
			ll next_cost = curr_cost;
			ll next_node = next.second;
			ll temp = next.first;
			ll k = ceil((long double)(next_cost - next.first) / M);
			next_cost = k * M + next.first + 1; // 건너는데 1분 걸림
			if (next_cost < cost[next_node]) {
				// 시간 갱신
				cost[next_node] = next_cost;
				// 갱신되는 노드를 큐에 삽입
				pq.push({ next_cost, next_node }); // 시간, 노드
			}
		}
	}
	return cost[end];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll N, M;
	cin >> N >> M;
	for (ll i = 0; i < M; i++) {
		ll A, B;
		cin >> A >> B;
		adj[A - 1].push_back({ i, B - 1 }); // 시작 시간, 끝점
		adj[B - 1].push_back({ i, A - 1 });
	}
	cout << dijkstra(0, N - 1, M) << "\n";


	return 0;
}