#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;
using ll = long long;
vector<vector<pii>> adj(5001); 
vector<bool> visited(5001);
vector<vector<int>> USADO(5001, vector<int>(5001));

void dfs(int x, int v, int s) { // 현재 노드, USADO, 시작 노드 
	visited[x] = true;
	for (auto Y : adj[x]) {
		int y = Y.fi;
		if (!visited[y]) {
			int usado = Y.se; 
			int next = min(v, usado); 
			USADO[s][y] = next;
			USADO[y][s] = next;
			dfs(y, next, s);
		}	
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, Q;
	cin >> N >> Q;
	for (int i = 0; i < N-1; i++) {
		int p, q, r;
		cin >> p >> q >> r;
		adj[p].push_back({q, r});
		adj[q].push_back({p, r});
	}
	for (int i = 1; i <= N; i++) {
		dfs(i, 1000000001, i);
		for (int j = 1; j <= N; j++) {
			visited[j] = false;
		}
	}
	for (int i = 0; i < Q; i++) {
		int k, v;
		cin >> k >> v;
		int cnt = 0;
		for (int j = 1; j <= N; j++) {
			if (USADO[v][j] >= k) cnt++;
		}
		cout << cnt << "\n";
	}
	
	return 0;
}