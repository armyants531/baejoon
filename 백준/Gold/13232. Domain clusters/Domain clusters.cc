// Domain clusters  // SCC
#include <bits/stdc++.h>

using namespace std;

int id;
int max_scc_len = 0;
vector<int> parent_arr(5001, 0);
vector<vector<int>> adj(5001);
vector<bool> finished(5001);
stack<int> st;

int dfs(int x) {
	parent_arr[x] = id;
	id++;
	st.push(x);

	int parent = parent_arr[x];
	for (int i = 0; i < adj[x].size(); i++) {
		int y = adj[x][i];
		if (parent_arr[y] == 0) { // 방문 x
			parent = min(parent, dfs(y));
		}
		else if (!finished[y]) {
			parent = min(parent, parent_arr[y]);
		}
	}

	if (parent == parent_arr[x]) {
		int len = 0;
		while (true) {
			int t = st.top();
			st.pop();
			finished[t] = true;
			len++;
			if (t == x) {
				break;
			}
		}
		max_scc_len = max(max_scc_len, len);
	}
	return parent;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int D, L;
	cin >> D;
	cin >> L;
	for (int i = 0; i < L; i++) {
		int A, B;
		cin >> A >> B;
		adj[A].push_back(B);
	}

	for (int i = 1; i <= D; i++) {
		if (parent_arr[i] == 0) {
			dfs(i);
		}
	}
	cout << max_scc_len << "\n";

	return 0;
}