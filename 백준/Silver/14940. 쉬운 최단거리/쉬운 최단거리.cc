#include <bits/stdc++.h>

using namespace std;

int visited[1000][1000];
int table[1000][1000];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

struct point {
	int x, y, cnt;
};
void bfs(int x, int y, int n, int m) {
	visited[x][y] = 0;
	queue<point> que;
	que.push({x, y, 0});
	while (!que.empty()) {
		x = que.front().x;
		y = que.front().y;
		int cnt = que.front().cnt;
		que.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && visited[nx][ny] == -1) {
				visited[nx][ny] = cnt + 1;
				que.push({nx, ny, cnt + 1});				
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	int x = 0;
	int y = 0;
	fill(&visited[0][0], &visited[999][1000], -1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> table[i][j];
			if (table[i][j] == 2) {
				x = i;
				y = j;
			}
			else if (table[i][j] == 0) {
				visited[i][j] = 0;
			}
		}
	}	
	bfs(x, y, n, m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << visited[i][j] << " "; 
		}
		cout << "\n";	
	}
	
	return 0;
}