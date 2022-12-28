// KUBC League (Small)  // dfs
// 인접행렬 만든 후, dfs를 시행하면서 뒤에서부터 노드의 값을 stack에 저장 
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
stack<int> st;

int dfs(int curr, int cnt) {
	visited[curr] = true;
	for (auto next : adj[curr]) {
		if (!visited[next]) {
			cnt = max(cnt, dfs(next, cnt + 1)); 
		}
	}
	st.push(curr);
	return cnt; 
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    adj.resize(N + 1);
    visited.resize(N + 1, false);
    for (int i = 1; i <= N; i++) {
    	for (int j = 1; j <= N; j++) {
    		int val;
    		cin >> val;
    		if (val == 1) {
    			adj[i].push_back(j); 
			}
		}
	}
	cout << dfs(1, 1) << "\n";
	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}
	cout << "\n";
	return 0;
}