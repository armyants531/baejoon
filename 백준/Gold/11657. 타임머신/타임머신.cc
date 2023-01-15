// 타임머신  // Bellman Ford
// "알고리즘 문제 해결 전략" 참고
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<pair<int, ll>> adj[1001]; // {연결 정점 번호, 간선 가중치}
ll INF = 5000000;
int N, M;

// 음수 사이클이 있으면 빈 배열을 반환
vector<ll> bellmanFord(int start) {
	// 초기화
	vector<ll> upper(N + 1, INF);
	upper[start] = 0;
	bool updated = false;
	for (int i = 0; i < N; i++) {
		updated = false;
		for (int curr = 1; curr <= N; curr++) {
			for (auto next : adj[curr]) {
				int next_node = next.first;
				int next_cost = next.second;
				if (upper[curr] != INF && upper[next_node] > upper[curr] + next_cost) {
					// 완화
					upper[next_node] = upper[curr] + next_cost;
					updated = true;
				}
			}
		}
		// 모든 간선에 대해 완화가 일어나지 않으면 종료
		if (!updated) break;
	}
	// 마지막 N번 째 순회에서 완화가 일어났으면 음수 사이클 존재
	if (updated) {
		upper.clear();
	}
	return upper;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		adj[A].push_back({ B, C });
	}
	vector<ll> ans = bellmanFord(1);
	if (ans.size()) {
		for (int i = 2; i <= N; i++) {
			if (ans[i] == INF) {
				cout << "-1" << "\n";
			}
			else {
				cout << ans[i] << "\n";
			}
		}
	}
	else {
		cout << "-1" << "\n";
	}

	return 0;
}