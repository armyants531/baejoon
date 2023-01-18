// 플로이드  // Floyd-Warshall
#include <bits/stdc++.h>

using namespace std;

int n, m;
int adj[101][101];
int MAX = 100000001;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	// init adj matrix
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			adj[i][j] = MAX;
		}
	}
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a][b] = min(adj[a][b], c);
	}
	// Floyd-Warshall
	// k: 거쳐가는 노드, i: 시작 노드, j: 도착 노드
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			if (adj[i][k] == MAX) { // i에서 k로 가는 경로가 없으면 넘어감
				continue;
			}
			for (int j = 1; j <= n; j++) {
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
			}
		}
	}
	// 출력
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (adj[i][j] == MAX || i == j) {
				cout << 0 << " ";
			}
			else {
				cout << adj[i][j] << " ";
			}
		}
		cout << "\n";
	}

	return 0;
}