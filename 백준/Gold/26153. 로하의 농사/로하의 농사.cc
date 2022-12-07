// 로하의 농사  // dfs
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph(50, vector<int>(50));
vector<vector<bool>> visited(50, vector<bool>(50, false));

int N, M, p, max_water = 0;
// 상, 하, 좌, 우
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int x, int y, int cnt, int w, int dir) { // x행 y열, 재료 갯수, 물의 양, 현재 방향(-1: 무방향, 0 ~ 3: 상, 하, 좌, 우)
	w += graph[x][y];
	visited[x][y] = true;
	max_water = max(max_water, w);
	// cout << graph[x][y] << "\n";
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if ((nx >= 0 && nx < N) && (ny >= 0 && ny < M) && !visited[nx][ny]) {
			if (dir == -1 || dir == i) { // 현재 시작점이거나 현재 방향과 같은 경우 
				if (cnt + 1 <= p) {
					dfs(nx, ny, cnt + 1, w, i);
					visited[nx][ny] = false;
				}
			}
			else { // 현재 방향과 다른 경우 
				if (cnt + 2 <= p) {
					dfs(nx, ny, cnt + 2, w, i);
					visited[nx][ny] = false;
				}
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int W;
			cin >> W;
			graph[i][j] = W;
		}
	}
	int x, y;
	cin >> x >> y >> p;
	dfs(x, y, 0, 0, -1);
	cout << max_water << "\n";

	return 0;
}