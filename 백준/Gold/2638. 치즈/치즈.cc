// 치즈  // bfs
#include <bits/stdc++.h>

using namespace std;

typedef struct NODE {
	int y;
	int x;
} node;

vector<vector<int>> graph;
queue<node> que;
int N, M, T = 0;
int cnt = -1;
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

// 치즈 바깥 공기 부분을 너비 우선 탐색하고 모두 녹았는지 여부를 리턴
void bfs(int y, int x) {
	cnt = 0; // 치즈 갯수 초기화
	vector<vector<bool>> visited(N, vector<bool>(M, false));
	que.push({ y, x });
	T++; // 시간 증가
	visited[y][x] = true; // 방문 처리
	while (!que.empty()) {
		int y = que.front().y;
		int x = que.front().x;
		que.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < M && !visited[ny][nx]) { // 범위 내에 있고 방문하지 않았으면
				if (graph[ny][nx] == 1) { // 방문하지 않은 치즈가 있는 칸이면
					graph[ny][nx] = -1; // 임시 녹임
					cnt++;
				}
				else if (graph[ny][nx] == -1) { // 임시 녹임 상태이면 
					visited[ny][nx] = true; // 방문 처리
					graph[ny][nx] = 0; // 녹임(bfs에서 두 번 방문 했으므로)
					cnt++; // 치즈 갯수 증가
				}
				else { // 치즈가 없는 칸이면
					visited[ny][nx] = true; // 방문 처리
					que.push({ ny, nx }); // 큐에 삽입
				}
			}
		}
	}
	if (cnt == 0) { // 치즈가 없으면
		T--; // 시간 1 줄이기
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		vector<int> arr;
		graph.push_back(arr);
		for (int j = 0; j < M; j++) {
			int val;
			cin >> val;
			graph[i].push_back(val);
		}
	}
	while (true) {
		if (cnt == 0) // 치즈가 없으면
			break;
		bfs(0, 0); // (0, 0)에서 시작(항상 치즈 없는 칸)
		// 임시 녹임 상태 치즈 다시 원상 복구
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (graph[i][j] == -1)
					graph[i][j] = 1;
			}
		}
	}
	cout << T << "\n";

	return 0;
}