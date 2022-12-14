// LCA 2  // tree  // Lowest Common Ancestor  // Sparse Table
// DP를 이용한 전처리를 통해 최적화된 LCA 알고리즘 사용
// x의 2^k(2의 k승)번째 부모: parent[x][k] = parent[parent[x][k - 1]][k - 1]
// O(log n)
// https://blog.naver.com/kks227/220820773477 참고
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> parent(100001, vector<int>(19, -1)); // ceil(log(2, 100000)) = 17
vector<int> depth(100001, -1); // 노드의 깊이
vector<int> adj[100001]; // 인접 리스트
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
		for (int i = 0; diff > 0; i++) {
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
	int i = max_depth;
	if (A != B) {
		while (i >= 0) {
			if (parent[A][i] != -1 && (parent[A][i] != parent[B][i])) {
				A = parent[A][i];
				B = parent[B][i];
			}
			i--;
		}
		// A의 부모가 공통 조상
		A = parent[A][0];
	}
	
	return A;
}

void makeParent(int N) {
	for (int j = 0; j < max_depth; j++) {
		for (int i = 2; i <= N; i++) {
			if (parent[i][j] != -1) {
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
	for (int i = 1; i < N; i++) {
		int A, B;
		cin >> A >> B;
		adj[A].push_back(B);
		adj[B].push_back(A);
	}
	// 루트 노드는 1번
	depth[1] = 0;
	treeDfs(1);
	// parent 초기화(전처리)
	makeParent(N);
	
	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		cout << LCA(A, B) << "\n";
	}

	return 0;
}