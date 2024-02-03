#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;

vector<vector<int>> A(65, vector<int>(65));
vector<vector<int>> B(65, vector<int>(65));
vector<vector<bool>> v(65, vector<bool>(65));

int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };

int H, W;
int cnt = 0;
int last_update = 0;

void dfs(int r, int c, int dir) {
	cnt++;
	if (r >= H || r < 0 || c >= W || c < 0) {
		return;
	}
	if (cnt - last_update > 100000) return;
	if (v[r][c] == false) {
		v[r][c] = true;
		last_update = cnt;
		int ndir = dir + A[r][c];
		ndir %= 4;
		int nr = r + dr[ndir];
		int nc = c + dc[ndir];
		dfs(nr, nc, ndir);
	}
	else { // v[r][c] = true;
		int ndir = dir + B[r][c];
		ndir %= 4;
		int nr = r + dr[ndir];
		int nc = c + dc[ndir];
		dfs(nr, nc, ndir);
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> H >> W;
	int R, C, D;
	cin >> R >> C >> D;
	for (int i = 0; i < H; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < W; j++) {
			A[i][j] = (int)(s[j] - '0');
		}
	}
	for (int i = 0; i < H; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < W; j++) {
			B[i][j] = (int)(s[j] - '0');
		}
	}
	dfs(R, C, D);
	cout << last_update << "\n";

	return 0;
}