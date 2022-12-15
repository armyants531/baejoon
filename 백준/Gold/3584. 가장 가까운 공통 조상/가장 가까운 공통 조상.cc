// 가장 가까운 공통 조상  // tree  // Lowest Common Ancestor  // dfs
// 일반 LCA 알고리즘 사용(dfs)
#include <bits/stdc++.h>

using namespace std;

vector<int> parent(10001, -1);
vector<int> depth(10001);
vector<vector<int>> adj(10001);

// 모든 노드의 깊이와, 부모 정보 구하기
void dfs(int node, int dep) {
	depth[node] = dep;
	for (int i = 0; i < adj[node].size(); i++) {
		int next = adj[node][i];
		if (parent[next] == -1) { // 방문을 하지 않았으면
			parent[next] = node;
			dfs(next, dep + 1);
		}
	}
}

int LCA(int A, int B) {
	// 두 노드 깊이 맞춤
	if (depth[B] > depth[A]) {
		swap(A, B);
	}
	while (depth[A] != depth[B]) {
		A = parent[A];
	}
	// 두 노드 같아질 때 까지 위로 올라가기
	while (A != B) {
		A = parent[A];
		B = parent[B];
	}
	return A;
}


int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;
		vector<int> arr(N + 1, 0); // 자식 노드 카운트
		int A, B;
		for (int j = 0; j < N - 1; j++) {
			cin >> A >> B;
			adj[A].push_back(B);
			arr[B]++;
		}
		// root 노드 찾기
		int root = 1;
		for (int i = 1; i <= N; i++) {
			if (arr[i] == 0) { // 그 누구의 자식도 아닌 노드
				root = i;
			}
		}
		dfs(root, 0);

		cin >> A >> B;
		cout << LCA(A, B) << "\n";

		// 초기화
		fill(parent.begin(), parent.end(), -1);
		adj.clear();
		adj.resize(10001);
	}

	return 0;
}