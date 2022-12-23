// 점프 점프  // dfs
#include <bits/stdc++.h>

using namespace std;

vector<int> arr;
vector<bool> visited;
int cnt = 0;
int n;

void dfs(int node) {
	cnt++;
	visited[node] = true;
	int a = arr[node];
	if (node - a >= 0 && !visited[node - a]) {
		dfs(node - a);
	}
	if (node + a < n && !visited[node + a]) {
		dfs(node + a);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	visited.resize(n, false);
	for (int i = 0; i < n; i++) {
		int ai;
		cin >> ai;
		arr.push_back(ai);
	}
	int s;
	cin >> s;
	dfs(s - 1);
	cout << cnt << "\n";

	return 0;
}