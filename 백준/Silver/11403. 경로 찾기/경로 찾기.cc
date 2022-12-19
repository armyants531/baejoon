// 경로 찾기  // Floyd-Warshall
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj(100, vector<int>(100));
int INF = 1000000000;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int val;
			cin >> val;
			if (val == 0) {
				adj[i][j] = INF;
			}
			else {
				adj[i][j] = 1;
			}
		}
	}

	// k: 거쳐가는 노드
	for (int k = 0; k < N; k++) {
		// i: 출발 노드
		for (int i = 0; i < N; i++) {
			// j: 도착 노드
			for (int j = 0; j < N; j++) {
				if (adj[i][k] + adj[k][j] < adj[i][j]) {
					adj[i][j] = adj[i][k] + adj[k][j];
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (adj[i][j] == INF) {
				cout << 0 << " ";
			}
			else {
				cout << 1 << " ";
			}
		}
		cout << "\n";
	}

	return 0;
}