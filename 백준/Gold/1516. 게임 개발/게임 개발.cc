#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
vector<int> t(501);
vector<int> ans(501);
vector<vector<int>> adj(501);
vector<vector<int>> pre(501);
vector<int> in(501); // indgree
vector<int> ord(501); // order

void topologySort(int n) {
	queue<int> que; // number
	// insert the nodes which have 0 indegree
	for (int i = 1; i <= n; i++) {
		if (in[i] == 0) {
			que.push({i});
		}
	}
	for (int i = 1; i <= n; i++) {
		// if queue is empty before visit n node
		if (que.empty()) {
			return;	
		}
		int node = que.front();
		que.pop();
		ord[i] = node;
		for (auto next : adj[node]) {
			in[next]--;
			if (in[next] == 0) {
				que.push(next);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int ti;
		cin >> ti;
		t[i] = ti;
		while (true) {
			int num;
			cin >> num;
			if (num == -1) break;
			adj[num].push_back(i);
			pre[i].push_back(num);
			in[i]++;
		}
	}
	topologySort(N);
	for (int i = 1; i <= N; i++) {
		int max_t = t[ord[i]];
		if (pre[ord[i]].size() != 0) {
			for (auto a : pre[ord[i]]) {
				max_t = max(max_t, t[a] + t[ord[i]]);
			}
		}
		t[ord[i]] = max_t;
		ans[ord[i]] = max_t;
	}
	for (int i = 1; i <= N; i++) {
		cout << ans[i] << "\n";
	}
	
	return 0;
}