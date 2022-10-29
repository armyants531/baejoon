#include <iostream>
#include <queue>

using namespace std;

typedef struct NODE {
	int z;
	int y;
	int x;
} node;

int M, N, H, cnt = 0;
int box[100][100][100]; // 높이, 세로, 가로
queue<node> que;
int dx[8] = {0, 0, 0, 0, 1, -1};
int dy[8] = {0, 0, 1, -1, 0, 0};
int dz[8] = {1, -1, 0, 0, 0, 0};

void bfs() {
	while (!que.empty()) {
		int z = que.front().z;
		int y = que.front().y;
		int x = que.front().x;
		que.pop();
		// 현재 익은 토마토와 인접한 칸을 확인
		for (int i = 0; i < 8; i++) {
			int nz = z + dz[i];
			int ny = y + dy[i];
			int nx = x + dx[i];
			// 범위 내의 익지 않은 토마토이면 
			if (0 <= nz && 0 <= ny && 0 <= nx && nz < H && ny < N && nx < M && box[nz][ny][nx] == 0) {
				box[nz][ny][nx] = box[z][y][x] + 1;
				que.push({nz, ny, nx});
			}
		}
	}
}

// 익지 못하는 토마토 있는지 확인하고 결과 출력
int check() {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (box[i][j][k] == 0) { // 안 익은 토마토 존재
					return -1;
				}
				else if (cnt < box[i][j][k]) { // 날짜 갱신
					cnt = box[i][j][k];
				}
			}
		}
	}
	return cnt - 1;
}

int main() {
	cin >> M >> N >> H;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> box[i][j][k];
				if (box[i][j][k] == 1) // 익은 토마토 queue에 추가
					que.push({ i, j, k });
			}
		}
	}

	// 익은 토마토와 연결된 모든 토마토를 익게하고 익은 날짜 + 1 값을 각 칸에 저장
	bfs(); 
	cout << check() << "\n";
	
	return 0;
}