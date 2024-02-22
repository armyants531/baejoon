#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<vector<bool>> v(101, vector<bool>(101));
unordered_map<int, bool> mp; // 해싱(두 좌표를 잇는 길이 있는가?)
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
vector<pair<int, int>> cow(101);

void bfs(pair<int, int> x, int N) {
	queue<pair<int, int>> que;  
	que.push(x);
	v[x.first][x.second] = true;
	while (!que.empty()) {
		int r = que.front().first;
		int c = que.front().second;
		que.pop();
		for (int i = 0; i < 4; i++) {
			int nr = r + dx[i];
			int nc = c + dy[i];
			if (nr >= 1 && nr <= N && nc >= 1 && nc <= N && !v[nr][nc]) {
				if (mp[1000000 * r + 10000 * c + 100 * nr + nc]) continue;
				que.push({nr, nc});
				v[nr][nc] = true;
			}
		}
	} 
	return;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, K, R;
	cin >> N >> K >> R;
	for (int i = 0; i < R; i++) {
		int r, c, r1, c1;
		cin >> r >> c >> r1 >> c1;
		// 다리는 양방향임에 주의! 
		mp[1000000 * r + 10000 * c + 100 * r1 + c1] = true; 
		mp[1000000 * r1 + 10000 * c1 + 100 * r + c] = true;
	}
	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y; 
		cow[i] = {x, y};
	}
	int cnt = 0; // 만날 수 있는 소의 쌍 수 
	for (int i = 0; i < K; i++) { // 각 소의 위치에서 bfs 시행 
		// 초기화 
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				v[j][k] = false;
			}
		}
		bfs(cow[i], N);
		for (int j = i + 1; j < K; j++) { // 자신보다 뒤의 소 탐색 
			if (v[cow[j].first][cow[j].second]) {
				cnt++;
			} 
		} 
	}
	// 만날 수 없는 소 쌍 수 = 모든 소 쌍 수 - 만날 수 있는 쌍 수 
	cout << K * (K-1) / 2 - cnt << "\n";
	
	return 0;
}