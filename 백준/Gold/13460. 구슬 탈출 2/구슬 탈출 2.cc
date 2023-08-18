// 구슬 탈출 2  // bfs
// 현재 상태에서 4방향으로 이동한 결과를 큐에 넣기
// 이동중에 파란공이 빠지는 경우 큐에 넣지 않고, 빨간공을 빼낼 수 있으면 종료 
#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;

bool visited[10][10][10][10]; // rx, ry, bx, by
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
char a[10][10]; // board
int ans = -1;

struct info {
	int rx, ry, bx, by, cnt;
};

void bfs(int rx, int ry, int bx, int by) {
	queue<info> que;
	que.push({ rx, ry, bx, by, 0 });
	while (!que.empty() && que.front().cnt < 10) {
		info cur = que.front();
		visited[cur.rx][cur.ry][cur.bx][cur.by] = true;
		que.pop();
		for (int i = 0; i < 4; i++) {
			int rx = cur.rx;
			int ry = cur.ry;
			int bx = cur.bx;
			int by = cur.by;
			int cnt = cur.cnt;
			// 파란 구슬 이동
			bool blueBlocked = false; // 빨간 구슬에게 막힘 
			bool blueIsInHole = false; // 구멍에 빠짐 
			while (true) {
				if (bx + dx[i] == rx && by + dy[i] == ry) { // 빨간 구슬에게 막힘
					blueBlocked = true;
					break;
				}
				else if (a[bx + dx[i]][by + dy[i]] == '.') {
					bx += dx[i];
					by += dy[i];
				}
				else if (a[bx + dx[i]][by + dy[i]] == '#') {
					break;
				}
				else { // 'O'
					blueIsInHole = true;
					break;
				}
			}
			if (blueIsInHole) {
				continue;
			}
			// 빨간 구슬 이동
			bool redIsInHole = false; // 구멍에 빠짐
			while (true) {
				if (rx + dx[i] == bx && ry + dy[i] == by) {
					break;
				}
				else if (a[rx + dx[i]][ry + dy[i]] == '.') {
					rx += dx[i];
					ry += dy[i];
				}
				else if (a[rx + dx[i]][ry + dy[i]] == '#') {
					break;
				}
				else { // 'O'
					redIsInHole = true;
					break;
				}
			}
			if (redIsInHole) { // 구멍에 빠진 빨간 구슬 치워주기
				rx = -1;
				ry = -1;
			}
			// 파란 구슬이 빨간 구슬에 가로막혔을 때
			if (blueBlocked) {
				while (true) {
					if (bx + dx[i] == rx && by + dy[i] == ry) {
						break;
					}
					else if (a[bx + dx[i]][by + dy[i]] == '.') {
						bx += dx[i];
						by += dy[i];
					}
					else if (a[bx + dx[i]][by + dy[i]] == '#') {
						break;
					}
					else { // 'O'
						blueIsInHole = true;
						break;
					}
				}
			}
			if (blueIsInHole) {
				continue;
			}
			else if (redIsInHole) {
				ans = cnt + 1;
				return;
			}
			else if (!visited[rx][ry][bx][by]) {
				//cout << rx << " " << ry << " " << bx << " " << by << " " << cur.cnt + 1 << "\n";
				que.push({ rx, ry, bx, by, cnt + 1 });
			}
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	int rx, ry, bx, by;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'R') {
				rx = i;
				ry = j;
			}
			else if (a[i][j] == 'B') {
				bx = i;
				by = j;
			}
		}
	}
	a[rx][ry] = '.';
	a[bx][by] = '.';
	bfs(rx, ry, bx, by);
	cout << ans << "\n";

	return 0;
}