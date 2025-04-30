#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj(1001);
vector<bool> v(1001);

void dfs(int N, int x) {
	cout << x << " ";
	for (int i = 0; i < adj[x].size(); i++) {
		int y = adj[x][i];
		if (!v[y]) {
			v[y] = true;
			dfs(N, y);
		}
	}
	return;
}

void bfs(int N, int V) {
	queue<int> que;
	que.push(V);
	v[V] = true;
	while (!que.empty()) {
		int x = que.front();
		cout << x << " ";
		que.pop();
		for (int i = 0; i < adj[x].size(); i++) {
			int y = adj[x][i];
			if (!v[y]) {
				que.push(y);
				v[y] = true;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, V;
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		sort(adj[i].begin(), adj[i].end());
	}
	v[V] = true;
	dfs(N, V);
	cout << "\n";
	for (int i = 1; i <= N; i++) {
		v[i] = false;
	}
	bfs(N, V);
	cout << "\n";
	
	return 0;
}