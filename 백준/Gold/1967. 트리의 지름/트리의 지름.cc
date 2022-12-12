// 트리의 지름  // dfs  // tree
#include <bits/stdc++.h>

using namespace std;

int max_dist = 0;
int max_node;
vector<pair<int, int>> adj[10001]; // 인접 리스트 <노드 번호, 가중치>
vector<bool> visited(10001, false); // 방문 여부 확인

// 가장 멀리 떨어진 노드 찾기
void dfs(int x, int dist) {
	visited[x] = true;
	if (max_dist < dist) { // 정보 갱신
		max_dist = dist;
		max_node = x;
	}
	for (int i = 0; i < adj[x].size(); i++) {
		int y = adj[x][i].first;
		if (!visited[y]) {
			dfs(y, dist + adj[x][i].second);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int A, B, w;
		cin >> A >> B >> w;
		adj[A].push_back({ B, w });
		adj[B].push_back({ A, w });
	}
	// 아무 노드에서 출발
	dfs(1, 0);
	// 벡터 초기화
	fill(visited.begin(), visited.end(), false);
	// 처음 노드에서 가장 멀리 떨어진 노드에서 출발
	dfs(max_node, 0);
	cout << max_dist << "\n";

	return 0;
}