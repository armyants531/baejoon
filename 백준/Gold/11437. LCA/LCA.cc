// LCA  // tree  // Lowest Common Ancestor  // bfs
// 일반 LCA 알고리즘 사용
#include <bits/stdc++.h>

using namespace std;

vector<bool> visited(50001, false);
vector<int> parent(50001);
vector<int> depth(50001); // 노드의 깊이(자신을 제외한 조상 노드의 개수)
vector<int> adj[50001];
queue<int> que;

// 모든 노드의 깊이 구하기
void bfs(int start) {
	visited[start] = true;
	depth[start] = 0;
	que.push(start);
	while (!que.empty()) {
		int x = que.front(); // 부모 노드
		que.pop();
		for (int i = 0; i < adj[x].size(); i++) {
			int y = adj[x][i];
			if (!visited[y]) {
				parent[y] = x;
				visited[y] = true;
				depth[y] = depth[x] + 1; // 부모 노드의 깊이 + 1
				que.push(y);
			}
		}
	}
}

// A와 B의 가장 가까운 공통 조상 찾기
int LCA(int A, int B) {
	// 두 노드의 깊이를 맞춰줌
	if (depth[A] > depth[B]) {
		while (depth[A] != depth[B]) {
			A = parent[A];
		}
	}
	else {
		while (depth[A] != depth[B]) {
			B = parent[B];
		}
	}
	// 공통 조상이 나올 때 까지 위로 올라감
	while (A != B) {
		A = parent[A];
		B = parent[B];
	}
	// 공통 조상 리턴
	return A;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	for (int i = 1; i < N; i++) {
		int A, B;
		cin >> A >> B;
		adj[A].push_back(B);
		adj[B].push_back(A);
	}

	bfs(1);

	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		cout << LCA(A, B) << "\n";
	}

	return 0;
}