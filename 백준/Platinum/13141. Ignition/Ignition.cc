// Ignition  // Floyd-Warshall
#include <bits/stdc++.h>

using namespace std;

int N, M;
int adj[201][201];
int MAX = 100000001;

struct edge {
	int S;
	int E;
	int L;
};

void floyd() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	// init
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			adj[i][j] = MAX;
		}
	}
	vector<edge> Edge;
	for (int i = 0; i < M; i++) {
		int S, E, L;
		cin >> S >> E >> L;
		int min_L = min(L, adj[S][E]);
		adj[S][E] = min_L;
		adj[E][S] = min_L;
		Edge.push_back({ S, E, L });
	}
	for (int i = 1; i <= N; i++) {
		adj[i][i] = 0;
	}
	floyd();
	double T = MAX;
	for (int i = 1; i <= N; i++) {
		double max_t = 0;
		// 시작 노드(i)에서 모든 edge를 이루는 두 vertex를 태우는데 걸리는 시간을 조사
		for (int j = 0; j < M; j++) { // edge 수 만큼 반복
			double t; // 해당 edge가 타는데 걸리는 시간
			double t1 = adj[i][Edge[j].E]; // E가 타는데 걸리는 시간
			double t2 = adj[i][Edge[j].S]; // S가 타는데 걸리는 시간
			double len = Edge[j].L; // edge의 길이
			// edge가 타는데 걸리는 시간 계산
			if (t1 > t2) {
				len -= (t1 - t2);
				t = t1 + len / 2.0;
			}
			else { // t1 <= t2
				len -= (t2 - t1);
				t = t2 + len / 2.0;
			}
			// 모두 타는데 걸리는 시간 갱신
			max_t = max(max_t, t);
		}
		// T는 max_t 중 최솟값
		T = min(T, max_t);
	}
	cout << fixed;
	cout.precision(1);
	cout << T << "\n";
}