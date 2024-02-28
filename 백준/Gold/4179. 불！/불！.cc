#include <bits/stdc++.h> 

using namespace std;

vector<vector<char>> board(1000, vector<char>(1000));
vector<vector<int>> v(1000, vector<int>(1000));
vector<vector<bool>> v2(1000, vector<bool>(1000));
int cnt = 0; // 넓이 
int num = 0; // 그림 수  
int n, m;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

struct node {
	int x, y, t;
};

void bfs(vector<pair<int, int>> fire) {
	queue<node> que;
	for (int i = 0; i < fire.size(); i++) {
		int a = fire[i].first;
		int b = fire[i].second;
		v[a][b] = 0;
		que.push({ a, b, 0 });
	}
	while (!que.empty()) {
		int x = que.front().x;
		int y = que.front().y;
		int t = que.front().t;
		que.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nt = t + 1;
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && v[nx][ny] == -1 && board[nx][ny] != '#') {
				v[nx][ny] = nt;
				que.push({ nx, ny, nt });
			}
		}
	}
}

int bfs2(int c, int d) {
	queue<node> que;
	v[c][d] = 0;
	que.push({ c, d, 0 });
	while (!que.empty()) {
		int x = que.front().x;
		int y = que.front().y;
		int t = que.front().t;
		que.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nt = t + 1;
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && !v2[nx][ny] && board[nx][ny] != '#') {
				if (v[nx][ny] > nt || v[nx][ny] == -1) { // 불에 닿기 전이면  
					v2[nx][ny] = true;
					que.push({ nx, ny, nt });
				}
			}
			else if (nx == -1 || nx == n || ny == -1 || ny == m) {
				return nt;
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	int c, d;
	vector<pair<int, int>> fire;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'F') {
				fire.push_back({i, j});
			}
			else if (board[i][j] == 'J') {
				c = i;
				d = j;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			v[i][j] = -1;
		}
	}
	if (fire.size() != 0) {
		bfs(fire);
	}
	int ans = bfs2(c, d);
	if (ans == -1) {
		cout << "IMPOSSIBLE" << "\n";
	}
	else {
		cout << ans << "\n";
	}
	return 0;
}