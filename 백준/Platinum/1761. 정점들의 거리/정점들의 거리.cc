// 정점들의 거리  // tree  // Lowest Common Ancestor
// 일반 LCA 알고리즘 사용
#include <bits/stdc++.h>

using namespace std;

vector<bool> visited(40001, false);
vector<int> parent(40001); // 각 노드의 부모
vector<int> depth(40001); // 각 노드의 깊이
vector<pair<int, int>> adj[40001]; // 인접 리스트
vector<int> length(50001); // 부모 노드와의 거리 저장
queue<int> que;

// 모든 노드의 깊이 구하기
void bfs(int start) {
	visited[start] = true;
	depth[start] = 0;
	length[start] = 0;
	que.push(start);
	while (!que.empty()) {
		int x = que.front();
		que.pop();
		for (int i = 0; i < adj[x].size(); i++) {
			int y = adj[x][i].first;
			if (!visited[y]) {
				parent[y] = x;
				visited[y] = true;
				depth[y] = depth[x] + 1;
				length[y] = adj[x][i].second;
				que.push(y);
			}
		}
	}
}

int distance(int A, int B) {
	// 두 노드의 깊이 맞추기
	int dist = 0;
	if (depth[A] > depth[B]) {
		while (depth[A] != depth[B]) {
			dist += length[A];
			A = parent[A];
		}
	}
	else {
		while (depth[A] != depth[B]) {
			dist += length[B];
			B = parent[B];
		}
	}
	// 공통 조상 찾을 때까지 반복
	while (A != B) {
		dist += length[A] + length[B];
		A = parent[A];
		B = parent[B];
	}
	return dist;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;

	vector<int> num(N + 1, 0);
	for (int i = 1; i < N; i++) {
		int A, B, len;
		cin >> A >> B >> len;
		adj[A].push_back({ B, len });
		adj[B].push_back({ A, len });
		num[A]++;
		num[B]++;
	}
	// 아무 노드에서 시작
	bfs(1);

	// 모든 노드의 깊이 구하기
	int M; 
	cin >> M;
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		cout << distance(A, B) << "\n";
	}

	return 0;
}