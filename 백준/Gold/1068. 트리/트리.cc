// 트리  // dfs  // tree
#include <bits/stdc++.h>

using namespace std;

vector<int> adj[50];
int leef_num = 0;
int del_node; // 지우는 노드

void dfs(int node) {
	if (node == del_node) {
		return;
	}
	else if (adj[node].empty()) {
		leef_num++;
	}
	else {
		for (int i = 0; i < adj[node].size(); i++) {
			int next = adj[node][i];
			if (next == del_node && adj[node].size() == 1) { // 제거된 노드로 인해 현재 노드가 리프 노드가 되는 경우
				leef_num++;
			}
			dfs(next);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	int root = 0;
	for (int i = 0; i < n; i++) {
		int parent;
		cin >> parent;
		if (parent == -1) {
			root = i;
		}
		else {
			adj[parent].push_back(i);
		}
	}
	cin >> del_node;
	dfs(root);
	cout << leef_num << "\n";

	return 0;
}