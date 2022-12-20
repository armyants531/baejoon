// 욕심쟁이 판다  // dp  // dfs
// 현재 위치에서 방문할 수 있는 칸의 최대 수를 talublation하며 dfs
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> forest(500, vector<int>(500));
vector<vector<int>> table(500, vector<int>(500)); // tabulation
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int n;

// 현재 칸에서 이동 가능 최대 횟수를 리턴 및 저장
int dfs(int x, int y) { // 행 번호, 열 번호
	int max_cnt = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < n && 0 <= ny && ny < n && forest[x][y] < forest[nx][ny]) {
			if (table[nx][ny] != 0) { // 이미 방문할 수 있는 칸 수를 아는 경우
				max_cnt = max(max_cnt, 1 + table[nx][ny]);
			}
			else {
				max_cnt = max(max_cnt, 1 + dfs(nx, ny)); // 1 + (nx, ny)에서 방문할 수 있는 칸 수와 비교
			}
		}
	}
	// 현재 위치의 방문 가능 최대 칸 수를 기록
	return table[x][y] = max_cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> forest[i][j];
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (table[i][j] == 0) {
				dfs(i, j);
			}
		}
	}

	// 칸 수의 최댓값 찾기
	int max_movement = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			max_movement = max(max_movement, table[i][j]);
			//cout << table[i][j] << " ";
		}
		//cout << "\n";
	}
	cout << max_movement << "\n";

	return 0;
}