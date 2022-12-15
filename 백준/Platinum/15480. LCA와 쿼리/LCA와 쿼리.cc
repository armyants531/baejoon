// LCA와 쿼리  // tree  // Lowest Common Ancestor
// LCA 2의 코드 이용
// root가 달라질 때마다 쿼리를 새로 구하면 시간 초과
// 1을 root로 하는 tree에서 LCA(r, u), LCA(u, v), LCA(v, r) 중 depth가 가장 큰 것이 답
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> parent(100001, vector<int>(19, -1));
vector<int> depth(100001, -1);
vector<vector<int>> adj(100001);
int max_depth = 18;

// dfs를 통해 각 node의 parent[i][0](i의 첫 번째 부모)와, depth 구하기
void treeDfs(int node) {
	for (int i = 0; i < adj[node].size(); i++) {
		int next = adj[node][i];
		if (depth[next] == -1) { // 방문하지 않았으면
			parent[next][0] = node;
			depth[next] = depth[node] + 1;
			treeDfs(next);
		}
	}
}

// A와 B의 가장 가까운 공통 조상 찾기
int LCA(int A, int B) {
	// 두 노드의 깊이를 맞춰줌
	if (depth[A] > depth[B]) {
		int diff = depth[A] - depth[B];
		for (int i = 0; diff > 0; i++) { // ex) 11 -> 1011(2) = 2^3 + 2^1 + 2^0
			if (diff % 2 == 1) {
				A = parent[A][i];
			}
			diff /= 2;
		}
	}
	else {
		int diff = depth[B] - depth[A];
		for (int i = 0; diff > 0; i++) {
			if (diff % 2 == 1) {
				B = parent[B][i];
			}
			diff /= 2;
		}
	}

	// A와 B가 같아질 때 까지 위로 이동
	if (A != B) {
		for (int i = max_depth; i >= 0; i--) {
			if (parent[A][i] != -1 && (parent[A][i] != parent[B][i])) {
				A = parent[A][i];
				B = parent[B][i];
			}
		}
		// parent[A][i] == parent[B][i]
		A = parent[A][0];
	}
	
	return A;
}

void makeParent(int N, int root) {
	for (int j = 0; j < max_depth; j++) {
		for (int i = 1; i <= N; i++) {
			if (parent[i][j] != -1 && i != root) {
				parent[i][j + 1] = parent[parent[i][j]][j];
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	// 루트 노드를 1번으로 설정
	depth[1] = 0;
	treeDfs(1);
	// parent 초기화(전처리)
	makeParent(N, 1);

	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int r, u, v;
		cin >> r >> u >> v;
		int A = depth[LCA(r, u)];
		int B = depth[LCA(u, v)];
		int C = depth[LCA(v, r)];
		vector<int> arr = { A, B, C };
		// 깊이가 최대인 원소 인덱스 찾기
		int max_idx = max_element(arr.begin(), arr.end()) - arr.begin();
		if (max_idx == 0) {
			cout << LCA(r, u) << "\n";
		}
		else if (max_idx == 1) {
			cout << LCA(u, v) << "\n";
		}
		else {
			cout << LCA(v, r) << "\n";
		}
	}

	return 0;
}