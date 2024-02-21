#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj(101);
vector<bool> v(101);

int bfs(int x, int y) {
	queue<pair<int, int>> que; // 번호, x와의 촌수 
	que.push({x, 0});
	while (!que.empty()) {
		int nx = que.front().first;
		int cnt = que.front().second;
		que.pop();
		v[nx] = true;
		if (nx == y) {
			return cnt;
		}
		for (auto a : adj[nx]) {
			if (!v[a]) {
				que.push({a, cnt + 1});
			}
		}
	} 
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, a, b, m;
	cin >> n >> a >> b >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	cout << bfs(a, b) << "\n";
	
	return 0;
}