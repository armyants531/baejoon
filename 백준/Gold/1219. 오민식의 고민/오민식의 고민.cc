// 오민식의 고민  // Bellman-Ford 
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<pair<ll, ll>> adj[50]; // 0~49번 도시
ll INF = 50000001;
int N, S, E, M;
vector<ll> money;

// 양수 사이클 위의 한 도시에서 도착 도시까지 도달할 수 있는가?
bool bfs(vector<int> cycle) {
	vector<bool> visited(N, false);
	queue<int> que;
	for (auto node : cycle) {
		que.push(node);
		visited[node] = true;
	}
	while (!que.empty()) {
		int curr = que.front();
		if (curr == E) { // 도착 가능하면
			return true;
		}
		que.pop();
		for (auto next : adj[curr]) {
			int next_node = next.first;
			if (!visited[next_node]) {
				que.push(next_node);
				visited[next_node] = true;
			}
		}
	}
	return false;
}

string bellmanFord() {
	vector<ll> lower(N, -INF);
	lower[S] = money[S];
	bool updated;
	
	for (int i = 0; i < N - 1; i++) { // N - 1번 반복
		updated = false;
		for (int curr = 0; curr <= N - 1; curr++) {
			for (auto next : adj[curr]) {
				int next_node = next.first;
				int next_money = next.second + money[next_node];
				if (lower[curr] != -INF && lower[next_node] < lower[curr] + next_money) {
					lower[next_node] = lower[curr] + next_money;
					updated = true;
				}
			}
		}
		if (!updated) {
			break;
		}
	}
	vector<int> updatedList; // N번 째 업데이트 된 노드 저장
	// N번 째 업데이트 시도
	updated = false;
	for (int curr = 0; curr <= N - 1; curr++) {
		for (auto next : adj[curr]) {
			int next_node = next.first;
			int next_money = next.second + money[next_node];
			if (lower[curr] != -INF && lower[next_node] < lower[curr] + next_money) {
				lower[next_node] = lower[curr] + next_money;
				updated = true;
				updatedList.push_back(next_node); // 양수 사이클을 형성하는 노드를 저장
			}
		}
	}
	if (lower[E] == -INF) { // 방문 불가
		return "gg";
	}
	else if (updated) { // 양수 사이클 존재(여러 개가 존재 가능) -> 한 사이클 당 한 개 이상의 노드를 탐색해야함
		if (bfs(updatedList)) {
			return "Gee";
		}
		else {
			return to_string(lower[E]);
		}
	}
	else {
		return to_string(lower[E]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> S >> E >> M;
	for (int i = 0; i < M; i++) {
		int start, end, cost;
		cin >> start >> end >> cost;
		adj[start].push_back({ end, -cost });
	}
	for (int i = 0; i < N; i++) {
		ll m;
		cin >> m;
		money.push_back(m);
	}
	cout << bellmanFord() << "\n";
}