// 트리의 부모 찾기  // dfs  // tree
#include <bits/stdc++.h>

using namespace std;

vector<int> adj[100001];
vector<int> parent(100001, 0);

void dfs(int x) {
	for (int i = 0; i < adj[x].size(); i++) {
		int y = adj[x][i];
		if (parent[y] == 0) {
			parent[y] = x;
			dfs(y);
		}
	}
}

int main() {
	int N;
	cin >> N;
	for (int i = 1; i < N; i++) {
		int A, B;
		cin >> A >> B;
		adj[A].push_back(B);
		adj[B].push_back(A);
	}
	
	parent[1] = 1;
	dfs(1);
	for (int i = 2; i <= N; i++) {
		cout << parent[i] << "\n";
	}
	
	return 0;
}