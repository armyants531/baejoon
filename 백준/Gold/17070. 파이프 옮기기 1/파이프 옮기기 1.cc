#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;

vector<vector<int>> v(17, vector<int>(17));
vector<vector<int>> dp(17, vector<int>(17));
int cnt = 0;
int N;

// type(이전 타입): |, \, -
void dfs(int x, int y, int type) {
	if (x == N-1 && y == N-1) {
		cnt++;
		return;
	} 
	if (x+1 < N && type != 3 && v[x+1][y] == 0) {
		dfs(x+1, y, 1);
	}
	if (x+1 < N && y+1 < N && v[x+1][y] == 0 && v[x][y+1] == 0 && v[x+1][y+1] == 0) {
		dfs(x+1, y+1, 2);
	}
	if (y+1 < N && type != 1 && v[x][y+1] == 0) {
		dfs(x, y+1, 3);
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> v[i][j];
		}
	}
	dfs(0, 1, 3);
	cout << cnt << "\n";
	
	return 0;
}