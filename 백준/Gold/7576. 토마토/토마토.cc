#include <iostream>
#include <queue>

using namespace std;

typedef struct NODE {
	int y;
	int x;
} node;

int M, N, cnt = 0;
int box[1000][1000];  // 세로, 가로
queue<node> que;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void bfs() {
	while (!que.empty()) { // queue에서 익은 토마토 꺼냄
		int y = que.front().y;
		int x = que.front().x;
		que.pop();
		// 현재 익은 토마토와 인접한 칸을 확인
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i]; 
			int nx = x + dx[i];
			// 범위 내의 익지 않은 토마토이면 
			if (0 <= ny && 0 <= nx && ny < N && nx < M && box[ny][nx] == 0) {
				box[ny][nx] = box[y][x] + 1; // 익은 날짜 + 1 값을 저장
				que.push({ny, nx});
			}
		}
	}
}

// 익지 못하는 토마토 있는지 확인하고 결과 출력
int check() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (box[i][j] == 0) { // 익지 않은 토마토 있으면
				return -1;
			}
			else if (cnt < box[i][j]) { // 날짜 갱신 
				cnt = box[i][j];
			}
		}
	}
	return cnt - 1;
	
}

int main() {
	cin >> M >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> box[i][j];
			if (box[i][j] == 1) // 익은 토마토이면 queue에 삽입
				que.push({ i, j });
		}
	}
	bfs(); // 익은 토마토와 연결된 모든 토마토를 익게하고 익은 날짜 + 1 값을 각 칸에 저장
	cout << check() << "\n";

	return 0;
}