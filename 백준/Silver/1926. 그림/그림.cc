#include <bits/stdc++.h> 

using namespace std;

vector<vector<int>> b(500, vector<int>(500));
vector<vector<bool>> v(500, vector<bool>(500));
int cnt = 0; // 넓이 
int num = 0; // 그림 수  
int n, m;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void dfs(int x, int y) {
	cnt++;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m && !v[nx][ny] && b[nx][ny] == 1) {
			v[nx][ny] = true;
			dfs(nx, ny);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> b[i][j];
		}
	}
	int max_cnt = 0; 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!v[i][j] && b[i][j] == 1) {
				num++; 
				cnt = 0;
				v[i][j] = true;
				dfs(i, j);
				max_cnt = max(max_cnt, cnt);
			}
		}
	}
	cout << num << "\n";
	cout << max_cnt << "\n";
	return 0;
}