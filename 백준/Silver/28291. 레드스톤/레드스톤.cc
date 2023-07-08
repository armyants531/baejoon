#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int visited[51][51];
int arr[51][51];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

struct point {
	int x, y, ten;
};

void bfs(queue<point> que, int W, int H) {
	while (!que.empty()) {
		int x = que.front().x;
		int y = que.front().y;
		int ten = que.front().ten;
		que.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < W && ny >= 0 && ny < H && arr[nx][ny] != 0 && arr[nx][ny] != -1 && visited[nx][ny] < ten - 1) {
				visited[nx][ny] = ten - 1;
				if (arr[nx][ny] == 1) {
					que.push({ nx, ny, ten - 1 });
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int W, H, N;
	cin >> W >> H >> N;
	queue<point> que;
	for (int i = 0; i < N; i++) {
		string s;
		int x, y;
		cin >> s >> x >> y;
		if (s == "redstone_block") {
			que.push({x, y, 16});
			visited[x][y] = 16;
			arr[x][y] = -1;
		}
		else if (s == "redstone_dust") {
			arr[x][y] = 1;
		}
		else {
			arr[x][y] = 2;
		}
	}
	bfs(que, W, H);
	bool can = true;
	for (int i = 0; i < W; i++) {
		for (int j = 0; j < H; j++) {
			if (arr[i][j] == 2 && visited[i][j] == 0) {
				can = false;
				//cout << i << " " << j << "\n";
				break;
			}
		}
	}
	if (can) {
		cout << "success" << "\n";
	}
	else {
		cout << "failed" << "\n";
	}

	return 0;
}