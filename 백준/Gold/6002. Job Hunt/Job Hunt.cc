// Job Hunt  // 
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<pair<int, ll>> adj[501]; // {연결 정점 번호, 간선 가중치}
ll INF = 5000000;
int D, P, C, F, S;
ll max_val = 0;

// 양수 사이클이 있으면 빈 배열을 반환
vector<ll> bellmanFord() {
	// 초기화
	vector<ll> lower(C + 1, -INF);
	lower[S] = D;
	max_val = D;
	bool updated = false;
	for (int i = 0; i < C; i++) {
		updated = false;
		for (int curr = 1; curr <= C; curr++) {
			for (auto next : adj[curr]) {
				int next_money = next.first;
				int next_node = next.second;
				if (lower[curr] != -INF && lower[next_node] < lower[curr] + next_money) {
					lower[next_node] = lower[curr] + next_money; // 완화
					max_val = max(max_val, lower[next_node]);
					//cout << max_val << "\n";
					updated = true;
				}
			}
		}
		// 모든 간선에 대해 완화가 일어나지 않으면 종료
		if (!updated) break;
	}
	// 마지막 C번 째 순회에서 양수 사이클 확인
	if (updated) {
		lower.clear();
	}
	return lower;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> D >> P >> C >> F >> S;
	for (int i = 0; i < P; i++) {
		int A, B;
		cin >> A >> B;
		adj[A].push_back({D, B}); // { money, destination }
	}
	for (int i = 0; i < F; i++) {
		int J, K, T;
		cin >> J >> K >> T;
		adj[J].push_back({D-T, K});
	}
	vector<ll> ans = bellmanFord();
	if (ans.size()) {
		cout << max_val << "\n";
	}
	else {
		cout << -1 << "\n";
	}
}