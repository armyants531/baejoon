// 플로이드 2  // Floyd-Warshall
// "알고리즘 문제 해결 전략" 참고
#include <bits/stdc++.h>

using namespace std;

int n, m;
int adj[101][101];
int MAX = 100000001;
int last_k[101][101]; // 마지막으로 경유한 도시 번호 저장

// Floyd-Warshall
void floyd() {
	memset(last_k, -1, sizeof(last_k)); // 초기화
	// k: 거쳐가는 노드, i: 시작 노드, j: 도착 노드
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			if (adj[i][k] == MAX) { // i에서 k로 가는 경로가 없으면 넘어감
				continue;
			}
			for (int j = 1; j <= n; j++) {
				if (adj[i][j] > adj[i][k] + adj[k][j]) {
					adj[i][j] = adj[i][k] + adj[k][j];
					last_k[i][j] = k; // k 경유 표시
				}
			}
		}
	}
}

// a에서 b로 가는 최단경로 찾기
void reconstruct(int a, int b, vector<int>& path) {
	if (last_k[a][b] == -1) { // basis
		path.push_back(a);
		if (a != b) path.push_back(b);
	}
	else {
		int k = last_k[a][b];
		reconstruct(a, k, path);
		path.pop_back(); // 중간의 k가 중복으로 들어감
		reconstruct(k, b, path);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
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
	for (int i = 1; i <= n; i++) {
		adj[i][i] = 0;
	}
	floyd();
	// 출력
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (adj[i][j] == MAX) {
				cout << 0 << " ";
			}
			else {
				cout << adj[i][j] << " ";
			}
		}
		cout << "\n";
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			vector<int> path;
			reconstruct(i, j, path);
			if (adj[i][j] == MAX || i == j) { // 갈 수 없거나 i -> i 로 갈 때
				cout << 0 << "\n";
			}
			else {
				cout << path.size() << " ";
				for (auto node : path) {
					cout << node << " ";
				}
				cout << "\n";
			}
		}
	}

	return 0;
}