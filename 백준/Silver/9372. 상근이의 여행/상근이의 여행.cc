// Flying Safely  // graph  // MST
// n개의 노드를 가진 트리는 n-1개의 edge 가짐
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj(1001);
vector<bool> visited(1001, false);
int min_cnt = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int n, m;
		cin >> n >> m;
		for (int j = 0; j < m; j++) {
			int a, b;
			cin >> a >> b;
		}
		cout << n - 1 << "\n";
	}

	return 0;
}