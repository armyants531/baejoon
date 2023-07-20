#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<vector<int>> height(100, vector<int>(100));
vector<vector<bool>> visited(100, vector<bool>(100));
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void flood(int N, int h) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (height[i][j] <= h) {
				visited[i][j] = true;
			}
		}
	}
}

void bfs(int N, int h, int a, int b) {
	queue<pair<int, int>> que;
	visited[a][b] = true;
	que.push({ a, b });
	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny] && height[nx][ny] > h) {
				visited[nx][ny] = true;
				que.push({ nx, ny });
			}
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	int min_h = 101;
	int max_h = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> height[i][j];
			max_h = max(height[i][j], max_h);
			min_h = min(height[i][j], min_h);
		}
	}
	int max_cnt = 1; // 잠기는 구역 x
	for (int h = min_h; h <= max_h; h++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				visited[i][j] = false;
			}
		}
		flood(N, h);
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j]) {
					cnt++;
					bfs(N, h, i, j);
				}
			}
		}
		//cout << cnt << "\n";
		max_cnt = max(max_cnt, cnt);
	}
	cout << max_cnt << "\n";

	return 0;
}