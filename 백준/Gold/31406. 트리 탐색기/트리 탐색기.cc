#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;
using pdd = pair<double, double>;

vector<vector<int>> adj(2001);
vector<bool> v(2001, 1); // v[i]: i의 toggle 여부 
vector<int> a; // 방문 순서 리스트  

void dfs(int x) { // toggle이 안된 것 순서대로 기록 
	if (!v[x]) {
		a.push_back(x);
		for (auto y : adj[x]) {
			dfs(y);
		}
	}
}

void toggle(int x) { // toggle 수행 
	for (auto y : adj[x]) {
		v[y] = !v[y];
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, Q;
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		int M;
		cin >> M;
		for (int j = 0; j < M; j++) {
			int e;
			cin >> e;
			adj[i].push_back(e);
		}	
	}
	// 초기화 
	v[1] = false;
	for (int i = 0; i < adj[1].size(); i++) {
		v[adj[1][i]] = false;
	} 
	dfs(1);	// 초기 상태 기록 
	int cur = 1;
	for (int i = 0; i < Q; i++) {
		string s;
		cin >> s;
		if (s == "toggle") {
			int start = a[cur];
			toggle(start);
			a.clear();
			dfs(1);	
		}
		else { // move
			int k;
			cin >> k;
			cur += k; 
			if (cur > (int)a.size() - 1) {
				cur = (int)a.size() - 1;
			}
			else if (cur < 1) {
				cur = 1;
			}
			cout << a[cur] << "\n";
		}
	}
	
	return 0;
}