// Letters  // dfs  // backtracking 
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;
typedef long long ll;

vector<bool> visited(26);
int board[20][20];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int max_cnt = 0;
int R, C;

void dfs(int x, int y, int cnt) {
	visited[board[x][y]] = true;
	bool can_move = false;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < R && ny >= 0 && ny < C && !visited[board[nx][ny]]) {
			can_move = true;
			dfs(nx, ny, cnt + 1);
			visited[board[nx][ny]] = false;
		}
	}
	if (can_move == false) {
		max_cnt = max(max_cnt, cnt);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> R >> C;
	string s;
	for (int i = 0; i < R; i++) {
		cin >> s;
		for (int j = 0; j < C; j++) {
			board[i][j] = s[j] - 'A';	
		}
	}
	dfs(0, 0, 1);
	cout << max_cnt << "\n";

	return 0;
}