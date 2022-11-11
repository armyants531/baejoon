// 트리의 지름  // dfs
// https://blog.myungwoo.kr/112 참고, https://dbstndi6316.tistory.com/153 참고
#include <bits/stdc++.h>

using namespace std;

int V; // input
int max_dist = 0;
int max_node;
vector <pair<int, int>> adj[100001]; // 인접 리스트(노드 번호, 거리)
vector<bool> visited(100001, false); // 100001 크기의 visited 벡터 초기화

void dfs(int node, int dist) {
	visited[node] = true; // 현재 노드 방문 처리
	if (dist > max_dist) {
		// 정보 갱신
		max_dist = dist;
		max_node = node;
	}
	int next;
	int dist2;
	for (int i = 0; i < adj[node].size(); i++) {
		next = adj[node][i].first; // 다음 노드 정보 저장
		dist2 = adj[node][i].second; // 거리 정보 저장
		if (!visited[next]) { // 방문하지 않았으면
			dfs(next, dist + dist2); // dfs 진행
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V;
	int num1, num2, dist;
	// input
	for (int i = 0; i < V; i++) {
		cin >> num1 >> num2;
		while (num2 != -1) {
			cin >> dist;
			adj[num1].push_back({ num2, dist });
			adj[num2].push_back({ num1, dist });
			cin >> num2;
		}
	}
	dfs(1, 0);
	fill(visited.begin(), visited.end(), false); // init visited
	dfs(max_node, 0);
	cout << max_dist << "\n";

	return 0;
}