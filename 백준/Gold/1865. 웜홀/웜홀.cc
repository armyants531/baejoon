// 웜홀  // Bellman-Ford 
// 음수 사이클 존재 여부 판단
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll INF = 5000001;
int N, M, W;

// N번 째 업데이트 유무만 알면 됨
bool bellmanFord(vector<pair<ll, ll>> adj[501]) {
	vector<ll> upper(N + 1, INF);
	bool updated = false;
	for (int i = 0; i < N; i++) {
		updated = false;
		// 모든 간선 업데이트
		for (int curr = 1; curr <= N; curr++) {
			for (auto next : adj[curr]) {
				ll next_node = next.first;
				ll next_cost = next.second;
				// upper[curr] == INF여도 완화를 시켜주어야 함(모든 그래프가 연결되었다는 조건 없음)
				if (upper[next_node] > upper[curr] + next_cost) {
					// 완화
					upper[next_node] = upper[curr] + next_cost;
					updated = true;
				}
			}
		}
		if (!updated) { // 업데이트 안 되면 종료
			break;
		}
	}
	// 마지막 N번 째에 업데이트 된 경우 음수 사이클 존재
	if (updated) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int TC;
	cin >> TC;
	for (int tc = 0; tc < TC; tc++) {
		cin >> N >> M >> W;
		vector<pair<ll, ll>> adj[501]; // {연결 정점 번호, 간선 가중치}
		for (int i = 0; i < M; i++) {
			ll S, E, T;
			cin >> S >> E >> T;
			// 도로는 무방향 간선
			adj[S].push_back({ E, T });
			adj[E].push_back({ S, T });
		}
		for (int i = 0; i < W; i++) {
			ll S, E, T;
			cin >> S >> E >> T;
			// 웜홀은 유방향 간선
			adj[S].push_back({ E, -T });
		}
		if (bellmanFord(adj)) {
			cout << "YES" << "\n";
		}
		else {
			cout << "NO" << "\n";
		}
	}
	
	return 0;
}