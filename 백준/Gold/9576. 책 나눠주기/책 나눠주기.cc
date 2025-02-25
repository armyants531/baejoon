#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

vector<vector<int>> a(MAX);
bool v[MAX];
int b[MAX];
int cnt = 0;

bool dfs(int x) {
	for (auto y : a[x]) {
		if (v[y]) continue;	
		v[y] = true;
		if (b[y] == 0 || dfs(b[y])) {
			b[y] = x;
			return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T, N, M;
	cin >> T; 
	while (T--) {
		cin >> N >> M;
		a = vector<vector<int>>(MAX);
		cnt = 0;
		for (int i = 1; i <= M; i++) {
			int ai, bi;
			cin >> ai >> bi;
			for (int j = ai; j <= bi; j++) {
				a[i].push_back(j); 
			}
		}
		for (int i = 1; i <= M; i++) {
			fill(v, v + N + 1, false);
			if (dfs(i)) {
				cnt++;
			}
		}
		cout << cnt << "\n";
		fill(b, b + N + 1, 0);
	}
}