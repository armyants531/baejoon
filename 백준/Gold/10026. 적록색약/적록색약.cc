#include <iostream>

using namespace std;

int N;
bool visited[100][100] = { false, };
char map[100][100];
int dy[4] = {1, -1, 0, 0}; // 상, 하, 좌, 우
int dx[4] = {0, 0, -1, 1};

void dfs(int y, int x) {
	visited[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= 0 && ny < N && nx >= 0 && nx < N && !visited[ny][nx] && (map[ny][nx] == map[y][x])) { // 범위 조건 만족하고 방문을 안 했고, 색상이 같으면
			dfs(ny, nx);
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}
	int r = 0, b = 0, g = 0;
	// 적록색약이 아닌 사람
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 'R' && !visited[i][j]) {
				dfs(i, j);
				r++;
			}
			else if (map[i][j] == 'B' && !visited[i][j]) {
				dfs(i, j);
				b++;
			}
			else if (map[i][j] == 'G' && !visited[i][j]) {
				dfs(i, j);
				g++;
			}
		}
	}
	cout << r + b + g << " ";
	
	// 적록색약인 사람 // G -> R로 변경
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 'G') {
				map[i][j] = 'R';
			}
			// initialize
			visited[i][j] = false;
		}
	}

	// initialize
	r = 0, b = 0; 
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 'R' && !visited[i][j]) {
				dfs(i, j);
				r++;
			}
			else if (map[i][j] == 'B' && !visited[i][j]) {
				dfs(i, j);
				b++;
			}
		}
	}
	cout << r + b << "\n";

	return 0;
}