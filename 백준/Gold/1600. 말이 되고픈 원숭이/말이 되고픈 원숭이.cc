// 말이 되고픈 원숭이  // bfs
#include <bits/stdc++.h>

using namespace std;

int dx[12] = { 0, 0, -1, 1, -1, -2, -2, -1, 1, 2, 2, 1 };
int dy[12] = { -1, 1, 0, 0, 2, 1, -1, -2, -2, -1, 1, 2 };
int mp[200][200] = { 0, };
bool visited[200][200][31] = {false,};
int W, H, K;
int min_cnt = 40001;

struct coord {
	int x;
	int y;
	int cnt;
	int abi;
};

void bfs(int x, int y) {
	queue<coord> que;
	visited[x][y][0] = true;
	que.push({x, y, 0, 0});
	while (!que.empty()) {
		coord c = que.front();
		//cout << c.x << " " << c.y << " " << c.cnt << " " << c.abi << "\n";
		que.pop();
		if (c.x == W - 1 && c.y == H - 1) {
			min_cnt = min(min_cnt, c.cnt);
		}
		for (int i = 0; i < 4; i++) {
			int nx = c.x + dx[i];
			int ny = c.y + dy[i];
			if (0 <= nx && nx < W && 0 <= ny && ny < H) {
				if (!visited[nx][ny][c.abi] && mp[nx][ny] == 0) {
					visited[nx][ny][c.abi] = true;
					que.push({ nx, ny, c.cnt + 1, c.abi });
				}
			}
		}
		if (c.abi < K) {
			for (int i = 4; i < 12; i++) {
				int nx = c.x + dx[i];
				int ny = c.y + dy[i];
				if (0 <= nx && nx < W && 0 <= ny && ny < H) {
					if (!visited[nx][ny][c.abi + 1] && mp[nx][ny] == 0) {
						visited[nx][ny][c.abi + 1] = true;
						que.push({ nx, ny, c.cnt + 1, c.abi + 1 });
					}
				}
			}
		}
	}
}

int main() {
	cin >> K;
	cin >> H >> W;
	for (int i = 0; i < W; i++) {
		for (int j = 0; j < H; j++) {
			cin >> mp[i][j];
		}
	}
	bfs(0, 0);
	if (min_cnt == 40001) {
		cout << -1 << "\n";
	}
	else {
		cout << min_cnt << "\n";
	}

	return 0;
}