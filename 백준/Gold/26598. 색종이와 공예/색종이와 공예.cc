#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<string> table;
vector<vector<int>> visited(1001, vector<int>(1001, 0));
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int N, M;

void dfs(int x, int y, int cnt) {
	visited[x][y] = cnt;
	char color = table[x][y];
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < N && 0 <= ny && ny < M && color == table[nx][ny]) {
			if (visited[nx][ny] == 0) {
				dfs(nx, ny, cnt);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		table.push_back(str);
	}
	int cnt = 0;
	bool pretty = true;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j] == 0) {
				cnt++;
				dfs(i, j, cnt);
				// 열 탐색
				int color = visited[i][j];
				int col_end = j;
				for (int x = j; x < M; x++) {
					if (visited[i][x] != color) {
						break; 
					}
					col_end = x;
				}
				// 행 탐색
				int row_end = i;
				for (int y = i; y < N; y++) {
					if (visited[y][j] != color) {
						break;
					}
					row_end = y;
				}
				//cout << row_end << " " << col_end << "\n";
				// 면 검사
				bool perfect = true;
				for (int y = i; y <= row_end; y++) {
					for (int x = j; x <= col_end; x++) {
						if (visited[y][x] != color) {
							perfect = false;
							//cout << "rr" << "\n";
							break;
						}
					}
					if (!perfect) {
						pretty = false;
						break;
					}
				}
				// 테두리 검사
				if (perfect) {
					for (int x = j - 1; x <= col_end + 1; x++) {
						if (i - 1 >= 0 && x >= 0 && x < M) {
							if (visited[i - 1][x] == color) {
								perfect = false;
								break;
							}
						}
						
						if (row_end + 1 < N && x >= 0 && x < M) {
							if (visited[row_end + 1][x] == color) {
								perfect = false;
								break;
							}
						}
						
					}
					if (!perfect) {
						pretty = false;
						break;
					}
					for (int y = i - 1; y <= row_end + 1; y++) {
						if (j - 1 >= 0 && y >= 0 && y < N) {
							if (visited[y][j - 1] == color) {
								perfect = false;
								
								break;
							}
						}
						
						if (col_end + 1 < M && y >= 0 && y < N) {
							if (visited[y][col_end + 1] == color) {
								perfect = false;
								break;
							}
						}
						
					}
					if (!perfect) {
						pretty = false;
						break;
					}
				}
				
			}
		}
		if (!pretty) {
			break;
		}
	}
	if (pretty) {
		cout << "dd" << "\n";
	}
	else {
		cout << "BaboBabo" << "\n";
	}

	return 0;
}