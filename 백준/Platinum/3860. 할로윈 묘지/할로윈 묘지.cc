// Haunted Graveyard  // Bellman-Ford
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll INF = 50000000; // 넉넉하게 5000 x 10000

struct hole {
	int x;
	int y;
	ll t;
};

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void bellmanFord(int W, int H, vector<vector<int>> board, vector<vector<hole>> adj) {
	vector<vector<ll>> upper(W, vector<ll>(H, INF));
	upper[0][0] = 0;
	bool updated = false;
	for (int i = 0; i < W * H; i++) {
		updated = false;
		for (int x = 0; x < W; x++) {
			for (int y = 0; y < H; y++) {
				if (board[x][y] == INF) continue; // 무덤인 경우
				if (x == W - 1 && y == H - 1) continue; // 종착지
				if (upper[x][y] == INF) continue; // 시작점에서부터 출발하지 않은 경우
				if (board[x][y] == -INF) { // 현재 위치가 귀신 구멍인 경우
					// 귀신 구멍을 통해 이동 
					hole out = adj[x][y];
					int nx = out.x;
					int ny = out.y;
					ll nt = upper[x][y] + out.t;
					if (upper[nx][ny] > nt) { // 완화
						upper[nx][ny] = nt;
						updated = true;
					}
				}
				else { // 귀신 구멍이 아닌 경우
					for (int j = 0; j < 4; j++) {
						int nx = x + dx[j];
						int ny = y + dy[j];
						ll nt = upper[x][y] + 1;
						//cout << nx << " " << ny << "\n";
						if (nx < 0 || nx >= W || ny < 0 || ny >= H || board[nx][ny] == INF) continue; // 범위를 넘어서거나 무덤인 경우
						if (upper[nx][ny] > nt) { // 완화
							upper[nx][ny] = nt;
							updated = true;
						}
					}
				}
			}
		}
		if (!updated) break;
	}
	if (updated) {
		cout << "Never" << "\n";
	}
	else if (upper[W - 1][H - 1] == INF) {
		cout << "Impossible" << "\n";
	}
	else {
		cout << upper[W - 1][H - 1] << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int W, H;
	cin >> W >> H;
	while (W != 0) {
		vector<vector<int>> board(W, vector<int>(H, 0));
		int G;
		cin >> G;
		for (int i = 0; i < G; i++) {
			int X, Y;
			cin >> X >> Y;
			board[X][Y] = INF; // 묘비 표시
		}
		int E;
		cin >> E;
		vector<vector<hole>> adj(W, vector<hole>(H));
		for (int i = 0; i < E; i++) {
			int X1, Y1, X2, Y2, T;
			cin >> X1 >> Y1 >> X2 >> Y2 >> T;
			board[X1][Y1] = -INF; // 귀신 구멍 표시
			adj[X1][Y1] = { X2, Y2, T };
		}
		bellmanFord(W, H, board, adj);
		cin >> W >> H;
	}

	return 0;
}