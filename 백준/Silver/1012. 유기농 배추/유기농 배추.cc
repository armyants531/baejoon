#include <iostream>
#include <queue>

using namespace std;

int T, M, N, K, cnt;
int map[50][50];
bool visited[50][50];
queue<pair<int, int>> que;
int dx[4] = {0, 1, 0, -1}; // up, right, down, left
int dy[4] = {1, 0, -1, 0};

void bfs(int y, int x) {
	cnt++; // 배추흰지렁이의 수 = bfs 함수 호출의 횟수
	que.push({ y, x }); // queue에 삽입
	visited[y][x] = true;
	while (!que.empty()) {
		int y = que.front().first;
		int x = que.front().second;
		que.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (0 <= nx && 0 <= ny && nx < M && ny < N && visited[ny][nx] == false && map[ny][nx] == 1) {
				visited[ny][nx] = true;
				que.push({ ny, nx }); // queue에 삽입
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> M >> N >> K;
		cnt = 0; // init cnt 

		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				map[y][x] = 0; // init map
				visited[y][x] = false; // init visited
			}
		}
		
		for (int j = 0; j < K; j++) {
			int X, Y;
			cin >> X >> Y;
			map[Y][X] = 1;
		}
		// conduct bfs
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				if (map[y][x] == 1 && visited[y][x] == false) {
					bfs(y, x);
				}
			}
		}
		cout << cnt << "\n";
	}

	return 0;
}